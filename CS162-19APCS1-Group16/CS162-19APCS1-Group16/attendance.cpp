#include "function.h"
std::string center_align(std::string str, int width) {
	std::string temp;
	int n = width - (int)strlen(str.c_str());
	if (n % 2 == 0)
		for (int i = 0; i < n; i++) {
			if (i == n / 2 - 1)
				temp += " " + str;
			else
				temp += " ";
		}
	else
		for (int i = 0; i < n; i++) {
			if (i == n / 2 - 1)
				temp += " " + str;
			else
				temp += " ";
		}
	return temp;
}
std::string FormatDate(dob date) {
	std::string temp;
	if (date.month < 10)
	{
		if (date.day < 10)
			temp = std::to_string(date.year) + "/" + "0" + std::to_string(date.month) + "/0" + std::to_string(date.day);
		else
			temp = std::to_string(date.year) + "/" + "0" + std::to_string(date.month) + "/" + std::to_string(date.day);
	}
	else
	{
		if (date.day < 10)
			temp = std::to_string(date.year) + "/" + std::to_string(date.month) + "/0" + std::to_string(date.day);
		else
			temp = std::to_string(date.year) + "/" + std::to_string(date.month) + "/" + std::to_string(date.day);
	}
	return temp;
}
std::string FormatTime(ttime t) {
	std::string temp;
	if (t.hour < 10) {
		if (t.minute < 10)
			temp = "0" + std::to_string(t.hour) + ":0" + std::to_string(t.minute);
		else
			temp= "0" + std::to_string(t.hour) + ":" + std::to_string(t.minute);
	}
	else {
		if (t.minute < 10)
			temp =std::to_string(t.hour) + ":0" + std::to_string(t.minute);
		else
			temp=std::to_string(t.hour) + ":" + std::to_string(t.minute);
	}
	return temp;
}
void printAttendance(attendance* a, std::string stuID, std::string stuName, int k) {
	for (int i = 0; i < 10; i++) {
		if (i == 4) {
			std::cout<<std::setfill(' ');
			k = (k + 1) / 2 + 1;
			std::cout << center_align(std::to_string(k), 8) << "|" << center_align(stuID, 20) << "|" << center_align(stuName, 30) << "|";
		}
		else {
		    std::cout<<std::setfill(' ');
			std::cout<<std::setw(8) <<" " <<"|"<< std::setw(20) <<" "<< "|" << std::setw(30) <<" "<< "|";
		}
		std::cout << std::setw(5) << " " << FormatDate(a[i].date) << std::setw(5) << " " << "|" << std::setw(5) << " " << FormatTime(a[i].start) << std::setw(5) << " " << "|" << std::setw(5) << " " << FormatTime(a[i].end) << std::setw(5) << " " << "|" << std::setw(5) << " " << FormatTime(a[i].checkin) << std::setw(5) << " " << "|" << std::endl;
	}
}
void view_attendance() {
	std::string tyears, tseme, tclassname, tcourseID;
	std::cout << "Please enter some information of the course you want to view the scoreboard: " << std::endl;
	std::cout << "Academic years: ";
	std::cin >> tyears;
	std::cout << "Semester: ";
	std::cin >> tseme;
	std::cout << "Course ID: ";
	std::cin >> tcourseID;
	std::cout << "This course is of the class: ";
	std::cin >> tclassname;
	std::ifstream fin;
	std::string* stu=NULL;
	std::string trash;
	int n;
	fin.open("Data/Courses/" + tyears + "/" + tseme + "/" + tcourseID + "/" + tclassname + "/" + "student.txt");
	if (!fin.is_open())
		std::cout << "Can not open the file." << std::endl;
	else {
		fin >> n;
		fin.ignore(1);
		stu = new std::string[2 * n];
		for (int i = 0; i < 2 * n; i = i + 2) {
			getline(fin, stu[i]);
			getline(fin, trash);
			if (trash == "0")
				--i;
		}
		fin.close();
		for (int i = 0; i < 2 * n; i = i + 2) {
			fin.open("Data/Login/student.txt");
			if (!fin.is_open())
				std::cout << "Can not open the file." << std::endl;
			else {
				getline(fin, trash);
				while (fin) {
					getline(fin, trash);
					if (trash == stu[i])
					{
						getline(fin, trash);
						getline(fin, trash);
						break;
					}
					getline(fin, trash);
					getline(fin, trash);
					getline(fin, trash);
				}
				fin.close();
				fin.open("Data/Class/" + trash + "/" + stu[i] + "/info.txt");
				if (!fin.is_open())
					std::cout << "Can not open file." << std::endl;
				else {
					getline(fin, trash);
					getline(fin, stu[i + 1]);
				}
				fin.close();
			}
		}
		system("CLS");
		std::cout << std::setw(65) << "ATTENDANCE LIST OF " << tcourseID << " IN CLASS " << tclassname << std::endl;
		std::cout << std::setfill('=');
		std::cout << std::setw(130) << "=" << std::endl;
		std::cout << std::setfill(' ');
		// Width of board: No-8, Student ID-20, Student name-30, Date-20, Time-15
		std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|" << std::setw(5) << " " << "Student ID" << std::setw(5) << " " << "|" << std::setw(9) << " " << "Student name" << std::setw(9) << " " << "|";
		std::cout << std::setw(8) <<" "<< "Date"<<std::setw(8)<<" " << "|" << std::setw(2) <<" "<< "Start time"<<std::setw(3)<<" " << "|" << std::setw(3)<<" " << "End time" << std::setw(4)<<" "<< "|" <<" Checkin time  "<<"|"<< std::endl;
		std::cout << std::setfill('-');
		std::cout << std::setw(130) << "-" << std::endl;
		std::cout << std::setfill(' ');
		attendance* a = new attendance[10];
		for (int i = 0; i < 2 * n; i = i + 2) {
			fin.open("Data/Courses/" + tyears + "/" + tseme + "/" + tcourseID + "/" + tclassname + "/" + stu[i] + "/attendance.txt");
			if (!fin.is_open())
				std::cout << "Can not open the file." << std::endl;
			else {
				for (int j = 0; j < 10; j++) {
					fin >> a[j].date.year;
					fin >> a[j].date.month;
					fin >> a[j].date.day;
					fin >> a[j].start.hour;
					fin >> a[j].start.minute;
					fin >> a[j].end.hour;
					fin >> a[j].end.minute;
					fin >> a[j].checkin.hour;
					fin >> a[j].checkin.minute;
				}
				fin.close();
				printAttendance(a, stu[i], stu[i + 1], i);
				std::cout << std::setfill('-');
				std::cout << std::setw(130) << "-" << std::endl;
				std::cout << std::setfill(' ');
			}
		}
		delete[]a;
		delete[]stu;
	}
}