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

//CLASS


//COURSE
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

//STAFF
struct staff {
	std::string username;
	std::string pass;
	std::string name;
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



