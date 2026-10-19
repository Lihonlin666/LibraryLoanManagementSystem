#include "User.h"
#include <iostream>

using namespace std;

User::User(const string& id, const string& name, int maxNum)
{
    this->userId = id;
    this->userName = name;
    this->maxBorrow = maxNum;
}

bool User::borrowBook(Book* pBook, const string& borrowDate, const string& recId)
{
    if (pBook == nullptr) return false;
    if (!pBook->getIsAvailable())
    {
        cout << "[Borrow failed] '" << pBook->getBookName() << "' already borrowed" << endl;
        return false;
    }
    if ((int)borrowedBooks.size() >= maxBorrow)
    {
        cout << "[Borrow failed] " << userName << " reached max borrow " << maxBorrow << endl;
        return false;
    }
    pBook->setIsAvailable(false);
    borrowedBooks.push_back(pBook);
    BorrowRecord rec(pBook, borrowDate);
    recordList.push_back(rec);
    cout << "[Borrow success] " << userName << " borrowed '" << pBook->getBookName() << "'" << endl;
    return true;
}

bool User::returnBook(Book* pBook, const string& retDate, double fineVal)
{
    if (pBook == nullptr) return false;
    bool found = false;
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it)
    {
        if (*it == pBook)
        {
            borrowedBooks.erase(it);
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "[Return failed] user did not borrow this book" << endl;
        return false;
    }
    pBook->setIsAvailable(true);
    for (auto& rec : recordList)
    {
        if (rec.getBook() == pBook && rec.getReturnDate() == "")
        {
            rec.setReturnInfo(retDate, fineVal);
            break;
        }
    }
    cout << "[Return success] " << userName << " returned '" << pBook->getBookName() << "', fine: " << fineVal << endl;
    return true;
}

void User::showBorrowed() const
{
    cout << "\n====== " << userName << " (" << userId << ") Borrowed (" << borrowedBooks.size() << ") ======" << endl;
    if (borrowedBooks.empty())
    {
        cout << "None" << endl;
        return;
    }
    for (const auto pb : borrowedBooks)
    {
        if (!pb) continue;
        cout << "- Title: " << pb->getBookName() << " Author: " << pb->getAuthor() << endl;
    }
}

void User::showAllRecord() const
{
    cout << "\n====== " << userName << " (" << userId << ") All Records (" << recordList.size() << ") ======" << endl;
    if (recordList.empty())
    {
        cout << "None" << endl;
        return;
    }
    for (const auto& r : recordList)
    {
        cout << "Title:" << r.getBook()->getBookName()
            << " Borrow:" << r.getBorrowDate()
            << " Return:" << r.getReturnDate()
            << " Fine:" << r.getFine() << endl;
    }
}

string User::getUserId() const
{
    return userId;
}
string User::getUserName() const
{
    return userName;
}
int User::getBorrowCount() const
{
    return (int)borrowedBooks.size();
}
int User::getMaxBorrow() const
{
    return maxBorrow;
}
