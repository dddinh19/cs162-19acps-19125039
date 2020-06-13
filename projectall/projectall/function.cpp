#include "function.h"

void enterfilename(std::ifstream& fi)
{
	char filename[100];
	int check = 0;
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
void load_data_student(std::ifstream& fi, student*& stu, int& num)
{
	enterfilename(fi);
	char ch[100];
	fi.getline(ch, 100);
	int data = -1, capacity = 10;
	int j;
	stu = new student[capacity];
	char str[100], str1[100];
	while (!fi.eof())
	{
		fi.getline(ch,100);
		j = 0;
		stu[num].id = new char[20];
		stu[num].name = new char[50];
		stu[num].date.year = new char[10];
		stu[num].date.month = new char[10];
		stu[num].date.day = new char[10];
		stu[num].classname = new char[10];
		for (int i = 0; i < strlen(ch)+1; ++i)
		{
			if ((ch[i] == ',') || (ch[i] == '\0'))
			{
				data++;
				for (int k = j; k < i; k++)
				{
					str[k - j] = ch[k];
				}
				str[i - j] = '\0';
				j = i+1;
			}
			if (data == 1)
			{
				strcpy_s(stu[num].id, strlen(str) + 1, str);
			}
			if (data == 2)
			{
				strcpy_s(stu[num].name, strlen(str) + 1, str);
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
						strcpy_s(stu[num].date.year, strlen(str1) + 1, str1);
					}
					if (order == 2)
					{
						strcpy_s(stu[num].date.month, strlen(str1) + 1, str1);
					}
					if (order == 3)
					{
						strcpy_s(stu[num].date.day, strlen(str1) + 1, str1);
					}
				}
			}
			if (data == 4)
			{
				strcpy_s(stu[num].classname, strlen(str) + 1, str);
			}
		}
		if (num == capacity - 1)
		{
			student* tmpstu = new student[capacity + 10];
			for (int i = 0; i <= num; i++)
			{
				tmpstu[i] = stu[i];
			}
			delete[] stu;
			stu = tmpstu;
			capacity = capacity + 10;
		}
		num++; data = -1; 
	}
	fi.close();
}
void delete_data_student(student*& stu, int num)
{
	for (int i = 0; i < num-1; i++)
	{
		delete[] stu[i].id;
		delete[] stu[i].name;		
		delete[] stu[i].classname;
		delete[] stu[i].date.year;
		delete[] stu[i].date.month;
		delete[] stu[i].date.day;
	}
	delete[] stu;
}