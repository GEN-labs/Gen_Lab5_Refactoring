
#include "Customer.h"
#include "Movie.h"
#include "Rental.h"

#include "gtest/gtest.h"

TEST(CustomerTest, simple){


    std::shared_ptr<Movie::RegularMovie> regularMovie = std::make_shared<Movie::RegularMovie>();
    std::shared_ptr<Movie::ChildrensMovie> childrensMovie = std::make_shared<Movie::ChildrensMovie>();
    std::shared_ptr<Movie::NewReleaseMovie> newReleaseMovie = std::make_shared<Movie::NewReleaseMovie>();

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", newReleaseMovie ), 5));
    customer.addRental( Rental( Movie("Snow White", childrensMovie), 3 ));

    ASSERT_EQ(customer.statement(), "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White"
                                    "\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points");
}



