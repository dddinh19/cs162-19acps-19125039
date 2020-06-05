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

//VIEW LIST STUDENT IN CLASS

void class_data(class_name*& p, int& n) {
	std::ifstream fi("Data/Class/class.txt");
	if (!fi.is_open()) std::cout << "Can not open class data file " << std::endl;
	else {
		fi >> n;
		p = new class_name[n];
		for (int i = 0; i < n; +i) {
			fi >> p[i].classname;
			fi >> p[i].status;
			if (p[i].status == 0) --i;
		}
		fi.close();
	}
}
void view_list_student_in_class(std::string tempt) {
	view_list_class();
	class_name* p_class = nullptr;
	int num_class = 0;
	class_data(p_class, num_class);
	//std::string tempt;
	//std::cout << "Enter class you want to view student " << std::endl;
	//std::cin >> tempt;
	int i;
	for (i = 0; i < num_class; ++i) {
		if (tempt == p_class[i].classname) {
			std::string filename = "Data/Class/" + tempt + "/" + tempt + ".txt";
			student* p = nullptr;
			int n = 0;
			student_class_data(filename, p, n);
			std::cout << "There are " << n << " students in " << tempt << " class" << std::endl;
			for (int j = 0; j < n; ++j) {
				student* a = nullptr;
				std::string filename = "Data/Class/" + tempt + "/" + p[j].id + "/info.txt";
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
			delete[]p;
			break;
		}
	}
	if (i == num_class) std::cout << "Can not find this class " << std::endl;
	delete[]p_class;
}

//EDIT EXISTING STUDENT

int check_student(student* p, int n) {
	std::string classname;
	std::string id;
	view_list_class();
	std::cout << "Enter student's class " << std::endl;
	std::cin >> classname;
	class_name* p_class = nullptr;
	int n_class = 0;
	class_data(p_class, n_class);
	int i;
	for (i = 0; i < n_class; ++i) {
		if (classname == p_class[i].classname) {
			view_list_student_in_class(classname);
			std::cout << "Enter student's id " << std::endl;
			std::cin >> id;
			break;
		}
	}
	if (i == n_class) std::cout << "Class does not exist " << std::endl;
	else {
		student* p_student = nullptr;
		int n_student = 0;
		std::string filename = "Data/Class/" + classname + "/" + classname + ".txt";
		student_class_data(filename, p_student, n_student);
		int j;
		for (j = 0; j < n_student; ++j) {
			if (id == p_student[j].id) {
				for (int k = 0; k < n; ++k) {
					if (id == p[k].id) return k;
				}
			}
		}
		if (j == n_student) std::cout << "Student does not exist " << std::endl;
		delete[]p_student;
	}
	delete[]p_class;
	return -1;
}
void edit_student_name(student* p, int n) {
	int k = check_student(p, n);
	if (k == -1) return;
	else {
		std::string filename = "Data/Class/" + p[k].classname + "/" + p[k].id + "/info.txt";
		student* a = nullptr;
		student_info_data(filename, a);
		std::cout << "Current name: " << std::endl;
		std::cout << a->name << std::endl;
		std::cout << "Enter new name: " << std::endl;
		getline(std::cin, a->name);
		getline(std::cin, a->name);
		write_student_info(filename, a);
		std::cout << "Student's anme has been changed successfully !!!" << std::endl;
		delete a;
	}
}
void edit_student_dob(student* p, int n) {
	int k = check_student(p, n);
	if (k == -1) return;
	else {
		std::string filename = "Data/Class/" + p[k].classname + "/" + p[k].id + "/info.txt";
		student* a = nullptr;
		student_info_data(filename, a);
		std::cout << "Current date of birth(year/month/day): " << std::endl;
		std::cout << a->date.year << "/" << a->date.month << "/" << a->date.day << std::endl;
		std::cout << "Enter new date of birth(year, month, day): " << std::endl;
		std::cin >> a->date.year >> a->date.month >> a->date.day;
		a->pass = std::to_string(a->date.year);
		if (a->date.month < 10) a->pass += "0" + std::to_string(a->date.month);
		else a->pass += std::to_string(a->date.month);
		if (a->date.day < 10) a->pass += "0" + std::to_string(a->date.day);
		else a->pass += std::to_string(a->date.day);
		write_student_info(filename, a);
		std::cout << "Date of birth has been changed successfully !!!" << std::endl;
		std::cout << "Password has been reset !!!" << std::endl;
		delete a;
	}
}
void change_class(student*& p, int n) {
	int k = check_student(p, n);
	if (k == -1) return;
	else {
		student* a = nullptr;
		std::string filename = "Data/Class/" + p[k].classname + "/" + p[k].id + "/info.txt";
		student_info_data(filename, a);
		student* p_student = nullptr;
		int n_student = 0;
		std::string filename = "Data/Class/" + p[k].classname + "/" + p[k].classname + ".txt";
		student_class_data(filename, p_student, n_student);
		for (int i = 0; i < n_student; ++i) {
			if (p_student[i].id == p[k].id) {
				p_student[i].status = 0;
				--n_student;
				break;
			}
		}
		write_student_class_data(filename, p_student, n_student);
		delete[]p_student;
		std::cout << "Current class: " << std::endl;
		std::cout << p[k].classname << std::endl;
		std::cout << "Enter new class: " << std::endl;
		view_list_class();
		std::cin >> a->classname;
		class_name* p_class;
		int n_class = 0;
		class_data(p_class, n_class);
		int i;
		for (i = 0; i < n_class; ++i) {
			if (a->classname == p_class[i].classname) break;
		}
		if (i == n_class) std::cout << "Class does not exist " << std::endl;
		else {
			filename = "Data/Class/" + a->classname + "/" + a->id;
			_mkdir(filename.c_str());
			filename += "/info.txt";
			write_student_info(filename, a);
			p[k].classname = a->classname;
			write_student_data(p, n);
			std::cout << "Student's class has been changed successfully !!!" << std::endl;
		}
		delete[]p_class;
		delete a;
	}
}
void remove_student(student*& p, int& n) {
	int k = check_student(p, n);
	if (k == -1) return;
	else {
		student* p_student = nullptr;
		int n_student = 0;
		std::string filename = "Data/Class/" + p[k].classname + "/" + p[k].classname + ".txt";
		student_class_data(filename, p_student, n_student);
		for (int i = 0; i < n_student; ++i) {
			if (p_student[i].id == p[k].id) {
				p_student[i].status = 0;
				--n_student;
				break;
			}
		}
		write_student_class_data(filename, p_student, n_student);
		delete[]p_student;
		p[k].status = 0;
		--n;
		write_student_data(p, n);
		std::cout << "Student has been removed successfully !!!" << std::endl;
	}
}
void edit_student(student*& p, int& n) {
	int choice;
	std::cout << "1. Edit student's name " << std::endl;
	std::cout << "2. Edit student's date of birth " << std::endl;
	std::cout << "3. Change student's class " << std::endl;
	std::cout << "4. Remove a student " << std::endl;
	std::cout << "Enter 0 to exit " << std::endl;
	std::cin >> choice;
	while (choice != 0) {
		if (choice == 1) edit_student_name(p, n);
		else if (choice == 2) edit_student_dob(p, n);
		else if (choice == 3) change_class(p, n);
		else if (choice == 4) remove_student(p, n);
		else if (choice == 0) break;
		std::cin >> choice;
	}
}