#include "Student.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

Student::Student()
{
    stuName = "";
    stuId = "";
    borrowCount = 0;
}

Student::Student(const string& name, const string& id)
{
    stuName = name;
    stuId = id;
    borrowCount = 0;
}

string Student::getStuName() const { return stuName; }
string Student::getStuId() const { return stuId; }
int Student::getBorrowCount() const { return borrowCount; }

void Student::setStuName(const string& n) { stuName = n; }
void Student::setStuId(const string& id) { stuId = id; }

void Student::borrowBook(Book& b)
{
    if (borrowCount >= MAX_BORROW)
    {
        cout << "[Borrow failed] reached max borrow limit " << MAX_BORROW << endl;
        return;
    }
    if (!b.getAvailable())
    {
        cout << "[Borrow failed] '" << b.getBookName() << "' already borrowed" << endl;
        return;
    }
    b.setAvailable(false);
    borrowCount++;
    cout << "[Borrow success] " << stuName << " borrowed '" << b.getBookName() << "'" << endl;
    cout << "Current borrowed: " << borrowCount << endl;
}

void Student::returnBook(Book& b)
{
    if (b.getAvailable())
    {
        cout << "[Return failed] book was not borrowed" << endl;
        return;
    }
    b.setAvailable(true);
    if (borrowCount > 0) borrowCount--;
    cout << "[Return success] " << stuName << " returned '" << b.getBookName() << "'" << endl;
    cout << "Current borrowed: " << borrowCount << endl;
}
