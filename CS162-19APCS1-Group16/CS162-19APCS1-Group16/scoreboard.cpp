#include "function.h"

void view_scoreboard(){
	std::string tyears, tseme, tclassname, tcourseID;
	semester* p_year = NULL;
	int n_year = 0;
	std::cout << "Please enter some information of the course you want to view the scoreboard: " << std::endl;
	std::cout << "Academic years: ";
	std::cin >> tyears;
	std::cout << "Semester: ";
	std::cin >> tseme;
	if (check_semester(p_year, n_year, tyears, tseme))
	{
		std::cout << "Course ID: ";
		std::cin >> tcourseID;
		std::cout << "This course is of the class: ";
		std::cin >> tclassname;
		std::ifstream fin;
		std::string* stu = NULL;
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
			system("CLS");
			std::cout << std::setw(50) << "SCOREBOARD OF " << tcourseID << " IN CLASS " << tclassname << std::endl;
			std::cout << std::setfill('=');
			std::cout << std::setw(105) << "=" << std::endl;
			std::cout << std::setfill(' ');
			std::cout << std::setw(10) << std::left << "No" << "|" << std::setw(20) << std::left << "Student ID" << "|" << std::setw(30) << std::left << "Student name" << "|";
			std::cout << std::setw(10) << std::left << "LAB" << "|" << std::setw(13) << std::left << "MIDTERM" << "|" << std::setw(10) << std::left << "FINAL" << "|" << std::setw(10) << std::left << "BONUS" << std::endl;
			std::cout << std::setfill('-');
			std::cout << std::setw(105) << "-" << std::endl;
			std::cout << std::setfill(' ');
			for (int i = 0; i < 2 * n; i = i + 2) {
				fin.open("Data/Login/student.txt");
				if (!fin.is_open())
					std::cout << "Can not open the file." << std::endl;
				else {
					getline(fin, trash);
					while (fin) {//neu sai thi coi cai nay
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
			int tlab, tmid, tfin, tbon;
			for (int i = 0; i < 2 * n; i = i + 2) {
				fin.open("Data/Courses/" + tyears + "/" + tseme + "/" + tcourseID + "/" + tclassname + "/" + stu[i] + "/scoreboard.txt");
				if (!fin.is_open())
					std::cout << "Can not open the file." << std::endl;
				else {
					fin >> tlab >> tmid >> tfin >> tbon;
					fin.close();
				}
				std::cout << std::setw(10) << std::left << (i + 1) / 2 + 1 << "|" << std::setw(20) << std::left << stu[i] << "|" << std::setw(30) << std::left << stu[i + 1] << "|";
				std::cout << std::setw(10) << std::left << tlab << "|" << std::setw(13) << std::left << tmid << "|" << std::setw(10) << std::left << tfin << "|" << std::setw(10) << std::left << tbon << std::endl;
				std::cout << std::setfill('-');
				std::cout << std::setw(105) << "-" << std::endl;
				std::cout << std::setfill(' ');
			}
		}
		delete[]stu;
	}
	else
		std::cout << "The academic years or the semester of this academic years is no longer existing!!!" << std::endl;
}