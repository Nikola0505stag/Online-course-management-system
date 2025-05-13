#include "User.h"

int User::counter = 100;

void User::setFirstName(const char* firstName)
{
	if (!firstName)
		throw std::invalid_argument("First Name is nullptr...");
	if (this->firstName == firstName)
		return;

	delete[] this->firstName;
	this->firstName = new char[strlen(firstName) + 1];
	strcpy(this->firstName, firstName);
}

void User::setLastName(const char* lastName)
{
	if (!lastName)
		throw std::invalid_argument("Last Name is nullptr...");
	if (this->lastName == lastName)
		return;

	delete[] this->lastName;
	this->lastName = new char[strlen(lastName) + 1];
	strcpy(this->lastName, lastName);
}

void User::setEmail(const char* email)
{
	if (!email)
		throw std::invalid_argument("Email is nullptr...");
	if (this->email == email)
		return;

	delete[] this->email;
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}

void User::setPassword(const char* password)
{
	if (!password)
		throw std::invalid_argument("Password is nullptr...");
	if (this->password == password)
		return;

	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

const char* User::getFirstName() const
{
	return firstName;
}

const char* User::getLastName() const
{
	return lastName;
}

const char* User::getEmail() const
{
	return email;
}

const char* User::getPassword() const
{
	return password;
}

int User::getID() const
{
	return ID;
}
