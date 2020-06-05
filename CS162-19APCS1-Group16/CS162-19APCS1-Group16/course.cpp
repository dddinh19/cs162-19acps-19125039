#include "function.h"
//#include <iostream>

/*void loadLecturerfile(ifstream& fin, lecturer*& all, int& n) {
	char temp1[50];
	fin >> n;
	fin.ignore(1);
	all = new lecturer[n];
	for (int i = 0; i < n; i++) {
		fin.getline(temp1, 50);
		all[i].username = new char[strlen(temp1) + 1];
		strcpy_s(all[i].username, strlen(temp1) + 1, temp1);
		fin.getline(temp1, 50);
		all[i].password = new char[strlen(temp1) + 1];
		strcpy_s(all[i].password, strlen(temp1) + 1, temp1);
		fin.getline(temp1, 50);
		all[i].lecturerName = new char[strlen(temp1) + 1];
		strcpy_s(all[i].lecturerName, strlen(temp1) + 1, temp1);
		fin.getline(temp1, 50);
		all[i].degree = new char[strlen(temp1) + 1];
		strcpy_s(all[i].degree, strlen(temp1) + 1, temp1);
		fin.getline(temp1, 50);
		all[i].gender = new char[strlen(temp1) + 1];
		strcpy_s(all[i].gender, strlen(temp1) + 1, temp1);
		fin.getline(temp1, 50);
		all[i].status = new char[strlen(temp1) + 1];
		strcpy_s(all[i].status, strlen(temp1) + 1, temp1);
	}
}
void inputaCourse(course& c) {
	char temp1[50];
	cout << "Course ID: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.courseID = new char[strlen(temp1) + 1];
	strcpy_s(c.courseID, strlen(temp1) + 1, temp1);
	cout << "Course name: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.courseName = new char[strlen(temp1) + 1];
	strcpy_s(c.courseName, strlen(temp1) + 1, temp1);
	cout << "Class: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.classname = new char[strlen(temp1) + 1];
	strcpy_s(c.classname, strlen(temp1) + 1, temp1);
	cout << "Username of lecturer: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.username = new char[strlen(temp1) + 1];
	strcpy_s(c.username, strlen(temp1) + 1, temp1);
	cout << "Lecturer name: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.lecturerName = new char[strlen(temp1) + 1];
	strcpy_s(c.lecturerName, strlen(temp1) + 1, temp1);
	cout << "Degree: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.degree = new char[strlen(temp1) + 1];
	strcpy_s(c.degree, strlen(temp1) + 1, temp1);
	cout << "Gender (0-Male, 1-Female): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.gender = new char[strlen(temp1) + 1];
	strcpy_s(c.gender, strlen(temp1) + 1, temp1);
	cout << "Start date: " << std::endl;
	cout << "Start year (Format: yyyy, Ex:2018): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.start.year = new char[strlen(temp1) + 1];
	strcpy_s(c.start.year, strlen(temp1) + 1, temp1);
	cout << "Start day (Format: dd, Ex: 04, 22): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.start.day = new char[strlen(temp1) + 1];
	strcpy_s(c.start.day, strlen(temp1) + 1, temp1);
	cout << "Start month (Format: mm, Ex:03, 12): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.start.month = new char[strlen(temp1) + 1];
	strcpy_s(c.start.month, strlen(temp1) + 1, temp1);
	cout << "End date: " << std::endl;
	cout << "End year (Format: yyyy, Ex:2018): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.end.year = new char[strlen(temp1) + 1];
	strcpy_s(c.end.year, strlen(temp1) + 1, temp1);
	cout << "End day (Format: dd, Ex: 04, 22): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.end.day = new char[strlen(temp1) + 1];
	strcpy_s(c.end.day, strlen(temp1) + 1, temp1);
	cout << "End month (Format: mm, Ex:03, 12): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.end.month = new char[strlen(temp1) + 1];
	strcpy_s(c.end.month, strlen(temp1) + 1, temp1);
	cout << "Day of week (Ex: 2 for Monday): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.dayofweek = new char[strlen(temp1) + 1];
	strcpy_s(c.dayofweek, strlen(temp1) + 1, temp1);
	cout << "Time: " << std::endl;
	cout << "Start hour (Ex: 7 or 12): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.startHour = new char[strlen(temp1) + 1];
	strcpy_s(c.startHour, strlen(temp1) + 1, temp1);
	cout << "Start minute (Ex: 9 or 45): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.startMinute = new char[strlen(temp1) + 1];
	strcpy_s(c.startMinute, strlen(temp1) + 1, temp1);
	cout << "End hour (Ex: 7 or 12): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.endHour = new char[strlen(temp1) + 1];
	strcpy_s(c.endHour, strlen(temp1) + 1, temp1);
	cout << "End minute (Ex: 9 or 45): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.endMinute = new char[strlen(temp1) + 1];
	strcpy_s(c.endMinute, strlen(temp1) + 1, temp1);
	cout << "Room: ";
	cin.get(temp1, 50);
	cin.ignore();
	c.room = new char[strlen(temp1) + 1];
	strcpy_s(c.room, strlen(temp1) + 1, temp1);
	cout << "Status (1-Active, 0-Unactive): ";
	cin.get(temp1, 50);
	cin.ignore();
	c.status = new char[strlen(temp1) + 1];
	strcpy_s(c.status, strlen(temp1) + 1, temp1);
}

void saveaCourse(ofstream& fout, course c) {
	fout << c.courseID << std::endl;
	fout << c.courseName << std::endl;
	fout << c.classname << std::endl;
	fout << c.username << std::endl;
	fout << c.lecturerName << std::endl;
	fout << c.degree << std::endl;
	fout << c.gender << std::endl;
	fout << c.start.year << " " << c.start.month << " " << c.start.day << std::endl;
	fout << c.end.year << " " << c.end.month << " " << c.end.day << std::endl;
	fout << c.dayofweek << std::endl;
	fout << c.startHour << std::endl;
	fout << c.startMinute << std::endl;
	fout << c.endHour << std::endl;
	fout << c.endMinute << std::endl;
	fout << c.room << std::endl;
	fout << c.status << std::endl;
}

void saveLecturer(ofstream& fout, lecturer* all, lecturer l, int n) {
	fout << n + 1 << std::endl;
	for (int i = 0; i < n; i++) {
		fout << all[i].username << std::endl;
		fout << all[i].password << std::endl;
		fout << all[i].lecturerName << std::endl;
		fout << all[i].degree << std::endl;
		fout << all[i].gender << std::endl;
		fout << all[i].status << std::endl;
	}
	fout << l.username << std::endl;
	fout << l.password << std::endl;
	fout << l.lecturerName << std::endl;
	fout << l.degree << std::endl;
	fout << l.gender << std::endl;
	fout << l.status << std::endl;
	cout << "Add this new lecturer successfully." << std::endl;
	cout << "This is the lecterer username and password: " << l.username << std::endl;
	cout << "Please remember to inform to this lecturer." << std::endl;
}
void deleteLecturerinMemory(lecturer& l) {
	delete[]l.degree;
	delete[]l.gender;
	delete[]l.lecturerName;
	delete[]l.password;
	delete[]l.status;
	delete[]l.username;

}
void deleteaCourseinMemory(course& c) {
	delete[]c.courseID;
	delete[]c.courseName;
	delete[]c.classname;
	delete[]c.username;
	delete[]c.lecturerName;
	delete[]c.degree;
	delete[]c.gender;
	delete[]c.start.year;
	delete[]c.start.month;
	delete[]c.start.day;
	delete[]c.end.year;
	delete[]c.end.month;
	delete[]c.end.day;
	delete[]c.dayofweek;
	delete[]c.startHour;
	delete[]c.startMinute;
	delete[]c.endHour;
	delete[]c.endMinute;
	delete[]c.room;
	delete[]c.status;
}

void addacourse() {
	int beginningyear;
	string semester;
	string courseID;
	string classofcourse;
	string checkCourseId, checkClass;
	cout << "Please enter the infomation" << endl;
	cout << "(Format: < beginning year> <semester> <courseID> <Class>) : " << endl;
	cin >> beginningyear >> semester >> courseID >> classofcourse;
	ifstream fin;
	fin.open("Data/Courses/" + to_string(beginningyear) + "-" + to_string(beginningyear + 1)+"/"+ to_string(beginningyear) + "-" + to_string(beginningyear + 1) + "-" + semester + ".txt");
	while (fin) {
		getline(fin, checkCourseId);
		if (checkCourseId == courseID) {
			getline(fin, checkCourseId);
			getline(fin, checkClass);
			if (checkClass == classofcourse) {
				cout << "Invalid. Course is exist " << endl;
				return;
			}
		}
	}
	cout << "This course is available to add. " << endl;


}
void addacourse1(academicyear*& a, int& n)
{
	ifstream fin;
	ofstream fout;
	course c;
	char temp1[50];
	char temp[20];
	char tempID[20];
	char tempC[20];
	fin.open("Data/Courses/semester.txt");
	if (!fin.is_open())
	{
		cout << "Can not open file" << std::endl;
		return;
	}
	else {
		loadSMTfile(fin, n, a);
	}
	cout << "Infomation from file semester.txt has been taken to use in this task." << std::endl;
	cout << "Please enter some information of a course you want to add in: " << std::endl;
	cout << "Years: ";
	cin.get(temp1, 50);
	cin.ignore();
	cout << "Semester: ";
	cin.get(temp, 20);
	cin.ignore();
	cout << "Course ID: ";
	cin.get(tempID, 20);
	cin.ignore();
	cout << "Class: ";
	cin.get(tempC, 20);
	cin.ignore();
	int IndexY = -1, IndexS = -1, IndexC = -1; // luu vi tri years va semester (neu co)
	// tim co years va semester khong?
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].year, temp1) == 0 && strcmp(a[i].status, "1") == 0)
			IndexY = i;
		for (int j = 0; j < a[i].numsem; j++) {
			if (strcmp(a[i].sem[j].semName, temp) == 0 && strcmp(a[i].sem[j].status, "1") == 0)
				IndexS = j;
			for (int k = 0; k < a[i].sem[j].numcourse; k++) {
				if (strcmp(a[i].sem[j].cou[k].courseID, tempID) == 0 && strcmp(a[i].sem[j].cou[k].classname, tempC) == 0)
				{
					IndexC = k;
					break;
				}
			}
		}
	}
	if (IndexY == -1 || IndexS == -1)
		cout << "This year/ semester does not exist or is not active anymore." << std::endl;
	else if (IndexY != -1 && IndexS != -1 && IndexC != -1)
		cout << "This course is aldready available. Can not add more!" << std::endl;
	// nhap thong tin couse can them vao va save course vo file semester.txt
	else {
		system("CLS");
		cout << "After checking, this is a new course and you can add it in." << std::endl;
		inputaCourse(c);
		fout.open("Data/Courses/semester.txt");
		if (!fout.is_open())
			cout << "Can not open file." << std::endl;
		else {
			fout << n << std::endl;
			for (int i = 0; i < n; i++) {
				fout << a[i].year << std::endl;
				fout << a[i].numsem << std::endl;
				for (int j = 0; j < a[i].numsem; j++) {
					fout << a[i].sem[j].semName << std::endl;
					if (i == IndexY && j == IndexS)
						fout << a[i].sem[j].numcourse + 1 << std::endl;
					else
						fout << a[i].sem[j].numcourse << std::endl;
					for (int k = 0; k < a[i].sem[j].numcourse; k++) {
						saveaCourse(fout, a[i].sem[j].cou[k]);
					}
					if (i == IndexY && j == IndexS)
						saveaCourse(fout, c);
					fout << a[i].sem[j].status << std::endl;
				}
				fout << a[i].status << std::endl;
			}
		}

		system("CLS");
		cout << "Add a new course successfully!" << std::endl;
		// check new lecturer 
		fout.close();
		lecturer* all = NULL;
		int m = 0;
		bool check = false;
		cout << "This is for checking if the lecturer of this new course is a new member or not. " << std::endl;
		fin.open("Data/Courses/lecturer.txt");
		if (!fin.is_open())
			cout << "Can not open file." << std::endl;
		else {
			loadLecturerfile(fin, all, m);
			fin.close();
		}
		for (int i = 0; i < m; i++) {
			if (strcmp(c.lecturerName, all[i].lecturerName) == 0) {
				check = true;
				break;
			}
		}
		if (check)
			cout << "This lecturer is already a member of our school." << std::endl;
		else {
			cout << "NEW LECTURER. LET'S CELEBRATE AND WELCOME OUR NEW MEMBER!!!" << std::endl;
			lecturer newlec;
			newlec.username = new char[strlen(c.username) + 1];
			strcpy_s(newlec.username, strlen(c.username) + 1, c.username);
			newlec.password = new char[strlen(c.username) + 1];
			strcpy_s(newlec.password, strlen(c.username) + 1, c.username);
			newlec.degree = new char[strlen(c.degree) + 1];
			strcpy_s(newlec.degree, strlen(c.degree) + 1, c.degree);
			newlec.gender = new char[strlen(c.gender) + 1];
			strcpy_s(newlec.gender, strlen(c.gender) + 1, c.gender);
			newlec.lecturerName = new char[strlen(c.lecturerName) + 1];
			strcpy_s(newlec.lecturerName, strlen(c.lecturerName) + 1, c.lecturerName);
			newlec.status = new char[strlen(c.status) + 1];
			strcpy_s(newlec.status, strlen(c.status) + 1, c.status);
			fout.open("Data/Courses/lecturer.txt");
			if (!fout.is_open())
				cout << "Can not open file" << std::endl;
			else {
				saveLecturer(fout, all, newlec, m);
				fout.close();
			}
			deleteLecturerinMemory(newlec);
			for (int i = 0; i < m; i++)
				deleteLecturerinMemory(all[i]);
			delete[]all;
		}
		deleteaCourseinMemory(c);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].numsem; j++)
			for (int k = 0; k < a[i].sem[j].numcourse; k++)
				deleteaCourseinMemory(a[i].sem[j].cou[k]);
		delete[]a[i].sem;
	}
	delete[]a;
	cout << "Delete successfully." << std::endl;
}
*/
void createNewCourse(course x, std::string academicyear, std::string semester) {
	std::string* Student = NULL;
	int n = 0;
	std::string trash;
	std::ifstream in;
	in.open("Data/Class/" + x.classname + ".txt");
	while (in) {
		in >> n;
		Student = new std::string[n];
		for (int i = 0; i < n; i++) {
			getline(in, trash);
			if (trash == "1") {
				getline(in, trash);
				getline(in, Student[i]);
				getline(in, trash);
				getline(in, trash);
				getline(in, trash);
			}
		}
	}
	in.close();
	std::ofstream out;
	out.open("Data/Course/" + academicyear + "/" + x.courseID + "-"+x.classname+"-"+semester + ".txt");
	for (int j = 0; j < n; j++) {
		out << Student[j] << std::endl;
		out << "0 0 0 0" << std::endl;

	}
	out.close();
	delete[]Student;
}

int dayofmonth(dob date) {
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
		return 31;
	else if (date.month == 2) {
		if (date.year % 4 == 0)
		{
			if (date.year % 100 == 0)
			{
				if (date.year % 400 == 0)
					return 29;
				else
					return 28;
			}
			else
				return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}

void saveaDateAttendance(std::ofstream& fout, dob date, course c){
	if (date.day < 10)
		fout << "0" << date.day << " ";
	else
		fout << date.day << " ";
	if (date.month < 10)
		fout << "0" << date.month << " ";
	else
		fout << date.month << " ";
	fout << date.year << std::endl;

}

void DateAttendance(std::ofstream& fout, course c){
	saveaDateAttendance(fout, c.start, c);
	dob tdate = c.start;
	for (int i = 0; i < 9; i++) {
		tdate.day += 7;
		if (tdate.day <= dayofmonth(tdate))
			saveaDateAttendance(fout, tdate, c);
		else {
			tdate.day -= dayofmonth(tdate);
			++tdate.month;
			if (tdate.month > 12)
			{
				tdate.month = 1;
				++tdate.year;
				saveaDateAttendance(fout, tdate, c);
			}
			saveaDateAttendance(fout, tdate, c);
		}
	}
}

//VIEW ACADEMIC YEAR, SEMESTER

void semester_data(semester*& p, int& n) {
	std::string filename = "Data/Courses/semester.txt";
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open semester data file " << std::endl;
	else {
		fi >> n;
		for (int i = 0; i < n; ++i) {
			fi >> p[i].year;
			fi >> p[i].status;
			fi >> p[i].sem1;
			fi >> p[i].status1;
			fi >> p[i].sem2;
			fi >> p[i].status2;
			fi >> p[i].sem3;
			fi >> p[i].status3;
			if (p[i].status == 0) --i;
		}
		fi.close();
	}
}
void view_academic_year(semester* p, int n) {
	std::cout << "LIST OF ACADEMIC YEARS: " << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << p[i].year << std::endl;
	}
}
int view_semester(semester* p, int n, std::string year) {
	int i;
	for (i = 0; i < n; ++i) {
		if (p[i].year == year && p[i].status == 1) {
			std::cout << "LIST OF SEMESTER IN THIS ACADEMIC YEAR: " << std::endl;
			if (p[i].status1 == 1) std::cout << p[i].sem1 << std::endl;
			if (p[i].status2 == 1) std::cout << p[i].sem2 << std::endl;
			if (p[i].status3 == 1) std::cout << p[i].sem3 << std::endl;
			return i;
		}
	}
	if (i == n) std::cout << "Academic year does not exist " << std::endl;
	return -1;
}

//WRITE SEMESTER DATA

void write_semester_data(semester* p, int n) {
	std::string filename = "Data/Courses/semester.txt";
	std::ofstream fo(filename);
	if (!fo.is_open()) std::cout << "Can not open semester data file " << std::endl;
	else {
		fo << n << std::endl;
		for (int i = 0; i < n; ++i) {
			fo << p[i].year << std::endl;
			fo << p[i].status << std::endl;
			fo << p[i].sem1 << std::endl;
			fo << p[i].status1 << std::endl;
			fo << p[i].sem2 << std::endl;
			fo << p[i].status2 << std::endl;
			fo << p[i].sem3 << std::endl;
			fo << p[i].status3 << std::endl;
		}
		fo.close();
	}
}

//CHECK ACADEMIC YEAR, SEMESTER EXISTING OR NOT

bool check_semester(semester* p_year, int n_year, std::string year, std::string sem) {
	semester_data(p_year, n_year);
	for (int i = 0; i < n_year; ++i) {
		if (year == p_year[i].year && ((sem == p_year[i].sem1 && p_year[i].status1 == 1) || (sem == p_year[i].sem2 && p_year[i].status2 == 1) || (sem == p_year[i].sem3 && p_year[i].status3 == 1)))
			return true;
	}
	return false;
}

//VIEW LIST OF COURSE

void course_info_data(std::string filename, course*& a) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Can not open course info data file " << std::endl;
	else {
		a = new course;
		fi >> a->courseID;
		getline(fi, a->courseName);
		getline(fi, a->courseName);
		fi >> a->classname;
		fi >> a->lecturer_couse.username;
		fi >> a->start_day.year >> a->start_day.month >> a->start_day.day;
		fi >> a->end_day.year >> a->end_day.month >> a->end_day.day;
		fi >> a->dayofweek;
		fi >> a->start_time.hour >> a->start_time.minute >> a->end_time.hour >> a->end_time.minute;
		fi >> a->room;
		fi.close();
	}
}
void view_course_info_data(course* a) {
	std::cout << "Course ID: " << a->courseID << std::endl;
	std::cout << "Course name: " << a->courseName << std::endl;
	std::cout << "Class: " << a->classname << std::endl;
	std::cout << "Start date: " << a->start_day.year << "/";
	if (a->start_day.month < 10) std::cout << "0" << a->start_day.month << "/";
	else std::cout << a->start_day.month << "/";
	if (a->start_day.day < 10) std::cout << "0" << a->start_day.day << std::endl;
	else std::cout << a->start_day.day << std::endl;
	std::cout << "End date: " << a->end_day.year << "/";
	if (a->end_day.month < 10) std::cout << "0" << a->end_day.month << "/";
	else std::cout << a->end_day.month << "/";
	if (a->end_day.day < 10) std::cout << "0" << a->end_day.day << std::endl;
	else std::cout << a->end_day.day << std::endl;
	std::cout << "Day of week: " << a->dayofweek << std::endl;
	std::cout << "Start time: " << a->start_time.hour << ":" << a->start_time.minute << std::endl;
	std::cout << "End time: " << a->end_time.hour << ":" << a->end_time.minute << std::endl;
	std::cout << "Room: " << a->room << std::endl;
}
