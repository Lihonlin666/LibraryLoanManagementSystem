#include "Book.h"
#include <iostream>

using std::cout;
using std::endl;

Book::Book()
{
    bookName = "";
    isbn = "";
    press = "";
    price = 0;
    page = 0;
    isAvailable = true;
}

Book::Book(const std::string& name, const std::string& isbn_, const std::string& press_, double price_, int page_, bool avail)
{
    bookName = name;
    isbn = isbn_;
    press = press_;
    price = price_;
    page = page_;
    isAvailable = avail;
}

std::string Book::getBookName() const { return bookName; }
std::string Book::getIsbn() const { return isbn; }
std::string Book::getPress() const { return press; }
double Book::getPrice() const { return price; }
int Book::getPage() const { return page; }
bool Book::getAvailable() const { return isAvailable; }

void Book::setBookName(const std::string& n) { bookName = n; }
void Book::setIsbn(const std::string& id) { isbn = id; }
void Book::setPress(const std::string& p) { press = p; }
void Book::setPrice(double pr) { price = pr; }
void Book::setPage(int pg) { page = pg; }
void Book::setAvailable(bool sta) { isAvailable = sta; }

bool Book::checkIsbnValid() const
{
    return isbn.size() == 13;
}

void Book::showInfo() const
{
    cout << "==== Book Info ====" << endl;
    cout << "Title: " << bookName << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Publisher: " << press << endl;
    cout << "Price: " << price << endl;
    cout << "Pages: " << page << endl;
    cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    cout << "ISBN check: " << (checkIsbnValid() ? "valid" : "invalid") << endl;
    cout << "================" << endl;
}
