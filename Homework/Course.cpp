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

void Course::addTask(Task task)
{
	tasks.push_back(task);
}

void Course::writeInBinary(std::ofstream& ofs) const
{
	teacher.writeInBinary(ofs);

	size_t len = description.getSize() + 1;

	ofs.write((const char*)&len, sizeof(len));
	ofs.write(description.c_str(), len);

	size_t size = tasks.getSize();
	ofs.write((const char*)&size, sizeof(size));

	for (int i = 0; i < tasks.getSize(); i++) {
		tasks[i].writeInBinary(ofs);
	}

	size = students.getSize();
	ofs.write((const char*)&size, sizeof(size));
	for (int i = 0; i < size; i++) {
		students[i].writeInBinary(ofs);
	}
}

void Course::readFromBinary(std::ifstream& ifs)
{
	teacher.readFromBinary(ifs);
	size_t len;
	ifs.read((char*)&len, sizeof(len));

	char* buff = new char[len];
	ifs.read(buff, len);
	description = buff;


	delete[] buff;

	size_t size;
	ifs.read((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		Task task;
		task.readFromBinary(ifs);
		tasks.push_back(task);
	}

	ifs.read((char*)&size, sizeof(size));
	for (int i = 0; i < size; i++) {
		Student student;
		student.readFromBinary(ifs);
		students.push_back(student);
	}
}

void Course::addStudent(Student student)
{
	students.push_back(student);
}

std::ostream& operator<<(std::ostream& os, const Course& course)
{
	os << "---------------------------------------------------\n";
	os << "TEACHER: \n";
	os << "---------------------------------------------------\n";
	os << course.teacher;
	os << "---------------------------------------------------\n";
	os << "DESCRIPTION: \n";
	os << "---------------------------------------------------\n";
	os << course.description << "\n";
	os << "---------------------------------------------------\n";
	os << "TASKS: \n";
	os << "---------------------------------------------------\n";
	for (int i = 0; i < course.tasks.getSize(); i++) {
		os << course.tasks[i];
	}
	os << "---------------------------------------------------\n";
	os << "STUDENTS: \n";
	os << "---------------------------------------------------\n";
	for (int i = 0; i < course.students.getSize(); i++) {
		os << course.students[i];
	}
	os << "---------------------------------------------------\n";
	return os;
}
