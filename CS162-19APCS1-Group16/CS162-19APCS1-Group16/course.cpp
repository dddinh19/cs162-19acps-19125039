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
	std::cin >> academic_year;
	std::string seme;
	std::cout << "Please input the semester you want to create: ";
	std::cin >> seme;
	fi.open("Data/Courses/semester.txt");
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
		fo.open("Data/Courses/semester.txt");
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
				str = "Data/Courses/" + avai_semester[j].year + "/" + seme;
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
				str = "Data/Courses/" + avai_semester[j].year + "/" + seme;
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
				str = "Data/Courses/" + avai_semester[j].year + "/" + seme;
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
		std::cout << "Create successfully!!" << std::endl;
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
	fi.open("Data/Courses/semester.txt");
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
	fo.open("Data/Courses/semester.txt");
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
		fo.open("Data/Courses/semester.txt");
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
	std::cin >> academic_year;
	int check_1;
	std::cout << "You want to delete the whole academic year(press 1) or just one semester in that academic year(press 2)? ";
	std::cin >> check_1;
	fi.open("Data/Courses/semester.txt");
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
	fo.open("Data/Courses/semester.txt");
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
			fo.open("Data/Courses/semester.txt");
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
			fo.open("Data/Courses/semester.txt");
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

void saveaDateAttendance(std::ofstream& fo, dob date, course c) {
	fo << date.year << " ";
	if (date.month < 10)
		fo << "0" << date.month << " ";
	else
		fo << date.month << " ";
	if (date.day < 10)
		fo << "0" << date.day << " " << std::endl;
	else
		fo << date.day << std::endl;
	fo << c.start_time.hour << " " << c.start_time.minute << " " << c.end_time.hour << " " << c.end_time.minute << " " << 0 << " " << 0 << std::endl;
}

void DateAttendance(std::ofstream& fo, course c) {
	saveaDateAttendance(fo, c.start_day, c);
	dob tdate = c.start_day;
	for (int i = 0; i < 9; i++) {
		tdate.day += 7;
		if (tdate.day <= dayofmonth(tdate))
			saveaDateAttendance(fo, tdate, c);
		else {
			tdate.day -= dayofmonth(tdate);
			++tdate.month;
			if (tdate.month > 12)
			{
				tdate.month = 1;
				++tdate.year;
				saveaDateAttendance(fo, tdate, c);
			}
			saveaDateAttendance(fo, tdate, c);
		}
	}
}

void enterinfo(std::ifstream& fi, std::string& academicyear, std::string& seme)
{
	char filename[100];
	std::cout << "Please enter academic year: ";
	std::cin >> academicyear;
	std::cout << "Please enter semester: ";
	std::cin >> seme;
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
void create_data_file(std::ifstream& fi, std::ofstream& fo, course*& cou, int num, std::string& academicyear, std::string& seme)
{
	int num_course = 0, n = 0;
	fi.open("Data/Courses/" + academicyear + "/" + seme + "/course.txt");
	fi >> num_course;
	course* cou_2 = new course[num_course];
	for (int i = 0; i < num_course; i++)
	{
		fi >> cou_2[i].courseID;
		fi >> cou_2[i].classname;
		fi >> cou_2[i].status;
		if (cou_2[i].status == 0)
			i--;
	}
	fi.close();
	fo.open("Data/Courses/" + academicyear + "/" + seme + "/course.txt");
	fo << num + num_course << std::endl;
	for (int i = 0; i < num + num_course; i++)
	{
		if (i < num_course)
		{
			fo << cou_2[i].courseID << std::endl;
			fo << cou_2[i].classname << std::endl;
			fo << cou_2[i].status << std::endl;
		}
		else
		{
			fo << cou[i - num_course].courseID << std::endl;
			fo << cou[i - num_course].classname << std::endl;
			fo << 1 << std::endl;
		}
	}
	fo.close();
	for (int i = 0; i < num; i++)
	{
		fo.open("Data/Courses/" + academicyear + "/" + seme + "/" + cou[i].courseID + "/" + cou[i].classname + "/info.txt");
		fo << cou[i].courseID << std::endl;
		fo << cou[i].courseName << std::endl;
		fo << cou[i].classname << std::endl;
		fo << cou[i].lecturer_couse.username << std::endl;
		fo << cou[i].start_day.year << " ";
		if (cou[i].start_day.month < 10)
			fo << "0" << cou[i].start_day.month << " ";
		else
			fo << cou[i].start_day.month << " ";
		if (cou[i].start_day.day < 10)
			fo << "0" << cou[i].start_day.day << " " << std::endl;
		else
			fo << cou[i].start_day.day << std::endl;
		fo << cou[i].end_day.year << " ";
		if (cou[i].end_day.month < 10)
			fo << "0" << cou[i].start_day.month << " ";
		else
			fo << cou[i].end_day.month << " ";
		if (cou[i].end_day.day < 10)
			fo << "0" << cou[i].end_day.day << " " << std::endl;
		else
			fo << cou[i].end_day.day << std::endl;
		fo << cou[i].dayofweek << std::endl;
		fo << cou[i].start_time.hour << " " << cou[i].start_time.minute << " " << cou[i].end_time.hour << " " << cou[i].end_time.minute << std::endl;
		fo << cou[i].room << std::endl;
		fo.close();
	}
	student* stu;
	fi.open("Data/Class/" + cou[0].classname + "/" + cou[0].classname + ".txt");
	fi >> n;
	fi.close();
	stu = new student[n];
	for (int j = 0; j < num; j++)
	{
		fo.open("Data/Courses/" + academicyear + "/" + seme + "/" + cou[j].courseID + "/" + cou[0].classname + "/student.txt");
		fi.open("Data/Class/" + cou[0].classname + "/" + cou[0].classname + ".txt");
		fo << n << std::endl;
		for (int i = 0; i < n; i++)
		{
			getline(fi, stu[i].id);
			getline(fi, stu[i].id);
			fi >> stu[i].status;
			if (stu[i].status == 1)
			{
				fo << stu[i].id << std::endl;
				fo << 1 << std::endl;
			}
			else i--;
		}
		fi.close();
		fo.close();
	}
	std::string str; const char* str1;
	for (int i = 0; i < n; i++)
	{
		str = "Data/Class/" + cou[0].classname + "/" + stu[i].id + "/" + academicyear;
		str1 = str.c_str();
		_mkdir(str1);
		str = str + "/" + seme;
		str1 = str.c_str();
		_mkdir(str1);
		fi.open(str + "/course.txt");
		if (!fi.is_open())
		{
			fo.open(str + "/course.txt");
			fo << num << std::endl;
			for (int i = 0; i < num; i++) {
				fo << cou[i].courseID << std::endl;
				fo << cou[i].classname << std::endl;
				fo << 1 << std::endl;
			}
			fo.close();
		}
		else {
			int num1;
			fi >> num1;
			course* cou1 = new course[num1];
			for (int i = 0; i < num1; i++) {
				fi >> cou1[i].courseID;
				fi >> cou1[i].classname;
				fi >> cou1[i].status;
				if (cou1[i].status == 0)
					i--;
			}
			fi.close();
			fo.open(str + "/course.txt");
			fo << num + num1 << std::endl;
			for (int i = 0; i < num+num1; i++) {
				if (i < num) {
					fo << cou[i].courseID << std::endl;
					fo << cou[i].classname << std::endl;
					fo << 1 << std::endl;
				}
				else
				{
					fo << cou1[i-num].courseID << std::endl;
					fo << cou1[i-num].classname << std::endl;
					fo << 1 << std::endl;
				}
			}
			fo.close();
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fo.open("Data/Courses/" + academicyear + "/" + seme + "/" + cou[i].courseID + "/" + cou[i].classname + "/" + stu[j].id + "/scoreboard.txt");
			fo << 0 << " " << 0 << " " << 0 << " " << 0;
			fo.close();
			fo.open("Data/Courses/" + academicyear + "/" + seme + "/" + cou[i].courseID + "/" + cou[i].classname + "/" + stu[j].id + "/attendance.txt");
			DateAttendance(fo, cou[i]);
			fo.close();
		}
	}
	delete[]stu;
}
void create_allfile_course(std::ifstream& fi, std::ofstream& fo, course*& cou, int& num, std::string& academicyear, std::string& seme)
{
	enterinfo(fi, academicyear, seme);
	load_data_course(fi, cou, num);
	std::string str, str1;
	str = "Data/Courses/" + academicyear;
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
	fi.open("Data/Courses/semester.txt");
	if (!fi)
	{
		std::cout << "Can't open this file! Please enter it again! " << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	int capacity = 10;
	semester* avai_semester = new semester[capacity];
	int n = 0, check_1 = 0, i = 0;
	fi >> n;
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
		if (compare(avai_semester[i].year, academicyear) && avai_semester[i].status == 1)
		{
			check_1 = 1;
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
	fi.close();
	fo.open("Data/Courses/semester.txt");
	if (check_1 == 0) n = n + 1;
	fo << n;
	for (int j = 0; j < i; j++)
	{
		fo << std::endl;
		fo << avai_semester[j].year << std::endl;
		if (compare(avai_semester[j].year, academicyear))
		{
			fo << 1 << std::endl;
		}
		else fo << avai_semester[j].status << std::endl;
		fo << avai_semester[j].sem1 << std::endl;
		if (compare(avai_semester[j].sem1, seme) && compare(avai_semester[j].year, academicyear))
		{
			fo << 1 << std::endl;
		}
		else fo << avai_semester[j].status1 << std::endl;
		fo << avai_semester[j].sem2 << std::endl;
		if (compare(avai_semester[j].sem2, seme) && compare(avai_semester[j].year, academicyear))
		{
			fo << 1 << std::endl;
		}
		else fo << avai_semester[j].status2 << std::endl;
		fo << avai_semester[j].sem3 << std::endl;
		if (compare(avai_semester[j].sem3, seme) && compare(avai_semester[j].year, academicyear))
		{
			fo << 1;
		}
		else fo << avai_semester[j].status3;
	}
	if (check_1 == 0)
	{
		fo << std::endl;
		fo << academicyear << std::endl;
		fo << 1 << std::endl;
		fo << "HK1" << std::endl;
		if (compare("HK1", seme)) fo << 1 << std::endl; else fo << 0 << std::endl;
		fo << "HK2" << std::endl;
		if (compare("HK2", seme)) fo << 1 << std::endl; else fo << 0 << std::endl;
		fo << "HK3" << std::endl;
		if (compare("HK3", seme)) fo << 1; else fo << 0;
	}
	fo.close();
	str = "Data/Courses/" + academicyear + "/" + seme + "/course.txt";
	fo.open(str);
	fo.close();
	for (int j = 0; j < num; j++)
	{
		str = "Data/Courses/" + academicyear + "/" + seme + "/" + cou[j].courseID;
		if (!check_openfile(fi, str))
		{
			const char* str1 = str.c_str();
			_mkdir(str1);
		}
		str = str + "/" + cou[j].classname;
		if (!check_openfile(fi, str))
		{
			const char* str1 = str.c_str();
			_mkdir(str1);
		}
		fo.open(str + "/student.txt");
		fo.close();
		fo.open(str + "/info.txt");
		fo.close();
		str = "Data/Class/" + cou[j].classname + "/" + cou[j].classname + ".txt";
		fi.open(str);
		fi >> n;
		for (int k = 0; k < n; k++)
		{
			student stu;
			getline(fi, stu.id);
			getline(fi, stu.id);
			fi >> stu.status;
			if (stu.status == 1)
			{
				str = "Data/Courses/" + academicyear + "/" + seme + "/" + cou[j].courseID + "/" + cou[j].classname + "/" + stu.id;
				const char* str1 = str.c_str();
				_mkdir(str1);
				fo.open(str + "/scoreboard.txt");
				fo.close();
				fo.open(str + "/attendance.txt");
				fo.close();
			}
			else k = k - 1;
		}
		fi.close();
	}
	create_data_file(fi, fo, cou, num, academicyear, seme);
	std::cout << "Import successfully!!" << std::endl;
}



void add_a_course()
{
	semester* p_year = nullptr;
	int n_year = 0;
	std::string year, sem;
	semester_data(p_year, n_year);
	view_academic_year(p_year, n_year);
	std::cout << "Enter academic year " << std::endl;
	std::cin >> year;
	if (view_semester(p_year, n_year, year) != -1) {
		std::cout << "Enter semester " << std::endl;
		std::cin >> sem;
		if (check_semester(p_year, n_year, year, sem)) {
			std::string p_class;
			std::cout << "Enter the class to add this course: ";
			std::cin >> p_class;
			if (check_class(p_class)) {
				course c;
				std::ifstream fi;
				int num_course = 0;
				fi.open("Data/Courses/" + year + "/" + sem + "/course.txt");
				fi >> num_course;
				course* cou_2 = new course[num_course];
				for (int i = 0; i < num_course; i++)
				{
					fi >> cou_2[i].courseID;
					fi >> cou_2[i].classname;
					fi >> cou_2[i].status;
					if (cou_2[i].status == 0)
						i--;
				}
				fi.close();
				std::cout << "Course ID: ";
				std::cin >> c.courseID;
				if (!check_course(cou_2, num_course, c.courseID, p_class)) {
					std::cout << "Name of the course: ";
					getline(std::cin, c.courseName);
					getline(std::cin, c.courseName);
					c.classname = p_class;
					std::cout << "Username of the lecturer: ";
					std::cin >> c.lecturer_couse.username;
					std::cout << "Start date (yyyy mm dd): ";
					std::cin >> c.start_day.year >> c.start_day.month >> c.start_day.day;
					std::cout << "End date (yyyy mm dd): ";
					std::cin >> c.end_day.year >> c.end_day.month >> c.end_day.day;
					std::cout << "Day of week (Ex:MON): ";
					std::cin >> c.dayofweek;
					std::cout << "Start time: " << std::endl;
					std::cout << "Hour: ";
					std::cin >> c.start_time.hour;
					std::cout << "Minute: ";
					std::cin >> c.start_time.minute;
					std::cout << "End time: " << std::endl;
					std::cout << "Hour: ";
					std::cin >> c.end_time.hour;
					std::cout << "Minute: ";
					std::cin >> c.end_time.minute;
					std::cout << "Room: ";
					std::cin >> c.room;
					c.status = 1;
					std::ofstream fo;
					fo.open("Data/Courses/" + year + "/" + sem + "/course.txt");
					fo << num_course + 1 << std::endl;
					for (int i = 0; i < num_course; i++)
					{
						fo << cou_2[i].courseID << std::endl;
						fo << cou_2[i].classname << std::endl;
						fo << cou_2[i].status << std::endl;
					}
					fo << c.courseID << std::endl;
					fo << p_class << std::endl;
					fo << c.status << std::endl;
					fo.close();
					std::string str = "Data/Courses/" + year + "/" + sem + "/" + c.courseID;
					const char* str1 = str.c_str();
					_mkdir(str1);
					student* stu; int n;
					fi.open("Data/Class/" + p_class + "/" + p_class + ".txt");
					fi >> n;
					fi.close();
					stu = new student[n];
					str = "Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class;
					str1 = str.c_str();
					_mkdir(str1);
					fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/student.txt");
					fi.open("Data/Class/" + p_class + "/" + p_class + ".txt");
					fo << n << std::endl;
					for (int i = 0; i < n; i++)
					{
						getline(fi, stu[i].id);
						getline(fi, stu[i].id);
						fi >> stu[i].status;
						if (stu[i].status == 1)
						{
							fo << stu[i].id << std::endl;
							fo << 1 << std::endl;
							str = "Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/" + stu[i].id;
							const char* str1 = str.c_str();
							_mkdir(str1);
						}
						else i--;
					}
					fi.close();
					fo.close();
					for (int i = 0; i < n; i++)
					{
						fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + c.classname + "/" + stu[i].id + "/scoreboard.txt");
						fo << 0 << " " << 0 << " " << 0 << " " << 0;
						fo.close();
						fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + c.classname + "/" + stu[i].id + "/attendance.txt");
						DateAttendance(fo, c);
						fo.close();
					}
					fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + c.classname + "/info.txt");
					fo << c.courseID << std::endl;
					fo << c.courseName << std::endl;
					fo << c.classname << std::endl;
					fo << c.lecturer_couse.username << std::endl;
					fo << c.start_day.year << " ";
					if (c.start_day.month < 10)
						fo << "0" << c.start_day.month << " ";
					else
						fo << c.start_day.month << " ";
					if (c.start_day.day < 10)
						fo << "0" << c.start_day.day << " " << std::endl;
					else
						fo << c.start_day.day << std::endl;
					fo << c.end_day.year << " ";
					if (c.end_day.month < 10)
						fo << "0" << c.start_day.month << " ";
					else
						fo << c.end_day.month << " ";
					if (c.end_day.day < 10)
						fo << "0" << c.end_day.day << " " << std::endl;
					else
						fo << c.end_day.day << std::endl;
					fo << c.dayofweek << std::endl;
					fo << c.start_time.hour << " " << c.start_time.minute << " " << c.end_time.hour << " " << c.end_time.minute << std::endl;
					fo << c.room << std::endl;
					fo.close();
					for (int i = 0; i < n; i++)
					{
						str = "Data/Class/" + c.classname + "/" + stu[i].id + "/" + year;
						str1 = str.c_str();
						_mkdir(str1);
						str = str + "/" + sem;
						str1 = str.c_str();
						_mkdir(str1);
						fi.open(str + "/course.txt");
						if (!fi.is_open())
						{
							fo.open(str + "/course.txt");
							fo << 1 << std::endl;
							for (int i = 0; i < 1; i++) {
								fo << c.courseID << std::endl;
								fo << c.classname << std::endl;
								fo << 1 << std::endl;
							}
							fo.close();
						}
						else
						{
							int num1;
							fi >> num1;
							course* cou1 = new course[num1];
							for (int i = 0; i < num1; i++) {
								fi >> cou1[i].courseID;
								fi >> cou1[i].classname;
								fi >> cou1[i].status;
								if (cou1[i].status == 0)
									i--;
							}
							fi.close();
							fo.open(str + "/course.txt");
							fo << 1 + num1 << std::endl;
							for (int i = 0; i < 1 + num1; i++) {
								if (i < 1) {
									fo << c.courseID << std::endl;
									fo << c.classname << std::endl;
									fo << 1 << std::endl;
								}
								else
								{
									fo << cou1[i - 1].courseID << std::endl;
									fo << cou1[i - 1].classname << std::endl;
									fo << 1 << std::endl;
								}
							}
							fo.close();
							std::cout << "Add successfully!!" << std::endl;
						}
					}
				}
				else
					std::cout << "This course in " << p_class << " is aldready available." << std::endl;
			}
			else
				std::cout << "This class doesn't exist." << std::endl;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[]p_year;
}

void removeacourse()
{
	semester* p_year = nullptr;
	int n_year = 0;
	std::string year, sem;
	semester_data(p_year, n_year);
	view_academic_year(p_year, n_year);
	std::cout << "Enter academic year " << std::endl;
	std::cin >> year;
	if (view_semester(p_year, n_year, year) != -1) {
		std::cout << "Enter semester " << std::endl;
		std::cin >> sem;
		if (check_semester(p_year, n_year, year, sem))
		{
			std::string p_class;
			std::cout << "Enter the class that has the course you want to remove: ";
			std::cin >> p_class;
			if (check_class(p_class))
			{
				course c;
				std::ifstream fi;
				int num_course = 0;
				fi.open("Data/Courses/" + year + "/" + sem + "/course.txt");
				fi >> num_course;
				course* cou_2 = new course[num_course];
				for (int i = 0; i < num_course; i++)
				{
					fi >> cou_2[i].courseID;
					fi >> cou_2[i].classname;
					fi >> cou_2[i].status;
					if (cou_2[i].status == 0)
						i--;
				}
				fi.close();
				std::cout << "Course ID: ";
				std::cin >> c.courseID;
				c.classname = p_class;
				if (check_course(cou_2, num_course, c.courseID, p_class))
				{
					std::ofstream fo;
					fo.open("Data/Courses/" + year + "/" + sem + "/course.txt");
					fo << num_course - 1 << std::endl;
					for (int i = 0; i < num_course; i++)
					{
						fo << cou_2[i].courseID << std::endl;
						fo << cou_2[i].classname << std::endl;
						if (cou_2[i].courseID == c.courseID && cou_2[i].classname == c.classname)
							fo << 0 << std::endl;
						else fo << 1 << std::endl;
					}
					fo.close();
					int n;
					fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + c.classname + "/student.txt");
					fi >> n;
					student* stu = new student[n];
					for (int i = 0; i < n; i++)
					{
						getline(fi, stu[i].id);
						getline(fi, stu[i].id);
						fi >> stu[i].status;
						if (stu[i].status == 0) i--;
						read_class_of_student(stu[i]);
					}
					fi.close();
					course* cou3 = nullptr;
					int n3;
					for (int i = 0; i < n; i++) {
						fi.open("Data/Class/" + stu[i].classname + "/" + stu[i].id + "/" + year + "/" + sem + "/course.txt");
						fi >> n3;
						cou3 = new course[n3];
						for (int j = 0; j < n3; j++) {
							fi >> cou3[j].courseID;
							fi >> cou3[j].classname;
							fi >> cou3[j].status;
							if (cou3[j].status == 0)
								j--;
						}
						fi.close();
						fo.open("Data/Class/" + stu[i].classname + "/" + stu[i].id + "/" + year + "/" + sem + "/course.txt");
						fo << n3 - 1 << std::endl;
						for (int j = 0; j < n3; j++) {
							fo << cou3[j].courseID << std::endl;
							fo << cou3[j].classname << std::endl;
							if (cou3[j].courseID == c.courseID && cou3[j].classname == c.classname)
								fo << 0 << std::endl;
							else fo << 1 << std::endl;
						}
						fo.close();
					}
					delete[]cou3;
				}
				else
					std::cout << "This course doesn't exist." << std::endl;
				delete[]cou_2;
			}
			else
				std::cout << "This class doesn't exist." << std::endl;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[]p_year;
}

void remove_a_student()
{
	std::ofstream fo;
	semester* p_year = nullptr;
	int n_year = 0;
	std::string year, sem;
	semester_data(p_year, n_year);
	view_academic_year(p_year, n_year);
	std::cout << "Enter academic year " << std::endl;
	std::cin >> year;
	if (view_semester(p_year, n_year, year) != -1) {
		std::cout << "Enter semester " << std::endl;
		std::cin >> sem;
		if (check_semester(p_year, n_year, year, sem))
		{
			std::string p_class;
			std::cout << "Enter the class that has the course you want to remove a student: ";
			std::cin >> p_class;
			if (check_class(p_class))
			{
				course c; int n;
				std::ifstream fi;
				int num_course = 0;
				fi.open("Data/Courses/" + year + "/" + sem + "/course.txt");
				fi >> num_course;
				course* cou_2 = new course[num_course];
				for (int i = 0; i < num_course; i++)
				{
					fi >> cou_2[i].courseID;
					fi >> cou_2[i].classname;
					fi >> cou_2[i].status;
					if (cou_2[i].status == 0)
						i--;
				}
				fi.close();
				std::cout << "Course ID: ";
				std::cin >> c.courseID;
				if (check_course(cou_2, num_course, c.courseID, p_class))
				{
					fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class);
					int num;
					fi >> num;
					student stu;
					std::cout << "The student ID of that student: ";
					std::cin >> stu.id;
					read_class_of_student(stu);
					fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/student.txt");
					int n;
					fi >> n;
					student* stu1 = new student[n];
					for (int i = 0; i < n; i++)
					{
						fi >> stu1[i].id;
						fi >> stu1[i].status;
						if (stu1[i].status == 0) i--;
					}
					fi.close();
					if (check_student(stu1, n, stu.id)) {
						fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/student.txt");
						fo << n - 1 << std::endl;
						for (int i = 0; i < n; i++)
						{
							fo << stu1[i].id << std::endl;
							if (stu1[i].id == stu.id)
								fo << 0 << std::endl;
							else fo << stu1[i].status << std::endl;
						}
						fo.close();
						fi.open("Data/Class/" + stu.classname + "/" + stu.id + "/" + year + "/" + sem + "/course.txt");
						fi >> num;
						course* cou = new course[num];
						for (int i = 0; i < num; i++)
						{
							fi >> cou[i].courseID;
							fi >> cou[i].classname;
							fi >> cou[i].status;
							if (cou[i].status == 0) i--;
						}
						fi.close();
						fo.open("Data/Class/" + stu.classname + "/" + stu.id + "/" + year + "/" + sem + "/course.txt");
						fo << num - 1 << std::endl;
						for (int i = 0; i < num; i++)
						{
							fo << cou[i].courseID << std::endl;
							fo << cou[i].classname << std::endl;
							if (c.courseID == cou[i].courseID) fo << 0 << std::endl;
							else fo << 1 << std::endl;
						}
						fo.close();
						delete[] stu1;
						delete[] cou;
					}
					else std::cout << "The student is not in this class.";
				}
			}
			else
				std::cout << "This class doesn't exist." << std::endl;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[] p_year;
}

void edit_course()
{
	std::ofstream fo;
	semester* p_year = nullptr;
	int n_year = 0;
	std::string year, sem;
	semester_data(p_year, n_year);
	view_academic_year(p_year, n_year);
	std::cout << "Enter academic year " << std::endl;
	std::cin >> year;
	if (view_semester(p_year, n_year, year) != -1) {
		std::cout << "Enter semester " << std::endl;
		std::cin >> sem;
		if (check_semester(p_year, n_year, year, sem))
		{
			std::string p_class;
			std::cout << "Enter the class to add this course: ";
			std::cin >> p_class;
			if (check_class(p_class))
			{
				course c; int n;
				std::ifstream fi;
				int num_course = 0;
				fi.open("Data/Courses/" + year + "/" + sem + "/course.txt");
				fi >> num_course;
				course* cou_2 = new course[num_course];
				for (int i = 0; i < num_course; i++)
				{
					fi >> cou_2[i].courseID;
					fi >> cou_2[i].classname;
					fi >> cou_2[i].status;
					if (cou_2[i].status == 0)
						i--;
				}
				fi.close();
				std::cout << "Course ID: ";
				std::cin >> c.courseID;
				if (check_course(cou_2, num_course, c.courseID, p_class))
				{
					delete[] cou_2;
					fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/info.txt");
					course cou;
					std::string newname;
					fi >> cou.courseID;
					getline(fi, cou.courseName);
					getline(fi, cou.courseName);
					fi >> cou.classname;
					fi >> cou.lecturer_couse.username;
					fi >> cou.start_day.year >> cou.start_day.month >> cou.start_day.day;
					fi >> cou.end_day.year >> cou.end_day.month >> cou.end_day.day;
					fi >> cou.dayofweek;
					fi >> cou.start_time.hour >> cou.start_time.minute >> cou.end_time.hour >> cou.end_time.minute;
					fi.close();
					int k;
					do
					{
						std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
						std::cout << "Press 1 to change the course's name." << std::endl;
						std::cout << "Press 2 to change the lecturer." << std::endl;
						std::cout << "Press 3 to change the start date and end date." << std::endl;
						std::cout << "Press 4 to change the day of week." << std::endl;
						std::cout << "Press 5 to change the room." << std::endl;
						std::cout << "Press 0 to stop the program." << std::endl;
						std::cout << "Choose the opion you want to (0-5): ";
						std::cin >> k;
						switch (k)
						{
						case 0:
							break;
						case 1:
						{
							std::cout << "The new course's name: ";
							getline(std::cin, newname);
							fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/info.txt");
							fo << cou.room << std::endl;
							fo << cou.courseID << std::endl;
							fo << newname << std::endl;
							fo << cou.classname << std::endl;
							fo << cou.lecturer_couse.username << std::endl;
							fo << cou.start_day.year << " ";
							if (cou.start_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.start_day.month << " ";
							if (cou.start_day.day < 10)
								fo << "0" << cou.start_day.day << " " << std::endl;
							else
								fo << cou.start_day.day << std::endl;
							fo << cou.end_day.year << " ";
							if (cou.end_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.end_day.month << " ";
							if (cou.end_day.day < 10)
								fo << "0" << cou.end_day.day << " " << std::endl;
							else
								fo << cou.end_day.day << std::endl;
							fo << cou.dayofweek << std::endl;
							fo << cou.start_time.hour << " " << cou.start_time.minute << " " << cou.end_time.hour << " " << cou.end_time.minute << std::endl;
							fo << cou.room << std::endl;
							fo.close();
							break;
						}
						case 2:
						{
							std::cout << "The new lecturer's username: ";
							newname;
							fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/info.txt");
							fo << cou.room << std::endl;
							fo << cou.courseID << std::endl;
							fo << cou.courseName << std::endl;
							fo << cou.classname << std::endl;
							fo << newname << std::endl;
							fo << cou.start_day.year << " ";
							if (cou.start_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.start_day.month << " ";
							if (cou.start_day.day < 10)
								fo << "0" << cou.start_day.day << " " << std::endl;
							else
								fo << cou.start_day.day << std::endl;
							fo << cou.end_day.year << " ";
							if (cou.end_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.end_day.month << " ";
							if (cou.end_day.day < 10)
								fo << "0" << cou.end_day.day << " " << std::endl;
							else
								fo << cou.end_day.day << std::endl;
							fo << cou.dayofweek << std::endl;
							fo << cou.start_time.hour << " " << cou.start_time.minute << " " << cou.end_time.hour << " " << cou.end_time.minute << std::endl;
							fo << cou.room << std::endl;
							fo.close();
							break;
						}
						case 3:
						{
							std::cout << "The new start day's year: ";
							int styear, symo, syda, enyear, enmo, enda;
							std::cin >> styear;
							std::cout << "The new start day's month: ";
							std::cin >> symo;
							std::cout << "The new start day's day: ";
							std::cin >> syda;
							std::cout << "The new end day's year: ";
							std::cin >> enyear;
							std::cout << "The new end day's month: ";
							std::cin >> enmo;
							std::cout << "The new end day's day: ";
							std::cin >> enda;
							fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/info.txt");
							fo << cou.room << std::endl;
							fo << cou.courseID << std::endl;
							fo << cou.courseName << std::endl;
							fo << cou.classname << std::endl;
							fo << newname << std::endl;
							fo << styear << " ";
							if (symo < 10)
								fo << "0" << symo << " ";
							else
								fo << symo << " ";
							if (syda < 10)
								fo << "0" << syda << " " << std::endl;
							else
								fo << syda << std::endl;
							fo << enyear << " ";
							if (enmo < 10)
								fo << "0" << enmo << " ";
							else
								fo << enmo << " ";
							if (enda < 10)
								fo << "0" << enda << " " << std::endl;
							else
								fo << enda << std::endl;
							fo << cou.dayofweek << std::endl;
							fo << cou.start_time.hour << " " << cou.start_time.minute << " " << cou.end_time.hour << " " << cou.end_time.minute << std::endl;
							fo << cou.room << std::endl;
							fo.close();
							break;
						}
						case 4:
						{
							std::cout << "The new day of week: ";
							newname;
							fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/info.txt");
							fo << cou.room << std::endl;
							fo << cou.courseID << std::endl;
							fo << cou.courseName << std::endl;
							fo << cou.classname << std::endl;
							fo << cou.lecturer_couse.username << std::endl;
							fo << cou.start_day.year << " ";
							if (cou.start_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.start_day.month << " ";
							if (cou.start_day.day < 10)
								fo << "0" << cou.start_day.day << " " << std::endl;
							else
								fo << cou.start_day.day << std::endl;
							fo << cou.end_day.year << " ";
							if (cou.end_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.end_day.month << " ";
							if (cou.end_day.day < 10)
								fo << "0" << cou.end_day.day << " " << std::endl;
							else
								fo << cou.end_day.day << std::endl;
							fo << newname << std::endl;
							fo << cou.start_time.hour << " " << cou.start_time.minute << " " << cou.end_time.hour << " " << cou.end_time.minute << std::endl;
							fo << cou.room << std::endl;
							fo.close();
							break;
						}
						case 5:
						{
							std::cout << "The new room: ";
							newname;
							fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/info.txt");
							fo << cou.room << std::endl;
							fo << cou.courseID << std::endl;
							fo << cou.courseName << std::endl;
							fo << cou.classname << std::endl;
							fo << cou.lecturer_couse.username << std::endl;
							fo << cou.start_day.year << " ";
							if (cou.start_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.start_day.month << " ";
							if (cou.start_day.day < 10)
								fo << "0" << cou.start_day.day << " " << std::endl;
							else
								fo << cou.start_day.day << std::endl;
							fo << cou.end_day.year << " ";
							if (cou.end_day.month < 10)
								fo << "0" << cou.start_day.month << " ";
							else
								fo << cou.end_day.month << " ";
							if (cou.end_day.day < 10)
								fo << "0" << cou.end_day.day << " " << std::endl;
							else
								fo << cou.end_day.day << std::endl;
							fo << cou.dayofweek << std::endl;
							fo << cou.start_time.hour << " " << cou.start_time.minute << " " << cou.end_time.hour << " " << cou.end_time.minute << std::endl;
							fo << newname << std::endl;
							fo.close();
							break;
						}
						}
					} while (k != 0);
				}
			}
		}
	}
}

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
		fin.close();
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
	if (p[n - 1].status1 != 0 || p[n - 1].status2 != 0 || p[n - 1].status3 != 0) {
		std::string filename = "Data/Courses/" + p[n - 1].year + "/" + current_sem(p, n) + "/course.txt";
		course* p_course = nullptr;
		int n_course = 0;
		read_course_in_semester(filename, p_course, n_course);
		for (int i = 0; i < n_course; i++) {
			filename = "Data/Courses/" + p[n - 1].year + "/" + current_sem(p, n) + "/" + p_course[i].courseID + "/" + p_course[i].classname + "/info.txt";
			read_course_info(filename, p_course[i]);
		}
		print_course_current_semester_board(p[n - 1].year, current_sem(p, n), p_course, n_course);
		delete[]p_course;
	}
	delete[]p;
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
	std::cout << std::setw(52) << "LIST OF LECTURERS " << std::endl;
	std::cout << std::setfill('=');
	std::cout << std::setw(81) << "=" << std::endl;
	std::cout << std::setfill(' ');
	// Width of board: No-8, Lecturer name-30, Lecturer username-20, Degree-10, Gender-8
	std::cout << std::setw(3) << " " << "No" << std::setw(3) << " " << "|";
	std::cout << std::setw(8) << " " << "Lecturer name" << std::setw(9) << " " << "|";
	std::cout << std::setw(1) << " " << "Lecturer username" << std::setw(2) << " " << "|";
	std::cout << std::setw(2) << " " << "Degree" << std::setw(2) << " " << "|";
	std::cout << " Gender " << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(81) << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < n; i++) {
		std::cout << center_align(std::to_string(i + 1), 8) << "|";
		std::cout << center_align(lec[i].name, 30) << "|";
		std::cout << center_align(lec[i].username, 20) << "|";
		std::cout << center_align(lec[i].degree, 10) << "|";
		if (lec[i].gender == 0) std::cout << "  Male  " << "|";
		else std::cout << " Female " << "|";
		std::cout << std::endl;
		std::cout << std::setfill('-');
		std::cout << std::setw(81) << "-" << std::endl;
		std::cout << std::setfill(' ');
	}
}

void add_student()
{
	std::ofstream fo;
	semester* p_year = nullptr;
	int n_year = 0;
	std::string year, sem;
	semester_data(p_year, n_year);
	view_academic_year(p_year, n_year);
	std::cout << "Enter academic year " << std::endl;
	std::cin >> year;
	if (view_semester(p_year, n_year, year) != -1) {
		std::cout << "Enter semester " << std::endl;
		std::cin >> sem;
		if (check_semester(p_year, n_year, year, sem))
		{
			std::string p_class;
			std::cout << "Enter the class that has the course you want to add a student: ";
			std::cin >> p_class;
			if (check_class(p_class))
			{
				course c; int n;
				std::ifstream fi;
				int num_course = 0;
				fi.open("Data/Courses/" + year + "/" + sem + "/course.txt");
				fi >> num_course;
				course* cou_2 = new course[num_course];
				for (int i = 0; i < num_course; i++)
				{
					fi >> cou_2[i].courseID;
					fi >> cou_2[i].classname;
					fi >> cou_2[i].status;
					if (cou_2[i].status == 0)
						i--;
				}
				fi.close();
				std::cout << "Course ID: ";
				std::cin >> c.courseID;
				if (check_course(cou_2, num_course, c.courseID, p_class))
				{
					student stu;
					std::cout << "The student ID of that student: ";
					std::cin >> stu.id;
					read_class_of_student(stu);
					fi.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/student.txt");
					int n;
					fi >> n;
					student* stu1 = new student[n];
					for (int i = 0; i < n; i++)
					{
						fi >> stu1[i].id;
						fi >> stu1[i].status;
						if (stu1[i].status == 0) i--;
					}
					if (!check_student(stu1, n, stu.id)) {
						fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/student.txt");
						fo << n + 1 << std::endl;
						for (int i = 0; i < n; i++)
						{
							fo << stu1[i].id << std::endl;
							fo << stu1[i].status << std::endl;
						}
						fo << stu.id << std::endl;
						fo << 1 << std::endl;
						fo.close();
						std::string str = "Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/" + stu.id;
						const char* str1 = str.c_str();
						_mkdir(str1);
						fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/" + stu.id + "/attendance.txt");
						DateAttendance(fo, c);
						fo.close();
						fo.open("Data/Courses/" + year + "/" + sem + "/" + c.courseID + "/" + p_class + "/" + stu.id + "/scoreboard.txt");
						fo << 0 << " " << 0 << " " << 0 << " " << " " << 0;
						fo.close();
						int num = 0;
						fi.open("Data/Class/" + stu.classname + "/" + stu.id + "/" + year + "/" + sem + "/course.txt");
						fi >> num;
						course* cou = new course[num];
						for (int i = 0; i < num; i++)
						{
							fi >> cou[i].courseID;
							fi >> cou[i].classname;
							fi >> cou[i].status;
							if (cou[i].status == 0) i--;
						}
						fi.close();
						fo.open("Data/Class/" + stu.classname + "/" + stu.id + "/" + year + "/" + sem + "/course.txt");
						fo << num + 1 << std::endl;
						for (int i = 0; i < num; i++)
						{
							fo << cou[i].courseID << std::endl;
							fo << cou[i].classname << std::endl;
							fo << cou[i].status << std::endl;
						}
						fo << c.courseID << std::endl;
						fo << p_class << std::endl;
						fo << 1;
						fo.close();
						delete[] stu1;
						delete[] cou;
					}
					else
						std::cout << "This student is aldready in this class." << std::endl;
				}
			}
			else
				std::cout << "This class doesn't exist." << std::endl;
		}
		else std::cout << "Semester does not exist " << std::endl;
	}
	else std::cout << "Academic year does not exist " << std::endl;
	delete[] p_year;
}
void view_all_lecturers() {
	lecturer* lec = NULL;
	int n = 0;
	read_lecturer_info(lec, n);
	print_lecturers(lec, n);
	delete[]lec;
}