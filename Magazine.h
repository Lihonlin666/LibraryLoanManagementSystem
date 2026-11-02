#pragma once
#include"Book.h"

class Magazine : public Book
{
private:
	string m_issue; // 期号
public:
	Magazine(string bookname, string barcode, string isbn, string author, string publisher, string issue);
	virtual void showInfo() const override;
};

