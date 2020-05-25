#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <fstream>

struct dob {
	char* day, * month, * year;
};
struct student {
	char* id, * pass, * name, * classname, * status;
	dob date;
};
struct lecturer {
	char* username;
	char* password;
	char* lecturerName;
	char* degree;
	char* sex;// 0 male 1 female
	char* status;
};
struct course {
	char* id, * name, * classname, * dayofweek, * room;
	int starthour, startminute, endhour, endminute;
	dob startdate, enddate;
	lecturer lec;
};

void enterinfo(std::ifstream& fi);
void load_data_course(std::ifstream& fi, course*& cou, int& num);
void delete_data_course(course*& cou, int num);

#endif
