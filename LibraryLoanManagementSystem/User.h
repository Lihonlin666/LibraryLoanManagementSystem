#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "BorrowRecord.h"
using namespace std;

class User
{
protected:
    string userId;
    string userName;
    int maxBorrow;
    vector<Book*> borrowedBooks;
    vector<BorrowRecord> recordList;
public:
    User(const std::string& id, const std::string& name, int maxNum);
    virtual ~User() {}

    virtual bool borrowBook(Book* pBook, const std::string& borrowDate, const std::string& recId);
    virtual bool returnBook(Book* pBook, const std::string& retDate, double fineVal);

    void showBorrowed() const;
    void showAllRecord() const;

    string getUserId() const;
    string getUserName() const;
    int getBorrowCount() const;
    int getMaxBorrow() const;
};

