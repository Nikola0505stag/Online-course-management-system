#include "System.h"

// 1 - admin
// 2 - student
// 3 - teacher

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

		if (buffI == 1) {
			admin.setFirstName(firstName);
			admin.setLastName(lastName);
			admin.setEmail(email);
			admin.setPassword(password);
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
