#include "Teacher.h"

Teacher::Teacher(string teaId, string name, string department, int maxBorrow)
    : User(name, department, maxBorrow)
{
    this->teaId = teaId;
}

string Teacher::getTeaId() const
{
    return teaId;
}

void Teacher::setTeaId(string newId)
{
    teaId = newId;
}
