#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

class User {
	char* firstName;
	char* lastName;
	char* email;
	char* password;
	static int counter;
	int ID;


	void free();
	void copyFrom(const User& other);
	void moveFrom(User&& other);

protected: void setPassword();
protected: void setID();

public:
	User();
	User(const char* firstName, const char* lastName, const char* email, const char* password);
	User(const User& other);
	User(User&& other) noexcept;
	User& operator=(const User& other);
	User& operator=(User&& other) noexcept;
	virtual ~User();

	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);
	void setEmail(const char* email);
	void setPassword(const char* password);

	const char* getFirstName() const;
	const char* getLastName() const;
	const char* getEmail() const;
	const char* getPassword() const;
	int getID() const;

	friend std::ostream& operator<<(std::ostream& os, const User& user);
};