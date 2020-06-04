#include "function.h"

//ADD A NEW STUDENT

void student_class_data(std::string filename, student*& p, int& n) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open student in class data file " << std::endl;
	else {
		fi >> n;
		p = new student[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].id;
			fi >> p[i].status;
			if (p[i].status == 0) --i;
		}
		fi.close();
	}
}
void write_student_class_data(std::string filename, student* p, int n) {
	std::ofstream fo(filename);
	if (!fo.is_open()) std::cout << "Can not open student in class data file " << std::endl;
	else {
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].id << std::endl;
			fo << p[i].status << std::endl;
		}
		fo.close();
	}
}
void input_new_student(student*& a) {
	a = new student;
	std::cout << "Enter student's id " << std::endl;
	std::cin >> a->id;
	std::cout << "Enter student's name " << std::endl;
	getline(std::cin, a->name);
	getline(std::cin, a->name);
	//std::cout << "Enter student's gender(0: Male, 1: Female) " << std::endl;
	//std::cin >> a->gender;
	std::cout << "Enter student's date of birth(year, month, day) " << std::endl;
	std::cin >> a->date.year >> a->date.month >> a->date.year;
	a->pass = std::to_string(a->date.year);
	if (a->date.month < 10) a->pass += "0" + std::to_string(a->date.month);
	else a->pass += std::to_string(a->date.month);
	if (a->date.day < 10) a->pass += "0" + std::to_string(a->date.day);
	else a->pass += std::to_string(a->date.day);
	std::cout << "Enter student's class " << std::endl;
	std::cin >> a->classname;
	a->status = 1;
}
void write_student_info(std::string filename, student* a) {
	std::ofstream fo(filename);
	if (!fo.is_open()) std::cout << "Can not open student info data file " << std::endl;
	else {
		fo << a->id << std::endl;
		fo << a->name << std::endl;
		//fo << a->gender << std::endl;
		fo << a->date.year << " " << a->date.month << " " << a->date.day << std::endl;
		fo << a->classname << std::endl;
		fo.close();
	}
}
int add_a_student(student*& p, int& n, student* a) {
	//student* a = nullptr;
	//input_new_student(a);
	for (int i = 0; i < n; ++i) {
		if (p[i].id == a->id && p[i].status == 1) {
			delete a;
			return 0;
		}
	}
	++n;
	student* p_tempt = new student[n];
	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			p_tempt[i].id = a->id;
			p_tempt[i].pass = a->pass;
			p_tempt[i].classname = a->classname;
			p_tempt[i].status = a->status;
		}
		else p_tempt[i] = p[i];
	}
	delete[]p;
	p = p_tempt;
	write_student_data(p, n);
	student* p_class = nullptr;
	int n_class = 0;
	std::string filename = "Data/Class/" + a->classname + ".txt";
	student_class_data(filename, p_class, n_class);
	++n_class;
	p_tempt = new student[n_class];
	for (int i = 0; i < n_class; ++i) {
		if (i == n_class - 1) {
			p_tempt[i].id = a->id;
			p_tempt[i].status = a->status;
		}
		else p_tempt[i] = p_class[i];
	}
	delete[]p_class;
	p_class = p_tempt;
	write_student_class_data(filename, p_class, n_class);
	delete[]p_class;
	filename = "Data/Class/" + a->classname + "/" + a->id;
	_mkdir(filename.c_str());
	filename += "/info.txt";
	write_student_info(filename, a);
	//delete a;
	return 1;
}

//VIEW LIST OF CLASS

void view_list_class() {
	std::ifstream fi("Data/Class/class.txt");
	if (!fi.is_open()) std::cout << "Can not open class data file " << std::endl;
	else {
		int n;
		class_name* p;
		fi >> n;
		p = new class_name[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].classname;
			fi >> p[i].status;
			if (p[i].status == 0) --i;
		}
		fi.close();
		std::cout << "LIST OF CLASS: " << std::endl;
		for (int i = 0; i < n; ++i) {
			std::cout << p[i].classname << std::endl;
		}
		delete[]p;
	}
}