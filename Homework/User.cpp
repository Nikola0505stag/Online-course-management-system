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
	if (strcmp(password, "0000") == 0)
		throw std::invalid_argument("Password can't be 0000...");

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

void User::free()
{
	delete[] firstName;
	delete[] lastName;
	delete[] email;
	delete[] password;
	
	firstName = nullptr;
	lastName = nullptr;
	email = nullptr;
	password = nullptr;
}

void User::copyFrom(const User& other)
{
	firstName = new char[strlen(other.firstName) + 1];
	lastName = new char[strlen(other.lastName) + 1];
	email = new char[strlen(other.email) + 1];
	password = new char[strlen(other.password) + 1];

	strcpy(firstName, other.firstName);
	strcpy(lastName, other.lastName);
	strcpy(email, other.email);
	strcpy(password, other.password);

}

void User::moveFrom(User&& other)
{
	firstName = other.firstName;
	lastName = other.lastName;
	email = other.email;
	password = other.password;

	other.firstName = nullptr;
	other.lastName = nullptr;
	other.email = nullptr;
	other.password = nullptr;
}

void User::setPassword()
{
	password = new char[strlen("0000") + 1];
	strcpy(password, "0000");
}

void User::setID()
{
	ID = 0;
}

User::User()
{
	setFirstName("DEFAULT_FIRST_NAME");
	setLastName("DEFAULT_LAST_NAME");
	setEmail("DEFAULT_EMAIL");
	setPassword("DEFAULT_PASSWORD");
	ID = counter++;
}

User::User(const char* firstName, const char* lastName, const char* email, const char* password)
{
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setPassword(password);
	ID = counter++;
}

User::User(const User& other)
{
	copyFrom(other);
	ID = counter++;
}

User::User(User&& other) noexcept
{
	moveFrom(std::move(other));
	ID = counter++;
}

User& User::operator=(const User& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

User& User::operator=(User&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

User::~User()
{
	free();
	ID = -1;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << "---------------------------------------------------\n";
	os << "ID: " << user.ID << "\n";
	os << "FIRST NAME: " << user.firstName << "\n";
	os << "LAST NAME: " << user.lastName << "\n";
	os << "EMAIL: " << user.email << "\n";
	os << "PASSWORD: " << user.password << "\n";
	os << "---------------------------------------------------\n";
	return os;
}
