#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"
#include "Message.h"
#include "Answer.h"

using namespace std;

int main() {


	//System st;
	//st.print();

	//st.logIn();
	//
	//st.deleteMessage();
	//st.viewMessage();


	Student test("Nikola", "Neychev", "nikneichev@abv.bg", "1231");

	Answer a1(test,"My homework .... some code here");

	std::ofstream ofs("Answer.bin", std::ios::binary);

	a1.writeInBinary(ofs);

	ofs.close();

	ifstream ifs("Answer.bin", std::ios::binary);

	Answer a2;
	cout << a2 << endl << endl << endl;
	a2.readFromBinary(ifs);

	ifs.close();
	cout << a2;

	return 0;
}