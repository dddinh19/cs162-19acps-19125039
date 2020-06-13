#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

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

void enterinfo(std::ifstream& fi, std::string& academicyear, std::string& seme);
void load_data_course(std::ifstream& fi, course*& cou, int& num);
void create_allfile_course(std::ifstream& fi, std::ofstream& fo, course*& cou, int& num, std::string& academicyear, std::string& seme);
void create_data_file(std::ifstream& fi, std::ofstream& fo, course*& cou, int num, std::string& academicyear, std::string& seme);
#endif
