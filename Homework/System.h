#pragma once
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"

class System
{

	Administrator admin;
	MyVector<Student> students;
	MyVector<Teacher> teachers;

	bool isAdmin = false;
	bool isTeacher = false;
	bool isStudent = false;


public:
	System();

	void print() const;

};

