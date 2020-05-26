#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <fstream>
#include <string>



// STRUCT
//ALLROLE

//DATE
struct dob {
	int year, day, month;
};

struct time {
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
//STUDENT
struct student {
	std::string id;
	std::string pass;
	std::string name;
	dob date;
	std::string classname;
	attendance* list_attend;
	scoreboard* score;
	int status;
};

//CLASS

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
	lecturer lecturer_couse;
	dob start_day, end_day;
	time start_time, end_time;
	std::string dayofweek;
	std::string room;
	int status;
};
//SCOREBOARD
struct scoreboard {
	double midterm, lab, final, bonus;
};
//ATTENDANCE
struct attendance {
	dob date;
	time start, end, checkin;
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



