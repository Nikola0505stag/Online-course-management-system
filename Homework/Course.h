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
	MyVector<Student> students;

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

	//void setPassword(MyString password);
	//MyString getPassword() const;

	friend std::ostream& operator<<(std::ostream& os, const Course& course);

	void addTask(Task task);

	void writeInBinary(std::ofstream& ofs) const;
	void readFromBinary(std::ifstream& ifs);

	void addStudent(Student student);

	Student& getStudents(int index);
	size_t getStudentsSize() const;

	size_t getTasksSize() const;
	Task& getTask(int index);
};
