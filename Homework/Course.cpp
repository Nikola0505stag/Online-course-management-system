#include "Course.h"

Course::Course()
{
	setTeacher("DEFAULT_FIRST_NAME", "DEFAULT_LAST_NAME", "DEFAULT_EMAIL", "DEFAULT_PASSWORD");
	setDescription("DEFAULT_DESCRIPTION");
}

Course::Course(Teacher teacher, MyString description)
{
	setTeacher(teacher);
	setDescription(description);
}

Course::Course(const char* firstName, const char* lastName, const char* email, 
	const char* password, MyString description)
{
	setTeacher(firstName, lastName, email, password);
	setDescription(description);
}

void Course::setTeacher(Teacher teacher)
{
	this->teacher = teacher;
}

void Course::setTeacher(const char* firstName, const char* lastName, const char* email, 
	const char* password)
{
	teacher.setFirstName(firstName);
	teacher.setLastName(lastName);
	teacher.setEmail(email);
	teacher.setPassword(password);
}

void Course::setDescription(MyString description)
{
	this->description = description;
}

Teacher Course::getTeacher() const
{
	return teacher;
}

MyString Course::getDescription() const
{
	return description;
}
