#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string bookname, string barcode, string isbn, string author, string publisher)
{
    this->m_bookname = bookname;
    this->m_barcode = barcode;
    this->m_isbn = isbn;
    this->m_author = author;
    this->m_publisher = publisher;
    this->m_isAvailable = true;
}

string Book::getBookName() const
{
    return m_bookname;
}
string Book::getBarcode() const
{
    return m_barcode;
}
string Book::getISBN() const
{
    return m_isbn;
}
string Book::getAuthor() const
{
    return m_author;
}
string Book::getPublisher() const
{
    return m_publisher;
}
bool Book::getIsAvailable() const
{
    return m_isAvailable;
}
void Book::setIsAvailable(bool available)
{
    this->m_isAvailable = available;
}
void Book::showInfo() const
{
    string stat = m_isAvailable ? "【可借】" : "【已借出】";
    cout << "条码:" << m_barcode << " 《" << m_bookname << "》作者:" << m_author
        << "，出版社:" << m_publisher << "，ISBN:" << m_isbn << " " << stat << endl;
}
