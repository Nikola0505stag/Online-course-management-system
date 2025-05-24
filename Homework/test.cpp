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


	System st;
	st.print();
	st.logIn();

	//st.addStudent();

	//st.addCourse();
	//st.printCourses();
	//st.addStudentInCourse();
	//st.addStudentInCourse();
	
	//st.addTaskInCourse();

	//st.addAnswer();
	//st.addGrade();
	cout << "\n\n\n\n\n\n\n";

	//st.sendMessageInCourse();

	
	st.viewMessage();

	cout << "\n\n\n\n\n\n\n";
	
	/*st.printCourses();*/

	//st.addGrade();
	


	
	return 0;
}
