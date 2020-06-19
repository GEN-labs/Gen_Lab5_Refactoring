#include "../Customer.h"
#include "../Movie.h"
#include "../Rental.h"

#include "gtest/gtest.h"
#include "../mocking/RentalMock.hpp"

using ::testing::Return;

TEST(CustomerTest, simple){



    std::shared_ptr<RentalMock> rentalMock1 = std::make_shared<RentalMock>();
    std::shared_ptr<RentalMock> rentalMock2 = std::make_shared<RentalMock>();
    EXPECT_CALL(*rentalMock1, getMovieTitle()).WillRepeatedly(Return("Nicolas et ses amis virutels"));
    EXPECT_CALL(*rentalMock2, getMovieTitle()).WillRepeatedly(Return("Lucas sans famille"));

    EXPECT_CALL(*rentalMock1, getRenterPoints()).WillRepeatedly(Return(1));
    EXPECT_CALL(*rentalMock2, getRenterPoints()).WillRepeatedly(Return(2));

    EXPECT_CALL(*rentalMock1, getAmount()).WillRepeatedly(Return(10.5));
    EXPECT_CALL(*rentalMock2, getAmount()).WillRepeatedly(Return(55.0));

    std::shared_ptr<Rental> rental1 = rentalMock1;
    std::shared_ptr<Rental> rental2 = rentalMock2;

    Customer customer("Moris la malice");
    customer.addRental(rental1);
    customer.addRental(rental2);

    std::string assertString = "Rental Record for Moris la malice\n\t"
                               "Nicolas et ses amis virutels\t10.5\n\t"
                               "Lucas sans famille\t55\n"
                               "Amount owed is 65.5\n"
                               "You earned 3 frequent renter points";

    ASSERT_EQ(customer.statement(), assertString);
}

TEST(GetName, simple){
    Customer c("Pirlouit");
    ASSERT_EQ(c.getName(),"Pirlouit");
}



