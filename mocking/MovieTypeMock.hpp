//
// Created by mle on 10.06.2020.
//

#ifndef LABO5_MOVIETYPEMOCK_HPP
#define LABO5_MOVIETYPEMOCK_HPP

#include "../Movie.h"
#include <gmock/gmock.h>

class RegularMovieMock : public Movie::MovieType {
public:
    MOCK_METHOD(double, getAmount,(int),(override));
};

class ChildrensMovieMock : public Movie::MovieType {
public:
    MOCK_METHOD(double, getAmount,(int),(override));
};

class NewReleaseMovieMock : public Movie::MovieType {
public:
    MOCK_METHOD(double, getAmount,(int),(override));
};


#endif //LABO5_MOVIETYPEMOCK_HPP
