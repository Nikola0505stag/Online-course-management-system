
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

void Student::writeInFile(std::ofstream& ofs) const
{
    //std::cout << "in1";
    User::writeInBinary(ofs);

    //std::cout << "in2";
    size_t gradesCount = grades.getSize();
    //std::cout << gradesCount;
    ofs.write((const char*)&gradesCount, sizeof(gradesCount));
    for (size_t i = 0; i < gradesCount; i++) {
        grades[i].writeInBinary(ofs);
    }
}

void Student::readFromFile(std::ifstream& ifs)
{
    User::readFromBinary(ifs);

    size_t gradesCount;
    ifs.read((char*)&gradesCount, sizeof(gradesCount));

    grades.clear(); // ако има стара информация
    for (size_t i = 0; i < gradesCount; ++i) {
        Grade g;
        g.readFromBinary(ifs);
        grades.push_back(g);
    }
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
