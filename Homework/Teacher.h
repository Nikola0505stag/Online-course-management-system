#pragma once
#include "User.h"

class Teacher : public User
{

public:
	Teacher();
	Teacher(const char* firstName, const char* lastName, const char* email, const char* password);

	friend std::istream& operator>>(std::istream& is, Teacher& teacher);
	friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);

};


