
#include "Message.h"

Message::Message()
{
	User us("DEFAULT_FIRST_NAME", "DEFAULT_LAST_NAME", "DEFAULT_EMAIL", "DEFAULT_PASSWORD");

	setSender(us);

	setContent("DEFAULT_CONTENT");

	timestamp = std::time(nullptr);
}

Message::Message(const User& sender, const MyString& content)
{
	setSender(sender);
	setContent(content);


	timestamp = std::time(nullptr);
}

void Message::setSender(const User& sender)
{
	this->sender.setFirstName(sender.getFirstName());
	this->sender.setLastName(sender.getLastName());
	this->sender.setEmail(sender.getEmail());
	this->sender.setPassword(sender.getPassword());
}

void Message::setContent(const MyString& content)
{
	this->content = content;
}

User Message::getSender() const
{
	return sender;
}

MyString Message::getContent() const
{
	return content;
}

std::time_t Message::getTimestamp() const
{
	return timestamp;
}

void Message::writeInBinary(std::ofstream& ofs) const
{
	sender.writeInBinary(ofs);

	size_t len = content.getSize() + 1;

	ofs.write((const char*)&len, sizeof(len));

	ofs.write(content.c_str(), len);

	ofs.write((const char*)&timestamp, sizeof(timestamp));
}

void Message::readFromBinary(std::ifstream& ifs)
{
	sender.readFromBinary(ifs);

	size_t len = 0;

	ifs.read((char*)&len, sizeof(len));

	char* buffer = new char[len];

	ifs.read(buffer, len);

	content = buffer;

	delete[] buffer;

	ifs.read((char*)&timestamp, sizeof(timestamp));
}

std::ostream& operator<<(std::ostream& os, const Message& message)
{
	os << "-------------------------------------------\n";
	os << "-------------------------------------------\n";
	os << "MESSAGE: \n";
	os << "-------------------------------------------\n";
	os << "-------------------------------------------\n";
	os << "SENDER: \n";
	os << "-------------------------------------------\n";
	os << "First Name: " << message.sender.getFirstName() << "\n";
	os << "Last Name: " << message.sender.getLastName() << "\n";
	os << "Email: " << message.sender.getEmail() << "\n";
	os << "Password:" << message.sender.getPassword() << "\n";
	os << "-------------------------------------------\n";
	os << "CONTENT: \n";
	os << "-------------------------------------------\n";
	os << message.content << "\n";
	os << "-------------------------------------------\n";
	os << "TIME: \n";
	os << "-------------------------------------------\n";
	os << std::ctime(&message.timestamp);
	os << "-------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Message& message)
{
	char buff[1024];

	is >> buff; message.sender.setFirstName(buff);
	is >> buff; message.sender.setLastName(buff);
	is >> buff; message.sender.setEmail(buff);
	is >> buff; message.sender.setPassword(buff);

	is.ignore();
	is.getline(buff, 1024);

	message.setContent(buff);

	message.timestamp = std::time(nullptr);

	return is;
}
