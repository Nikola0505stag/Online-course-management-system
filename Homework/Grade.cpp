#include "Grade.h"

Grade::Grade(MyString course, MyString task, double grade, MyString description)
{
	setCourse(course);
	setTask(task);
	setGrade(grade);
	setDescription(description);
}

Grade::Grade()
{
	setCourse("DEFAULT_COURSE");
	setTask("DEFAULT_TASK");
	this->grade = 0.0;
	setDescription("DEFAULT_DESCRIPTION");
}

const MyString& Grade::getCourse() const
{
	return course;
}

const MyString& Grade::getTask() const
{
	return task;
}

const MyString& Grade::getDescription() const
{
	return description;
}

double Grade::getGrade() const
{
	return grade;
}

void Grade::setCourse(const MyString& course)
{
	this->course = course;
}

void Grade::setTask(const MyString& task)
{
	this->task = task;
}

void Grade::setDescription(const MyString& description)
{
	this->description = description;
}

void Grade::setGrade(double grade)
{
	if (grade < 2)
		throw std::invalid_argument("Тhe grade must be at leat 2...");
	if (grade > 6)
		throw std::invalid_argument("The grade must be at most 6...");

	this->grade = grade;
}

std::istream& operator>>(std::istream& is, Grade& grade)
{
	char buff[1024];

	is.getline(buff, 1024);
	grade.setCourse(buff);

	is.getline(buff, 1024);
	grade.setTask(buff);

	is >> grade.grade;

	is.ignore();

	is.getline(buff, 1024);
	grade.setDescription(buff);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Grade& grade)
{
	os << grade.course << "  |  " << grade.task << "  |  " << grade.grade << "  |  " <<
		grade.description;

	return os;
}
