#include "System.h"

System::System()
{
	std::ifstream ifs("Users.txt");

	char firstName[1024];
	char lastName[1024];
	char email[1024];

	ifs >> firstName;
	ifs >> lastName;
	ifs >> email;

	admin.setFirstName(firstName);
	admin.setLastName(lastName);
	admin.setEmail(email);
	ifs.close();
}

void System::print() const
{
	std::cout << admin;
}
