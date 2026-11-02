#pragma once
#include "Book.h"

class EBook : public Book
{
private:
    string url;
public:
    EBook(string bookname, string barcode, string isbn, string author, string publisher, string url);
    virtual void showInfo() const override;
};
