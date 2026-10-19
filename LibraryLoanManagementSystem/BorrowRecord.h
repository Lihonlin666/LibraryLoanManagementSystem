#pragma once
#include <string>
#include "Book.h"
using namespace std;

class BorrowRecord
{
private:
    Book* book;
    string borrowDate;
    string returnDate;
    double fine;
public:
    BorrowRecord(Book* b, string bDate);

    Book* getBook() const;
    string getBorrowDate() const;
    string getReturnDate() const;
    double getFine() const;

    void setReturnInfo(string rDate, double f);
};
