//
// Created by mle on 10.06.2020.
//

#include "gtest/gtest.h"
#include <string>
#include "../mocking/MovieTypeMock.hpp"
#include "../Movie.h"
#include "../mocking/MovieMock.hpp"
#include "../Rental.h"

using ::testing::Return;

TEST(GetAmountTest, unitaire) {

    std::string movieName = "La belle et la best";
    int nbDays = 10;

    std::shared_ptr<MovieMock> movieMock = std::make_shared<MovieMock>();
    std::shared_ptr<Movie> movie = movieMock;
    EXPECT_CALL(*movieMock, getAmount(nbDays)).WillRepeatedly(Return(30));
    Rental rental(movie, nbDays);
    ASSERT_DOUBLE_EQ(rental.getAmount(), 30);
}

TEST(getRenterPoints, unitaire){

}

TEST(GetMovie, unitaire) {

}