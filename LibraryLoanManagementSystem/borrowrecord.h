#pragma once
#include "Book.h"
#include "User.h"
#include <string>
using namespace std;

class BorrowRecord
{
private:
    Book* pBook;
    User* pUser;
    string borrowDate;
    string dueDate;
    string returnDate;
    double fine;
public:
    BorrowRecord(Book* pb, User* pu, string bDate, string dDate, string rDate, double f);

    Book* getBook() const;
    User* getUser() const;
    string getBorrowDate() const;
    string getDueDate() const;
    string getReturnDate() const;
    double getFine() const;

    void setReturnDate(string retDate);
    void setFine(double f);
};
