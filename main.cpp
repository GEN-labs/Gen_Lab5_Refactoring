#include <iostream>

#include "Customer.h"

using namespace std;

/*
int main() {

    //Should be singleton...
    std::shared_ptr<Movie::NewReleaseMovie> newReleaseType = std::make_shared<Movie::NewReleaseMovie>();
    std::shared_ptr<Movie::ChildrensMovie> childrenType = std::make_shared<Movie::ChildrensMovie>();

    std::shared_ptr<Movie> movie1 = std::make_shared<Movie>("Karate Kid");
    std::shared_ptr<Movie> movie2 = std::make_shared<Movie>("Avengers: Endgame", newReleaseType);
    std::shared_ptr<Movie> movie3 = std::make_shared<Movie>("Snow White", childrenType);

    Customer customer("Olivier");

    std::shared_ptr<Rental> rental1 = std::make_shared<Rental>(movie1,7);
    std::shared_ptr<Rental> rental2 = std::make_shared<Rental>(movie2,5);
    std::shared_ptr<Rental> rental3 = std::make_shared<Rental>(movie3,3);

    customer.addRental(rental1);
    customer.addRental(rental2);
    customer.addRental(rental3);

    std::cout << customer.statement() << std::endl;

    return 0;
}*/
