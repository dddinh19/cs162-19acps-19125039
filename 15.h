#ifndef _15_H_
#define _15_H_

#include <iostream>
#include <fstream>

using namespace std;
struct dob {
	char* year, * day, * month;
};
struct course {
	char* courseID;
	char* courseName;
	char* classname;
	char* username;
	char* lecturerName;
	char* degree;
	char* gender; // 0 male 1 female
	dob start;
	dob end;
	char* dayofweek;
	char* startHour, *startMinute, *endHour, *endMinute;
	char* room;
	char* status;
};
struct academicsem {
	char* semName;
	int numcourse;
	course* cou;
	char* status;
};
struct academicyear {
	char* year;
	int numsem;
	academicsem* sem;
	char* status;
};
void addacourse(academicyear*& a, int& n);
void loadSMTfile(ifstream& fin, int& n, academicyear*& a);
void inputaCourse(course& c);
void saveaCourse(ofstream& fout, course c);
void deleteaCourseinMemory(course& c);

#endif // !_15_H_

