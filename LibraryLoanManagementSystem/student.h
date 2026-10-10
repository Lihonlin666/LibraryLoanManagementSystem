#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Book.h"


class Student
{
private:
    std::string stuName;
    std::string stuId;
    int borrowCount;
    static constexpr int MAX_BORROW = 3;
public:
    Student();
    Student(const std::string& name, const std::string& id);

    std::string getStuName() const;
    std::string getStuId() const;
    int getBorrowCount() const;

    void setStuName(const std::string& n);
    void setStuId(const std::string& id);

    //依赖关系：Book引用传递
    void borrowBook(Book& b);
    void returnBook(Book& b);
};
#endif
