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