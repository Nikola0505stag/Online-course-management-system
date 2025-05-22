
#include "Student.h"

Student::Student() : User()
{}

Student::Student(const char* firstName, const char* lastName, const char* email, const char* password) : User(firstName, lastName,
    email, password)
{}


void Student::addGrade(Grade grade)
{
    grades.push_back(grade);
}

size_t Student::getGradesSize() const
{
    return grades.getSize();
}

size_t Student::getGradesCapacity() const
{
    return grades.getCapacity();
}

std::istream& operator>>(std::istream& is, Student& student)
{
    char buff[1024];

    is >> buff;
    student.setFirstName(buff);

    is >> buff;
    student.setLastName(buff);

    is >> buff;
    student.setEmail(buff);

    is >> buff;
    student.setPassword(buff);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "---------------------------------------------------\n";
    os << "ID: " << student.getID() << "\n";
    os << "FIRST NAME: " << student.getFirstName() << "\n";
    os << "LAST NAME: " << student.getLastName() << "\n";
    os << "EMAIL: " << student.getEmail() << "\n";
    os << "PASSWORD: " << student.getPassword() << "\n";
    os << "GRADES: ";
    for (int i = 0; i < student.getGradesSize(); i++) {
        os << student.grades[i] << "\n";
    }
    os << std::endl;
    os << "---------------------------------------------------\n";

    return os;
}
