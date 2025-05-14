#include "Administrator.h"

Administrator::Administrator(): User()
{
    setPassword();
    setID();
}

Administrator::Administrator(const char* firstName, const char* lastName, const char* email):User(firstName,lastName,email,
    "DEFAULT_PASSWORD")
{
    setPassword();
    setID();

}



std::istream& operator>>(std::istream& is, Administrator& admin)
{
    char buff[1024];

    is >> buff;
    admin.setFirstName(buff);
    
    is >> buff;
    admin.setLastName(buff);

    is >> buff;
    admin.setEmail(buff);
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const Administrator& admin)
{
    os << "---------------------------------------------------\n";
    os << "ID: " << admin.getID() << "\n";
    os << "FIRST NAME: " << admin.getFirstName() << "\n";
    os << "LAST NAME: " << admin.getLastName() << "\n";
    os << "EMAIL: " << admin.getEmail() << "\n";
    os << "PASSWORD: " << admin.getPassword() << "\n";
    os << "---------------------------------------------------\n";
    return os;
}