#ifndef LABO5_MOVIEMOCK_HPP
#define LABO5_MOVIEMOCK_HPP

#include "../Movie.h"
#include <gmock/gmock.h>

class MovieMock : public Movie {
public:
    MOCK_METHOD(std::string, getTitle, (),(const));
    MOCK_METHOD(double, getAmount, (int),(const));
    MOCK_METHOD(std::shared_ptr<Movie::MovieType>, getMovieType, (),(const));
};


#endif //LABO5_MOVIEMOCK_HPP
