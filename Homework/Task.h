#pragma once
#include "User.h"
#include "Answer.h"
#include "Teacher.h"
#include "MyString.h"

class Task
{
	MyString description;
	MyVector<Answer> answers;

public:
	Task();
	Task(MyString description);
;
	void setDescription(MyString description);

	const MyString getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const Task& task);

	void addAnswer(Answer answer);

	void writeInBinary(std::ofstream& ofs) const;
	void readFromBinary(std::ifstream& ifs);

};

