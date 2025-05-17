#pragma once
#include "User.h"
#include "MyString.h"
#include "Student.h"

class Answer
{
	Student user;
	MyString answer;

public:
	Answer();
	Answer(Student user, MyString answer);
	Answer(const char* firstName, const char* lastName, const char* email,
		const char* password, MyString answer);

	const Student getStudent() const;
	const MyString getAnswer() const;
	
	void setStudent(Student user);
	void setStudent(const char* firstName, const char* lastName, const char* email,
		const char* password);
	void setAnswer(MyString answer);


	friend std::ostream& operator<< (std::ostream& os, const Answer& answer);
	//friend std::istream& operator>> (std::istream& is, Answer& answer);

	void writeInBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);
};

