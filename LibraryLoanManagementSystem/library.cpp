#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;

Library::Library()
{
    this->bookCount = 0;
    this->userCount = 0;
    this->recordCount = 0;
    for (int i = 0; i < 100; i++)
    {
        books[i] = nullptr;
        users[i] = nullptr;
        records[i] = nullptr;
    }
}

Library::~Library()
{
    for (int i = 0; i < bookCount; i++) delete books[i];
    for (int i = 0; i < userCount; i++) delete users[i];
    for (int i = 0; i < recordCount; i++) delete records[i];
}

void Library::addBook(Book* bk)
{
    if (bookCount >= 100 || bk == nullptr) return;
    books[bookCount++] = bk;
}

void Library::addUser(User* us)
{
    if (userCount >= 100 || us == nullptr) return;
    users[userCount++] = us;
}

int Library::calcDayDiff(const std::string& date1, const std::string& date2)
{
    int y1, m1, d1, y2, m2, d2;
    char dash;
    std::stringstream ss1(date1);
    ss1 >> y1 >> dash >> m1 >> dash >> d1;
    std::stringstream ss2(date2);
    ss2 >> y2 >> dash >> m2 >> dash >> d2;

    int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    auto totalDay = [&](int y, int m, int d)->int {
        int sum = 0;
        for (int i = 1; i < m; i++) sum += monthDay[i];
        sum += d;
        return sum + y * 365;
        };
    return totalDay(y2, m2, d2) - totalDay(y1, m1, d1);
}

int Library::getBorrowedCount(User* user)
{
    int cnt = 0;
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i]->getUser() == user && records[i]->getReturnDate() == "")
        {
            cnt++;
        }
    }
    return cnt;
}

bool Library::borrowBook(User* user, Book* book, const std::string& borrowDate, const std::string& dueDate)
{
    if (!book->getIsAvailable())
    {
        cout << "[Info] Book already borrowed." << endl;
        return false;
    }
    if (getBorrowedCount(user) >= user->getMaxBorrow())
    {
        cout << "[Info] Reached maximum borrow limit." << endl;
        return false;
    }
    if (recordCount >= 100)
    {
        cout << "[Info] Borrow records full." << endl;
        return false;
    }
    BorrowRecord* newRec = new BorrowRecord(book, user, borrowDate, dueDate, "", 0.0);
    records[recordCount++] = newRec;
    book->setIsAvailable(false);
    return true;
}

double Library::returnBook(User* user, Book* book, const std::string& returnDate)
{
    BorrowRecord* target = nullptr;
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i]->getBook() == book
            && records[i]->getUser() == user
            && records[i]->getReturnDate() == "")
        {
            target = records[i];
            break;
        }
    }
    if (target == nullptr)
    {
        cout << "[Info] Cannot find corresponding borrow record." << endl;
        return -1;
    }

    int days = calcDayDiff(target->getDueDate(), returnDate);
    double fine = 0.0;
    if (days > 0)
    {
        cout << "[Overdue] Days overdue: " << days << endl;
        fine = days * 0.2;
    }

    target->setReturnDate(returnDate);
    target->setFine(fine);
    book->setIsAvailable(true);
    return fine;
}

Book* Library::queryBookByIsbn(const std::string& isbn)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i]->getISBN() == isbn)
            return books[i];
    }
    return nullptr;
}

User* Library::queryUserByName(const std::string& name)
{
    for (int i = 0; i < userCount; i++)
    {
        if (users[i]->getName() == name)
            return users[i];
    }
    return nullptr;
}

//========新增：按学号/工号查询用户========
User* Library::queryUserById(const std::string& id)
{
    for (int i = 0; i < userCount; ++i)
    {
        User* pu = users[i];
        Student* ps = dynamic_cast<Student*>(pu);
        if (ps != nullptr)
        {
            if (ps->getStuId() == id)
            {
                return pu;
            }
        }
        Teacher* pt = dynamic_cast<Teacher*>(pu);
        if (pt != nullptr)
        {
            if (pt->getTeaId() == id)
            {
                return pu;
            }
        }
    }
    return nullptr;
}

void Library::showAllBooks() const
{
    cout << "\n======== All Books ========" << endl;
    for (int i = 0; i < bookCount; i++)
    {
        cout << "[" << i + 1 << "] Title:" << books[i]->getBookName()
            << " |Barcode:" << books[i]->getBarcode()
            << " |ISBN:" << books[i]->getISBN()
            << " |Author:" << books[i]->getAuthor()
            << " |Publisher:" << books[i]->getPublisher()
            << " |Price:" << books[i]->getBookPrice()
            << " |Available:" << books[i]->getIsAvailable() << endl;
    }
}

void Library::showAllUsers() const
{
    cout << "\n======== All Users ========" << endl;
    for (int i = 0; i < userCount; i++)
    {
        User* pu = users[i];
        Student* ps = dynamic_cast<Student*>(pu);
        Teacher* pt = dynamic_cast<Teacher*>(pu);
        cout << "[" << i + 1 << "] Name:" << pu->getName();
        if (ps)
        {
            cout << " |StudentID:" << ps->getStuId();
        }
        if (pt)
        {
            cout << " |TeacherID:" << pt->getTeaId();
        }
        cout << " |Department:" << pu->getDepartment()
            << " |MaxBorrow:" << pu->getMaxBorrow() << endl;
    }
}

void Library::showAllRecords() const
{
    cout << "\n======== Borrow Records ========" << endl;
    for (int i = 0; i < recordCount; i++)
    {
        cout << "[" << i + 1 << "] User:" << records[i]->getUser()->getName()
            << " |Book:" << records[i]->getBook()->getBookName()
            << " |BorrowDate:" << records[i]->getBorrowDate()
            << " |DueDate:" << records[i]->getDueDate()
            << " |ReturnDate:" << records[i]->getReturnDate()
            << " |Fine:" << records[i]->getFine() << endl;
    }
}

int Library::getBookCount() const { return bookCount; }
int Library::getUserCount() const { return userCount; }
int Library::getRecordCount() const { return recordCount; }
