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
	std::cout << "Enter student's gender(0: Male, 1: Female) " << std::endl;
	std::cin >> a->gender;
	std::cout << "Enter student's date of birth(year, month, day) " << std::endl;
	std::cin >> a->date.year >> a->date.month >> a->date.day;
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
		fo << a->gender << std::endl;
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
	std::string filename = "Data/Class/" + a->classname + "/" + a->classname + ".txt";
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
		std::cout << "LIST OF CLASSES: " << std::endl;
		for (int i = 0; i < n; ++i) {
			std::cout << "  " << i + 1 << "." << p[i].classname << std::endl;
		}
		delete[]p;
	}
}

//VIEW LIST STUDENT IN CLASS
void student_class_board(student* a) {
	std::cout << center_align(a->id, 20) << "|"; 
	std::cout<< center_align(a->name, 30) << "|";
	if (a->gender == 0) std::cout << "  Male  " << "|";
	else std::cout << " Female " << "|";
	std::cout << std::setw(5) << " " << FormatDate(a->date) << std::setw(5) << " " << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(91) << "-" << std::endl;
	std::cout << std::setfill(' ');
} 

void class_data(class_name*& p, int& n) {
	std::ifstream fi("Data/Class/class.txt");
	if (!fi.is_open()) std::cout << "Can not open class data file " << std::endl;
	else {
		fi >> n;
		p = new class_name[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].classname;
			fi >> p[i].status;
			if (p[i].status == 0) --i;
		}
		fi.close();
	}
}
void view_list_student_in_class(std::string tempt) {
	//view_list_class();
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
			std::cout << std::setw(55) << "LIST OF STUDENTS IN CLASS " << tempt << std::endl;
			std::cout << std::setfill('=');
			std::cout << std::setw(91) << "=" << std::endl;
			std::cout << std::setfill(' ');
			// Width of board: No-8, Student ID-20, Student name-30, Gender-8, DOB-20
			std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
			std::cout << std::setw(5) << " " << "Student ID" << std::setw(5) << " " << "|";
			std::cout << std::setw(9) << " " << "Student name" << std::setw(9) << " " << "|";
			std::cout << " Gender " << "|";
			std::cout << std::setw(3) << " " << "Date of birth" << std::setw(4) << " " << "|" << std::endl;
			std::cout << std::setfill('-');
			std::cout << std::setw(91) << "-" << std::endl;
			std::cout << std::setfill(' ');
			for (int j = 0; j < n; ++j) {
				student* a = nullptr;
				std::string filename = "Data/Class/" + tempt + "/" + p[j].id + "/info.txt";
				student_info_data(filename, a);
				std::cout << center_align(std::to_string(j+1), 8) << "|";
				student_class_board(a);
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
void edit_student_dob(student*& p, int n) {
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
		p[k].pass = std::to_string(a->date.year);
		if (a->date.month < 10) p[k].pass += "0" + std::to_string(a->date.month);
		else p[k].pass += std::to_string(a->date.month);
		if (a->date.day < 10) p[k].pass += "0" + std::to_string(a->date.day);
		else p[k].pass += std::to_string(a->date.day);
		write_student_info(filename, a);
		write_student_data(p, n);
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
		filename = "Data/Class/" + p[k].classname + "/" + p[k].classname + ".txt";
		student_class_data(filename, p_student, n_student);
		for (int i = 0; i < n_student; ++i) {
			if (p_student[i].id == p[k].id) {
				p_student[i].status = 0;
				--n_student;
				break;
			}
		}
		std::ofstream fo(filename);
		if (!fo.is_open()) std::cout << "Can not open student in class data file " << std::endl;
		else {
			fo << n_student << std::endl;
			for (int i = 0; i < n_student + 1; ++i) {
				fo << p_student[i].id << std::endl;
				fo << p_student[i].status << std::endl;
			}
			fo.close();
		}
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
			filename = "Data/Class/" + a->classname + "/" + a->id + "/info.txt";
			write_student_info(filename, a);
			p[k].classname = a->classname;
			write_student_data(p, n);
			filename = "Data/Class/" + p[k].classname + "/" + p[k].classname + ".txt";
			student_class_data(filename, p_student, n_student);
			++n_student;
			student* tempt = new student[n_student];
			for (int i = 0; i < n_student; ++i) {
				if (i == n_student - 1) {
					tempt[i].id = a->id;
					tempt[i].status = 1;
				}
				else {
					tempt[i] = p_student[i];
				}
			}
			delete[]p_student;
			p_student = tempt;
			write_student_class_data(filename, p_student, n_student);
			delete[]p_student;
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
		std::ofstream fo(filename);
		if (!fo.is_open()) std::cout << "Can not open student in class data file " << std::endl;
		else {
			fo << n_student << std::endl;
			for (int i = 0; i < n_student + 1; ++i) {
				fo << p_student[i].id << std::endl;
				fo << p_student[i].status << std::endl;
				}
			fo.close();
		}
		delete[]p_student;
		p[k].status = 0;
		--n;
		fo.open("Data/Login/student.txt");
		if (!fo.is_open()) std::cout << "Can not open student data file " << std::endl;
		else {
			fo << n << std::endl;
			for (int i = 0; i < n + 1; ++i) {
				fo << p[i].id << std::endl;
				fo << p[i].pass << std::endl;
				fo << p[i].classname << std::endl;
				fo << p[i].status << std::endl;
			}
			fo.close();
		}
		std::cout << "Student has been removed successfully !!!" << std::endl;
	}
}
void edit_student(student*& p, int& n) {
	int choice;
	do {
		std::cout << "1. Edit student's name " << std::endl;
		std::cout << "2. Edit student's date of birth " << std::endl;
		std::cout << "3. Change student's class " << std::endl;
		std::cout << "4. Remove a student " << std::endl;
		std::cout << "Enter 0 to exit " << std::endl;
		std::cin >> choice;
		if (choice == 1) edit_student_name(p, n);
		else if (choice == 2) edit_student_dob(p, n);
		else if (choice == 3) change_class(p, n);
		else if (choice == 4) remove_student(p, n);
		else if (choice == 0) break;
	} while (choice != 0);
}

//IMPORT STUDENT

bool check_class(std::string classname) {
	class_name* p_class = nullptr;
	int n_class = 0;
	class_data(p_class, n_class);
	for (int i = 0; i < n_class; ++i) {
		if (p_class[i].classname == classname && p_class[i].status == 1) {
			delete[]p_class;
			return true;
		}	
	}
	delete[]p_class;
	return false;
}
void write_class_data(class_name* p, int n) {
	std::ofstream fo("Data/Class/class.txt");
	if (!fo.is_open()) std::cout << "Can not open class data file " << std::endl;
	else{
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].classname << std::endl;
			fo << p[i].status << std::endl;
		}
		fo.close();
	}
}
void read_student_csv(std::string filename, std::string& classname, student*& p, int& n) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open this file " << std::endl;
	else {
		std::cout << "Enter classname: " << std::endl;
		std::cin >> classname;
		if (!check_class(classname)) {
			class_name* p_class = nullptr;
			int n_class = 0;
			class_data(p_class, n_class);
			++n_class;
			class_name* p_tempt = new class_name[n_class];
			for (int i = 0; i < n_class; ++i) {
				if (i == n_class - 1) {
					p_tempt[i].classname = classname;
					p_tempt[i].status = 1;
				}
				else p_tempt[i] = p_class[i];
			}
			delete[]p_class;
			p_class = p_tempt;
			write_class_data(p_class, n_class);
			std::string filename1 = "Data/Class/" + classname;
			_mkdir(filename1.c_str());
			delete[]p_class;
		}
		int i = 0;
		int num = 10;
		p = new student[num];
		std::string tempt;
		std::string::size_type sz;
		getline(fi, tempt);
		while (!fi.eof()) {
			getline(fi, tempt, ',');
			getline(fi, p[i].id, ',');
			getline(fi, p[i].name, ',');
			getline(fi, tempt, ',');
			if (tempt == "Female") p[i].gender = 1;
			else p[i].gender = 0;
			getline(fi, tempt, '-');
			p[i].date.year = std::stof(tempt, &sz);
			getline(fi, tempt, '-');
			p[i].date.month = std::stof(tempt, &sz);
			getline(fi, tempt);
			p[i].date.day = std::stof(tempt, &sz);
			++n;
			if (i == num - 1) {
				student* tmp = new student[num + 10];
				for (int j = 0; j < num; ++j) {
					tmp[j] = p[j];
				}
				delete[]p;
				p = tmp;
				num += 10;
			}
			++i;
		}
	}
}
void import_student_csv(student*& p_student, int& n_student, std::string classname, student* p, int n) {
	int s = 0;
	for (int i = 0; i < n; ++i) {
		student* a = new student;
		a->id = p[i].id;
		a->classname = classname;
		a->name = p[i].name;
		a->gender = p[i].gender;
		a->date.year = p[i].date.year;
		a->date.month = p[i].date.month;
		a->date.day = p[i].date.day;
		a->pass = std::to_string(p[i].date.year);
		if (p[i].date.month < 10) a->pass += "0" + std::to_string(p[i].date.month);
		else a->pass += std::to_string(p[i].date.month);
		if (p[i].date.day < 10) a->pass += "0" + std::to_string(p[i].date.day);
		else a->pass += std::to_string(p[i].date.day);
		a->status = 1;
		s += add_a_student(p_student, n_student, a);
		delete a;
	}
	std::cout << "Import successfully " << s << " student in class " << classname << std::endl;
	std::cout << "Import fail " << n - s << " student" << std::endl;
}