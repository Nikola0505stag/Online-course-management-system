
#pragma once
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "MyString.h"
#include "Message.h"
#include <iostream>
#include "Course.h"

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

	void fileToVector(MyVector<MyString>& vec) const;
	void vectorToFile(const MyVector<MyString>& vec) const;

	//size_t messageCount = 0;

	MyVector<Message> messages;
	MyVector<Course> courses;

	void makeMessages();
	void makeCourses();

	void convertData(char* firstName, char* lastName, char* email, char* password) const;

	size_t getCourseIndex(MyString curr);

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

	void changePassword();

	void sendMessage();
	void viewMessage() const;
	void deleteMessage();

	void addCourse();
	void addStudentInCourse();
	void addTaskInCourse();
	void addAnswer();
	void addGrade();

	void sendMessageInCourse();


	void viewGrades();

	void printCourses();
};
