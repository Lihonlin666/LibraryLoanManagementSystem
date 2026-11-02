#include "EBook.h"

EBook::EBook(string bookname, string barcode, string isbn, string author, string publisher, string url)
    :Book(bookname, barcode, isbn, author, publisher)
{
    this->url = url;
}

void EBook::showInfo() const
{
    cout << "[电子资源] ";
    Book::showInfo();
    cout << "    访问链接：" << url << endl;
}
