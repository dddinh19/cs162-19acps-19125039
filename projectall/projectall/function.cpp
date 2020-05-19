#include "function.h"

void enterfilename(std::ifstream& fi)
{
	char filename[12];
	int check = 0;
	do
	{
		std::cout << "Please enter filename: ";
		std::cin.get(filename, 12);
		std::cin.get();
		fi.open(filename);
		if (!fi)
		{
			std::cout << "Error! Please do it again! " << std::endl;
			std::cout << "--------------------------" << std::endl;
			check = 0;
		}
		else check = 1;
	} while (check == 0);
}
void load_data_student(std::ifstream& fi, student* stu)
{
	enterfilename(fi);
	char ch[100];
	fi.getline(ch,100);
	int data = 0, capacity = 10;
	int j, num;
	stu = new student[capacity];
	while (!fi.eof())
	{
		fi.getline(ch,100);
		j = 0, num = 0;
		char str[100], str1[100];
		for (int i = 0; i <= strlen(ch); ++i)
		{
			if ((ch[i] == ',')||(ch[i]=='\0'))
			{
				for (int k = j; k < i; k++)
				{
					str[k - j] = ch[j];
				}
				str[i - j] = '\0';
				j = i+1;
			}
			if (data==1) strcpy(stu[num].id, str);
			if (data == 2) strcpy(stu[num].name, str);
			if (data == 3)
			{
				int check = 0, order = 1;
				for (int i = 0; i <= strlen(str); i++)
				{
					if ((str[i] == '-') || (str[i] == '\0'))
					{
						for (int k = check; k < i; k++)
						{
							str1[k - check] = str[check];
						}
						str[i - check] = '\0';
						check = i + 1;
					}
					if (order==1) strcpy(stu[num].date.year, str);
					if (order == 2) strcpy(stu[num].date.month, str);
					if (order == 3) strcpy(stu[num].date.day, str);
					order++;
				}
			}
			if (data == 4) strcpy(stu[num].classname, str);
			data++;
		}
		if (num == capacity)
		{
			student* tmpstu = new student[capacity + 5];
			for (int i = 0; i < num; i++)
			{
				tmpstu[i] = stu[i];
			}
			delete[] stu;
			stu = tmpstu;
		}
		num++;
	}
	fi.close();
}
void save_data_student(std::ofstream& fout, student* stu)
{

}