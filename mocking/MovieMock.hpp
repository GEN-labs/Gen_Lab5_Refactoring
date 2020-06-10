//
// Created by mle on 10.06.2020.
//

#ifndef LABO5_MOVIEMOCK_HPP
#define LABO5_MOVIEMOCK_HPP

#include "../Movie.h"
#include <gmock/gmock.h>

class MovieMock : public Movie {
public:
    MOCK_METHOD(std::string, getTitle, (),(const));
};


#endif //LABO5_MOVIEMOCK_HPP
