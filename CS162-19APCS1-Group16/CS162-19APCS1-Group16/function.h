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
	std::string seme1, seme2, seme3;
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
	attendance* list_attend;
	scoreboard* score; // co can dau *?
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
//COURSE

//SCOREBOARD

//ATTENDANCE
std::string center_align(std::string str, int width);
std::string FormatDate(dob date);
std::string FormatTime(ttime t);

//LECTURER


//STUDENT
void checkin(student stu);
void view_checkin(student stu);
void view_schedule(student stu);
void view_score(student stu);

#endif



