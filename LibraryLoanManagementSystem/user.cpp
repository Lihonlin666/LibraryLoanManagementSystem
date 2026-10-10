#include "user.h"

// 使用 std::string 并实现与 user.h 中声明匹配的成员
User::User(std::string name, std::string department, int maxborrow, int ID)
{
    this->name = std::move(name);
    this->department = std::move(department);
    this->maxborrow = maxborrow;
    this->ID = ID;
}

// 三参数构造，ID 设为 0
User::User(std::string name, std::string department, int maxborrow)
{
    this->name = std::move(name);
    this->department = std::move(department);
    this->maxborrow = maxborrow;
    this->ID = 0;
}

std::string User::getName() const { return name; }
std::string User::getDepartment() const { return department; }
int User::getMaxBorrow() const { return maxborrow; }
int User::getID() const { return ID; }

void User::setName(std::string newName) { name = std::move(newName); }
void User::setDepartment(std::string newDep) { department = std::move(newDep); }
void User::setMaxBorrow(int num) { maxborrow = num; }
void User::setID(int id) { ID = id; }
