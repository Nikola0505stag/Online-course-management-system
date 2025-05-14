#pragma once
#include "MyVector.hpp"
#include "User.h"

class Student : public User
{
	MyVector<double> grades;

public:

	Student();
	Student(const char* firstName, const char* lastName, const char* email, const char* password);

	void addGrade(double grade);
	size_t getGradesSize() const;
	size_t getGradesCapacity() const;


	friend std::istream& operator>>(std::istream& is, Student& student);
	friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

