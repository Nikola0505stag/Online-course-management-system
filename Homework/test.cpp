#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"
#include "Message.h"

using namespace std;

int main() {


	/*System st;
	st.print();

	st.logIn();
	
	st.changePassword();*/


	Message m1;
	cin >> m1;


	ofstream ofs("Message.bin", std::ios::binary);

	m1.writeInBinary(ofs);

	ofs.close();
	
	Message m2;
	cout << m2 << endl << endl << endl;

	ifstream ifs("Message.bin", std::ios::binary);
	m2.readFromBinary(ifs);

	ifs.close();
	
	cout << m2;

	return 0;
}