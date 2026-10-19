#include <iostream>
#include <limits>
#include "Library.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
    Library lib;
    //初始图书
    lib.addNewBook(new Book("C++ Primer", "B001", "978xxxx", "Lippman", "人民邮电出版社"));
    lib.addNewBook(new Book("数据结构", "B002", "978yyyy", "严蔚敏", "清华大学出版社"));
    lib.addNewBook(new Book("操作系统", "B003", "978zzzz", "汤子瀛", "西安电子科大出版社"));

    //初始用户
    lib.addUser(new Student("2026001", "张三"));
    lib.addUser(new Student("2026002", "李四"));
    lib.addUser(new Teacher("T001", "王教授"));

    int choice;
    string uid, bar, date, recid, retDate;
    string bkName, bkBar, bkIsbn, bkAuth, bkPub;
    string newId, newName;
    int userType;
    double fine;
    while (true)
    {
        cout << "\n=====图书馆借阅管理系统菜单=====\n";
        cout << "1.显示全部图书\n";
        cout << "2.显示全部用户(学生+教师)\n";
        cout << "3.用户借书\n";
        cout << "4.用户还书\n";
        cout << "5.查看用户当前借阅\n";
        cout << "6.查看用户全部借阅记录\n";
        cout << "7.新增图书\n";
        cout << "8.删除图书(按条码)\n";
        cout << "9.新增用户(学生/教师)\n";
        cout << "0.退出\n";
        cout << "请输入选项：";
        if (!(cin >> choice)) {
            cout << "输入无效，请输入数字选项。" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice == 0) break;
        switch (choice)
        {
        case 1:
            lib.showAllBooks();
            break;
        case 2:
            lib.showAllUsers();
            break;
        case 3:
        {
            cout << "输入用户ID：";
            cin >> uid;
            cout << "输入图书条码：";
            cin >> bar;
            cout << "输入借书日期：";
            cin >> date;
            cout << "输入本次记录编号：";
            cin >> recid;
            User* usr = lib.findUserById(uid);
            Book* bk = lib.findBookByBarcode(bar);
            if (!usr || !bk) {
                cout << "用户或者图书不存在！" << endl;
                break;
            }
            usr->borrowBook(bk, date, recid);
            break;
        }
        case 4:
        {
            cout << "输入用户ID：";
            cin >> uid;
            cout << "输入图书条码：";
            cin >> bar;
            cout << "输入还书日期：";
            cin >> retDate;
            cout << "输入罚金：";
            cin >> fine;
            User* usr = lib.findUserById(uid);
            Book* bk = lib.findBookByBarcode(bar);
            if (!usr || !bk) {
                cout << "用户或者图书不存在！" << endl;
                break;
            }
            usr->returnBook(bk, retDate, fine);
            break;
        }
        case 5:
        {
            cout << "输入用户ID：";
            cin >> uid;
            User* usr = lib.findUserById(uid);
            if (!usr) { cout << "用户不存在\n"; break; }
            usr->showBorrowed();
            break;
        }
        case 6:
        {
            cout << "输入用户ID：";
            cin >> uid;
            User* usr = lib.findUserById(uid);
            if (!usr) { cout << "用户不存在\n"; break; }
            usr->showAllRecord();
            break;
        }
        case 7:
        {
            cout << "请输入书名：";
            cin >> bkName;
            cout << "请输入条码：";
            cin >> bkBar;
            cout << "请输入ISBN：";
            cin >> bkIsbn;
            cout << "请输入作者：";
            cin >> bkAuth;
            cout << "请输入出版社：";
            cin >> bkPub;
            lib.addNewBook(new Book(bkName, bkBar, bkIsbn, bkAuth, bkPub));
            cout << "[新增图书成功]" << endl;
            break;
        }
        case 8:
        {
            cout << "输入待删除图书条码：";
            cin >> bar;
            lib.deleteBook(bar);
            break;
        }
        case 9:
        {
            cout << "请选择用户类型：1=学生，2=教师\n";
            cin >> userType;
            cout << "输入用户ID：";
            cin >> newId;
            cout << "输入用户姓名：";
            cin >> newName;
            if (userType == 1)
            {
                lib.addUser(new Student(newId, newName));
                cout << "[新增学生用户成功]" << endl;
            }
            else if (userType == 2)
            {
                lib.addUser(new Teacher(newId, newName));
                cout << "[新增教师用户成功]" << endl;
            }
            else
            {
                cout << "类型输入错误！" << endl;
            }
            break;
        }
        default:
            cout << "无效选项\n";
        }
    }
    cout << "系统结束\n";
    return 0;
}
