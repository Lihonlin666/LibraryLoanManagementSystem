#include "NormalBook.h"

NormalBook::NormalBook(string bookname, string barcode, string isbn, string author, string publisher)
	: Book(bookname, barcode, isbn, author, publisher)
{
}
void NormalBook::showInfo() const
{
	cout << "[一般图书]";
	Book::showInfo();
}