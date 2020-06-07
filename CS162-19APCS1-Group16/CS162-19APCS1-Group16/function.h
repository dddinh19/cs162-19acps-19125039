#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <direct.h>
#include <sys/stat.h>
#include <ctime>



// STRUCT
//ALLROLE
struct class_name {
	std::string classname;
	int status;
};
//DATE
struct dob {
	int year, day, month;
};

struct ttime {
	int hour, minute;
};
//STAFF
struct staff {
	std::string username;
	std::string pass;
	std::string name;
	int gender;
};
//LECTURER
struct lecturer {
	std::string username;
	std::string password;
	std::string name;
	std::string degree;
	int gender;// 0 male 1 female
};
//SCOREBOARD
struct scoreboard {
	double midterm, lab, final, bonus;
};
//ATTENDANCE
struct attendance {
	dob date;
	ttime start, end, checkin;
};
//COURSE
struct semester {
	std::string year;
	int status;
	std::string sem1, sem2, sem3;
	int status1, status2, status3;
};
struct course {
	std::string courseID;
	std::string courseName;
	std::string classname;
	lecturer lecturer_couse;
	dob start_day, end_day;
	ttime start_time, end_time;
	std::string dayofweek;
	std::string room;
	int status;
};
//STUDENT
struct student {
	std::string id;
	std::string pass;
	std::string name;
	dob date;
	std::string classname;
	attendance list_attend[10];
	scoreboard score;
	int gender;
	int status;
};

//FUNCTION 
//ALLROLE
void student_data(student*& p, int& n);
void staff_data(staff*& p, int& n);
void lecturer_data(lecturer*& p, int& n);
void login(student*& p_student, int& n_student, staff*& p_staff, int& n_staff, lecturer*& p_lecturer, int& n_lecturer, std::string username, std::string pass);

void student_info_data(std::string filename, student*& a);
void view_student_profile(student* p, int k);
void view_staff_profile(staff* p, int k);
void lecturer_info_data(std::string filename, lecturer*& a);
void view_lecturer_profile(lecturer* p, int k);

void write_student_data(student* p, int n);
void change_student_password(student*& p, int n, int k);
void write_staff_data(staff* p, int n);
void change_staff_password(staff*& p, int n, int k);
void write_lecturer_data(lecturer* p, int n);
void change_lecturer_password(lecturer*& p, int n, int k);
//CLASS
void student_class_data(std::string filename, student*& p, int& n);
void write_student_class_data(std::string filename, student* p, int n);
void input_new_student(student*& a);
void write_student_info(std::string filename, student* a);
int add_a_student(student*& p, int& n, student* a);

void view_list_class();
void class_data(class_name*& p, int& n);
void view_list_student_in_class(std::string tempt);

int check_student(student* p, int n);
void edit_student_name(student* p, int n);
void edit_student_dob(student* p, int n);
void change_class(student*& p, int n);
void remove_student(student*& p, int& n);
void edit_student(student*& p, int& n);
//COURSE
void semester_data(semester*& p, int& n);
void view_academic_year(semester* p, int n);
int view_semester(semester* p, int n, std::string year);

void write_semester_data(semester* p, int n);
bool check_semester(semester* p_year, int n_year, std::string year, std::string sem);

void read_coursename(std::string tseme, std::string tyear, course*& sch, int n);
void course_info_data(std::string filename, course*& a);
void view_course_info_data(course* a);
void view_list_student_in_course();

//SCOREBOARD
void view_scoreboard();

//ATTENDANCE
std::string center_align(std::string str, int width);
std::string FormatDate(dob date);
std::string FormatTime(ttime t);
void printAttendance(attendance* a, std::string stuID, std::string stuName, int k);
void view_attendance();

//LECTURER
void lecturer_course_data(std::string filename, course*& p, int& n);
void lecturer_view_list_course(lecturer* p, int k);

bool check_course(course* p_course, int n_course, std::string courseid, std::string classname);
void student_course_data(std::string filename, student*& p, int& n);
void read_student_name(std::string id);
void lecturer_view_list_student_course(lecturer* p, int k);

void read_attendance(std::string filename, attendance a[]);
void view_attendance(attendance a[]);
void lecturer_view_list_attendance_course(lecturer* p, int k);

void read_scoreboard(std::string filename, scoreboard a);
void view_scoreboard(scoreboard a);
void lecturer_view_scoreboard(lecturer* p, int k);

//STUDENT
void read_courses_student(std::string tID, std::string tclass, std::string tseme, std::string tyear, course*& sch, int& n);
void read_studentattendance(std::string tseme, std::string tyear, course cou, std::string tID, attendance*& att);
void write_studentattendance(std::string tseme, std::string tyear, course cou, std::string tID, attendance* att);
void checkin(student stu);
void print_checkinboard(attendance* att, course cou);
void view_checkin(student stu);
void read_time_room_dow(std::string tseme, std::string tyear, course*& sch, int n);
void print_scheduleboard(std::string tseme, std::string tyear, course* sch, int n);
void view_schedule(student stu);
void read_scoreboard(std::string tseme, std::string tyear, course cou, std::string tID, scoreboard& sco);
void view_score(student stu);

#endif



