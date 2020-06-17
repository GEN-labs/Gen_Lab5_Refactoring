#include <iostream>

#include "Customer.h"

using namespace std;


int main() {

    //Shoulb be singleton...
    std::shared_ptr<Movie::NewReleaseMovie> newReleaseType = std::make_shared<Movie::NewReleaseMovie>();
    std::shared_ptr<Movie::ChildrensMovie> childrenType = std::make_shared<Movie::ChildrensMovie>();

    std::shared_ptr<Movie> movie1 = std::make_shared<Movie>("Karate Kid");
    std::shared_ptr<Movie> movie2 = std::make_shared<Movie>("Avengers: Endgame", newReleaseType);
    std::shared_ptr<Movie> movie3 = std::make_shared<Movie>("Snow White", childrenType);

/*
    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NewReleaseMovie ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
    std::cout << customer.statement() << std::endl;
    */


    return 0;
}
