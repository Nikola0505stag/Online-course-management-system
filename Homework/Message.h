#pragma once
#include <iostream>
#include <ctime>
#include "MyString.h"
#include "User.h"
#include <fstream>

class Message
{
	User sender;
	MyString content;
	std::time_t timestamp;

public:
	Message();
	Message(const User& sender, const MyString& content);

	friend std::ostream& operator<<(std::ostream& os, const Message& message);
	friend std::istream& operator>>(std::istream& is, Message& message);

	void setSender(const User& sender);
	void setContent(const MyString& content);

	User getSender() const;
	MyString getContent() const;
	std::time_t getTimestamp() const;

	void writeInBinary(std::ofstream& ofs) const;
	void readFromBinary(std::ifstream& ifs);

};

