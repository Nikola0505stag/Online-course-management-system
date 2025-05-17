#include "Answer.h"

Answer::Answer()
{
	setStudent("DEFAULT_FIRST_NAME", "DEFAULT_LAST_NAME",
		"DEFAULT_EMAIL", "DEFAULT_PASSWORD");
	setAnswer("DEFAULT_ANSWER");
}

Answer::Answer(Student user, MyString answer)
{
	setStudent(user);
	setAnswer(answer);
}

Answer::Answer(const char* firstName, const char* lastName, const char* email, const char* password, MyString answer)
{
	setStudent(firstName, lastName, email, password);
	setAnswer(answer);
}

const Student Answer::getStudent() const
{
	return user;
}

const MyString Answer::getAnswer() const
{
	return answer;
}

void Answer::setStudent(Student user)
{
	this->user = std::move(user);
}

void Answer::setStudent(const char* firstName, const char* lastName, const char* email, const char* password)
{
	Student curr(firstName, lastName, email, password);

	this->user = std::move(curr);
}

void Answer::setAnswer(MyString answer)
{
	this->answer = answer;
}

void Answer::writeInBinary(std::ofstream& ofs)
{
	user.writeInBinary(ofs);

	size_t len = answer.getSize() + 1;

	ofs.write((const char*)&len, sizeof(len));
	ofs.write(answer.c_str(), len);
}

void Answer::readFromBinary(std::ifstream& ifs)
{
	user.readFromBinary(ifs);

	size_t len;
	ifs.read((char*)&len, sizeof(len));

	char* buffer = new char[len];
	ifs.read(buffer, len);
	answer = buffer;

	delete[] buffer;
}



std::ostream& operator<<(std::ostream& os, const Answer& answer)
{
	os << "---------------------------------------------------\n";
	os << "USER: \n";
	os << "---------------------------------------------------\n";
	os << answer.user;
	os << "---------------------------------------------------\n";
	os << "ANSWER: \n";
	os << "---------------------------------------------------\n";
	os << answer.answer << "\n";
	os << "---------------------------------------------------\n";

	return os;
}


