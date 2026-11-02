#include "Magazine.h"
Magazine::Magazine(string bookname, string barcode, string isbn, string author, string publisher, string issue)
	: Book(bookname, barcode, isbn, author, publisher) {
	this->m_issue = issue;
}
void Magazine::showInfo() const {
	cout << "[杂志]";
	Book::showInfo();
	cout << " 期号: " << m_issue << endl;
}