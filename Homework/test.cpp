//5MI0600551
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

void options() {
	cout << "add_student: Add a student to the program";
	cout << "add_teacher: Add a teacher to the program";
	cout << "remove_teacher: Remove teacher from the program";
	cout << "remove_student: Remove student from the program";
	cout << "change_password: To change the password";
	cout << "send_message: To send a message";
	cout << "view_message: To view a message";
	cout << "delete_message: To delete a message";
	cout << "add_course: To add a course";
	cout << "add_student_in_course: To add a student in course";
	cout << "add_task_in_course: To add task in course";
	cout << "add_answer: To add answer in course";
	cout << "add_grade: To rate student in course";
	cout << "send_message_in_course: To send a message to the entire course";
	cout << "view_grades: To view your grades";
	cout << "print_course: To print course";
	cout << "print: To print users";
}

int main() {

	MyString answer;
	System st;
	
	again:
	cout << "> ";
	cin >> answer;
	
	if (answer == "login") {
		st.logIn();

		do {
			cout << "> ";
			cin >> answer;

			if (answer == "add_student") st.addStudent();
			else if (answer == "add_teacher") st.addTeacher();
			else if (answer == "remove_teacher") st.removeTeacher();
			else if (answer == "remove_student") st.removeStudent();
			else if (answer == "change_password") st.changePassword();
			else if (answer == "send_message") st.sendMessage();
			else if (answer == "view_message") st.viewMessage();
			else if (answer == "delete_message") st.deleteMessage();
			else if (answer == "add_course") st.addCourse();
			else if (answer == "add_student_in_course") st.addStudentInCourse();
			else if (answer == "add_task_in_course") st.addTaskInCourse();
			else if (answer == "add_answer") st.addAnswer();
			else if (answer == "add_grade") st.addGrade();
			else if (answer == "send_message_in_course") st.sendMessageInCourse();
			else if (answer == "view_grades") st.viewGrades();
			else if (answer == "print_course") st.printCourses();
			else if (answer == "print") st.print();
			else if (answer == "help") options();
			else {
				cout << "Incorrectly entered";
			}

		} while (answer != "exit");
	}
	else {
		cout << "You need to log in...\n";
		goto again;
	}
	
	return 0;
}
