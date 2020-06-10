// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <memory>

class Movie {

public:
    class MovieType {
    public:
        virtual double getAmount(int daysRented) = 0;
    };

    class RegularMovie : public MovieType {
    public:
        double getAmount(int daysRented) override {
            double amount = 2;
            if ( daysRented > 2 )
                amount += ( daysRented - 2 ) * 1.5 ;
            return amount;
        }
    };

    class ChildrensMovie : public MovieType {
    public:
        double getAmount(int daysRented) override {
            double amount = 1.5;
            if ( daysRented > 3 )
                amount += ( daysRented - 3 ) * 1.5;
            return amount;
        }
    };

    class NewReleaseMovie : public MovieType {
    public:
        double getAmount(int daysRented) override {
            return daysRented * 3;
        }
    };

    Movie( const std::string& title, std::shared_ptr<MovieType> movieType = std::make_shared<RegularMovie>())
    : _title(title), _movieType(movieType)
    {}

    std::shared_ptr<Movie::MovieType> getMovieType() const;

    //TODO : inline plus bas
    double getAmount(int daysRented) const{
        return _movieType->getAmount(daysRented);
    }
    void setMovieType( std::shared_ptr<MovieType> arg );
    std::string getTitle() const;

private:
    std::string _title;
    std::shared_ptr<MovieType> _movieType;

};

inline std::shared_ptr<Movie::MovieType> Movie::
getMovieType() const { return _movieType; }

inline void Movie::
setMovieType( std::shared_ptr<MovieType> arg  ) { _movieType = arg; }

inline std::string Movie::
getTitle() const { return _title; }


#endif // MOVIE_H