#pragma once

#include <string>

class User
{
protected:
    std::string name;
    std::string department;
    int maxborrow;
    int ID;
public:
    User(std::string name, std::string department, int maxborrow, int ID);
    User(std::string name, std::string department, int maxborrow); // overload for existing code
    virtual ~User() = default; // 使 User 成为多态基类，允许 dynamic_cast

    std::string getName() const;
    std::string getDepartment() const;
    int getMaxBorrow() const;
    int getID() const;

    void setName(std::string newName);
    void setDepartment(std::string newDep);
    void setMaxBorrow(int num);
    void setID(int id);
};

