#include <iostream>
#include <cstdlib>          
#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include "NormalBook.h"
#include "Magazine.h"
#include "EBook.h"

int main()
{
    system("chcp 65001 > nul");  

    Library lib;
    lib.addNewBook(new NormalBook("C++ Primer", "B001", "978xxxx", "Lippman", "人民邮电出版社"));
    lib.addNewBook(new Magazine("计算机学报", "M001", "978m1", "编辑部", "科学出版社", "2026-05"));
    lib.addNewBook(new EBook("C++在线文档", "E001", "978e1", "C++标准委员会", "开放出版社", "https://cppreference.com"));

    lib.addUser(new Student("2026001", "张三"));
    lib.addUser(new Student("2026002", "李四"));
    lib.addUser(new Teacher("T001", "王教授"));

    int choice;
    string uid, bar, date, recid, retDate, name;
    int typeSel;
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
        cin >> choice;
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
            cout << "输入用户ID："; cin >> uid;
            cout << "输入图书条码："; cin >> bar;
            cout << "输入借书日期："; cin >> date;
            cout << "输入记录编号："; cin >> recid;
            User* u = lib.findUserById(uid);
            Book* b = lib.findBookByBarcode(bar);
            if (!u || !b) { cout << "用户或者图书不存在！\n"; break; }
            u->borrowBook(b, date, recid);
            break;
        }
        case 4:
        {
            cout << "输入用户ID："; cin >> uid;
            cout << "输入图书条码："; cin >> bar;
            cout << "输入还书日期："; cin >> retDate;
            cout << "输入罚金："; cin >> fine;
            User* u = lib.findUserById(uid);
            Book* b = lib.findBookByBarcode(bar);
            if (!u || !b) { cout << "用户或者图书不存在！\n"; break; }
            u->returnBook(b, retDate, fine);
            break;
        }
        case 5:
        {
            cout << "输入用户ID："; cin >> uid;
            User* u = lib.findUserById(uid);
            if (!u) { cout << "用户不存在\n"; break; }
            u->showBorrowed();
            break;
        }
        case 6:
        {
            cout << "输入用户ID："; cin >> uid;
            User* u = lib.findUserById(uid);
            if (!u) { cout << "用户不存在\n"; break; }
            u->showAllRecord();
            break;
        }
        case 7:
        {
            int subType;
            string n, b, isbn, aut, pub, extra;
            cout << "选择类型：1=一般图书 2=杂志 3=电子资源：";
            cin >> subType;
            cout << "名称："; cin >> n;
            cout << "条码："; cin >> b;
            cout << "ISBN："; cin >> isbn;
            cout << "作者："; cin >> aut;
            cout << "出版社："; cin >> pub;
            if (subType == 1)
            {
                lib.addNewBook(new NormalBook(n, b, isbn, aut, pub));
                cout << "[新增一般图书成功]\n";
            }
            else if (subType == 2)
            {
                cout << "输入期号："; cin >> extra;
                lib.addNewBook(new Magazine(n, b, isbn, aut, pub, extra));
                cout << "[新增杂志成功]\n";
            }
            else if (subType == 3)
            {
                cout << "输入访问链接："; cin >> extra;
                lib.addNewBook(new EBook(n, b, isbn, aut, pub, extra));
                cout << "[新增电子资源成功]\n";
            }
            break;
        }
        case 8:
        {
            cout << "输入待删除图书条码："; cin >> bar;
            lib.deleteBook(bar);
            break;
        }
        case 9:
        {
            cout << "选择用户类型：1=学生，2=教师："; cin >> typeSel;
            cout << "用户ID："; cin >> uid;
            cout << "用户姓名："; cin >> name;
            if (typeSel == 1)
            {
                lib.addUser(new Student(uid, name));
                cout << "[新增学生用户成功]\n";
            }
            else if (typeSel == 2)
            {
                lib.addUser(new Teacher(uid, name));
                cout << "[新增教师用户成功]\n";
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
