#include "BorrowRecord.h"

BorrowRecord::BorrowRecord(Book* pb, User* pu, string bDate, string dDate, string rDate, double f)
{
    this->pBook = pb;
    this->pUser = pu;
    this->borrowDate = bDate;
    this->dueDate = dDate;
    this->returnDate = rDate;
    this->fine = f;
}

Book* BorrowRecord::getBook() const
{
    return pBook;
}

User* BorrowRecord::getUser() const
{
    return pUser;
}

string BorrowRecord::getBorrowDate() const
{
    return borrowDate;
}

string BorrowRecord::getDueDate() const
{
    return dueDate;
}

string BorrowRecord::getReturnDate() const
{
    return returnDate;
}

double BorrowRecord::getFine() const
{
    return fine;
}

void BorrowRecord::setReturnDate(string retDate)
{
    this->returnDate = retDate;
}

void BorrowRecord::setFine(double f)
{
    this->fine = f;
}
