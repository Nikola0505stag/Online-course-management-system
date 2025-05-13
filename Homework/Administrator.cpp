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
