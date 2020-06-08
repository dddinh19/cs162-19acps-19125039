#include "function.h"

//LECTURER VIEW LIST COURSE

void lecturer_course_data(std::string filename, course*& p, int& n) {
	std::ifstream fi(filename);
	if (!fi.is_open()) 
		std::cout << "Can not open the file or this path doesn't exist." << std::endl;
	else {
		fi >> n;
		p = new course[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].courseID;
			fi >> p[i].classname;
			fi >> p[i].status;
			if (p[i].status == 0)
				--i;
		}
		fi.close();
	}
}
void lecturer_view_list_course(lecturer* p, int k) {
	semester* p_year = nullptr;
	int n_year = 0;
	semester_data(p_year, n_year);
	std::string filename = "Data/Login/lecturer/" + p[k].username + "/" + p_year[n_year - 1].year + "/" + current_sem(p_year, n_year) + "/course.txt";
	course* p_course = nullptr;
	int n_course = 0;
	lecturer_course_data(filename, p_course, n_course);
	for (int i = 0; i < n_course; i++) {
		filename = "Data/Courses/" + p_year[n_year - 1].year + "/" + current_sem(p_year, n_year) + "/" + p_course[i].courseID + "/" + p_course[i].classname + "/info.txt";
		read_course_info(filename, p_course[i]);
	}
	print_course_current_semester_board(p_year[n_year - 1].year, current_sem(p_year, n_year), p_course, n_course);
	delete[]p_year;
	delete[]p_course;
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

void read_student_name1(student& stu) {
	std::ifstream fi("Data/Class/" + stu.classname + "/" + stu.id + "/info.txt");
	if (!fi.is_open())
		std::cout << "Can not open student in course data file " << std::endl;
	else {
		getline(fi, stu.id);
		getline(fi, stu.name);
	}
	fi.close();
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
			read_time_room_dow(sem, year, p_course, n_course);
			system("CLS");
			int choice;
			std::cout << std::setw(72) << "YOUR COURSES IN " << year << " OF " << sem << std::endl;
			print_scheduleboard(sem, year, p_course, n_course);
			do {
				std::cout << "Please enter an attached number of the course you want to view students list: ";
				std::cin >> choice;
				if (choice <= 0 && choice > n_course)
					std::cout << "Invalid choice!!! Please choose again. " << std::endl;
			} while (choice <= 0 && choice > n_course);
			if (check_course(p_course, n_course, p_course[choice-1].courseID, p_course[choice - 1].classname)) {
				student* p_student = nullptr;
				int n_student = 0;
				filename = "Data/Courses/" + year + "/" + sem + "/" + p_course[choice - 1].courseID + "/" + p_course[choice - 1].classname + "/student.txt";
				student_course_data(filename, p_student, n_student);
				for (int i = 0; i < n_student; i++) {
					read_class_of_student(p_student[i]);
					read_student_info_in_class(p_student[i]);
				}
				system("CLS");
				print_student_list_in_course(p_course[choice - 1].courseID, p_course[choice - 1].classname, p_student, n_student);
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
			fi >> a[i].end.hour;
			fi >> a[i].end.minute;
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
			read_time_room_dow(sem, year, p_course, n_course);
			system("CLS");
			int choice;
			std::cout << std::setw(72) << "YOUR COURSES IN " << year << " OF " << sem << std::endl;
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
					std::cout << std::setfill('-');
					std::cout << std::setw(130) << "-" << std::endl;
					std::cout << std::setfill(' ');
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
		fi >> a.total;
		fi >> a.midterm;
		fi >> a.final;
		fi >> a.bonus;
		fi.close();
	}
}
void view_scoreboard(scoreboard a) {
	std::cout << "Total: " << a.total << " Midterm: " << a.midterm << " Final: " << a.final << " Bonus: " << a.bonus << std::endl;
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

//EDIT ATTENDANCE

bool check_student(student* p,int n, std::string student) {
	for (int i = 0; i < n; ++i) {
		if (student == p[i].id) return true;
	}
	return false;
}
int check_date(attendance a[], dob b) {
	for (int i = 0; i < 10; ++i) {
		if (a[i].date.year == b.year && a[i].date.month == b.month && a[i].date.day == b.day) return i;
	}
	return -1;
}
void write_attendance(std::string filename, attendance a[]) {
	std::ofstream fo(filename);
	if (!fo.is_open()) std::cout << "Can not read attendance data file " << std::endl;
	else {
		for (int i = 0; i < 10; ++i) {
			fo << a[i].date.year << " ";
			if (a[i].date.month < 10) fo << "0" << a[i].date.month << " ";
			else fo << a[i].date.month << " ";
			if (a[i].date.day < 10) fo << " 0" << a[i].date.day << std::endl;
			else fo << a[i].date.day << std::endl;
			fo << a[i].start.hour << " " << a[i].start.minute << " " << a[i].end.hour << a[i].end.minute << " " << a[i].checkin.hour << a[i].checkin.minute << std::endl;
		}
		fo.close();
	}
}
void edit_attendance(lecturer* p, int k) {
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
			std::cout << "Enter course ID and class you want to edit attendance " << std::endl;
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
				std::string studentid;
				std::cout << "Enter student id you want to edit attendance" << std::endl;
				std::cin >> studentid;
				if (check_student(p_student, n_student, studentid)) {
					attendance a[10];
					filename = "Data/Courses/" + year + "/" + sem + "/" + courseid + "/" + classname + "/" + studentid + "/attendance.txt";
					read_attendance(filename, a);
					view_attendance(a);
					dob b;
					std::cout << "Enter date you want to edit attendance(year, month, day) " << std::endl;
					std::cin >> b.year >> b.month >> b.day;
					if (check_date(a, b)!=-1) {
						std::cout << "Enter hour and minute " << std::endl;
						std::cin >> a[check_date(a, b)].checkin.hour >> a[check_date(a, b)].checkin.minute;
						write_attendance(filename, a);
					}
					else std::cout << "Date does not exist " << std::endl;
				}
				else std::cout << " Student does not exist " << std::endl;
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
