#include "Library.h"
#include <iostream>

Library::Library() {}

Library::~Library()
{
    for (auto p : bookList) delete p;
    for (auto p : userList) delete p;
}

void Library::addNewBook(Book* b)
{
    bookList.push_back(b);
}

bool Library::deleteBook(string barcode)
{
    for (auto it = bookList.begin(); it != bookList.end(); ++it)
    {
        if (*it && (*it)->getBarcode() == barcode)
        {
            if (!(*it)->getIsAvailable())
            {
                cout << "[Delete failed] Book is currently borrowed, cannot delete." << endl;
                return false;
            }
            delete *it;
            bookList.erase(it);
            cout << "[Delete success] Barcode: " << barcode << endl;
            return true;
        }
    }
    cout << "[Delete failed] Book with barcode not found." << endl;
    return false;
}

void Library::addUser(User* u)
{
    userList.push_back(u);
}

Book* Library::findBookByBarcode(string bar)
{
    for (auto b : bookList)
    {
        if (b->getBarcode() == bar)
            return b;
    }
    return nullptr;
}

User* Library::findUserById(string uid)
{
    for (auto u : userList)
    {
        if (u->getUserId() == uid)
            return u;
    }
    return nullptr;
}

void Library::showAllBooks() const
{
    cout << "\n=========馆藏全部图书=========\n";
    for (auto b : bookList)
    {
        if (!b) continue;
        string stat = b->getIsAvailable() ? "[Available]" : "[Borrowed]";
        cout << "Barcode:" << b->getBarcode()
            << " '" << b->getBookName() << "'"
            << " Author:" << b->getAuthor()
            << stat << endl;
    }
}

void Library::showAllUsers() const
{
    cout << "\n=========注册用户列表（学生+教师）=========\n";
    for (auto u : userList)
    {
        if (!u) continue;
        cout << "ID:" << u->getUserId()
            << " Name:" << u->getUserName()
            << " Borrowed:" << u->getBorrowCount()
            << "/" << u->getMaxBorrow() << endl;
    }
}
