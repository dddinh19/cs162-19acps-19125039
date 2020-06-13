#include "function.h"
int main() {
	student* p_student = nullptr;
	int n_student = 0;
	lecturer* p_lecturer = nullptr;
	int n_lecturer = 0;
	staff* p_staff = nullptr;
	int n_staff = 0;
	student_data(p_student, n_student);
	staff_data(p_staff, n_staff);
	lecturer_data(p_lecturer, n_lecturer);
	std::string username, pass;
	std::cout << "Enter username: " << std::endl;
	getline(std::cin, username);
	std::cout << "Enter password: " << std::endl;
	getline(std::cin, pass);
	login(p_student, n_student, p_staff, n_staff, p_lecturer, n_lecturer, username, pass);

	delete[]p_student;
	delete[]p_lecturer;
	delete[]p_staff;
	return 0;
}