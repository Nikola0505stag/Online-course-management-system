# Homework

An online course management system that allows management of users with different roles: Administrator, Teachers and Students. Each user has a first name, last name, unique identification number and an inbox for receiving messages. Each message is characterized by sender, content, date and time. The system includes course management, assignments and assessments.

# The system:

- Loads users, courses, and messages from files on startup. Allows user login, but not registration. Only the administrator can create new users, and they exist in the system record even before the first launch.
- Logging into the system is done through a unique identification number (ID) and password. We assume that the administrator's ID is 0 and his default password is “0000”.
- Allows management of course and user data.
- Stores users' incoming messages in their mailboxes.
- Supports different roles with different access and communication rights.

# “Administrator” functionalities:
- The system has one administrator.
- Can create and delete teachers and students. The administrator sets a default password for each user. The user can change it later
- Can send messages to all users.
- Has access to all users' inboxes.

# “Teacher” functionalities:
- Can create new courses
- Can create new assignments in a course, with an assignment containing the students' answers (in the form of a string). Answers to assignments can only be viewed by the instructor who is leading the course.
- It can enroll students in its courses.
- Can set a password for self-enrollment of students in a course he leads
- Може да оценява задания на студентите.
- Can send messages to students in a course he is teaching.

# “Student” functionalities:
- He can enroll in courses, but only if he knows the password for the course in question.
- Can submit solutions to course assignments.
- He can see his grades.
- Can send messages to other users in the system.
- Can view his inbox and delete messages from there.

# Example use of the system:

> login 0 0000
Login successful!
> add_teacher Pesho Petrov qwerty
Added teacher Pesho Petrov with ID 100!
> add_student Ivan Ivanov 123456
Added student Ivan Ivanov with ID 101!
>  add_student Ilian Iliev 000000
Added student Ilian Iliev with ID 102!
> message_all Welcome to our Course Management System!
> logout

> login 100 qwerty
Login successful!
Pesho Petrov | Teacher | 100
> change_password qwerty 111111
Password changed successfully!
> create_course OOP-SE cooked
> add_to_course OOP-SE 100
> logout

> login 101 123456
Login successful!
Ivan Ivanov | Student | 101
> mailbox
15:00 08.05.2025, sent by admin: Welcome to our Course Management System!
15:12 08.05.2025, sent by Pesho Petrov: Pesho Petrov added you to OOP-SE
> logout

> login 102 000000
Login successful!
Ilian Iliev | Student | 102
> enroll OOP-SE cooked
Successfully enrolled in OOP-SE!
> logout

> login 100 111111
Login successful!
Pesho Petrov | Teacher | 100
> assign_homework OOP-SE Homework1
Successfully created a new assignment!
> message_students OOP-SE You have a new homework assignment published in OOP-SE!
> logout

> login 102 000000
Login successful!
Ilian Iliev | Student | 102
> mailbox
15:00 08.05.2025, sent by admin: Welcome to our Course Management System!
16:09 08.05.2025, sent by Pesho Petrov: You have a new 
assignment published in OOP-SE!
> submit_assignment OOP-SE Homework1 Link to my source code: https://github.com/...
> message 101 Do you need help with your homework?
> logout

> login 100 111111
Login successful!
Pesho Petrov | Teacher | 100
> view_assignment_submissions OOP-SE Homework1
Ilian Iliev, 100: Link to my source code: https://github.com/...
> grade_assignment OOP-SE Homework1 100 5.89 Great Work!
> logout

> login 102 000000
Login successful!
Ilian Iliev | Student | 102
> mailbox
15:00 08.05.2025, sent by admin: Welcome to our Course Management System!
16:09 08.05.2025, sent by Pesho Petrov: You have a new homework assignment published in OOP-SE!
09:58 09.05.2025, sent by Pesho Petrov: Pesho Petrov graded your work on Homework1 in OOP-SE
> clear_mailbox
> mailbox
No messages to show!
> grades
OOP-SE | Homework1 | 5.89 | Great work!
