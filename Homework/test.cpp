#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"
#include "Message.h"
#include "Answer.h"
#include "Task.h"

using namespace std;

int main() {


	//System st;
	//st.print();

	//st.logIn();
	//
	//st.deleteMessage();
	//st.viewMessage();


	Student testt("Nikola", "Neychev", "nikneichev@abv.bg", "1231");

	Answer a1(testt,"My homework .... some code here");

	std::ofstream ofs("Answer.bin", std::ios::binary);

	a1.writeInBinary(ofs);

	ofs.close();

	ifstream ifs("Answer.bin", std::ios::binary);

	Answer a2;
	//cout << a2 << endl << endl << endl;
	a2.readFromBinary(ifs);

	ifs.close();
	cout << a2;

	Teacher test("Nikola","Neychev","nikneichev@abv.bg","012043");

	Task t1(test,"OOP-SE-1kurs");

	t1.addAnswer(a1);
	t1.addAnswer(a1);

	cout << t1;

	std::ofstream ofs1("Task.bin", std::ios::binary);
	t1.writeInBinary(ofs1);
	ofs1.close();

	ifstream ifs1("Task.bin", std::ios::binary);
	cout << "\n\n\n\n\n\n";

	Task t2;
	cout << t2;
	cout << "\n\n\n\n\n\n";
	t2.readFromBinary(ifs1);

	ifs1.close();
	cout << t2;
	return 0;
}