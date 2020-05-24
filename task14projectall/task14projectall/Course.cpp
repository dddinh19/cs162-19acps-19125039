#include "Course.h"

void enterinfo(std::ifstream& fi)
{
	char academicyear[10], semester[10], classname[10], filename[100];
	int check = 0;
	std::cout << "Please enter academic year: ";
	std::cin.get(academicyear, 10);
	std::cin.get();
	std::cout << "Please enter semester: ";
	std::cin.get(semester, 10);
	std::cin.get();
	std::cout << "Please enter class's name:";
	std::cin.get(classname, 10);
	std::cin.get();
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
	char ch[100];
	fi.getline(ch, 100);
	int data = -1, capacity = 10;
	int j;
	cou = new course[capacity];
	char str[100], str1[100];
	while (!fi.eof())
	{
		fi.getline(ch, 100);
		j = 0;
		cou[num].id = new char[10];
		cou[num].name = new char[50];
		cou[num].classname = new char[10];
		cou[num].dayofweek = new char[10];
		cou[num].room= new char[10];
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
			{
				strcpy_s(cou[num].id, strlen(str) + 1, str);
			}
			if (data == 2)
			{
				strcpy_s(cou[num].name, strlen(str) + 1, str);
			}
			if (data == 3)
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
					{
						strcpy_s(cou[num].date.year, strlen(str1) + 1, str1);
					}
					if (order == 2)
					{
						strcpy_s(cou[num].date.month, strlen(str1) + 1, str1);
					}
					if (order == 3)
					{
						strcpy_s(cou[num].date.day, strlen(str1) + 1, str1);
					}
				}
			}
			if (data == 4)
			{
				strcpy_s(cou[num].classname, strlen(str) + 1, str);
			}
		}
		if (num == capacity - 1)
		{
			coudent* tmpcou = new coudent[capacity + 10];
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
