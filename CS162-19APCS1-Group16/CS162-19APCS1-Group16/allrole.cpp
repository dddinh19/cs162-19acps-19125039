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

//VIEW PROFILE

void student_info_data(std::string filename, student*& a) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open file " << std::endl;
	else {
		a = new student;
		fi >> a->id;
		getline(fi, a->name);
		getline(fi, a->name);
		//fi >> a->gender;
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
	//if (a->gender == 1) std::cout << "Gender: Female" << std::endl;
	//else std::cout << "Gender: Male " << std::endl;
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