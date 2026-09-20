#pragma once

#include <string>
#include<iostream>

using namespace std;
class Book
{
private:
	string bookname;
	string barcode;
	string isbn;
	string author;
	string publisher;
	double bookprice;
	bool isAvailable;
public:
	Book(string bookname, string barcode, string isbn, string author, string publisher, double bookprice);
	string getBookName() const;
	string getBarcode() const;
	string getISBN()const;
	string getAuthor()const;
	string getPublisher() const;
	double getBookPrice() const;
	bool getIsAvailable() const;
	void setIsAvailable(bool available);
};
