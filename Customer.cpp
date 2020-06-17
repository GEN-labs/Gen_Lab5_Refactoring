// Customer.cpp
#include <sstream>
#include "Customer.h"

using std::ostringstream;
using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for(std::shared_ptr<Rental> rental : _rentals ){

        double thisAmount = rental->getAmount();
        frequentRenterPoints += rental->getRenterPoints();

        // show figures for this rental
        result << "\t" << rental->getMovieTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}