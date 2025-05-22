
#pragma once
#include "MyVector.hpp"
#include "User.h"
#include "Grade.h"

class Student : public User
{
	MyVector<Grade> grades;

public:

	Student();
	Student(const char* firstName, const char* lastName, const char* email, const char* password);

	void addGrade(Grade grade);
	size_t getGradesSize() const;
	size_t getGradesCapacity() const;

	

	friend std::istream& operator>>(std::istream& is, Student& student);
	friend std::ostream& operator<<(std::ostream& os, const Student& student);
};
