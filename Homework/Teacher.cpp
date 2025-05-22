
#include "Teacher.h"

Teacher::Teacher() : User()
{}

Teacher::Teacher(const char* firstName, const char* lastName, const char* email, const char* password) :User(firstName, lastName,
    email, password)
{}

std::istream& operator>>(std::istream& is, Teacher& teacher)
{
    char buff[1024];

    is >> buff;
    teacher.setFirstName(buff);

    is >> buff;
    teacher.setLastName(buff);

    is >> buff;
    teacher.setEmail(buff);

    is >> buff;
    teacher.setPassword(buff);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacher)
{
    os << "---------------------------------------------------\n";
    os << "ID: " << teacher.getID() << "\n";
    os << "FIRST NAME: " << teacher.getFirstName() << "\n";
    os << "LAST NAME: " << teacher.getLastName() << "\n";
    os << "EMAIL: " << teacher.getEmail() << "\n";
    os << "PASSWORD: " << teacher.getPassword() << "\n";
    os << "---------------------------------------------------\n";
    return os;
}
