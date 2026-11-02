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
        if ((*it)->getBarcode() == barcode)
        {
            if (!(*it)->getIsAvailable())
            {
                cout << "[删除失败]该图书已经被借出，不能删除！" << endl;
                return false;
            }
            delete (*it); 
            bookList.erase(it);
            cout << "[删除成功]图书条码：" << barcode << endl;
             return true;
        }
    }
    cout << "[删除失败]找不到该条码的图书！" << endl;
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
        b->showInfo();
    }
}

void Library::showAllUsers() const
{
    cout << "\n=========注册用户列表（学生+教师）=========\n";
    for (auto u : userList)
    {
        cout << "ID:" << u->getUserId()
            << " 姓名:" << u->getUserName()
            << " 当前已借:" << u->getBorrowCount()
            << "/" << u->getMaxBorrow() << endl;
    }
}
