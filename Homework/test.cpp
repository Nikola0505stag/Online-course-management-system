#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"
#include "Message.h"

using namespace std;

int main() {


	System st;
	st.print();

	st.logIn();
	
	st.viewMessage();

	//st.deleteMessage();

	return 0;
}