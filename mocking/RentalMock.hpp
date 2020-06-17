//
// Created by mle on 17.06.2020.
//

#ifndef LABO5_RENTALMOCK_HPP
#define LABO5_RENTALMOCK_HPP

#include "../Rental.h"
#include <gmock/gmock.h>

class RentalMock : public Rental {
public:
    MOCK_METHOD(std::string, getMovieTitle, (),(const));
    MOCK_METHOD(double, getAmount, (),(const));
    MOCK_METHOD(int, getRenterPoints, (),(const));
};

#endif //LABO5_RENTALMOCK_HPP
