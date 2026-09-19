#pragma once

#include <string>
using namespace std;
class Book
{
private:
	string bookname;
	string barcode;
	string isbn;
	string author;
	string publisher;
	bool isAvailable;
public:
	Book(string bookname, string barcode, string isbn,  string author, string publisher);
	string getBookName() const;
	string getBarcode() const;
	string getISBN()const ;
	string getAuthor()const ;
	string getPublisher() const;
	bool getIsAvailable() const;
	void setIsAvailable(bool available);
}
