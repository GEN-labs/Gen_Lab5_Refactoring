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

    std::shared_ptr<Movie::RegularMovie> regularMovie = std::make_shared<Movie::RegularMovie>();
    std::shared_ptr<Movie::NewReleaseMovie> newRelease = std::make_shared<Movie::NewReleaseMovie>();

    /* Check with the regularMovieType behavior */
    std::shared_ptr<MovieMock> movieMockRegular = std::make_shared<MovieMock>();
    EXPECT_CALL(*movieMockRegular, getMovieType()).WillRepeatedly(Return(regularMovie));

    std::shared_ptr<Movie> movieRegular = movieMockRegular;
    Rental rental(movieRegular, 1);

    ASSERT_EQ(rental.getRenterPoints(),1);

    /* Check with the newRelease behavior */
    std::shared_ptr<MovieMock> movieMockNewRelease = std::make_shared<MovieMock>();
    EXPECT_CALL(*movieMockRegular, getMovieType()).WillRepeatedly(Return(newRelease));

    std::shared_ptr<Movie> movieNewRelease = movieMockRegular;
    Rental rental2(movieNewRelease, 2);
    Rental rental3(movieNewRelease, 1);

    ASSERT_EQ(rental2.getRenterPoints(),2);
    ASSERT_EQ(rental3.getRenterPoints(),1);
}

TEST(GetMovie, unitaire) {

    std::shared_ptr<Movie::RegularMovie> regularMovie = std::make_shared<Movie::RegularMovie>();

    std::shared_ptr<MovieMock> movieMock = std::make_shared<MovieMock>();

    EXPECT_CALL(*movieMock, getMovieType()).WillRepeatedly(Return(regularMovie));
    EXPECT_CALL(*movieMock, getTitle()).WillRepeatedly(Return("Titre de film"));

    std::shared_ptr<Movie> movie = movieMock;
    Rental rental(movie, 1);
    //To check if both movies are equal, we compare their title and type
    ASSERT_EQ(rental.getMovie()->getTitle(), movieMock->getTitle());
    ASSERT_EQ(rental.getMovie()->getMovieType(), movieMock->getMovieType());

}