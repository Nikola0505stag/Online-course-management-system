#include "Administrator.h"

void Administrator::createFile()
{
}

Administrator::Administrator(): User()
{
    setPassword();
    setID();
    createFile();
}

Administrator::Administrator(const char* firstName, const char* lastName, const char* email):User(firstName,lastName,email,
    "DEFAULT_PASSWORD")
{
    setPassword();
    setID();
    createFile();
}

void Administrator::createFile()
{
    std::string name = std::string(getEmail()) + ".txt";

    std::ofstream ofs(name);
    std::cout << "fiel";
    ofs << "Admin...";
    ofs.close();
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

    std::string name;
    name = (std::string)admin.getEmail() + ".txt";

    std::ofstream ofs(name);
    ofs << "Admin...";
    ofs.close();
    
    return is;
}
