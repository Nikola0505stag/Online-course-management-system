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
	
	st.removeTeacher();

	return 0;
}