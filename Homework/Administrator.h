#pragma once
#include "User.h"

class Administrator: public User
{

public:
	Administrator();
	Administrator(const char* firstName, const char* lastName, const char* email);

	friend std::istream& operator>>(std::istream& is, Administrator& admin);
	friend std::ostream& operator<<(std::ostream& os, const Administrator& admin);

};

