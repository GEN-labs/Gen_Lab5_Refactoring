// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental(std::shared_ptr<Movie> movie, int daysRented );

    std::shared_ptr<Movie> getMovie() const;
    double getAmount() const {
        return _movie->getAmount(_daysRented);
    }
    int getRenterPoints(){
        if(typeid(*_movie->getMovieType()) == typeid(Movie::NewReleaseMovie) && _daysRented > 1 )
            return 2;
        return 1;
    }

private:
    std::shared_ptr<Movie> _movie;
    int _daysRented;
};

inline Rental::
Rental( std::shared_ptr<Movie> movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {

}

inline std::shared_ptr<Movie> Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H