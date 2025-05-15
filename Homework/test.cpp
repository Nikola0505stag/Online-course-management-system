#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"

using namespace std;

int main() {


	System st;
	st.print();

	st.logIn();
	cout << endl << endl;
	cout << st.getFirstName() << "\t" << st.getLastName() << '\t' << st.getPassword() << "\n"<<st.getEmail() << "\t" << st.getID();
	return 0;
}