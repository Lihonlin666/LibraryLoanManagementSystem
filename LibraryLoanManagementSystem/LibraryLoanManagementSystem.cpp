#include"book.h"
#include"user.h"
#include<iostream>
#include<string>

using namespace std;
int main()
{
	// Create a book object
	Book book1("The Great Gatsby", "123456789", "978-0743273565", "F. Scott Fitzgerald", "Scribner", 10.99);
	// Display book information
	cout << "Book Name: " << book1.getBookName() << endl;
	cout << "Barcode: " << book1.getBarcode() << endl;
	cout << "ISBN: " << book1.getISBN() << endl;
	cout << "Author: " << book1.getAuthor() << endl;
	cout << "Publisher: " << book1.getPublisher() << endl;
	cout << "Price: $" << book1.getBookPrice() << endl;
	cout << "Availability: " << (book1.getIsAvailable() ? "Available" : "Not Available") << endl;
	// Create a user object
	User user1("Alice Smith", "Computer Science", 5);
	// Display user information
	cout << "\nUser Name: " << user1.getName() << endl;
	cout << "Department: " << user1.getDepartment() << endl;
	cout << "Max Borrow Limit: " << user1.getMaxBorrow() << endl;
	return 0;
}