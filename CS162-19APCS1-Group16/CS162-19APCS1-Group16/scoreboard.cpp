#include "function.h" 
void printScore(scoreboard a, std::string stuID, std::string stuName, int k) {
	std::cout << center_align(std::to_string(k), 8) << "|";
	std::cout << center_align(stuID, 20) << "|";
	std::cout << center_align(stuName, 30) << "|";
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	std::cout << "  "<<a.midterm<<"  " << "|";
	std::cout << "  " << a.final << "  " << "|";
	std::cout << "  " << a.bonus << "  " << "|";
	std::cout << "  " << a.total << "  " << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(97) << "-" << std::endl;
	std::cout << std::setfill(' ');
}
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
			std::cout << std::setw(45) << "SCOREBOARD OF " << tcourseID << " IN CLASS " << tclassname << std::endl;
			std::cout << std::setfill('=');
			std::cout << std::setw(97) << "=" << std::endl;
			std::cout << std::setfill(' ');
			// No-8, Student ID-20, Student name-30, Mark-8
			std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
			std::cout << std::setw(5) << " " << "Student ID" << std::setw(5) << " " << "|";
			std::cout << std::setw(9) << " " << "Student name" << std::setw(9) << " " << "|";
			std::cout << std::setw(2) << " " << "MID" << std::setw(3) << " " << "|";
			std::cout << std::setw(1) << " " << "FINAL" << std::setw(2) << " " << "|";
			std::cout << std::setw(1) << " " << "BONUS" << std::setw(2) << " " << "|";
			std::cout << std::setw(1) << " " << "TOTAL" << std::setw(2) << " " << "|" << std::endl;
			std::cout << std::setfill('-');
			std::cout << std::setw(97) << "-" << std::endl;
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
			scoreboard a;
			for (int i = 0; i < 2 * n; i = i + 2) {
				fin.open("Data/Courses/" + tyears + "/" + tseme + "/" + tcourseID + "/" + tclassname + "/" + stu[i] + "/scoreboard.txt");
				if (!fin.is_open())
					std::cout << "Can not open the file." << std::endl;
				else {
					fin >> a.midterm >> a.final >> a.bonus >> a.total;
					fin.close();
				}
				printScore(a, stu[i], stu[i + 1], (i + 1) / 2 + 1);
			}
		}
		delete[]stu;
	}
	else
		std::cout << "The academic years or the semester of this academic years is no longer existing!!!" << std::endl;
}