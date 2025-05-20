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


	System st;
	st.print();
	st.logIn();
	

	st.addCourse();

	cout << "\n\n\n\n";
	st.printCourses();
	
	return 0;
}