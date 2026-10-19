#include "BorrowRecord.h"

BorrowRecord::BorrowRecord(Book* b, string bDate)
{
    this->book = b;
    this->borrowDate = bDate;
    this->returnDate = "";
    this->fine = 0.0;
}

Book* BorrowRecord::getBook() const
{
    return book;
}
string BorrowRecord::getBorrowDate() const
{
    return borrowDate;
}
string BorrowRecord::getReturnDate() const
{
    return returnDate;
}
double BorrowRecord::getFine() const
{
    return fine;
}

void BorrowRecord::setReturnInfo(string rDate, double f)
{
    this->returnDate = rDate;
    this->fine = f;
}
