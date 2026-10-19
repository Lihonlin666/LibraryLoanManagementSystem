#pragma once
#include <vector>
#include "Book.h"
#include "User.h"
using namespace std;

class Library
{
private:
    vector<Book*> bookList;
    vector<User*> userList;
public:
    Library();
    ~Library();

    void addNewBook(Book* b);
    bool deleteBook(string barcode);

    void addUser(User* u);

    Book* findBookByBarcode(string bar);
    User* findUserById(string uid);

    void showAllBooks() const;
    void showAllUsers() const;
};
