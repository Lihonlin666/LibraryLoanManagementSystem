#include "user.h"
User::User (string name, string department, int maxborrow)
{
	this->name = name;
	this->department = department;
	this->maxborrow = maxborrow;
}

string User::getName() const
{
	return name;
}

string User::getDepartment() const
{
	return department;
}

int User::getMaxBorrow() const
{
	return maxborrow;
}

void User::setName(string name)
{
	this->name = name;
}

void User::setDepartment(string department)
{
	this->department = department;
}

void User::setMaxBorrow(int maxborrow)
{
	this->maxborrow = maxborrow;
}
