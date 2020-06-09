#include "function.h"
std::string center_align(std::string str, int width) {
	std::string temp;
	int n = width - (int)strlen(str.c_str());
	if (n % 2 == 0)
		for (int i = 0; i < n; i++) {
			if (i == n / 2 - 1)
				temp += " " + str;
			else
				temp += " ";
		}
	else
		for (int i = 0; i < n; i++) {
			if (i == n / 2 - 1)
				temp += " " + str;
			else
				temp += " ";
		}
	return temp;
}
std::string FormatDate(dob date) {
	std::string temp;
	if (date.month < 10)
	{
		if (date.day < 10)
			temp = std::to_string(date.year) + "/" + "0" + std::to_string(date.month) + "/0" + std::to_string(date.day);
		else
			temp = std::to_string(date.year) + "/" + "0" + std::to_string(date.month) + "/" + std::to_string(date.day);
	}
	else
	{
		if (date.day < 10)
			temp = std::to_string(date.year) + "/" + std::to_string(date.month) + "/0" + std::to_string(date.day);
		else
			temp = std::to_string(date.year) + "/" + std::to_string(date.month) + "/" + std::to_string(date.day);
	}
	return temp;
}
std::string FormatTime(ttime t) {
	std::string temp;
	if (t.hour < 10) {
		if (t.minute < 10)
			temp = "0" + std::to_string(t.hour) + ":0" + std::to_string(t.minute);
		else
			temp= "0" + std::to_string(t.hour) + ":" + std::to_string(t.minute);
	}
	else {
		if (t.minute < 10)
			temp =std::to_string(t.hour) + ":0" + std::to_string(t.minute);
		else
			temp=std::to_string(t.hour) + ":" + std::to_string(t.minute);
	}
	return temp;
}
void printAttendance(attendance* a, std::string stuID, std::string stuName, int k) {
	for (int i = 0; i < 10; i++) {
		if (i == 4) {
			std::cout<<std::setfill(' ');
			k = (k + 1) / 2 + 1;
			std::cout << center_align(std::to_string(k), 8) << "|" << center_align(stuID, 20) << "|" << center_align(stuName, 30) << "|";
		}
		else {
		    std::cout<<std::setfill(' ');
			std::cout<<std::setw(8) <<" " <<"|"<< std::setw(20) <<" "<< "|" << std::setw(30) <<" "<< "|";
		}
		std::cout << std::setw(5) << " " << FormatDate(a[i].date) << std::setw(5) << " " << "|" << std::setw(5) << " " << FormatTime(a[i].start) << std::setw(5) << " " << "|" << std::setw(5) << " " << FormatTime(a[i].end) << std::setw(5) << " " << "|" << std::setw(5) << " " << FormatTime(a[i].checkin) << std::setw(5) << " " << "|" << std::endl;
	}
	std::cout << std::setfill('-');
	std::cout << std::setw(130) << "-" << std::endl;
	std::cout << std::setfill(' ');
}
void view_attendance() {
	semester* p_year = nullptr;
	int n_year = 0;
	std::string year, sem;
	semester_data(p_year, n_year);
	view_academic_year(p_year, n_year);
	std::cout << "Enter academic year " << std::endl;
	std::cin >> year;
	if (view_semester(p_year, n_year, year) != -1) {
		std::cout << "Enter semester " << std::endl;
		std::cin >> sem;
		if (check_semester(p_year, n_year, year, sem)) {
			course* p_course;
			int n_course = 0;
			std::string filename = "Data/Courses/" + year + "/" + sem + "/course.txt";
			lecturer_course_data(filename, p_course, n_course);
			read_coursename(sem, year, p_course, n_course);
			read_time_room_dow(sem, year, p_course, n_course);
			system("CLS");
			int choice;
			std::cout << std::setw(75) << "COURSES IN " << year << " OF " << sem << std::endl;
			print_scheduleboard(sem, year, p_course, n_course);
			do {
				std::cout << "Please enter an attached number of the course you want to view students list: ";
				std::cin >> choice;
				if (choice <= 0 && choice > n_course)
					std::cout << "Invalid choice!!! Please choose again. " << std::endl;
			} while (choice <= 0 && choice > n_course);
			if (check_course(p_course, n_course, p_course[choice - 1].courseID, p_course[choice - 1].classname)) {
				student* p_student = nullptr;
				int n_student = 0;
				filename = "Data/Courses/" + year + "/" + sem + "/" + p_course[choice - 1].courseID + "/" + p_course[choice - 1].classname + "/student.txt";
				student_course_data(filename, p_student, n_student);
				system("CLS");
				std::cout << std::setw(65) << "ATTENDANCE LIST OF " << p_course[choice - 1].courseID << " IN CLASS " << p_course[choice - 1].classname << std::endl;
				std::cout << std::setfill('=');
				std::cout << std::setw(130) << "=" << std::endl;
				std::cout << std::setfill(' ');
				// Width of board: No-8, Student ID-20, Student name-30, Date-20, Time-15
				std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
				std::cout << std::setw(5) << " " << "Student ID" << std::setw(5) << " " << "|";
				std::cout << std::setw(9) << " " << "Student name" << std::setw(9) << " " << "|";
				std::cout << std::setw(8) << " " << "Date" << std::setw(8) << " " << "|";
				std::cout << std::setw(2) << " " << "Start time" << std::setw(3) << " " << "|";
				std::cout << std::setw(3) << " " << "End time" << std::setw(4) << " " << "|";
				std::cout << " Checkin time  " << "|" << std::endl;
				std::cout << std::setfill('-');
				std::cout << std::setw(130) << "-" << std::endl;
				std::cout << std::setfill(' ');
				for (int i = 0; i < n_student; i++) {
					read_class_of_student(p_student[i]);
					read_student_name1(p_student[i]);
					filename = "Data/Courses/" + year + "/" + sem + "/" + p_course[choice - 1].courseID + "/" + p_course[choice - 1].classname + "/" + p_student[i].id + "/attendance.txt";
					read_attendance(filename, p_student[i].list_attend);
					printAttendance(p_student[i].list_attend, p_student[i].id, p_student[i].name, i);
				}
				delete[]p_student;
			}
			else std::cout << "Course does not exist " << std::endl;
			delete[]p_course;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[]p_year;
}
