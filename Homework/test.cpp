#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"
#include "Message.h"
#include "Answer.h"
#include "Task.h"
#include "Course.h"

using namespace std;

int main() {


	//System st;
	//st.print();

	//st.logIn();

	//st.viewMessage();
	//st.addStudent();

	
	Task t1("Homework1");
	Task t2("Homework2");

	t2.addAnswer(Answer("Nikola","Neychev","nikneichev@abv.bg","0","nikla's code..."));
	t2.addAnswer(Answer("Valentin", "Vulkov", "valval@abv.bg", "1", "valentin's code..."));
	t2.addAnswer(Answer("Martin", "Stanchev", "mar@abv.bg", "2", "Martin's homework"));

	Course course("Kristian", "Krustev", "kris@abv.bg", "3", "OOP-SE");

	course.addTask(t2);
	course.addTask(t1);
	
	Course c2;
	cout << c2;

	std::ofstream ofs("Course.bin", std::ios::binary);
	course.writeInBinary(ofs);
	ofs.close();

	ifstream ifs("Course.bin", std::ios::binary);


	c2.readFromBinary(ifs);
	ifs.close();

	cout << "\n\n\n" << c2;

	return 0;
}