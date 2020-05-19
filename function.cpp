#include "function.h"
void student_data(student*& p, int& n){
	std::ifstream fi("student.txt");
	if (!fi.is_open()) std::cout << " Can not open student data file " << std::endl;
	else {
		fi >> n;
		char tempt[50];
		p = new student[n];
		for (int i = 0; i < n; ++i) {
			fi >> tempt;
			p[i].id = new char[strlen(tempt) + 1];
			strcpy_s(p[i].id, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].pass = new char[strlen(tempt) + 1];
			strcpy_s(p[i].pass, strlen(tempt) + 1, tempt);
			fi.getline(tempt, 50);
			fi.getline(tempt, 50);
			p[i].name = new char[strlen(tempt) + 1];
			strcpy_s(p[i].name, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].classname = new char[strlen(tempt) + 1];
			strcpy_s(p[i].classname, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].status = new char[strlen(tempt) + 1];
			strcpy_s(p[i].status, strlen(tempt) + 1, tempt);
		}
		fi.close();
	}
}
void staff_data(staff*& p, int& n) {
	std::ifstream fi("staff.txt");
	if (!fi.is_open()) std::cout << " Can not open staff data file " << std::endl;
	else {
		char tempt[50];
		fi >> n;
		p = new staff[n];
		for (int i = 0; i < n; ++i) {
			fi >> tempt;
			p[i].username = new char[strlen(tempt) + 1];
			strcpy_s(p[i].username, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].pass = new char[strlen(tempt) + 1];
			strcpy_s(p[i].pass, strlen(tempt) + 1, tempt);
			fi.getline(tempt, 50);
			fi.getline(tempt, 50);
			p[i].name = new char[strlen(tempt) + 1];
			strcpy_s(p[i].name, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].sex = new char[strlen(tempt) + 1];
			strcpy_s(p[i].sex, strlen(tempt) + 1, tempt);
		}
		fi.close();
	}
}
void lecturer_data(lecturer*& p, int& n) {
	std::ifstream fi("lecturer.txt");
	if (!fi.is_open()) std::cout << " Can not open lecturer data file " << std::endl;
	else {
		char tempt[50];
		fi >> n;
		p = new lecturer[n];
		for (int i = 0; i < n; ++i) {
			fi >> tempt;
			p[i].username = new char[strlen(tempt) + 1];;
			strcpy_s(p[i].username, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].pass = new char[strlen(tempt) + 1];
			strcpy_s(p[i].pass, strlen(tempt) + 1, tempt);
			fi.getline(tempt, 50);
			fi.getline(tempt, 50);
			p[i].name = new char[strlen(tempt) + 1];
			strcpy_s(p[i].name, strlen(tempt) + 1, tempt);
			fi.getline(tempt, 50);
			p[i].degree = new char[strlen(tempt) + 1];
			strcpy_s(p[i].degree, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].sex = new char[strlen(tempt) + 1];
			strcpy_s(p[i].sex, strlen(tempt) + 1, tempt);
		}
		fi.close();
	}
}
void delete_student_data(student*& p, int n) {
	for (int i = 0; i < n; ++i) {
		delete[]p[i].id;
		delete[]p[i].pass;
		delete[]p[i].name;
		delete[]p[i].classname;
		delete[]p[i].status;
	}
	delete[]p;
}
void delete_staff_data(staff*& p, int n) {
	for (int i = 0; i < n; ++i) {
		delete[]p[i].username;
		delete[]p[i].pass;
		delete[]p[i].name;
		delete[]p[i].sex;
	}
	delete[]p;
}
void delete_lecturer_data(lecturer*& p, int n) {
	for (int i = 0; i < n; ++i) {
		delete[]p[i].username;
		delete[]p[i].pass;
		delete[]p[i].name;
		delete[]p[i].degree;
		delete[]p[i].sex;
	}
	delete[]p;
}
bool login(char username[], char pass[], student* p_student, staff* p_staff, lecturer* p_lecturer, int n_student, int n_staff, int n_lecturer, int& type, int& user) {
	for (int i = 0; i < n_student; ++i) {
		if (strcmp(p_student[i].id, username) == 0 && strcmp(p_student[i].pass, pass) == 0 && strcmp(p_student[i].status, "1") == 0) {
			user = i;
			type = 1;
			return true;
		}
	}
	for (int i = 0; i < n_staff; ++i) {
		if (strcmp(p_staff[i].username, username) == 0 && strcmp(p_staff[i].pass, pass) == 0) {
			user = i;
			type = 2;
			return true;
		}
	}
	for (int i = 0; i < n_lecturer; ++i) {
		if (strcmp(p_lecturer[i].username, username) == 0 && strcmp(p_lecturer[i].pass, pass) == 0) {
			user = i;
			type = 3;
			return true;
		}
	}
}
int staff_menu() {
	int choice;
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
	return choice;
}
int staff_class() {
	int choice;
	std::cout << "Academic staff- class menu: " << std::endl;
	std::cout << "1. Import students of a class such as 18CLC6 from a csv file. " << std::endl;
	std::cout << "2.Manually add a new student to a class. " << std::endl;
	std::cout << "3.Edit an existing student." << std::endl;
	std::cout << "4.Remove a student." << std::endl;
	std::cout << "5.Change students from class A to class B" << std::endl;
	std::cout << "6.View list of classes." << std::endl;
	std::cout << "7.View list of students in a class." << std::endl;
	std::cout << "Please choose a task(1-7): " << std::endl;
	std::cin >> choice;
	return choice;
}
int staff_course() {
	int choice;
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
	std::cout << "Please choose a task(1-11): " << std::endl;
	std::cin >> choice;
	return choice;
}
int staff_scoreboard() {
	int choice;
	std::cout << "Academic staff- scoreboard menu: " << std::endl;
	std::cout << "1.Search and view the scoreboard of a course." << std::endl;
	std::cout << "2.Export a scoreboard to a csv file." << std::endl;
	std::cout << "Please choose a task(1-2): " << std::endl;
	std::cin >> choice;
	return choice;
}
int staff_attendance() {
	int choice;
	std::cout << "Academic staff- attendance list menu: " << std::endl;
	std::cout << "1.Search and view attendance list of a course." << std::endl;
	std::cout << "2.Export a attendance list to a csv file." << std::endl;
	std::cout << "Please choose a task(1-2): " << std::endl;
	std::cin >> choice;
	return choice;
}
int lecturer_menu() {
	int choice;
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
	return choice;
}
int student_menu() {
	int choice;
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
	return choice;
}
void class_data(char filename[], student*& p, int& n) {
	std::ifstream fi(filename);
	fi >> n;
	p = new student[n];
	char tempt[50];
	if (!fi.is_open()) std::cout << " Can not open " << filename << " file " << std::endl;
	else {
		for (int i = 0; i < n; ++i) {
			fi >> tempt;
			p[i].id = new char[strlen(tempt) + 1];
			strcpy_s(p[i].id, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].pass = new char[strlen(tempt) + 1];
			strcpy_s(p[i].pass, strlen(tempt) + 1, tempt);
			fi.getline(tempt, 50);
			fi.getline(tempt, 50);
			p[i].name = new char[strlen(tempt) + 1];
			strcpy_s(p[i].name, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].date.year = new char[strlen(tempt) + 1];
			strcpy_s(p[i].date.year, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].date.month = new char[strlen(tempt) + 1];
			strcpy_s(p[i].date.month, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].date.day = new char[strlen(tempt) + 1];
			strcpy_s(p[i].date.day, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].classname = new char[strlen(tempt) + 1];
			strcpy_s(p[i].classname, strlen(tempt) + 1, tempt);
			fi >> tempt;
			p[i].status = new char[strlen(tempt) + 1];
			strcpy_s(p[i].status, strlen(tempt) + 1, tempt);
		}
		fi.close();
	}
}
void delete_class_data(student*& p, int n) {
	for (int i = 0; i < n; ++i) {
		delete[]p[i].id;
		delete[]p[i].pass;
		delete[]p[i].name;
		delete[]p[i].date.year;
		delete[]p[i].date.month;
		delete[]p[i].date.day;
		delete[]p[i].classname;
		delete[]p[i].status;
	}
	delete[]p;
}
void view_student_info(student* p, int i) {
	char filename[20];
	strcpy_s(filename, strlen(p[i].classname) + 1, p[i].classname);
	strcat_s(filename, 20, ".txt");
	student* p_class = nullptr;
	int n_student_class = 0;
	class_data(filename, p_class, n_student_class);
	for (int j = 0; j < n_student_class; ++j) {
		if (strcmp(p_class[j].id, p[i].id) == 0) {
			std::cout << "Student ID: " << p_class[j].id << std::endl;
			std::cout << "Full name: " << p_class[j].name << std::endl;
			std::cout << "Date of birth(year, month, day): " << p_class[j].date.year << " " << p_class[j].date.month << " " << p_class[j].date.day << std::endl;
			std::cout << "Class: " << p_class[j].classname << std::endl;
			break;
		}
	}
	delete_class_data(p_class, n_student_class);
}
void view_staff_info(staff* p, int i) {
	std::cout << " Full name: " << p[i].name << std::endl;
	if (strcmp(p[i].sex, "1") == 0) std::cout << " Sex: Female" << std::endl;
	else std::cout << " Sex: Male" << std::endl;
}
void view_lecturer_info(lecturer* p, int i) {
	std::cout << " Full name: " << p[i].name << std::endl;
	std::cout << " Degree: " << p[i].degree << std::endl;
	if (strcmp(p[i].sex, "1") == 1)std::cout << " Sex: Female " << std::endl;
	else std::cout << " Sex: Male " << std::endl;
}
void write_student_data(student* p, int n) {
	std::ofstream fo("student.txt");
	if (!fo.is_open()) std::cout << " Can not open student data file " << std::endl;
	else {
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].id << std::endl;
			fo << p[i].pass << std::endl;
			fo << p[i].name << std::endl;
			fo << p[i].classname << std::endl;
			fo << p[i].status << std::endl;
		}
		fo.close();
	}
}
void change_student_password(student*& p, int n, int i) {
	char tempt[20];
	do {
		std::cout << " Enter your current password " << std::endl;
		std::cin >> tempt;
	} while (strcmp(tempt, p[i].pass) != 0);
	std::cout << " Enter new password " << std::endl;
	std::cin >> tempt;
	char tempt_2[20];
	do {
		std::cout << " Enter new password again " << std::endl;
		std::cin >> tempt_2;
	} while (strcmp(tempt_2, tempt) != 0);
	p[i].pass = new char[strlen(tempt) + 1];
	strcpy_s(p[i].pass, strlen(tempt) + 1, tempt);
	write_student_data(p, n);
}