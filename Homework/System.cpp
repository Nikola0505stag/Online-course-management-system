
#include "System.h"

// 1 - admin
// 2 - student
// 3 - teacher


void System::fileToVector(MyVector<MyString>& data) const
{
	std::ifstream ifs("Users.txt");

	MyString buff;

	while (!ifs.eof()) {
		ifs >> buff;
		data.push_back(buff);
	}

	ifs.close();
}

void System::vectorToFile(const MyVector<MyString>& data) const
{
	std::ofstream ofs("Users.txt");

	for (int i = 0; i < data.getSize(); i++) {
		ofs << data[i] << " ";
		if ((i + 1) % 5 == 0) ofs << std::endl;
	}

	ofs.close();
}

void System::makeMessages()
{
	MyString nameS;
	nameS = email + ".bin";

	char name[1024];
	strcpy(name, nameS.c_str());

	std::ifstream ifs(name, std::ios::binary);

	while (ifs.peek() != EOF) {
		Message msg;
		msg.readFromBinary(ifs);
		messages.push_back(msg);
	}

	//std::cout << messages.getSize();
}

void System::makeCourses()
{
	std::ifstream ifs("Courses.bin", std::ios::binary);

	while (ifs.peek() != EOF) {
		Course course;
		course.readFromBinary(ifs);
		courses.push_back(course);
	}
	ifs.close();
}

void System::convertData(char* firstName, char* lastName, char* email, char* password) const
{
	strcpy(firstName, this->firstName.c_str());
	strcpy(lastName, this->lastName.c_str());
	strcpy(email, this->email.c_str());
	strcpy(password, this->password.c_str());
}


System::System()
{
	std::ifstream ifs("Users.txt");

	int buffI;
	char firstName[1024];
	char lastName[1024];
	char email[1024];
	char password[1024];

	while (!ifs.eof()) {
		ifs >> buffI;
		ifs >> firstName;
		ifs >> lastName;
		ifs >> email;
		ifs >> password;

		//MyString curr = email + ".bin";

		std::string curr = email + (std::string)".bin";


		std::ofstream ofs(curr, std::ios::binary | std::ios::app);
		ofs.close();

		if (buffI == 1) {
			if (adminFound)
				throw std::invalid_argument("There is only one admin...");

			admin.setFirstName(firstName);
			admin.setLastName(lastName);
			admin.setEmail(email);
			adminFound = true;
		}
		else if (buffI == 2) {
			Student st(firstName, lastName, email, password);
			students.push_back(st);
		}
		else {
			Teacher th(firstName, lastName, email, password);
			teachers.push_back(th);
		}


	}
	ifs.close();

}

void System::print() const
{
	std::cout << "ADMIN: \n";
	std::cout << admin;
	std::cout << "\n\n";
	std::cout << "TEACHERS: \n";
	for (int i = 0; i < teachers.getSize(); i++) {
		std::cout << teachers[i];
	}
	std::cout << "\n\n";
	std::cout << "STUDENTS: \n";
	for (int i = 0; i < students.getSize(); i++) {
		std::cout << students[i];
	}
}

const MyString& System::getFirstName() const
{
	return firstName;
}

const MyString& System::getLastName() const
{
	return lastName;
}

const MyString& System::getEmail() const
{
	return email;
}

const MyString& System::getPassword() const
{
	return password;
}

size_t System::getID() const
{
	return ID;
}

void System::logIn()
{
	size_t ID;
	char password[1024];

	std::cout << "Insert ID: ";
	std::cin >> ID;
	std::cout << "\nInsert Password: ";
	std::cin >> password;

	makeCourses();

	//std::cout << admin.getID() << " " << admin.getPassword();

	if (ID == admin.getID() && strcmp(password, admin.getPassword()) == 0) {
		//std::cout << "in";
		isAdmin = true;
		std::cout << std::endl << "Welcome Admin " << admin.getFirstName() << " " << admin.getLastName() << std::endl;

		firstName = admin.getFirstName();
		lastName = admin.getLastName();
		email = admin.getEmail();
		this->password = admin.getPassword();
		this->ID = admin.getID();

		makeMessages();

		return;
	}

	for (int i = 0; i < students.getSize(); i++) {
		if (ID == students[i].getID() && strcmp(password, students[i].getPassword()) == 0) {
			isStudent = true;
			std::cout << std::endl << "Welcome Student " << students[i].getFirstName() << " " << students[i].getLastName() << std::endl;

			firstName = students[i].getFirstName();
			lastName = students[i].getLastName();
			email = students[i].getEmail();
			this->password = students[i].getPassword();
			this->ID = students[i].getID();

			makeMessages();

			return;
		}
	}

	for (int i = 0; i < teachers.getSize(); i++) {
		if (ID == teachers[i].getID() && strcmp(password, teachers[i].getPassword()) == 0) {
			isTeacher = true;
			std::cout << std::endl << "Welcome Teacher " << teachers[i].getFirstName() << " " << teachers[i].getLastName() << std::endl;

			firstName = teachers[i].getFirstName();
			lastName = teachers[i].getLastName();
			email = teachers[i].getEmail();
			this->password = teachers[i].getPassword();
			this->ID = teachers[i].getID();

			makeMessages();

			return;
		}
	}
	std::cout << "Not Found...\nTry again!";
	logIn();
}

void System::addStudent()
{
	if (!isAdmin) {
		std::cout << "\nYou do not have the authority to add a student.";
		return;
	}

	char firstName[1024], lastName[1024], email[1024], password[1024];

	std::cout << "\nInsert first name, last name, email and password";
	std::cin >> firstName >> lastName >> email >> password;

	Student stu(firstName, lastName, email, password);

	students.push_back(stu);

	std::ofstream ofs("Users.txt", std::ios::app);
	ofs << "\n";
	ofs << 2 << " " << firstName << " " << lastName << " " << email << " " << password;

	ofs.close();
}

void System::addTeacher()
{
	if (!isAdmin) {
		std::cout << "\nYou do not have the authority to add a teacher.";
		return;
	}

	char firstName[1024], lastName[1024], email[1024], password[1024];

	std::cout << "\nInsert first name, last name, email and password";
	std::cin >> firstName >> lastName >> email >> password;

	Teacher tea(firstName, lastName, email, password);

	teachers.push_back(tea);

	std::ofstream ofs("Users.txt", std::ios::app);
	ofs << "\n";
	ofs << 3 << " " << firstName << " " << lastName << " " << email << " " << password;

	ofs.close();
}

void System::removeStudent()
{
	if (!isAdmin) {
		std::cout << "\nYou do not have the authority to remove a student.";
		return;
	}

	std::cout << "Insert first name and last name: ";
	char firstName[1024], lastName[1024];

	std::cin >> firstName >> lastName;

	std::ifstream ifs("Users.txt");

	MyVector<MyString> data;

	fileToVector(data);

	int row = 0;

	for (int i = 0; i < data.getSize(); i++) {
		if (i % 5 == 0) {
			if (data[i] == "2") {
				row = i / 5;
				if (data[i + 1] == firstName && data[i + 2] == lastName) {
					data.erase(i + 4);
					data.erase(i + 3);
					data.erase(i + 2);
					data.erase(i + 1);
					data.erase(i);
				}
			}
		}
	}

	vectorToFile(data);

	for (int i = 0; i < students.getSize(); i++) {
		if ((strcmp(students[i].getFirstName(), firstName) == 0) &&
			(strcmp(students[i].getLastName(), lastName) == 0)) {
			students.erase(i);
		}
	}

	for (int i = 0; i < students.getSize(); i++) {
		std::cout << std::endl;
		std::cout << students[i];
	}
}

void System::removeTeacher()
{
	if (!isAdmin) {
		std::cout << "\nYou do not have the authority to remove a teacher.";
		return;
	}

	std::cout << "Insert first name and last name: ";
	char firstName[1024], lastName[1024];

	std::cin >> firstName >> lastName;

	std::ifstream ifs("Users.txt");

	MyVector<MyString> data;

	fileToVector(data);

	int row = 0;

	for (int i = 0; i < data.getSize(); i++) {
		if (i % 5 == 0) {
			if (data[i] == "3") {
				row = i / 5;
				if (data[i + 1] == firstName && data[i + 2] == lastName) {
					data.erase(i + 4);
					data.erase(i + 3);
					data.erase(i + 2);
					data.erase(i + 1);
					data.erase(i);
				}
			}
		}
	}

	vectorToFile(data);

	for (int i = 0; i < teachers.getSize(); i++) {
		if ((strcmp(teachers[i].getFirstName(), firstName) == 0) &&
			(strcmp(teachers[i].getLastName(), lastName) == 0)) {
			teachers.erase(i);
		}
	}

	for (int i = 0; i < teachers.getSize(); i++) {
		std::cout << std::endl;
		std::cout << teachers[i];
	}
}

void System::changePassword()
{
	if (isAdmin) return;

	MyString password;

	std::cout << "\n\nInsert new password:";
	std::cin >> password;

	this->password = password;


	MyVector<MyString> data;

	fileToVector(data);

	for (int i = 0; i < data.getSize(); i++) {
		if (i % 5 == 0) {
			if (data[i + 1] == this->firstName && data[i + 2] == this->lastName) {
				data[i + 4] = this->password;
			}
		}
	}

	vectorToFile(data);

}

void System::sendMessage()
{

	std::cout << "\nInsert email: ";

	MyString email;
	std::cin >> email;
	std::cin.ignore();
	MyString name = email + ".bin";

	char nameC[1024];
	strcpy(nameC, name.c_str());

	std::ofstream ofs(nameC, std::ios::binary | std::ios::app);

	char firstName[1024];
	char lastName[1024];
	char password[1024];
	char emailC[1024];

	convertData(firstName, lastName, emailC, password);

	User curr(firstName, lastName, emailC, password);

	MyString content;

	std::cout << std::endl << "Type what you want: \n";

	char buff[1024];

	std::cin.getline(buff, 1024);

	//std::cout << "\n\n" << buff;

	content = buff;

	//std::cout << std::endl << std::endl << content;

	Message message(curr, content);
	message.writeInBinary(ofs);

	ofs.close();

}

void System::viewMessage()
{

	if (isAdmin) {
		std::cout << "\nWrite the email you want to check:\t";
		MyString email;
		std::cin >> email;

		MyString nameS;
		nameS = email + ".bin";

		char name[1024];
		strcpy(name, nameS.c_str());

		std::ifstream ifs(name, std::ios::binary);

		while (ifs.peek() != EOF) {
			Message msg;
			msg.readFromBinary(ifs);
			std::cout << msg << std::endl;
		}

		ifs.close();

	}
	else {
		std::cout << "\n";
		for (int i = 0; i < messages.getSize(); i++) {
			std::cout << messages[i];
		}
	}
}

void System::deleteMessage()
{
	std::cout << "\nSelect which message you want to delete (counting starts from 1):";
	size_t index;
	std::cin >> index;
	index--;

	messages.erase(index);

	MyString nameS = email + ".bin";
	char name[1024];

	strcpy(name, nameS.c_str());

	std::ofstream ofs(name, std::ios::binary);

	for (int i = 0; i < messages.getSize(); i++) {
		messages[i].writeInBinary(ofs);
	}
	ofs.close();
}

void System::addCourse()
{
	if (isTeacher) {
		char firstName[1024];
		char lastName[1024];
		char email[1024];
		char password[1024];

		convertData(firstName, lastName, email, password);


		Teacher teacher(firstName, lastName, email, password);

		char buff[1024];
		MyString description;

		std::cout << "Insert name for the course: \n";
		std::cin.ignore();
		std::cin.getline(buff, 1024);

		description = buff;

		Course course(teacher, description);

		courses.push_back(course);

		std::ofstream ofs("Courses.bin", std::ios::binary | std::ios::app);
		course.writeInBinary(ofs);
		ofs.close();
	}
	else {
		std::cout << "\nYou do not have the authority to create a course.";
	}
}

void System::addStudentInCourse()
{
	if (isTeacher) {
		MyString firstName;
		MyString lastName;

		size_t index = -1;

		char firstNameC[1024];
		char lastNameC[1024];
		char password[1024];
		char email[1024];

		convertData(firstNameC, lastNameC, email, password);

		Teacher teacher(firstNameC, lastNameC, email, password);

		std::cout << "Insert name of the course: \n";
		char buff[1024];
		std::cin.ignore();
		std::cin.getline(buff, 1024);
		MyString courseName = buff; //std::cout << courseName;

		for (int i = 0; i < courses.getSize(); i++) {
			//std::cout << "in";
			if (courses[i].getDescription() == courseName) {
				index = i;
			}
		}


		std::cout << "Insert first name and last name of the student: \n";
		std::cin >> firstName >> lastName;

		bool found = false;

		for (int i = 0; i < students.getSize(); i++) {
			if (firstName == students[i].getFirstName() &&
				lastName == students[i].getLastName()) {
				// da napisha kakvo stava kato se vidi che studenta realno sustehstvuva
				found = true;
				if (index == -1)
					throw std::invalid_argument("Wrong course");
				courses[index].addStudent(students[i]);
			}
		}
		if (!found) {
			std::cout << "There is no such student.";
			addStudentInCourse();
		}

		std::ofstream ofs("Courses.bin", std::ios::binary);

		for (int i = 0; i < courses.getSize(); i++) {
			courses[i].writeInBinary(ofs);
		}
		ofs.close();
	}
	else {
		std::cout << "\nYou do not have the authority to add student in course.\n";
	}
}

void System::addTaskInCourse()
{
	if (isTeacher) {
		MyString firstName;
		MyString lastName;

		size_t index = -1;

		char firstNameC[1024];
		char lastNameC[1024];
		char password[1024];
		char email[1024];

		convertData(firstNameC, lastNameC, email, password);

		Teacher teacher(firstNameC, lastNameC, email, password);

		std::cout << "Insert name of the course: \n";
		char buff[1024];
		std::cin.ignore();
		std::cin.getline(buff, 1024);
		MyString courseName = buff; //std::cout << courseName;

		for (int i = 0; i < courses.getSize(); i++) {
			//std::cout << "in";
			if (courses[i].getDescription() == courseName &&
				strcmp(firstNameC, courses[i].getTeacher().getFirstName()) == 0 &&
				strcmp(lastNameC, courses[i].getTeacher().getLastName()) == 0) {
				index = i;
			}
		}
		//std::cout << index;

		if (index == -1)
			throw std::invalid_argument("Course not found or course not belong to u");

		std::cout << "Description/name for your task: \n";
		//char buff[1024];
		//std::cin.ignore();
		std::cin.getline(buff, 1024);
		MyString description = buff;
		Task task(description);

		courses[index].addTask(task);


		std::ofstream ofs("Courses.bin", std::ios::binary);

		for (int i = 0; i < courses.getSize(); i++) {
			courses[i].writeInBinary(ofs);
		}
		ofs.close();
	}
	else {
		std::cout << "\nYou do not have the authority to add task in course.\n";
	}
}

void System::addAnswer()
{
	if (isStudent) {
		char buff[1024];
		bool studentFound = false;

		char firstName[1024], lastName[1024], email[1024], password[1024];;
		convertData(firstName, lastName, email, password);

		//std::cout << firstName;
		
		std::cout << "\nInsert course: \n";
		std::cin.ignore();
		std::cin.getline(buff, 1024);

		//std::cout << buff;

		MyString desc = buff;

		int courseIndex = -1;

		for (int i = 0; i < courses.getSize(); i++) {
			if (courses[i].getDescription() == desc) {
				courseIndex = i;
			}
		}
		if (courseIndex == -1)
			throw std::invalid_argument("Wrong course...");
		//std::cout << courseIndex + 1;

		/*for (int i = 0; i < courses[i].getStudentsSize(); i++) {

		}*/
		//std::cout << courses[courseIndex].getStudentsSize();

		for (int i = 0; i < courses[courseIndex].getStudentsSize(); i++) {
			if (courses[courseIndex].getStudents(i).getFirstName() == this->firstName &&
				courses[courseIndex].getStudents(i).getLastName() == this->lastName) {
				studentFound = true;
			}
		}
		
		if (studentFound) {
			std::cout << "\nInsert Task: \n";
			//std::cin.ignore();
			std::cin.getline(buff, 1024);
			desc = buff;
			//std::cout << "\n" << desc << "\n";

			for (int i = 0; i < courses[courseIndex].getTasksSize(); i++) {
				if (courses[courseIndex].getTask(i).getDescription() == desc) {
					
					Student stu(firstName, lastName, email, password);
					MyString answer;
					std::cout << "\nInsert answer: \n";
					std::cin.getline(buff, 1024);

					answer = buff;
					std::cout << answer;

					Answer ans(stu,answer);
					courses[courseIndex].getTask(i).addAnswer(ans);
					
					
					std::ofstream ofs("Courses.bin", std::ios::binary);

					for (int i = 0; i < courses.getSize(); i++) {
						courses[i].writeInBinary(ofs);
					}
					ofs.close();
					return;
				}
			}

		}
		else {
			throw std::invalid_argument("You don't belong in this course...");
		}

		
	}
	else {
		std::cout << "\nYou do not have the authority to add answer in course.\n";
	}
}

void System::printCourses() const {
	if (isTeacher) {
		for (int i = 0; i < courses.getSize(); i++) {
			if (courses[i].getTeacher().getFirstName() == this->firstName &&
				courses[i].getTeacher().getLastName() == this->lastName) {
				std::cout << courses[i];
			}
		}
	}
	else if (isAdmin) {
		for (int i = 0; i < courses.getSize(); i++) {
			std::cout << courses[i];
		}
	}
	else {
		//std::cout << "\nYou do not have the authority to view courses.\n";
		for (int i = 0; i < courses.getSize(); i++) {
			for (int j = 0; j < courses[i].getStudentsSize(); j++) {
				if (courses[i].getStudents(j).getFirstName() == this->firstName &&
					courses[i].getStudents(j).getLastName() == this->lastName) {
					std::cout << courses[i];
				}
			}
		}
	}
}



std::ostream& operator<<(std::ostream& os, const System& system)
{
	os << "---------------------------------------------------\n";
	os << "LOG IN: \n";
	os << "---------------------------------------------------\n";
	os << "ID: " << system.getID() << "\n";
	os << "FIRST NAME: " << system.getFirstName() << "\n";
	os << "LAST NAME: " << system.getLastName() << "\n";
	os << "EMAIL: " << system.getEmail() << "\n";
	os << "---------------------------------------------------\n";

	return os;
}
