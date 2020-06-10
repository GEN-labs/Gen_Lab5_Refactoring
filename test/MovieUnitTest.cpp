//
// Created by mle on 10.06.2020.
//
#include "gtest/gtest.h"
#include <string>
#include "../mocking/MovieTypeMock.hpp"

using ::testing::Return;

TEST(MovieGetAmountTest, unitaire){
    std::string name = "Blanche fesse et les septs mains";


    std::shared_ptr<RegularMovieMock> regularMovieMock = std::make_shared<RegularMovieMock>();
    std::shared_ptr<ChildrensMovieMock> childrensMovieMock = std::make_shared<ChildrensMovieMock>();
    std::shared_ptr<NewReleaseMovieMock> newReleaseMovieMock = std::make_shared<NewReleaseMovieMock>();


    EXPECT_CALL(*regularMovieMock, getAmount(1)).WillRepeatedly(Return(2));
    EXPECT_CALL(*regularMovieMock, getAmount(4)).WillRepeatedly(Return(3));

    EXPECT_CALL(*childrensMovieMock, getAmount(1)).WillRepeatedly(Return(1.5));
    EXPECT_CALL(*childrensMovieMock, getAmount(5)).WillRepeatedly(Return(3));

    EXPECT_CALL(*newReleaseMovieMock, getAmount(1)).WillRepeatedly(Return(3));
    EXPECT_CALL(*newReleaseMovieMock, getAmount(4)).WillRepeatedly(Return(12));

    Movie movie_1(name, regularMovieMock);
    Movie movie_2(name, childrensMovieMock);
    Movie movie_3(name, newReleaseMovieMock);

    ASSERT_DOUBLE_EQ(movie_1.getAmount(1), 2);
    ASSERT_DOUBLE_EQ(movie_1.getAmount(4), 3);
    ASSERT_DOUBLE_EQ(movie_2.getAmount(1), 1.5);
    ASSERT_DOUBLE_EQ(movie_2.getAmount(5), 3);
    ASSERT_DOUBLE_EQ(movie_3.getAmount(1), 3);
    ASSERT_DOUBLE_EQ(movie_3.getAmount(4), 12);
}
TEST(MovieTitle, unit){
    std::string name = "Jean-Cul GodeHard - Pierro le Foutre";
    std::shared_ptr<RegularMovieMock> regularMovieMock = std::make_shared<RegularMovieMock>();
    Movie movie_1(name, regularMovieMock);
    ASSERT_EQ(movie_1.getTitle(), name);
}

TEST(MovieGetMovieType, unit){
    std::shared_ptr<RegularMovieMock> regularMovieMock = std::make_shared<RegularMovieMock>();
    Movie movie_1("Coco l'asticot", regularMovieMock);
    ASSERT_EQ(movie_1.getMovieType(), regularMovieMock);

}
