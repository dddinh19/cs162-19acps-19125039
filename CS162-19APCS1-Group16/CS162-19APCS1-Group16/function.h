#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// STRUCT
//ALLROLE

//DATE
struct dob {
	int year, day, month;
};

struct time {
	int hour, minute;
};

//CLASS


//COURSE
struct course {
	string courseID;
	string courseName;
	lecturer lecturer_couse;
	attendance attendance_course;
	string dayofweek;
	string room;
	int status;
};
//SCOREBOARD
struct scoreboad {
	double midterm, lab, final, bonus;
};
//ATTENDANCE
struct attendance {
	dob startdate, enddate;
	time start, end, checkin;
};
//LECTURER
struct lecturer {
	string username;
	string password;
	string name;
	string degree;
	int gender;// 0 male 1 female
};

//STUDENT
struct student {
	string id;
	string pass;
	string name;
	dob date;
	string classname;
	int status;
};

//STAFF
struct staff {
	string username;
	string pass;
	string name;
	int gender;
};




//FUNCTION 
//ALLROLE

//CLASS

//COURSE

//SCOREBOARD

//ATTENDANCE

//LECTURER

//STUDENT

#endif



