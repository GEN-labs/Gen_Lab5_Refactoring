// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental(std::shared_ptr<Movie> movie, int daysRented );

    Rental();

    std::shared_ptr<Movie> getMovie() const;
    virtual double getAmount() const {
        return _movie->getAmount(_daysRented);
    }
    virtual int getRenterPoints() const {
        if(typeid(*_movie->getMovieType()) == typeid(Movie::NewReleaseMovie) && _daysRented > 1 )
            return 2;
        return 1;
    }

    virtual std::string getMovieTitle() const {
        return _movie->getTitle();
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

inline Rental::Rental() {}

#endif // RENTAL_H