#include "User.h"
#include "Administrator.h"
#include "Student.h"
#include "Teacher.h"
#include "System.h"
#include "Message.h"
#include "Answer.h"
#include "Task.h"
#include "Course.h"
#include "Grade.h"

using namespace std;

int main() {


	/*System st;
	st.print();
	st.logIn();*/


	//st.addCourse();

	//cout << "\n\n\n\n";
	//st.printCourses();
	//st.addStudentInCourse();
	//st.addTaskInCourse();
	//st.addAnswer();
	//cout << "\n\n\n\n";

	//st.addTaskInCourse();

	//st.addAnswer();


	Grade grade; 
	cout << grade << "\n";
	cin >> grade;
	cout << "\n\n" << grade << "\n\n";

	return 0;
}
