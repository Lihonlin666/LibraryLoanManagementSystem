#pragma once
#include"Book.h"

class NormalBook:public Book
{
public:
	NormalBook(string bookname, string barcode, string isbn, string author, string publisher);
	virtual void showInfo() const override;
};

