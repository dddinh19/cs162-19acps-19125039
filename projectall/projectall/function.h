#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <fstream>

struct dob {
	char day[10], month[10], year[10];
};
struct student {
	char id[20];
	int status;
	char pass[20], name[50], classname[20];
	dob date;
};

void enterfilename(std::ifstream& fi);
void load_data_student(std::ifstream& fi, student* stu);
#endif
