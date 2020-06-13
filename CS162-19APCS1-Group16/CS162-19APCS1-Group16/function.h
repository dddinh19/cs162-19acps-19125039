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
	float midterm, final, bonus, total;
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
bool check_class(std::string classname);
void edit_student_dob(student*&p, int n);
void change_class(student*& p, int n);
void remove_student(student*& p, int& n);
void edit_student(student*& p, int& n);

bool check_class(std::string classname);
void write_class_data(class_name* p, int n);
void read_student_csv(std::string filename, std::string& classname, student*& p, int& n);
void import_student_csv(student*& p_student, int& n_student, std::string classname, student* p, int n);

//COURSE
void semester_data(semester*& p, int& n);
void view_academic_year(semester* p, int n);
int view_semester(semester* p, int n, std::string year);

void write_semester_data(semester* p, int n);
bool check_semester(semester* p_year, int n_year, std::string year, std::string sem);

void create_year_semester(std::ifstream& fi, std::ofstream& fo);
void update_year_semester(std::ifstream& fi, std::ofstream& fo);
void delete_year_semester(std::ifstream& fi, std::ofstream& fo);
void create_allfile_course(std::ifstream& fi, std::ofstream& fo, course*& cou, int& num, std::string& academicyear, std::string& seme);
void add_a_course();
void add_student();
void edit_course();
void remove_a_student();
void removeacourse();

void course_info_data(std::string filename, course*& a);
void view_course_info_data(course* a);

void read_class_of_student(student& stu);
void read_student_info_in_class(student& stu);
void print_student_list_in_course(std::string tcourseID, std::string tclassname, student* stu, int n);
void view_list_student_in_course();

void read_course_in_semester(std::string filename, course*& cou, int& n);
void read_course_info(std::string filename, course& cou);
void print_course_current_semester_board(std::string tyear, std::string tseme, course* cou, int n);
std::string current_sem(semester* p, int n);
void view_list_course_current_semester();

void read_lecturer_info(lecturer*& lec, int& n);
void print_lecturers(lecturer* lec, int n);
void view_all_lecturers();

//SCOREBOARD
void printScore(scoreboard a, std::string stuID, std::string stuName, int k);
void staff_view_scoreboard();
void export_scoreboard();

//ATTENDANCE
std::string center_align(std::string str, int width);
std::string FormatDate(dob date);
std::string FormatTime(ttime t);
void printAttendance(attendance* a, std::string stuID, std::string stuName, int k);
void view_attendance();
void export_attendancelist();

//LECTURER
void lecturer_course_data(std::string filename, course*& p, int& n);
void lecturer_view_list_course(lecturer* p, int k);

bool check_course(course* p_course, int n_course, std::string courseid, std::string classname);
void student_course_data(std::string filename, student*& p, int& n);
void read_student_name(std::string id);
void read_student_name1(student& stu);
void lecturer_view_list_student_course(lecturer* p, int k);

void read_attendance(std::string filename, attendance a[]);
void view_attendance(attendance a[]);
void lecturer_view_list_attendance_course(lecturer* p, int k);

void read_scoreboard(std::string filename, scoreboard& a);
void view_scoreboard(scoreboard a);
void lecturer_view_scoreboard(lecturer* p, int k);

bool check_student(student* p, int n, std::string student);
int check_date(attendance a[], dob b);
void write_attendance(std::string filename, attendance a[]);
void edit_attendance(lecturer* p, int k);

void write_scoreboard(std::string filename, scoreboard a);
void edit_scoreboard(lecturer* p, int k);

void read_scoreboard_csv(char filename[], lecturer* p, int k, std::string& year, std::string& sem, std::string& courseid, std::string& classname, student*& p_student, int& n_student);
void import_scoreboard_csv(std::string year, std::string sem, std::string courseid, std::string classname, student* p_student, int n_student);

//STUDENT
void read_courses_student(std::string tID, std::string tclass, std::string tseme, std::string tyear, course*& sch, int& n);
void read_coursename(std::string tseme, std::string tyear, course*& sch, int n);;
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

//MENU
void task13();
void staff_class(student*& p_student, int& n_student);
void staff_course();
void staff_scoreboard();
void staff_attendance();
void lecturer_menu(lecturer* p_lecturer, int n_lecturer, int k);
void student_menu(student*& p_student, int n_student, int k);
void staff_menu(student*& p_student, int& n_student, staff*& p_staff, int n_staff, int k);
#endif



