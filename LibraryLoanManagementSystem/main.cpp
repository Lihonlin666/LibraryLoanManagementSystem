#include <iostream>
#include "Book.h"
#include "Student.h"
using namespace std;

int main()
{
    //创建图书对象
    Book b1("C++面向对象程序设计", "9787302156567", "清华大学出版社", 49.5, 380);
    Book b2("数据结构", "9787111528081", "机械工业出版社", 55, 420);
    Book b3("操作系统", "9787111641247", "机械工业出版社", 69, 512);

    //创建学生对象
    Student stu("张三", "S2026001");

    cout << "----------系统初始图书状态----------" << endl;
    b1.showInfo();
    b2.showInfo();
    b3.showInfo();

    cout << "----------执行借书操作----------" << endl;
    stu.borrowBook(b1);
    cout << endl;
    stu.borrowBook(b2);
    cout << endl;
    stu.borrowBook(b1);   //重复借同一本书，失败
    cout << endl;

    cout << "----------借书之后图书状态----------" << endl;
    b1.showInfo();
    b2.showInfo();

    cout << "----------执行还书操作----------" << endl;
    stu.returnBook(b1);
    cout << endl;

    cout << "----------还书之后图书状态----------" << endl;
    b1.showInfo();

    cout << "----------继续借书，达到借书上限测试----------" << endl;
    stu.borrowBook(b1);
    stu.borrowBook(b3);
    stu.borrowBook(b1);
    cout << endl;

    return 0;
}
