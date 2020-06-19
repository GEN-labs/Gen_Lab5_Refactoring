#include "../Movie.h"

#include "gtest/gtest.h"

TEST(Regular, unit){

    std::shared_ptr<Movie::RegularMovie> regularMovie = std::make_shared<Movie::RegularMovie>();

    //Test if right amount with default value and daysRented > 2
    Movie movie1("Karate Kid");
    double amount = movie1.getAmount(7);
    ASSERT_EQ(amount, 9.5);

    //test if right amount with coded value
    Movie movie2("Karate Kid", regularMovie);
    amount = movie2.getAmount(1);
    ASSERT_EQ(amount, 2);
}

TEST(Children, unit){
    std::shared_ptr<Movie::ChildrensMovie> childrensMovie = std::make_shared<Movie::ChildrensMovie>();

    //Test if right amount with default value and daysRented > 3
    Movie movie1("Karate Kid", childrensMovie);
    double amount = movie1.getAmount(7);
    ASSERT_EQ(amount, 7.5);

    //test if right amount dayRented <= 3
    Movie movie2("Karate Kid", childrensMovie);
    amount = movie2.getAmount(1);
    ASSERT_EQ(amount, 1.5);
}

TEST(NewRelease, unit){
    std::shared_ptr<Movie::NewReleaseMovie> newReleaseMovie = std::make_shared<Movie::NewReleaseMovie>();

    Movie movie1("Karate Kid", newReleaseMovie);
    double amount = movie1.getAmount(2);
    ASSERT_EQ(amount, 6);
}
