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

void Grade::writeInBinary(std::ofstream& ofs) const
{
	size_t len;
	len = course.getSize() + 1;
	ofs.write((const char*)&len, sizeof(len));
	ofs.write(course.c_str(), len);

	len = task.getSize() + 1;
	ofs.write((const char*)&len, sizeof(len));
	ofs.write(task.c_str(), len);

	len = description.getSize() + 1;
	ofs.write((const char*)&len, sizeof(len));
	ofs.write(description.c_str(), len);
	
	ofs.write((const char*)&grade, sizeof(grade));

}

void Grade::readFromBinary(std::ifstream& ifs)
{
	size_t len;
	char* buff;

	ifs.read((char*)&len, sizeof(len));
	buff = new char[len];
	ifs.read(buff, len);
	course = buff;
	delete[] buff;

	ifs.read((char*)&len, sizeof(len));
	buff = new char[len];
	ifs.read(buff, len);
	task = buff;
	delete[] buff;

	ifs.read((char*)&len, sizeof(len));
	buff = new char[len];
	ifs.read(buff, len);
	description = buff;
	delete[] buff;

	ifs.read((char*)&grade, sizeof(grade));
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
