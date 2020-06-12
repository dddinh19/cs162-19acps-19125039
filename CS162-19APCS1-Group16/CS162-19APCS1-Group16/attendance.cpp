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

void export_attendancelist()
{
	std::ofstream fo;
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
		if (check_semester(p_year, n_year, year, sem))
		{
			std::string p_class;
			std::cout << "Enter the class to add this course: ";
			std::cin >> p_class;
			if (check_class(p_class))
			{
				course c; int n;
				std::ifstream fi;
				int num_course = 0;
				fi.open("Data/Courses/" + year + "/" + sem + "/course.txt");
				fi >> num_course;
				course* cou_2 = new course[num_course];
				for (int i = 0; i < num_course; i++)
				{
					fi >> cou_2[i].courseID;
					fi >> cou_2[i].classname;
					fi >> cou_2[i].status;
					if (cou_2[i].status == 0)
						i--;
				}
				fi.close();
				std::cout << "Course ID: ";
				std::cin >> c.courseID;
				if (check_course(cou_2, num_course, c.courseID, p_class)) {
					std::ofstream fo("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/attendance.csv");
					fo << "No,Student ID,Student name,Start hour,Start minute,End hour,End minute";
					fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/student.txt");
					fi >> n;
					student* stu = new student[n];
					for (int i = 0; i < n; i++)
					{
						getline(fi, stu[i].id);
						getline(fi, stu[i].id);
						fi >> stu[i].status;
						if (stu[i].status == 0) i--;
					}
					fi.close();
					attendance* att = new attendance[10];
					int check = 0;
					for (int i = 0; i < n; i++)
					{
						read_class_of_student(stu[i]);
						read_student_name1(stu[i]);
						fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/" + stu[i].id + "/attendance.txt");
						if (check == 0)
						{
							for (int j = 0; j < 10; j++)
							{
								fi >> att[j].date.year >> att[j].date.month >> att[j].date.day;
								fi >> att[j].start.hour >> att[j].start.minute;
								fi >> att[j].end.hour >> att[j].end.minute;
								fi >> att[j].checkin.hour >> att[j].checkin.minute;
								fo << ",";
								fo << att[j].date.year << "-" << att[j].date.month << "-" << att[j].date.day;
							}
							fo << std::endl;
						}
						fo << i + 1 << "," << stu[i].id << "," << stu[i].name << "," << att[0].start.hour << "," << att[0].start.minute << "," << att[0].end.hour << "," << att[0].end.minute;
						for (int j = 0; j < 10; j++)
						{
							fo << ",";
							fo << FormatTime(att[j].checkin);
						}
						fo << std::endl;
						fi.close();
						check = 1;
					}
					delete[]att;
				}
				else
					std::cout << "This course doesn't exist." << std::endl;
				delete[]cou_2;
			}
			else
				std::cout << "This class doesn't exist." << std::endl;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[] p_year;
}

