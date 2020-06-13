#include "Course.h"

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
void enterinfo(std::ifstream& fi,std::string& academicyear,std::string& seme)
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

void create_allfile_course(std::ifstream& fi, std::ofstream& fo, course*& cou, int& num, std::string& academicyear, std::string& seme)
{
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
