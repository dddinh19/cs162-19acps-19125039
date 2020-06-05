#include "function.h"

//LECTURER VIEW LIST COURSE

void lecturer_course_data(std::string filename, course*& p, int& n) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Data do not exist" << std::endl;
	else {
		fi >> n;
		p = new course[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].courseID;
			fi >> p[i].classname;
		}
		fi.close();
	}
}
void lecturer_view_list_course(lecturer* p, int k) {
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
			std::string filename = "Data/Login/lecturer/" + p[k].username + "/" + year + "/" + sem + "/course.txt";
			lecturer_course_data(filename, p_course, n_course);
			std::cout << "List of courses for you in " << year << " of " << sem << std::endl;
			for (int i = 0; i < n_course; ++i) {
				course* a = new course;
				filename = "Data/Courses/" + year + "/" + sem + "/" + p_course[i].courseID + "/" + p_course[i].classname + "/info.txt";
				course_info_data(filename,a);
				view_course_info_data(a);
				delete a;
			}
			delete[]p_course;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[]p_year;
}

//VIEW_LIST_STUDENT_COURSE

bool check_course(course* p_course, int n_course, std::string courseid, std::string classname) {
	for (int i = 0; i < n_course; ++i) {
		if (p_course[i].courseID == courseid && p_course[i].classname == classname) return true;
	}
	return false;
}
void student_course_data(std::string filename, student*& p, int& n) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open student in course data file " << std::endl;
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
void read_student_name(std::string id) {
	student* p = 0;
	int n = 0;
	student_data(p, n);
	for (int i = 0; i < n; ++i) {
		if (p[i].id == id) {
			std::string filename = "Data/Class/" + p[i].classname + "/" + id + "/info.txt";
			std::ifstream fi(filename);
			if (!fi.is_open()) std::cout << "Can not open student data file " << std::endl;
			else {
				getline(fi, p[i].name);
				getline(fi, p[i].name);
				std::cout << p[i].name << std::endl;
				fi.close();
			}
			break;
		}
	}
	delete[]p;
}
void lecturer_view_list_student_course(lecturer* p, int k) {
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
			std::string filename = "Data/Login/lecturer/" + p[k].username + "/" + year + "/" + sem + "/course.txt";
			lecturer_course_data(filename, p_course, n_course);
			read_coursename(sem, year, p_course, n_course);
			std::cout << "List of courses for you in " << year << " of " << sem << std::endl;
			for (int i = 0; i < n_course; ++i) {
				std::cout << p_course[i].courseID << ": " << p_course[i].courseName << std::endl;
				std::cout << "Class: " << p_course[i].classname << std::endl;
			}
			std::string courseid, classname;
			std::cout << "Enter course ID and class you want to view student " << std::endl;
			std::cin >> courseid >> classname;
			if (check_course(p_course, n_course, courseid, classname)) {
				student* p_student = nullptr;
				int n_student = 0;
				filename = "Data/Courses/" + year + "/" + sem + "/" + courseid + "/" + classname + "/student.txt";
				student_course_data(filename, p_student, n_student);
				std::cout << "List of student in " << courseid << " of " << classname << std::endl;
				for (int i = 0; i < n_student; ++i) {
					std::cout << p_student[i].id << ": ";
					read_student_name(p_student[i].id);
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

//VIEW LIST ATTENDANCE OF A COURSE

void read_attendance(std::string filename, attendance a[]) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open attendance data file " << std::endl;
	else {
		for (int i = 0; i < 10; ++i) {
			fi >> a[i].date.year;
			fi >> a[i].date.month;
			fi >> a[i].date.day;
			fi >> a[i].start.hour;
			fi >> a[i].start.minute;
			fi >> a[i].checkin.hour;
			fi >> a[i].checkin.minute;
		}
		fi.close();
	}
}
void view_attendance(attendance a[]) {
	for (int i = 0; i < 10; ++i) {
		std::cout << a[i].date.year << "/";
		if (a[i].date.month < 10) std::cout << "0" << a[i].date.month << "/";
		else std::cout << a[i].date.month << "/";
		if (a[i].date.day < 10) std::cout << "0" << a[i].date.day << " " << std::endl;
		else std::cout << a[i].date.day << " " << std::endl;
		std::cout << a[i].start.hour << ":" << a[i].start.minute << " ";
		std::cout << a[i].end.hour << ":" << a[i].end.minute << " ";
		std::cout << a[i].checkin.hour << ":" << a[i].checkin.minute << std::endl;
	}
}
void lecturer_view_list_attendance_course(lecturer* p, int k) {
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
			std::string filename = "Data/Login/lecturer/" + p[k].username + "/" + year + "/" + sem + "/course.txt";
			lecturer_course_data(filename, p_course, n_course);
			read_coursename(sem, year, p_course, n_course);
			std::cout << "List of courses for you in " << year << " of " << sem << std::endl;
			for (int i = 0; i < n_course; ++i) {
				std::cout << p_course[i].courseID << ": " << p_course[i].courseName << std::endl;
				std::cout << "Class: " << p_course[i].classname << std::endl;
			}
			std::string courseid, classname;
			std::cout << "Enter course ID and class you want to view attendance list " << std::endl;
			std::cin >> courseid >> classname;
			if (check_course(p_course, n_course, courseid, classname)) {
				student* p_student = nullptr;
				int n_student = 0;
				filename = "Data/Courses/" + year + "/" + sem + "/" + courseid + "/" + classname + "/student.txt";
				student_course_data(filename, p_student, n_student);
				std::cout << "List of attendance in " << courseid << " of " << classname << std::endl;
				for (int i = 0; i < n_student; ++i) {
					std::cout << p_student[i].id << ": ";
					read_student_name(p_student[i].id);
					filename = "Data/Courses/" + year + "/" + sem + "/" + courseid + "/" + classname + "/" + p_student[i].id + "/attendance.txt";
					read_attendance(filename, p_student[i].list_attend);
					view_attendance(p_student[i].list_attend);
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

//VIEW SCOREBOARD

void read_scoreboard(std::string filename, scoreboard a) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open scoreboard data file " << std::endl;
	else {
		fi >> a.lab;
		fi >> a.midterm;
		fi >> a.final;
		fi >> a.bonus;
		fi.close();
	}
}
void view_scoreboard(scoreboard a) {
	std::cout << "Lab: " << a.lab << " Midterm: " << a.midterm << " Final: " << a.final << " Bonus: " << a.bonus << std::endl;
}
void lecturer_view_scoreboard(lecturer* p, int k) {
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
			std::string filename = "Data/Login/lecturer/" + p[k].username + "/" + year + "/" + sem + "/course.txt";
			lecturer_course_data(filename, p_course, n_course);
			read_coursename(sem, year, p_course, n_course);
			std::cout << "List of courses for you in " << year << " of " << sem << std::endl;
			for (int i = 0; i < n_course; ++i) {
				std::cout << p_course[i].courseID << ": " << p_course[i].courseName << std::endl;
				std::cout << "Class: " << p_course[i].classname << std::endl;
			}
			std::string courseid, classname;
			std::cout << "Enter course ID and class you want to view scoreboard " << std::endl;
			std::cin >> courseid >> classname;
			if (check_course(p_course, n_course, courseid, classname)) {
				student* p_student = nullptr;
				int n_student = 0;
				filename = "Data/Courses/" + year + "/" + sem + "/" + courseid + "/" + classname + "/student.txt";
				student_course_data(filename, p_student, n_student);
				std::cout << "List of attendance in " << courseid << " of " << classname << std::endl;
				for (int i = 0; i < n_student; ++i) {
					std::cout << p_student[i].id << ": ";
					read_student_name(p_student[i].id);
					filename = "Data/Courses/" + year + "/" + sem + "/" + courseid + "/" + classname + "/" + p_student[i].id + "/scoreboard.txt";
					read_scoreboard(filename, p_student[i].score);
					view_scoreboard(p_student[i].score);
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
