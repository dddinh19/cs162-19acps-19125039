#include "function.h"
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
	for (int i = 0; i < n_lecturer; ++i) {
		if ((username == p_lecturer[i].username) && (pass == p_lecturer[i].password)) {

			return;
		}
	}
	for (int i = 0; i < n_staff; ++i) {
		if ((username == p_staff[i].username) && (pass == p_staff[i].pass)) {

			return;
		}
	}
	for (int i = 0; i < n_student; ++i) {
		if ((username == p_student[i].id) && (pass == p_student[i].pass) && (p_student[i].status == 1)) {

			return;
		}
	}
}