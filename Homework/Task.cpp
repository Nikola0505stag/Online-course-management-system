#include "Task.h"

Task::Task()
{
    setTeacher("DEFAULT_FIRST_NAME", "DEFAULT_LAST_NAME", "DEFAULT_EMAIL", "DEFAULT_PASSWORD");
    setDescription("DEFAULT_DESCRIPTION");
}

Task::Task(Teacher teacher, MyString description)
{
    setTeacher(teacher);
    setDescription(description);
}

Task::Task(const char* firstName, const char* lastName, const char* email, const char* password, 
    MyString description)
{
    setTeacher(firstName, lastName, email, password);
    setDescription(description);
}

void Task::setTeacher(Teacher teacher)
{
    this->teacher = std::move(teacher);
}

void Task::setTeacher(const char* firstName, const char* lastName, const char* email, const char* password)
{
    Teacher curr(firstName, lastName, email, password);
    this->teacher = std::move(curr);
}

void Task::setDescription(MyString description)
{
    this->description = description;
}

const Teacher Task::getTeacher() const
{
    return teacher;
}

const MyString Task::getDescription() const
{
    return description;
}

void Task::addAnswer(Answer answer)
{
    answers.push_back(answer);
}

void Task::writeInBinary(std::ofstream& ofs) const
{
    teacher.writeInBinary(ofs);

    size_t len = description.getSize() + 1;

    ofs.write((const char*)&len, sizeof(len));

    ofs.write(description.c_str(), len);

    size_t size = answers.getSize();

    ofs.write((const char*)&size, sizeof(size));

    for (int i = 0; i < answers.getSize(); i++) {
        answers[i].writeInBinary(ofs);
    }
}

void Task::readFromBinary(std::ifstream& ifs)
{
    teacher.readFromBinary(ifs);

    size_t len;

    ifs.read((char*)&len, sizeof(len));

    char* buff = new char[len];

    ifs.read(buff, len);

    description = buff;

    size_t size;
    ifs.read((char*)&size, sizeof(size));

    for (int i = 0; i < size; i++) {
        Answer ans;
        ans.readFromBinary(ifs);
        answers.push_back(ans);
    }
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
    os << "----------------------------------------------\n";
    os << "TEACHER: \n";
    os << "----------------------------------------------\n";
    os << task.teacher;
    os << "----------------------------------------------\n";
    os << "DESCRIPTION: \n";
    os << task.description << "\n";
    os << "----------------------------------------------\n";
    os << "ANSWERS: \n";
    os << "----------------------------------------------\n";
    for (int i = 0; i < task.answers.getSize(); i++) {
        os << task.answers[i];
    }
    os << "----------------------------------------------\n";

    return os;
}
