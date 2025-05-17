#pragma once
#include "User.h"
#include "MyString.h"
class Answer
{
	User user;
	MyString answer;

public:
	Answer();
	Answer(User user, MyString answer);
	Answer(const char* firstName, const char* lastName, const char* email,
		const char* password, MyString answer);

	const User getUser() const;
	const MyString getAnswer() const;
	
	void setUser(User user);
	void setUser(const char* firstName, const char* lastName, const char* email,
		const char* password);
	void setAnswer(MyString answer);


	friend std::ostream& operator<< (std::ostream& os, const Answer& answer);
	//friend std::istream& operator>> (std::istream& is, Answer& answer);

	void writeInBinary(std::ofstream& ofs);
	void readFromBinary(std::ifstream& ifs);
};

