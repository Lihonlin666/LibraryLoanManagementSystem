#pragma once
#include "Book.h"
#include "User.h"
#include "BorrowRecord.h"
#include <string>

class Library
{
private:
    Book* books[100];
    User* users[100];
    BorrowRecord* records[100];
    int bookCount;
    int userCount;
    int recordCount;

    int calcDayDiff(const std::string& date1, const std::string& date2);
public:
    Library();
    ~Library();

    void addBook(Book* bk);
    void addUser(User* us);

    bool borrowBook(User* user, Book* book, const std::string& borrowDate, const std::string& dueDate);
    double returnBook(User* user, Book* book, const std::string& returnDate);

    //==== 查询接口：3个 ====
    Book* queryBookByIsbn(const std::string& isbn);
    User* queryUserByName(const std::string& name);
    User* queryUserById(const std::string& id);      //新增：按学号/工号查询

    void showAllBooks() const;
    void showAllUsers() const;
    void showAllRecords() const;

    int getBorrowedCount(User* user);

    int getBookCount() const;
    int getUserCount() const;
    int getRecordCount() const;
};
