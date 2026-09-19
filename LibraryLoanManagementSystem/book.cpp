#include "book.h"
#include<iostream>

Book::Book(string bookname, string barcode, string isbn, string author, string publisher)
{
	this->bookname = bookname;
	this->barcode = barcode;
	this->isbn = isbn;
	this->author = author;
	this->publisher = publisher;
	this->isAvailable = true;
}

string Book::getBookName() const
{
	return bookname;
}

string Book::getBarcode() const
{
	return barcode;
}

string Book::getISBN() const
{
	return isbn;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getPublisher() const
{
	return publisher;
}

bool Book::getIsAvailable() const
{
	return isAvailable;
}

void Book::setIsAvailable(bool available)
{
	isAvailable = available;
}