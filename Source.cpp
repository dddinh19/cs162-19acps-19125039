#include "Header.h"

bool compare(string str1, string str2)
{
	if (str1.compare(str2) == 0) return true;
	return false;
}
void create_year_semester(ifstream& fi,ofstream& fo)
{
	string academic_year;
	cout << "Please input the academic year you want to create: ";
	getline(cin, academic_year);
	string seme;
	cout << "Please input the semester you want to create: ";
	getline(cin, seme);
	fi.open("D:/Data/Course/semester.txt");
	if (!fi)
	{
		std::cout << "Can't open this file! Please enter it again! " << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	int capacity = 10;
	semester* avai_semester = new semester[capacity];
	int num, check_1 = 0, i = 0, check_2 = 0;
	if (!fi.eof()) fi >> num;
	while (!fi.eof())
	{
		getline(fi, avai_semester[i].year);
		getline(fi, avai_semester[i].year);
		fi >> avai_semester[i].status;
		getline(fi, avai_semester[i].seme1);
		getline(fi, avai_semester[i].seme1);
		fi >> avai_semester[i].status1;
		getline(fi, avai_semester[i].seme2);
		getline(fi, avai_semester[i].seme2);
		fi >> avai_semester[i].status2;
		getline(fi, avai_semester[i].seme3);
		getline(fi, avai_semester[i].seme3);
		fi >> avai_semester[i].status3;
		if (compare(avai_semester[i].year, academic_year) && avai_semester[i].status == 1)
		{
			if ((compare(avai_semester[i].seme1, seme) && avai_semester[i].status1 == 1) || (compare(avai_semester[i].seme2, seme) && avai_semester[i].status2 == 1) || (compare(avai_semester[i].seme3, seme) && avai_semester[i].status3 == 1))
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
		cout << "The academic year and the semester you want to create have existed!!!" << endl;
		cout << "Do you want to create again (y for yes and n for no): ";
		cin >> check_3;
		if (check_3 == 'y')
		{
			cout << "-----------------------------------------------";
			fi.close();
			create_year_semester(fi, fo);
		}
		else
		{
			fi.close();
			fo.close();
			return;
		}
	}
	else
	{
		fo.open("D:/Data/Course/semester.txt");
		fo << num + 1;
		for (int j = 0; j < i; j++)
		{
			fo << avai_semester[j].year;
			if (compare(avai_semester[j].year, academic_year))
			{
				fo << 1;
				check_2 = 1;
			}
			fo << avai_semester[j].seme1;
			if (compare(avai_semester[j].seme1, seme)) fo << 1;
			fo << avai_semester[j].seme2;
			if (compare(avai_semester[j].seme2, seme)) fo << 1;
			fo << avai_semester[j].seme3;
			if (compare(avai_semester[j].seme3, seme)) fo << 1;
		}
		if (check_2 == 0)
		{
			fo << academic_year;
			fo << 1;
			fo << "HK1";
			if (compare("HK1", seme)) fo << 1; else fo << 0;
			fo << "HK2";
			if (compare("HK2", seme)) fo << 1; else fo << 0;
			fo << "HK3";
			if (compare("HK3", seme)) fo << 1; else fo << 0;
		}
		cout << "Create successfully!!";
	}
	fi.close();
	fo.close();
}