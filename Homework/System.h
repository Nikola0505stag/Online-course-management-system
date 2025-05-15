#pragma once
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "MyString.h"

class System
{

	Administrator admin;
	MyVector<Student> students;
	MyVector<Teacher> teachers;

	size_t ID;
	MyString firstName;
	MyString lastName;
	MyString email;
	MyString password;

	bool adminFound = false;

	bool isAdmin = false;
	bool isTeacher = false;
	bool isStudent = false;


public:
	System();

	void print() const;


	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getEmail() const;
	const MyString& getPassword() const;
	size_t getID() const;

	void logIn();

	friend std::ostream& operator<<(std::ostream& os, const System& system);

	void addStudent();
	void addTeacher();

	void removeStudent();
	void removeTeacher();

};

