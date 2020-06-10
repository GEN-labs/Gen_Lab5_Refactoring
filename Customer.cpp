// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for(Rental rental : _rentals ){

        double thisAmount = rental.getMovie().getAmount(rental.getDaysRented());

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental

        if(typeid(*rental.getMovie().getMovieType()) == typeid(Movie::NewReleaseMovie) && rental.getDaysRented() > 1 )
            frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}