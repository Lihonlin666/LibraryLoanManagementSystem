#pragma once
#include<string>
using namespace std;

class User
{
protected:
	string name;
	string department;
	int maxborrow;
public:
	User(string name, string department, int maxborrow);
	string getName() const;
	string getDepartment() const;
	int getMaxBorrow() const;
	void setName(string name);
	void setDepartment(string department);
	void setMaxBorrow(int maxborrow);
};

