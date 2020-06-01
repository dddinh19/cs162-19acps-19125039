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
	fi.open("Data/Course/semester.txt");
	if (!fi)
	{
		std::cout << "Can't open this file! Please enter it again! " << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	int capacity = 10;
	semester* avai_semester = new semester[capacity];
	int num, check_1 = 0, i = 0, check_2 = 0;
	string str;
	fi >> num;
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
			cout << "-----------------------------------------------" << endl;
			fi.close();
			cin.get();
			create_year_semester(fi, fo);
		}
		else
		{
			fi.close();
			return;
		}
	}
	else
	{
		fi.close();
		fo.open("Data/Course/semester.txt");
		num = num + 1;
		fo << num << endl;
		for (int j = 0; j < i; j++)
		{
			fo << avai_semester[j].year << endl;
			if (compare(avai_semester[j].year, academic_year))
			{
				fo << 1 << endl;
				check_2 = 1;
				if (avai_semester[j].status == 0)
				{
					str = "Data/Course/" + avai_semester[j].year;
					const char* str1 = str.c_str();
					_mkdir(str1);
				}
			}
			else fo << avai_semester[j].status << endl;
			fo << avai_semester[j].seme1 << endl;
			if (compare(avai_semester[j].seme1, seme) && compare(avai_semester[j].year, academic_year))
			{
				fo << 1 << endl;
				str = "Data/Course/" + avai_semester[j].year + "/" + seme + ".txt";
			}
			else fo << avai_semester[j].status1 << endl;
			fo << avai_semester[j].seme2 << endl;
			if (compare(avai_semester[j].seme2, seme) && compare(avai_semester[j].year, academic_year))
			{
				fo << 1 << endl;
				str = "Data/Course/" + avai_semester[j].year + "/" + seme + ".txt";
			}
			else fo << avai_semester[j].status2 << endl;
			fo << avai_semester[j].seme3 << endl;
			if (compare(avai_semester[j].seme3, seme) && compare(avai_semester[j].year, academic_year))
			{
				fo << 1;
				str = "Data/Course/" + avai_semester[j].year + "/" + seme + ".txt";
			}
			else fo << avai_semester[j].status3;
			if (j < i - 1) fo << endl;
		}
		if (check_2 == 0)
		{
			fo << endl;
			fo << academic_year << endl;
			fo << 1 << endl;
			fo << "HK1" << endl;
			if (compare("HK1", seme)) fo << 1 << endl; else fo << 0 << endl;
			fo << "HK2" << endl;
			if (compare("HK2", seme)) fo << 1 << endl; else fo << 0 << endl;
			fo << "HK3" << endl;
			if (compare("HK3", seme)) fo << 1; else fo << 0;
			str = "Data/Course/" + academic_year;
			const char* str1 = str.c_str();
			_mkdir(str1);
			str = str + "/" + seme;
			fo.close();
			fo.open(str);
			fo.close();
		}
		else
		{
			fo.close();
			fo.open(str);
			fo.close();
		}
		cout << "Create successfully!!";
	}
}
void update_year_semester(ifstream& fi, ofstream& fo)
{
	string academic_year, year_alt;
	cout << "Please input the academic year you want to update: ";
	getline(cin, academic_year);
	cout << "Please input the alternative for that academic year: ";
	getline(cin, year_alt);
	string seme, seme_alt;
	cout << "Please input the semester you want to update: ";
	getline(cin, seme);
	cout << "Please input the alternative for that semester: ";
	getline(cin, seme_alt);
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
		getline(fi, avai_semester[i].seme1);
		getline(fi, avai_semester[i].seme1);
		fi >> avai_semester[i].status1;
		getline(fi, avai_semester[i].seme2);
		getline(fi, avai_semester[i].seme2);
		fi >> avai_semester[i].status2;
		getline(fi, avai_semester[i].seme3);
		getline(fi, avai_semester[i].seme3);
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
	fo << num << endl;
	for (int j = 0; j < i; j++)
	{
		if (avai_semester[j].year == academic_year)
		{
			fo << year_alt << endl;
			check_1 = 1;
			check_2 = 1;
		}
		else fo << avai_semester[j].year << endl;
		fo << avai_semester[j].status << endl;
		if ((avai_semester[j].seme1 == seme) && (check_1 == 1) && (avai_semester[j].status1 == 1))
		{
			fo << seme_alt << endl;
			check_3 = 1;
		}
		else fo << avai_semester[j].seme1 << endl;
		fo << avai_semester[j].status1 << endl;
		if ((avai_semester[j].seme2 == seme) && (check_1 == 1) && (avai_semester[j].status2 == 1))
		{
			fo << seme_alt << endl;
			check_3 = 1;
		}
		else fo << avai_semester[j].seme2 << endl;
		fo << avai_semester[j].status2 << endl;
		if ((avai_semester[j].seme2 == seme) && (check_1 == 1) && (avai_semester[j].status3 == 1))
		{
			fo << seme_alt << endl;
			check_3 = 1;
		}
		else fo << avai_semester[j].seme3 << endl;
		fo << avai_semester[j].status3;
		check_1 = 0;
	}
	char check_4;
	fo.close();
	fo.open("Data/Course/semester.txt");
	if ((check_2 == 0) || (check_3 == 0))
	{
		fo << num << endl;
		for (int j = 0; j < i; j++)
		{
			fo << avai_semester[j].year << endl;
			fo << avai_semester[j].status << endl;
			fo << avai_semester[j].seme1 << endl;
			fo << avai_semester[j].status1 << endl;
			fo << avai_semester[j].seme2 << endl;
			fo << avai_semester[j].status2 << endl;
			fo << avai_semester[j].seme3 << endl;
			fo << avai_semester[j].status3 << endl;
		}
		cout << "The academic year and the semester you want to update haven't existed!!!" << endl;
		cout << "Do you want to update again (y for yes and n for no): ";
		cin >> check_4;
		if (check_4 == 'y')
		{
			cout << "-----------------------------------------------" << endl;
			fo.close();
			cin.get();
			update_year_semester(fi, fo);
		}
		else
		{
			fo.close();
			return;
		}
	}
	else
	{
		cout << "Update successfully!!!" << endl;
		fo.close();
	}
}