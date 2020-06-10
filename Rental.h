// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;

    double getAmount() const {
        return _movie.getAmount(_daysRented);
    }
    int getRenterPoints(){
        if(typeid(*_movie.getMovieType()) == typeid(Movie::NewReleaseMovie) && _daysRented > 1 )
            return 2;
        return 1;
    }

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H