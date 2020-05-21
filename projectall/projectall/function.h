#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <fstream>

struct dob {
	char* day, * month, * year;
};
struct student {
	char* id, * pass, * name, * classname, * status;
	dob date;
};

void enterfilename(std::ifstream& fi);
void load_data_student(std::ifstream& fi, student*& stu, int& num);
void delete_data_student(student*& stu, int num);
#endif
