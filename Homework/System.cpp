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

	//std::cout << admin.getID() << " " << admin.getPassword();

	if (ID == admin.getID() && strcmp(password,admin.getPassword()) == 0) {
		//std::cout << "in";
		isAdmin = true;
		std::cout << std::endl << "Welcome Admin " << admin.getFirstName() << " " << admin.getLastName() << std::endl;

		firstName = admin.getFirstName();
		lastName = admin.getLastName();
		email = admin.getEmail();
		this->password = admin.getPassword();
		this->ID = admin.getID();

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
	
	std::string email;
	std::cin >> email;
	std::cin.ignore();
	std::string name = email + (std::string)".bin";

	std::ofstream ofs(name, std::ios::binary | std::ios::app);

	char firstName[1024];
	strcpy(firstName, this->firstName.c_str());
	
	char lastName[1024];
	strcpy(lastName, this->lastName.c_str());

	char password[1024];
	strcpy(password, this->password.c_str());

	char emailC[1024];
	strcpy(emailC, this->email.c_str());

	User curr(firstName, lastName, emailC, password);

	MyString content;

	std::cout << std::endl << "Type what you want: \n";

	char buff[1024];

	std::cin.getline(buff,1024);

	//std::cout << "\n\n" << buff;

	content = buff;

	//std::cout << std::endl << std::endl << content;

	Message message(curr, content);
	message.writeInBinary(ofs);

	ofs.close();

}

void System::viewMessage()
{
	
	char email[1024];
	strcpy(email, this->email.c_str());

	std::string name = email + (std::string)".bin";

	std::ifstream ifs(name, std::ios::binary);

	while (ifs.peek() != EOF) {
		Message msg;
		msg.readFromBinary(ifs);
		std::cout << msg << std::endl;
	}

	ifs.close();
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
