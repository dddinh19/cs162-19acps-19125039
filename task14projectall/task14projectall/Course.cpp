#include "Course.h"

void enterinfo(std::ifstream& fi)
{
	char academicyear[10], semester[10], classname[10], filename[100];
	int check = 0;
	//std::cout << "Please enter academic year: ";
	//std::cin.get(academicyear, 10);
	//std::cin.get();
	//std::cout << "Please enter semester: ";
	//std::cin.get(semester, 10);
	//std::cin.get();
	//std::cout << "Please enter class's name:";
	//std::cin.get(classname, 10);
	//std::cin.get();
	do
	{
		std::cout << "Please enter filename: ";
		std::cin.get(filename, 100);
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
	char ch[1000];
	fi.getline(ch, 1000);
	int data = -1, capacity = 10;
	int j;
	cou = new course[capacity];
	char str[100], str1[100];
	while (!fi.eof())
	{
		fi.getline(ch, 1000);
		j = 0;
		cou[num].id = new char[10];
		cou[num].name = new char[50];
		cou[num].classname = new char[10];
		cou[num].dayofweek = new char[10];
		cou[num].room = new char[10];
		cou[num].lec.username = new char[10];
		cou[num].lec.lecturerName = new char[50];
		cou[num].lec.sex = new char[10];
		cou[num].lec.degree = new char[10];
		cou[num].startdate.day = new char[10];
		cou[num].startdate.month = new char[10];
		cou[num].startdate.year = new char[10];
		cou[num].enddate.day = new char[10];
		cou[num].enddate.month = new char[10];
		cou[num].enddate.year = new char[10];
		for (int i = 0; i < strlen(ch) + 1; ++i)
		{
			if ((ch[i] == ',') || (ch[i] == '\0'))
			{
				data++;
				for (int k = j; k < i; k++)
				{
					str[k - j] = ch[k];
				}
				str[i - j] = '\0';
				j = i + 1;
			}
			if (data == 1)
				strcpy_s(cou[num].id, strlen(str) + 1, str);
			if (data == 2)
				strcpy_s(cou[num].name, strlen(str) + 1, str);
			if (data == 3)
				strcpy_s(cou[num].classname, strlen(str) + 1, str);
			if (data == 4)
				strcpy_s(cou[num].lec.username, strlen(str) + 1, str);
			if (data == 5)
				strcpy_s(cou[num].lec.lecturerName, strlen(str) + 1, str);
			if (data == 6)
				strcpy_s(cou[num].lec.sex, strlen(str) + 1, str);
			if (data == 7)
				strcpy_s(cou[num].lec.degree, strlen(str) + 1, str);
			if (data == 8)
			{
				int check = 0, order = 0;
				for (int m = 0; m <= strlen(str); m++)
				{
					if ((str[m] == '-') || (str[m] == '\0'))
					{
						order++;
						for (int k = check; k < m; k++)
						{
							str1[k - check] = str[k];
						}
						str1[m - check] = '\0';
						check = m + 1;
					}
					if (order == 1)
						strcpy_s(cou[num].startdate.year, strlen(str1) + 1, str1);
					if (order == 2)
						strcpy_s(cou[num].startdate.month, strlen(str1) + 1, str1);
					if (order == 3)
						strcpy_s(cou[num].startdate.day, strlen(str1) + 1, str1);
				}
			}
			if (data == 9)
			{
				int check = 0, order = 0;
				for (int m = 0; m <= strlen(str); m++)
				{
					if ((str[m] == '-') || (str[m] == '\0'))
					{
						order++;
						for (int k = check; k < m; k++)
						{
							str1[k - check] = str[k];
						}
						str1[m - check] = '\0';
						check = m + 1;
					}
					if (order == 1)
						strcpy_s(cou[num].enddate.year, strlen(str1) + 1, str1);
					if (order == 2)
						strcpy_s(cou[num].enddate.month, strlen(str1) + 1, str1);
					if (order == 3)
						strcpy_s(cou[num].enddate.day, strlen(str1) + 1, str1);
				}
			}
			if (data == 10)
				strcpy_s(cou[num].dayofweek, strlen(str) + 1, str);
			if (data == 11)
			{
				cou[num].starthour = 0;
				for (int i = 0; i < strlen(str); i++)
					cou[num].starthour = (str[i]-'0') + cou[num].starthour * 10;
			}
			if (data == 12)
			{
				cou[num].startminute = 0;
				for (int i = 0; i < strlen(str); i++)
					cou[num].startminute = (str[i]-'0') + cou[num].startminute * 10;
			}
			if (data == 13)
			{
				cou[num].endhour = 0;
				for (int i = 0; i < strlen(str); i++)
					cou[num].endhour = (str[i]-'0') + cou[num].endhour * 10;
			}
			if (data == 14)
			{
				cou[num].endminute = 0;
				for (int i = 0; i < strlen(str); i++)
					cou[num].endminute = (str[i]-'0') + cou[num].endminute * 10;
			}
			if (data == 15)
				strcpy_s(cou[num].room, strlen(str) + 1, str);
		}
		if (num == capacity - 1)
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
		num++; data = -1;
	}
	fi.close();
}
void delete_data_course(course*& cou, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		delete[] cou[i].id;
		delete[] cou[i].name;
		delete[] cou[i].classname;
		delete[] cou[i].dayofweek;
		delete[] cou[i].startdate.year;
		delete[] cou[i].startdate.month;
		delete[] cou[i].startdate.day;
		delete[] cou[i].enddate.year;
		delete[] cou[i].enddate.month;
		delete[] cou[i].enddate.day;
		delete[] cou[i].room;
		delete[] cou[i].lec.username;
		delete[] cou[i].lec.lecturerName;
		delete[] cou[i].lec.sex;
		delete[] cou[i].lec.degree;
	}
	delete[] cou;
}
	