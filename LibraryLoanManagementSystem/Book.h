#pragma once
#include <string>
using namespace std;

class Book
{
private:
    string m_bookname;    // 书名
    string m_barcode;     // 图书条码号
    string m_isbn;        // ISBN
    string m_author;      // 作者
    string m_publisher;   // 出版社
    bool m_isAvailable;   // 是否可借
public:
    Book(string bookname, string barcode, string isbn, string author, string publisher);

    string getBookName() const;
    string getBarcode() const;
    string getISBN() const;
    string getAuthor() const;
    string getPublisher() const;
    bool getIsAvailable() const;

    void setIsAvailable(bool available);
};
