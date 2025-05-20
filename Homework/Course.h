#pragma once
#include "MyString.h"
//#include "MyVector.hpp"
#include "Task.h"
#include <fstream>
#include "Teacher.h"

class Course
{

	Teacher teacher;
	MyString description;
	MyVector<Task> tasks;

public:
	Course();
	Course(Teacher teacher, MyString description);
	Course(const char* firstName, const char* lastName, const char* email, const char* password,
		MyString description);

	void setTeacher(Teacher teacher);
	void setTeacher(const char* firstName, const char* lastName, const char* email, const char*
		password);

	void setDescription(MyString description);

	Teacher getTeacher() const;
	
	MyString getDescription() const;


};

