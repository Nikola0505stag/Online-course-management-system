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


	/*Message m1;
	cin >> m1;

	cout << m1;*/


	User u1("Nikola", "Neychev", "nikneichev@abv.bg", "00101");
	
	ofstream ofs("Test.bin", std::ios::binary);

	u1.writeInBinary(ofs);

	ofs.close();

	ifstream ifs("Test.bin", std::ios::binary);

	User u2;
	u2.readFromBinary(ifs);

	cout << u2;

	ifs.close();

	return 0;
}