#include "function.h"

bool compare(std::string str1, std::string str2)
{
	if (str1.compare(str2) == 0) return true;
	return false;
}

bool check_openfile(std::ifstream& fi, std::string filename)
{
	fi.open(filename);
	if (!fi) return false; else
	{
		fi.close();
		return true;
	}
}

void create_year_semester(std::ifstream& fi, std::ofstream& fo)
{
	std::string academic_year;
	std::cout << "Please input the academic year you want to create: ";
	getline(std::cin, academic_year);
	std::string seme;
	std::cout << "Please input the semester you want to create: ";
	getline(std::cin, seme);
	fi.open("Data/Course/semester.txt");
	if (!fi)
	{
		std::cout << "Can't open this file! Please enter it again! " << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	int capacity = 10;
	semester* avai_semester = new semester[capacity];
	int num = 0, check_1 = 0, i = 0, check_2 = 0;
	std::string str;
	fi >> num;
	while (!fi.eof())
	{
		getline(fi, avai_semester[i].year);
		getline(fi, avai_semester[i].year);
		fi >> avai_semester[i].status;
		getline(fi, avai_semester[i].sem1);
		getline(fi, avai_semester[i].sem1);
		fi >> avai_semester[i].status1;
		getline(fi, avai_semester[i].sem2);
		getline(fi, avai_semester[i].sem2);
		fi >> avai_semester[i].status2;
		getline(fi, avai_semester[i].sem3);
		getline(fi, avai_semester[i].sem3);
		fi >> avai_semester[i].status3;
		if (compare(avai_semester[i].year, academic_year) && avai_semester[i].status == 1)
		{
			check_2 = 1;
			if ((compare(avai_semester[i].sem1, seme) && avai_semester[i].status1 == 1) || (compare(avai_semester[i].sem2, seme) && avai_semester[i].status2 == 1) || (compare(avai_semester[i].sem3, seme) && avai_semester[i].status3 == 1))
			{
				check_1 = 1;
			}
		}
		if (i == capacity - 1)
		{
			semester* tmp = new semester[capacity + 10];
			for (int j = 0; j <= i; j++)
			{
				tmp[j] = avai_semester[j];
			}
			delete[] avai_semester;
			avai_semester = tmp;
			capacity = capacity + 10;
		}
		i++;
	}
	char check_3;
	if (check_1 == 1)
	{
		std::cout << "The academic year and the semester you want to create have existed!!!" << std::endl;
		std::cout << "Do you want to create again (y for yes and n for no): ";
		std::cin >> check_3;
		if (check_3 == 'y')
		{
			std::cout << "-----------------------------------------------" << std::endl;
			fi.close();
			std::cin.get();
			delete[] avai_semester;
			create_year_semester(fi, fo);
		}
		else
		{
			delete[] avai_semester;
			fi.close();
			return;
		}
	}
	else
	{
		fi.close();
		fo.open("Data/Course/semester.txt");
		if (check_2 == 0) num = num + 1;
		fo << num;
		for (int j = 0; j < i; j++)
		{
			fo << std::endl;
			fo << avai_semester[j].year << std::endl;
			if (compare(avai_semester[j].year, academic_year))
			{
				fo << 1 << std::endl;
				if (avai_semester[j].status == 0)
				{
					str = "Data/Course/" + avai_semester[j].year;
					if (!check_openfile(fi, str))
					{
						const char* str1 = str.c_str();
						_mkdir(str1);
					}
				}
			}
			else fo << avai_semester[j].status << std::endl;
			fo << avai_semester[j].sem1 << std::endl;
			if (compare(avai_semester[j].sem1, seme) && compare(avai_semester[j].year, academic_year))
			{
				fo << 1 << std::endl;
				str = "Data/Course/" + avai_semester[j].year + "/" + seme;
				if (!check_openfile(fi, str))
				{
					const char* str1 = str.c_str();
					_mkdir(str1);
				}
			}
			else fo << avai_semester[j].status1 << std::endl;
			fo << avai_semester[j].sem2 << std::endl;
			if (compare(avai_semester[j].sem2, seme) && compare(avai_semester[j].year, academic_year))
			{
				fo << 1 << std::endl;
				str = "Data/Course/" + avai_semester[j].year + "/" + seme;
				if (!check_openfile(fi, str))
				{
					const char* str1 = str.c_str();
					_mkdir(str1);
				}
			}
			else fo << avai_semester[j].status2 << std::endl;
			fo << avai_semester[j].sem3 << std::endl;
			if (compare(avai_semester[j].sem3, seme) && compare(avai_semester[j].year, academic_year))
			{
				fo << 1;
				str = "Data/Course/" + avai_semester[j].year + "/" + seme;
				if (!check_openfile(fi, str))
				{
					const char* str1 = str.c_str();
					_mkdir(str1);
				}
			}
			else fo << avai_semester[j].status3;
		}
		if (check_2 == 0)
		{
			fo << std::endl;
			fo << academic_year << std::endl;
			fo << 1 << std::endl;
			fo << "HK1" << std::endl;
			if (compare("HK1", seme)) fo << 1 << std::endl; else fo << 0 << std::endl;
			fo << "HK2" << std::endl;
			if (compare("HK2", seme)) fo << 1 << std::endl; else fo << 0 << std::endl;
			fo << "HK3" << std::endl;
			if (compare("HK3", seme)) fo << 1; else fo << 0;
			str = "Data/Course/" + academic_year;
			if (!check_openfile(fi, str))
			{
				const char* str1 = str.c_str();
				_mkdir(str1);
			}
			str = str + "/" + seme;
			if (!check_openfile(fi, str))
			{
				const char* str1 = str.c_str();
				_mkdir(str1);
			}
		}
		fo.close();
		delete[] avai_semester;
		std::cout << "Create successfully!!";
	}
}

void update_year_semester(std::ifstream& fi, std::ofstream& fo)
{
	std::string academic_year, year_alt;
	std::cout << "Please input the academic year you want to update: ";
	getline(std::cin, academic_year);
	std::cout << "Please input the alternative for that academic year: ";
	getline(std::cin, year_alt);
	std::string seme, seme_alt;
	std::cout << "Please input the semester you want to update: ";
	getline(std::cin, seme);
	std::cout << "Please input the alternative for that semester: ";
	getline(std::cin, seme_alt);
	fi.open("Data/Course/semester.txt");
	if (!fi)
	{
		std::cout << "Can't open this file! Please enter it again! " << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	int capacity = 10;
	semester* avai_semester = new semester[capacity];
	int num, check_1 = 0, i = 0, check_2 = 0, check_3 = 0;
	fi >> num;
	while (!fi.eof())
	{
		getline(fi, avai_semester[i].year);
		getline(fi, avai_semester[i].year);
		fi >> avai_semester[i].status;
		getline(fi, avai_semester[i].sem1);
		getline(fi, avai_semester[i].sem1);
		fi >> avai_semester[i].status1;
		getline(fi, avai_semester[i].sem2);
		getline(fi, avai_semester[i].sem2);
		fi >> avai_semester[i].status2;
		getline(fi, avai_semester[i].sem3);
		getline(fi, avai_semester[i].sem3);
		fi >> avai_semester[i].status3;
		if (i == capacity - 1)
		{
			semester* tmp = new semester[capacity + 10];
			for (int j = 0; j <= i; j++)
			{
				tmp[j] = avai_semester[j];
			}
			delete[] avai_semester;
			avai_semester = tmp;
			capacity = capacity + 10;
		}
		i++;
	}
	fi.close();
	fo.open("Data/Course/semester.txt");
	fo << num;
	for (int j = 0; j < i; j++)
	{
		fo << std::endl;
		if (avai_semester[j].year == academic_year)
		{
			fo << year_alt << std::endl;
			check_1 = 1;
			check_2 = 1;
		}
		else fo << avai_semester[j].year << std::endl;
		fo << avai_semester[j].status << std::endl;
		if ((avai_semester[j].sem1 == seme) && (check_1 == 1) && (avai_semester[j].status1 == 1))
		{
			fo << seme_alt << std::endl;
			check_3 = 1;
		}
		else fo << avai_semester[j].sem1 << std::endl;
		fo << avai_semester[j].status1 << std::endl;
		if ((avai_semester[j].sem2 == seme) && (check_1 == 1) && (avai_semester[j].status2 == 1))
		{
			fo << seme_alt << std::endl;
			check_3 = 1;
		}
		else fo << avai_semester[j].sem2 << std::endl;
		fo << avai_semester[j].status2 << std::endl;
		if ((avai_semester[j].sem3 == seme) && (check_1 == 1) && (avai_semester[j].status3 == 1))
		{
			fo << seme_alt << std::endl;
			check_3 = 1;
		}
		else fo << avai_semester[j].sem3 << std::endl;
		fo << avai_semester[j].status3;
		check_1 = 0;
	}
	char check_4;
	fo.close();
	if ((check_2 == 0) || (check_3 == 0))
	{
		fo.open("Data/Course/semester.txt");
		fo << num;
		for (int j = 0; j < i; j++)
		{
			fo << std::endl;
			fo << avai_semester[j].year << std::endl;
			fo << avai_semester[j].status << std::endl;
			fo << avai_semester[j].sem1 << std::endl;
			fo << avai_semester[j].status1 << std::endl;
			fo << avai_semester[j].sem2 << std::endl;
			fo << avai_semester[j].status2 << std::endl;
			fo << avai_semester[j].sem3 << std::endl;
			fo << avai_semester[j].status3;
		}
		std::cout << "The academic year and the semester you want to update haven't existed!!!" << std::endl;
		std::cout << "Do you want to update again (y for yes and n for no): ";
		std::cin >> check_4;
		if (check_4 == 'y')
		{
			std::cout << "-----------------------------------------------" << std::endl;
			fo.close();
			std::cin.get();
			delete[] avai_semester;
			update_year_semester(fi, fo);
		}
		else
		{
			fo.close();
			delete[] avai_semester;
			return;
		}
	}
	else
	{
		delete[] avai_semester;
		std::cout << "Update successfully!!!" << std::endl;
	}
}

void delete_year_semester(std::ifstream& fi, std::ofstream& fo)
{
	std::string academic_year, seme;
	std::cout << "Please input the academic year: ";
	getline(std::cin, academic_year);
	int check_1;
	std::cout << "You want to delete the whole academic year(press 1) or just one semester in that academic year(press 2)? ";
	std::cin >> check_1;
	fi.open("Data/Course/semester.txt");
	if (!fi)
	{
		std::cout << "Can't open this file! Please enter it again! " << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	int capacity = 10;
	semester* avai_semester = new semester[capacity];
	int num, i = 0, check_2 = 0, check_3 = 0;
	fi >> num;
	while (!fi.eof())
	{
		getline(fi, avai_semester[i].year);
		getline(fi, avai_semester[i].year);
		fi >> avai_semester[i].status;
		getline(fi, avai_semester[i].sem1);
		getline(fi, avai_semester[i].sem1);
		fi >> avai_semester[i].status1;
		getline(fi, avai_semester[i].sem2);
		getline(fi, avai_semester[i].sem2);
		fi >> avai_semester[i].status2;
		getline(fi, avai_semester[i].sem3);
		getline(fi, avai_semester[i].sem3);
		fi >> avai_semester[i].status3;
		if (i == capacity - 1)
		{
			semester* tmp = new semester[capacity + 10];
			for (int j = 0; j <= i; j++)
			{
				tmp[j] = avai_semester[j];
			}
			delete[] avai_semester;
			avai_semester = tmp;
			capacity = capacity + 10;
		}
		i++;
	}
	char check_4;
	fi.close();
	fo.open("Data/Course/semester.txt");
	if (check_1 == 1)
	{
		num = num - 1;
		fo << num;
		for (int j = 0; j < i; j++)
		{
			fo << std::endl;
			fo << avai_semester[j].year << std::endl;
			if (compare(avai_semester[j].year, academic_year))
			{
				fo << 0 << std::endl;
				check_2 = 1;
			}
			else fo << avai_semester[j].status << std::endl;
			fo << avai_semester[j].sem1 << std::endl;
			fo << avai_semester[j].status1 << std::endl;
			fo << avai_semester[j].sem2 << std::endl;
			fo << avai_semester[j].status2 << std::endl;
			fo << avai_semester[j].sem3 << std::endl;
			fo << avai_semester[j].status3;
		}
		if (check_2 == 0)
		{
			fo.close();
			fo.open("Data/Course/semester.txt");
			std::cout << "The academic year you want to delete haven't existed yet!!" << std::endl;
			num = num + 1;
			fo << num;
			for (int j = 0; j < i; j++)
			{
				fo << std::endl;
				fo << avai_semester[j].year << std::endl;
				fo << avai_semester[j].status << std::endl;
				fo << avai_semester[j].sem1 << std::endl;
				fo << avai_semester[j].status1 << std::endl;
				fo << avai_semester[j].sem2 << std::endl;
				fo << avai_semester[j].status2 << std::endl;
				fo << avai_semester[j].sem3 << std::endl;
				fo << avai_semester[j].status3;
			}
			fo.close();
			std::cout << "Do you want to delete again (y for yes and n for no): ";
			std::cin >> check_4;
			if (check_4 == 'y')
			{
				std::cout << "-----------------------------------------------" << std::endl;
				fo.close();
				std::cin.get();
				delete[] avai_semester;
				delete_year_semester(fi, fo);
			}
			else
			{
				fo.close();
				delete[] avai_semester;
				return;
			}
		}
		else
		{
			delete[] avai_semester;
			std::cout << "Delete successfully!!!" << std::endl;
		}
	}
	if (check_1 == 2)
	{
		std::cout << "The semester you want to delete in that academic year: ";
		std::cin >> seme;
		fo << num;
		for (int j = 0; j < i; j++)
		{
			fo << std::endl;
			fo << avai_semester[j].year << std::endl;
			if ((avai_semester[j].year == academic_year) && (avai_semester[j].status == 1))
			{
				check_2 = 1;
			}
			fo << avai_semester[j].status << std::endl;
			fo << avai_semester[j].sem1 << std::endl;
			if ((avai_semester[j].sem1 == seme) && (check_2 == 1) && (avai_semester[j].status1 == 1))
			{
				check_3 = 1;
				fo << 0 << std::endl;
			}
			else fo << avai_semester[j].status1 << std::endl;
			fo << avai_semester[j].sem2 << std::endl;
			if ((avai_semester[j].sem2 == seme) && (check_2 == 1) && (avai_semester[j].status2 == 1))
			{
				check_3 = 1;
				fo << 0 << std::endl;
			}
			else fo << avai_semester[j].status2 << std::endl;
			fo << avai_semester[j].sem3 << std::endl;
			if ((avai_semester[j].sem3 == seme) && (check_2 == 1) && (avai_semester[j].status3 == 1))
			{
				check_3 = 1;
				fo << 0;
			}
			else fo << avai_semester[j].status3;
		}
		fo.close();
		if ((check_2 == 0) || (check_3 == 0))
		{
			fo.open("Data/Course/semester.txt");
			fo << num;
			for (int j = 0; j < i; j++)
			{
				fo << std::endl;
				fo << avai_semester[j].year << std::endl;
				fo << avai_semester[j].status << std::endl;
				fo << avai_semester[j].sem1 << std::endl;
				fo << avai_semester[j].status1 << std::endl;
				fo << avai_semester[j].sem2 << std::endl;
				fo << avai_semester[j].status2 << std::endl;
				fo << avai_semester[j].sem3 << std::endl;
				fo << avai_semester[j].status3;
			}
			std::cout << "The academic year and the semester you want to delete haven't existed!!!" << std::endl;
			std::cout << "Do you want to update again (y for yes and n for no): ";
			std::cin >> check_4;
			if (check_4 == 'y')
			{
				std::cout << "-----------------------------------------------" << std::endl;
				fo.close();
				std::cin.get();
				delete[] avai_semester;
				delete_year_semester(fi, fo);
			}
			else
			{
				fo.close();
				delete[] avai_semester;
				return;
			}
		}
		else
		{
			delete[] avai_semester;
			std::cout << "Delete successfully!!!" << std::endl;
		}
	}
}

int covert_number(std::string str)
{
	int n = 0;
	for (int i = 0; i < str.length(); i++)
		n = (str[i] - '0') + n * 10;
	return n;
}

void enterinfo(std::ifstream& fi)
{
	std::string academicyear, semester, classname;
	char filename[100];
	std::cout << "Please enter academic year: ";
	std::cin >> academicyear;
	std::cout << "Please enter semester: ";
	std::cin >> semester;
	int check;
	do
	{
		std::cout << "Please enter filename: ";
		std::cin >> filename;
		std::cin.get();
		fi.open(filename);
		if (!fi)
		{
			std::cout << "Can't open this file! Please enter it again! " << std::endl;
			std::cout << "--------------------------" << std::endl;
			check = 0;
		}
		else check = 1;
	} while (check == 0);
}

void load_data_course(std::ifstream& fi, course*& cou, int& num)
{
	std::string ch;
	getline(fi, ch);
	int capacity = 10;
	cou = new course[capacity];
	while (!fi.eof())
	{
		getline(fi, ch, ',');
		if (size(ch) == 0) break;
		num = covert_number(ch);
		getline(fi, cou[num - 1].courseID, ',');
		getline(fi, cou[num - 1].courseName, ',');
		getline(fi, cou[num - 1].classname, ',');
		getline(fi, cou[num - 1].lecturer_couse.username, ',');
		getline(fi, cou[num - 1].lecturer_couse.name, ',');
		getline(fi, cou[num - 1].lecturer_couse.degree, ',');
		getline(fi, ch, ',');
		if (ch == "Male") cou[num - 1].lecturer_couse.gender = 0;
		else cou[num - 1].lecturer_couse.gender = 1;
		getline(fi, ch, '-');
		cou[num - 1].start_day.year = covert_number(ch);
		getline(fi, ch, '-');
		cou[num - 1].start_day.month = covert_number(ch);
		getline(fi, ch, ',');
		cou[num - 1].start_day.day = covert_number(ch);
		getline(fi, ch, '-');
		cou[num - 1].end_day.year = covert_number(ch);
		getline(fi, ch, '-');
		cou[num - 1].end_day.month = covert_number(ch);
		getline(fi, ch, ',');
		cou[num - 1].end_day.day = covert_number(ch);
		getline(fi, cou[num - 1].dayofweek, ',');
		getline(fi, ch, ',');
		cou[num - 1].start_time.hour = covert_number(ch);
		getline(fi, ch, ',');
		cou[num - 1].start_time.minute = covert_number(ch);
		getline(fi, ch, ',');
		cou[num - 1].end_time.hour = covert_number(ch);
		getline(fi, ch, ',');
		cou[num - 1].end_time.minute = covert_number(ch);
		getline(fi, cou[num - 1].room);
		if (num == capacity)
		{
			course* tmpcou = new course[capacity + 10];
			for (int i = 0; i <= num; i++)
			{
				tmpcou[i] = cou[i];
			}
			delete[] cou;
			cou = tmpcou;
			capacity = capacity + 10;
		}
	}
	fi.close();
}


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
	cout << "Please enter the infomation" << std::endl;
	cout << "(Format: < beginning year> <semester> <courseID> <Class>) : " << std::endl;
	cin >> beginningyear >> semester >> courseID >> classofcourse;
	ifstream fin;
	fin.open("Data/Courses/" + to_string(beginningyear) + "-" + to_string(beginningyear + 1)+"/"+ to_string(beginningyear) + "-" + to_string(beginningyear + 1) + "-" + semester + ".txt");
	while (fin) {
		getline(fin, checkCourseId);
		if (checkCourseId == courseID) {
			getline(fin, checkCourseId);
			getline(fin, checkClass);
			if (checkClass == classofcourse) {
				cout << "Invalid. Course is exist " << std::endl;
				return;
			}
		}
	}
	cout << "This course is available to add. " << std::endl;


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
	saveaDateAttendance(fout, c.start_day, c);
	dob tdate = c.start_day;
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
		p = new semester[n];
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
	/*std::cout << "Course ID: " << a->courseID << std::endl;
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
	std::cout << "Room: " << a->room << std::endl;*/
	std::cout << center_align(a->courseID, 15) << "|";
	std::cout << center_align(a->courseName, 50) << "|";
	std::cout << center_align(a->classname, 15) << "|";
	std::cout << center_align(a->lecturer_couse.username, 17) << "|";
	std::cout << center_align(a->dayofweek, 11) << "|";
	std::cout << std::setw(5) << " " << FormatDate(a->start_day) << std::setw(5) << " " << "|";
	std::cout << std::setw(5) << " " << FormatDate(a->end_day) << std::setw(5) << " " << "|";
	std::cout << std::setw(5) << " " << FormatTime(a->start_time) << std::setw(5) << " " << "|";
	std::cout << std::setw(5) << " " << FormatTime(a->end_time) << std::setw(5) << " " << "|";
	std::cout << center_align(a->room, 10) << "|" << std::endl;
}

void read_class_of_student(student& stu) {
	std::ifstream fin;
	std::string trash;
	fin.open("Data/Login/student.txt");
	if (!fin.is_open())
		std::cout << "Can not open the file." << std::endl;
	else
	{
		getline(fin, trash);
		while (fin) {
			getline(fin, trash);
			if (trash == stu.id)
			{
				getline(fin, trash);
				getline(fin, stu.classname);
				break;
			}
			else
			{
				getline(fin, trash);
				getline(fin, trash);
				getline(fin, trash);
			}
		}
		fin.close();
	}
}

void read_student_info_in_class(student& stu) {
	std::ifstream fin;
	fin.open("Data/Class/" + stu.classname + "/" + stu.id + "/info.txt");
	if (!fin.is_open())
		std::cout << "Can not open file." << std::endl;
	else {
		getline(fin, stu.id);
		getline(fin, stu.name);
		fin >> stu.gender;
		fin >> stu.date.year;
		fin >> stu.date.month;
		fin >> stu.date.day;
		fin.ignore(1);
		getline(fin, stu.classname);
	}
}

void print_student_list_in_course(std::string tcourseID, std::string tclassname, student* stu, int n) {
	std::cout << std::setw(50) << "STUDENTS LIST OF " << tcourseID << " OF CLASS " << tclassname << std::endl;
	std::cout << std::setfill('=');
	std::cout << std::setw(102) << "=" << std::endl;
	std::cout << std::setfill(' ');
	// Width of board: No-8, Student ID-20, Student name-30, Class-10, Gender-8, DOB-20
	std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
	std::cout << std::setw(5) << " " << "Student ID" << std::setw(5) << " " << "|";
	std::cout << std::setw(9) << " " << "Student name" << std::setw(9) << " " << "|";
	std::cout << std::setw(2) << " " << "Class" << std::setw(3) << " " << "|";
	std::cout << " Gender " << "|";
	std::cout << std::setw(3) << " " << "Date of birth" << std::setw(4) << " " << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(102) << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < n; i++) {
		std::cout << center_align(std::to_string(i + 1), 8) << "|";
		std::cout << center_align(stu[i].id, 20) << "|";
		std::cout << center_align(stu[i].name, 30) << "|";
		std::cout << center_align(stu[i].classname, 10) << "|";
		if (stu[i].gender == 0) std::cout << "  Male  " << "|";
		else std::cout << " Female " << "|";
		std::cout << std::setw(5) << " " << FormatDate(stu[i].date) << std::setw(5) << " " << "|" << std::endl;
		std::cout << std::setfill('-');
		std::cout << std::setw(102) << "-" << std::endl;
		std::cout << std::setfill(' ');
	}
}

void view_list_student_in_course() {
	std::string tyears, tseme, tclassname, tcourseID;
	semester* p_year = NULL;
	int n_year = 0;
	std::cout << "Please enter some information of the course you want to view the students list: " << std::endl;
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
		student* stu = NULL;
		std::string trash;
		int n;
		fin.open("Data/Courses/" + tyears + "/" + tseme + "/" + tcourseID + "/" + tclassname + "/" + "student.txt");
		if (!fin.is_open())
			std::cout << "Can not open the file." << std::endl;
		else {
			fin >> n;
			fin.ignore(1);
			stu = new student[n];
			for (int i = 0; i < n; i++) {
				getline(fin, stu[i].id);
				fin >> stu[i].status;
				getline(fin, trash);
				if (stu[i].status == 0)
					--i;
			}
			fin.close();
			for (int i = 0; i < n; i++) {
				read_class_of_student(stu[i]);
				read_student_info_in_class(stu[i]);
			}
			system("CLS");
			print_student_list_in_course(tcourseID, tclassname, stu, n);
			delete[]stu;
		}
		delete[]p_year;
	}
	else
		std::cout << "The academic years or the semester of this academic years is no longer existing!!!" << std::endl;
}

void read_course_in_semester(std::string filename, course*& cou, int& n) {
	std::ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
		std::cout << "Can not open file." << std::endl;
	else {
		fin >> n;
		fin.ignore(1);
		cou = new course[n];
		for (int i = 0; i < n; i++) {
			getline(fin, cou[i].courseID);
			getline(fin, cou[i].classname);
			fin >> cou[i].status;
			fin.ignore(1);
			if (cou[i].status == 0)
				--i;
		}
		fin.close();
	}
}

void read_course_info(std::string filename, course& cou) {
	std::ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
		std::cout << "Can not open file." << std::endl;
	else {
		fin >> cou.courseID;
		getline(fin, cou.courseName);
		getline(fin, cou.courseName);
		fin >> cou.classname;
		fin >> cou.lecturer_couse.username;
		fin >> cou.start_day.year >> cou.start_day.month >> cou.start_day.day;
		fin >> cou.end_day.year >> cou.end_day.month >> cou.end_day.day;
		fin >> cou.dayofweek;
		fin >> cou.start_time.hour >> cou.start_time.minute >> cou.end_time.hour >> cou.end_time.minute;
		fin >> cou.room;
		fin.close();
	}
}

void print_course_current_semester_board(std::string tyear, std::string tseme, course* cou, int n) {
	std::cout << std::setw(110) << "LIST OF COURSES IN " << tyear << " OF " << tseme << std::endl;
	std::cout << std::setfill('=');
	std::cout << std::setw(207) << "=" << std::endl;
	std::cout << std::setfill(' ');
	// Width of board: No-8, Coruse ID-15, Course name-50, Course of class- 15,Lecturer username-17, Day of week-11, Date-20, Time-15, Room-10
	std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
	std::cout << std::setw(3) << " " << "Course ID" << std::setw(3) << " " << "|";
	std::cout << std::setw(19) << " " << "Course name" << std::setw(20) << " " << "|";
	std::cout << "Course of class" << "|";
	std::cout << "Lecturer username" << "|";
	std::cout << "Day of week" << "|";
	std::cout << std::setw(5) << " " << "Start date" << std::setw(5) << " " << "|";
	std::cout << std::setw(6) << " " << "End date" << std::setw(6) << " " << "|";
	std::cout << std::setw(2) << " " << "Start time" << std::setw(3) << " " << "|";
	std::cout << std::setw(3) << " " << "End time" << std::setw(4) << " " << "|";
	std::cout << std::setw(3) << " " << "Room" << std::setw(3) << " " << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(207) << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < n; i++) {
		std::cout << center_align(std::to_string(i + 1), 8) << "|";
		std::cout << center_align(cou[i].courseID, 15) << "|";
		std::cout << center_align(cou[i].courseName, 50) << "|";
		std::cout << center_align(cou[i].classname, 15) << "|";
		std::cout << center_align(cou[i].lecturer_couse.username, 17) << "|";
		std::cout << center_align(cou[i].dayofweek, 11) << "|";
		std::cout << std::setw(5) << " " << FormatDate(cou[i].start_day) << std::setw(5) << " " << "|";
		std::cout << std::setw(5) << " " << FormatDate(cou[i].end_day) << std::setw(5) << " " << "|";
		std::cout << std::setw(5) << " " << FormatTime(cou[i].start_time) << std::setw(5) << " " << "|";
		std::cout << std::setw(5) << " " << FormatTime(cou[i].end_time) << std::setw(5) << " " << "|";
		std::cout << center_align(cou[i].room, 10) << "|" << std::endl;
		std::cout << std::setfill('-');
		std::cout << std::setw(207) << "-" << std::endl;
		std::cout << std::setfill(' ');
	}
}

std::string current_sem(semester* p, int n) {
	if (p[n - 1].status3 == 1) return p[n - 1].sem3;
	if (p[n - 1].status2 == 1) return p[n - 1].sem2;
	if (p[n - 1].status1 == 1) return p[n - 1].sem1;
}
void view_list_course_current_semester() {
	semester* p = nullptr;
	int n = 0;
	semester_data(p, n);
	std::string filename = "Data/Courses/" + p[n - 1].year + "/" + current_sem(p, n) + "/course.txt";
	course* p_course = nullptr;
	int n_course = 0;
	read_course_in_semester(filename, p_course, n_course);
	for (int i = 0; i < n_course; i++) {
		filename = "Data/Courses/" + p[n - 1].year + "/" + current_sem(p, n) + "/" + p_course[i].courseID + "/" + p_course[i].classname + "/info.txt";
		read_course_info(filename, p_course[i]);
	}
	print_course_current_semester_board(p[n - 1].year, current_sem(p, n), p_course, n_course);
	delete[]p;
	delete[]p_course;
}

void read_lecturer_info(lecturer*& lec, int& n) {
	std::ifstream fin;
	fin.open("Data/Login/lecturer.txt");//take username and password
	if (!fin.is_open())
		std::cout << "Can not open file." << std::endl;
	else {
		fin >> n;
		lec = new lecturer[n];
		for (int i = 0; i < n; i++) {
			fin >> lec[i].username;
			fin >> lec[i].password;
		}
		fin.close();
	}
	for (int i = 0; i < n; i++) {
		fin.open("Data/Login/lecturer/" + lec[i].username + "/info.txt");//other info
		if (!fin.is_open())
			std::cout << "Can not open file." << std::endl;
		else {
			getline(fin, lec[i].name);
			getline(fin, lec[i].degree);
			fin >> lec[i].gender;
		}
		fin.close();
	}
}

void print_lecturers(lecturer* lec, int n) {
	std::cout << std::setw(63) << "LIST OF LECTURERS " << std::endl;
	std::cout << std::setfill('=');
	std::cout << std::setw(102) << "=" << std::endl;
	std::cout << std::setfill(' ');
	// Width of board: No-8, Lecturer name-30, Lecturer username-20, Lecturer password- 20, Degree-10, Gender-8
	std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
	std::cout << std::setw(8) << " " << "Lecturer name" << std::setw(9) << " " << "|";
	std::cout << std::setw(1) << " " << "Lecturer username" << std::setw(2) << " " << "|";
	std::cout << std::setw(1) << " " << "Lecturer password" << std::setw(2) << " " << "|";
	std::cout << std::setw(2) << " " << "Degree" << std::setw(2) << " " << "|";
	std::cout << " Gender " << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(102) << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < n; i++) {
		std::cout << center_align(std::to_string(i + 1), 8) << "|";
		std::cout << center_align(lec[i].name, 30) << "|";
		std::cout << center_align(lec[i].username, 20) << "|";
		std::cout << center_align(lec[i].password, 20) << "|";
		std::cout << center_align(lec[i].degree, 10) << "|";
		if (lec[i].gender == 0) std::cout << "  Male  " << "|";
		else std::cout << " Female " << "|";
		std::cout << std::endl;
		std::cout << std::setfill('-');
		std::cout << std::setw(102) << "-" << std::endl;
		std::cout << std::setfill(' ');
	}
}

void view_all_lecturers() {
	lecturer* lec = NULL;
	int n = 0;
	read_lecturer_info(lec, n);
	print_lecturers(lec, n);
	delete[]lec;
}