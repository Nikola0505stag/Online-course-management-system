#pragma once
#include "User.h"
#include "Answer.h"
#include "Teacher.h"
#include "MyString.h"

class Task
{
	Teacher teacher;
	MyString description;
	MyVector<Answer> answers;

public:
	Task();
	Task(Teacher teacher, MyString description);
	Task(const char* firstName, const char* lastName, const char* email, const char* password,
		MyString description);

	void setTeacher(Teacher teacher);
	void setTeacher(const char* firstName, const char* lastName, const char* email,
		const char* password);
	void setDescription(MyString description);

	const Teacher getTeacher() const;
	const MyString getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const Task& task);

	void addAnswer(Answer answer);

	void writeInBinary(std::ofstream& ofs) const;
	void readFromBinary(std::ifstream& ifs);

};

