#include "function.h"

//LOGIN

void student_data(student*& p, int& n) {
	std::ifstream fi("Data/Login/student.txt");
	if (!fi.is_open()) std::cout << "Can not open student data file " << std::endl;
	else {
		fi >> n;
		p = new student[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].id;
			fi >> p[i].pass;
			fi >> p[i].classname;
			fi >> p[i].status;
			if (p[i].status == 0) --i;
		}
		fi.close();
	}
}
void staff_data(staff*& p, int& n) {
	std::ifstream fi("Data/Login/staff.txt");
	if (!fi.is_open()) std::cout << "Can not open staff data file " << std::endl;
	else {
		fi >> n;
		p = new staff[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].username;
			fi >> p[i].pass;
			getline(fi, p[i].name);
			getline(fi, p[i].name);
			fi >> p[i].gender;
		}
		fi.close();
	}
}
void lecturer_data(lecturer*& p, int& n) {
	std::ifstream fi("Data/Login/lecturer.txt");
	if (!fi.is_open()) std::cout << "Can not open lecturer data file " << std::endl;
	else {
		fi >> n;
		p = new lecturer[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].username;
			fi >> p[i].password;
		}
		fi.close();
	}
}
void login(student*& p_student, int& n_student, staff*& p_staff, int& n_staff, lecturer*& p_lecturer, int& n_lecturer, std::string username, std::string pass) {
	system("CLS");
	for (int i = 0; i < n_lecturer; ++i) {
		if ((username == p_lecturer[i].username) && (pass == p_lecturer[i].password)) {
			lecturer_menu(p_lecturer, n_lecturer, i);
			return;
		}
	}
	for (int i = 0; i < n_staff; ++i) {
		if ((username == p_staff[i].username) && (pass == p_staff[i].pass)) {
			staff_menu(p_student, n_student, p_staff, n_staff, i);
			return;
		}
	}
	for (int i = 0; i < n_student; ++i) {
		if ((username == p_student[i].id) && (pass == p_student[i].pass)) {
			student_menu(p_student, n_student, i);
			return;
		}
	}
}

//VIEW PROFILE

void student_info_data(std::string filename, student*& a) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open file " << std::endl;
	else {
		a = new student;
		fi >> a->id;
		getline(fi, a->name);
		getline(fi, a->name);
		fi >> a->gender;
		fi >> a->date.year;
		fi >> a->date.month;
		fi >> a->date.day;
		fi >> a->classname;
		fi.close();
	}
}
void view_student_profile(student* p, int k) {
	student* a = nullptr;
	std::string filename = "Data/Class/" + p[k].classname + "/" + p[k].id + "/info.txt";
	student_info_data(filename, a);
	std::cout << "Id: " << a->id << std::endl;
	std::cout << "Name: " << a->name << std::endl;
	if (a->gender == 1) std::cout << "Gender: Female" << std::endl;
	else std::cout << "Gender: Male " << std::endl;
	std::cout << "Date of birth(year/month/day): " << a->date.year << "/";
	if (a->date.month < 10) std::cout << "0" << a->date.month << "/";
	else std::cout << a->date.month << "/";
	if (a->date.day < 10) std::cout << "0" << a->date.day << std::endl;
	else std::cout << a->date.day << std::endl;
	std::cout << "Class: " << a->classname << std::endl;
	delete a;
}
void view_staff_profile(staff* p, int k) {
	std::cout << "Name: " << p[k].name << std::endl;
	if (p[k].gender == 1) std::cout << "Gender: Female " << std::endl;
	else std::cout << "Gender: Male " << std::endl;
}
void lecturer_info_data(std::string filename, lecturer*& a) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open file " << std::endl;
	else {
		a = new lecturer;
		getline(fi, a->name);
		getline(fi, a->degree);
		fi >> a->gender;
		fi.close();
	}
}
void view_lecturer_profile(lecturer* p, int k) {
	lecturer* a = nullptr;
	std::string filename = "Data/Login/Lecturer/" + p[k].username + "/info.txt";
	lecturer_info_data(filename, a);
	std::cout << "Name: " << a->name << std::endl;
	std::cout << "Degree: " << a->degree << std::endl;
	if (a->gender == 0) std::cout << "Gender: Male" << std::endl;
	else std::cout << "Gender: Female" << std::endl;
	delete a;
}

//CHANGE PASSWORD

void write_student_data(student* p, int n) {
	std::ofstream fo("Data/Login/student.txt");
	if (!fo.is_open()) std::cout << "Can not open student data file " << std::endl;
	else {
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].id << std::endl;
			fo << p[i].pass << std::endl;
			fo << p[i].classname << std::endl;
			fo << p[i].status << std::endl;
		}
		fo.close();
	}
}
void change_student_password(student*& p, int n, int k) {
	std::string tempt;
	std::string cur;
	do {
		std::cout << "Enter your current password " << std::endl;
		std::cin >> tempt;
	} while (tempt != p[k].pass);
	std::cout << "Enter your new password(no space) " << std::endl;
	std::cin >> tempt;
	do {
		std::cout << "Enter your new password again " << std::endl;
		std::cin >> cur;
	} while (cur != tempt);
	std::cout << "Password has been changed successfully !!!" << std::endl;
	p[k].pass = tempt;
	write_student_data(p, n);
}
void write_staff_data(staff* p, int n) {
	std::ofstream fo("Data/Login/staff.txt");
	if (!fo.is_open()) std::cout << "Can not open staff data file " << std::endl;
	else {
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].username << std::endl;
			fo << p[i].pass << std::endl;
			fo << p[i].name << std::endl;
			fo << p[i].gender << std::endl;
		}
		fo.close();
	}
}
void change_staff_password(staff*& p, int n, int k) {
	std::string tempt;
	std::string cur;
	do {
		std::cout << "Enter your current password " << std::endl;
		std::cin >> tempt;
	} while (tempt != p[k].pass);
	std::cout << "Enter your new password(no space) " << std::endl;
	std::cin >> tempt;
	do {
		std::cout << "Enter your new password again " << std::endl;
		std::cin >> cur;
	} while (cur != tempt);
	p[k].pass = tempt;
	write_staff_data(p, n);
}
void write_lecturer_data(lecturer* p, int n) {
	std::ofstream fo("Data/Login/lecturer.txt");
	if (!fo.is_open()) std::cout << "Can not open lecturer data file " << std::endl;
	else {
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].username << std::endl;
			fo << p[i].password << std::endl;
		}
		fo.close();
	}
}
void change_lecturer_password(lecturer*& p, int n, int k) {
	std::string tempt;
	std::string cur;
	do {
		std::cout << "Enter your current password " << std::endl;
		std::cin >> tempt;
	} while (tempt != p[k].password);
	std::cout << "Enter your new password(no space) " << std::endl;
	std::cin >> tempt;
	do {
		std::cout << "Enter your new password again " << std::endl;
		std::cin >> cur;
	} while (cur != tempt);
	std::cout << "Password has been changed successfully !!!" << std::endl;
	p[k].password = tempt;
	write_lecturer_data(p, n);
}

//MENU

void staff_menu(student*& p_student, int& n_student, staff*& p_staff, int n_staff, int k) {
	int choice;
	do {
		std::cout << "Menu for staff:" << std::endl;
		std::cout << "1.Class" << std::endl;
		std::cout << "2.Course" << std::endl;
		std::cout << "3.Score board" << std::endl;
		std::cout << "4.Attendance list" << std::endl;
		std::cout << "5.View profile info:" << std::endl;
		std::cout << "6.Change password" << std::endl;
		std::cout << "7.Log out" << std::endl;
		std::cout << "Please choose a section(1-7): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			system("CLS");
			staff_class(p_student, n_student);
			break;
		}
		case 2: {
			system("CLS");
			staff_course();
			break;
		}
		case 3: {
			system("CLS");
			staff_scoreboard();
			break;
		}
		case 4: {
			system("CLS");
			staff_attendance();
			break;
		}
		case 5: {
			system("CLS");
			view_staff_profile(p_staff, k);
			break;
		}
		case 6: {
			system("CLS");
			change_staff_password(p_staff, n_staff, k);
			break;
		}
		}
	} while (choice != 7);
}
void staff_class(student*& p_student, int& n_student) {
	int choice;
	do {
		std::cout << "Academic staff- class menu: " << std::endl;
		std::cout << "1. Import students of a class such as 18CLC6 from a csv file. " << std::endl;
		std::cout << "2.Manually add a new student to a class. " << std::endl;
		std::cout << "3.Edit an existing student." << std::endl;
		std::cout << "4.View list of classes." << std::endl;
		std::cout << "5.View list of students in a class." << std::endl;
		std::cout << "6.Exit." << std::endl;
		std::cout << "Please choose a task(1-7): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			char filename[100];
			std::cout << "Enter path to import csv file " << std::endl;
			std::cin.get();
			std::cin.get(filename, 100, '\n');
			std::string classname;
			student* p = nullptr;
			int n = 0;
			read_student_csv(filename, classname, p, n);
			import_student_csv(p_student, n_student, classname, p, n);
			delete[]p;
			break;
		}
		case 2: {
			student* a = nullptr;
			input_new_student(a);
			std::cout << "Import successfully " << add_a_student(p_student, n_student, a) << " " << std::endl;
			delete a;
			break;
		}
		case 3: {
			edit_student(p_student, n_student);
			break;
		}
		case 4: {
			view_list_class();
			break;
		}
		case 5: {
			view_list_class();
			std::string tempt;
			std::cout << "Enter class you want to view student " << std::endl;
			std::cin >> tempt;
			view_list_student_in_class(tempt);
			break;
		}
		}
	} while (choice != 6);
}
void task13() {
	int choice;
	std::ifstream fi; std::ofstream fo;
	std::cout << "1. Create academic years and semesters. " << std::endl;
	std::cout << "2. Update academic years and semesters. " << std::endl;
	std::cout << "3. Delete academic years and semesters. " << std::endl;
	std::cout << "4. View academic year. " << std::endl;
	std::cout << "5. View semester " << std::endl;
	std::cin >> choice;
	switch (choice) {
	case 1:
	{
		create_year_semester(fi, fo);
		break;
	}
	case 2:
	{
		update_year_semester(fi, fo);
		break;
	}
	case 3:
	{
		delete_year_semester(fi, fo);
		break;
	}
	case 4:
	{
		semester* p = nullptr;
		int n = 0;
		semester_data(p, n);
		view_academic_year(p, n);
		delete[]p;
		break;
	}
	case 5:
	{
		semester* p = nullptr;
		int n = 0;
		semester_data(p, n);
		view_academic_year(p, n);
		std::string year;
		std::cout << "Enter academic year you want to view semester " << std::endl;
		std::cin >> year;
		view_semester(p, n, year);
		delete[]p;
		break;
	}
	}
}
void staff_course() {
	int choice;
	do {
		std::cout << "Academic staff- course menu: " << std::endl;
		std::cout << "1.Create / update / delete / view academic years (2018-2019), and semesters (Fall)." << std::endl;
		std::cout << "2.From a semester, import courses such as CTT008, CTT010 from a csv file." << std::endl;
		std::cout << "3.Manually add a new course." << std::endl;
		std::cout << "4.Edit an existing course." << std::endl;
		std::cout << "5.Remove a course." << std::endl;
		std::cout << "6.Remove a specific student from a course." << std::endl;
		std::cout << "7.Add a specific student to a course." << std::endl;
		std::cout << "8.View list of courses in the current semester." << std::endl;
		std::cout << "9.View list of students of a course." << std::endl;
		std::cout << "10.View attendance list of a course." << std::endl;
		std::cout << "11.Create / update / delete / view all lecturers." << std::endl;
		std::cout << "12.Exit " << std::endl;
		std::cout << "Please choose a task(1-11): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			system("CLS");
			task13();
			break;
		}
		case 2: {
			system("CLS");
			std::ifstream fi; std::ofstream fo; course* cou = nullptr; int num;
			std::string academicyear, seme;
			create_allfile_course(fi, fo, cou, num, academicyear, seme);
			break;
		}
		case 3: {
			system("CLS");
			add_student();
			break;
		}
		case 4: {
			system("CLS");
			edit_course();
			break;
		}
		case 5: {
			system("CLS");
			removeacourse();
			break;
		}
		case 6: {
			system("CLS");
			remove_a_student();
			break;
		}
		case 7: {
			system("CLS");
			add_student();
			break;
		}
		case 8: {
			system("CLS");
			view_list_course_current_semester();
			break;
		}
		case 9: {
			system("CLS");
			view_list_student_in_course();
			break;
		}
		case 10: {
			system("CLS");
			view_attendance();
			break;
		}
		case 11: {
			system("CLS");
			view_all_lecturers();
			break;
		}
		}
	} while (choice != 12);
}
void staff_scoreboard() {
	int choice;
	do {
		std::cout << "Academic staff- scoreboard menu: " << std::endl;
		std::cout << "1.Search and view the scoreboard of a course." << std::endl;
		std::cout << "2.Export a scoreboard to a csv file." << std::endl;
		std::cout << "3.Exit " << std::endl;
		std::cout << "Please choose a task(1-2): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			system("CLS");
			staff_view_scoreboard();
			break;
		}
		case 2: {
			system("CLS");
			export_scoreboard();
			break;
		}
		}
	} while (choice != 3);
}
void staff_attendance() {
	int choice;
	do {
		std::cout << "Academic staff- attendance list menu: " << std::endl;
		std::cout << "1.Search and view attendance list of a course." << std::endl;
		std::cout << "2.Export a attendance list to a csv file." << std::endl;
		std::cout << "3. Exit." << std::endl;
		std::cout << "Please choose a task(1-2): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			system("CLS");
			view_attendance();
			break;
		}
		case 2: {
			system("CLS");
			export_attendancelist();
			break;
		}
		}
	} while (choice != 3);
}
void lecturer_menu(lecturer* p_lecturer,int n_lecturer, int k) {
	int choice;
	do {
		std::cout << "Menu for lecturer:" << std::endl;
		std::cout << "1.View list of courses in the current semester." << std::endl;
		std::cout << "2.View list of students of a course." << std::endl;
		std::cout << "3.View attendance list of a course." << std::endl;
		std::cout << "4.Edit an attendance." << std::endl;
		std::cout << "5.Import scoreboard of a course (midterm, final, lab, bonus) from a csv file." << std::endl;
		std::cout << "6.Edit grade of a student" << std::endl;
		std::cout << "7.View a scoreboard" << std::endl;
		std::cout << "8.View profile info:" << std::endl;
		std::cout << "9.Change password" << std::endl;
		std::cout << "10.Log out" << std::endl;
		std::cout << "Please choose a task (1-10): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			system("CLS");
			view_list_course_current_semester();
			break;
		}
		case 2: {
			system("CLS");
			lecturer_view_list_student_course(p_lecturer, k);
			break;
		}
		case 3: {
			system("CLS");
			lecturer_view_list_attendance_course(p_lecturer, k);
			break;
		}
		case 4: {
			system("CLS");
			edit_attendance(p_lecturer, k);
			break;
		}
		case 5: {
			system("CLS");
			char filename[100];
			std::cout << "Enter path to import csv file " << std::endl;
			std::cin.get();
			std::cin.get(filename, 100, '\n');
			std::string year, sem, courseid, classname;
			student* p;
			int n = 0;
			read_scoreboard_csv(filename, p_lecturer, k, year, sem, courseid, classname, p, n);
			import_scoreboard_csv(year, sem, courseid, classname, p, n);
			delete[]p;
			break;
		}
		case 6: {
			system("CLS");
			edit_scoreboard(p_lecturer, k);
			break;
		}
		case 7: {
			system("CLS");
			lecturer_view_scoreboard(p_lecturer, k);
			break;
		}
		case 8: {
			system("CLS");
			view_lecturer_profile(p_lecturer, k);
			break;
		}
		case 9: {
			system("CLS");
			change_lecturer_password(p_lecturer, n_lecturer, k);
			break;
		}
		}
	} while (choice != 10);
}
void student_menu(student*& p_student,int n_student, int k) {
	int choice;
	do {
		std::cout << "Menu for student:" << std::endl;
		std::cout << "1.Check-in (1 check-in/week) in 11 weeks" << std::endl;
		std::cout << "2.View check-in result." << std::endl;
		std::cout << "3.View schedules." << std::endl;
		std::cout << "4.View his/her scores of a course." << std::endl;
		std::cout << "5.View profile info:" << std::endl;
		std::cout << "6.Change password" << std::endl;
		std::cout << "7.Log out" << std::endl;
		std::cout << "Please choose a task (1-7): " << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			system("CLS");
			checkin(p_student[k]);
			break;
		}
		case 2: {
			system("CLS");
			view_checkin(p_student[k]);
			break;
		}
		case 3: {
			system("CLS");
			view_schedule(p_student[k]);
			break;
		}
		case 4: {
			system("CLS");
			view_score(p_student[k]);
			break;
		}
		case 5: {
			system("CLS");
			view_student_profile(p_student, k);
			break;
		}
		case 6: {
			system("CLS");
			change_student_password(p_student, n_student, k);
			break;
		}
		}
	} while (choice != 7);
}

