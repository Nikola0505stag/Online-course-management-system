#pragma once
#include "MyString.h"
class Grade
{
	MyString course;
	MyString task;
	MyString description;
	double grade;

public:
	Grade(MyString course, MyString task, double grade, MyString description);
	Grade();
	
	friend std::istream& operator>>(std::istream& is, Grade& grade);
	friend std::ostream& operator<<(std::ostream& os, const Grade& grade);

	const MyString& getCourse() const;
	const MyString& getTask() const;
	const MyString& getDescription() const;
	double getGrade() const;

	void setCourse(const MyString& course);
	void setTask(const MyString& task);
	void setDescription(const MyString& description);
	void setGrade(double grade);
};

