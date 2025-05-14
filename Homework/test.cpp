#include "User.h"
#include "Administrator.h"
#include "Student.h"

using namespace std;

int main() {


	Administrator admin;
	cout << admin;
	
	Student st;
	cin >> st;
	st.addGrade(5.6);
	cout << st << "\n" << st.getGradesCapacity() << "\t" << st.getGradesSize();


	return 0;
}