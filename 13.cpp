#include "13.h"

void createys( int& n , yearsem*& a) {
	ifstream fin;
	ofstream fout;
	char* year, * sem, status;
	fin.open("D:/TXT/semester.txt");
	if (!fin.is_open())
		cout << "Can not open file" << endl;
	else {
		fin >> n;
		fin.ignore(1);
		a = new yearsem[n];
		char temp1[15];
		char temp[10];
		for (int i = 0; i < n; i++) {
			fin.getline(temp1, 15);
			a[i].year = new char[strlen(temp1)+1];
			strcpy_s(a[i].year, strlen(temp1)+1, temp1);
			fin.getline(temp, 10);
			a[i].sem = new char[strlen(temp)+1];
			strcpy_s(a[i].sem, strlen(temp)+1, temp);
			fin >> a[i].status;
			fin.ignore(1);
		}
		fin.close();
	}
	year = new char[10];
	sem = new char[4];
	cin.get(year, 10);
	cin.ignore();
	cin.get(sem, 4);
	cin.ignore();
	cin >> status;
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].year, year) == 0 && strcmp(a[i].sem, sem) == 0) {
			check = true;
			break;
		}
	}
	if (check == true) {
		cout << "Available academic year and semester." << endl;
		return;
	}
	else {
		fout.open("D:/TXT/semester.txt");
		if (!fout.is_open())
			cout << "Can not open file" << endl;
		else {
			fout << n + 1 << endl;
			for (int i = 0; i < n; i++) {
				fout << a[i].year << endl;
				fout << a[i].sem << endl;
				fout << a[i].status << endl;
			}
			fout << year << endl;
			fout << sem << endl;
			fout << status << endl;
		}
		fout.close();
	}
	delete[]a;
	delete[]year;
	delete[]sem;
}
void deleteys(int&n, yearsem*&a) {
	ifstream fin;
	ofstream fout;
	fin.open("D:/TXT/semester.txt");
	if (!fin.is_open())
		cout << "Can not open file" << endl;
	else {
		fin >> n;
		fin.ignore(1);
		a = new yearsem[n];
		char temp1[15];
		char temp[10];
		for (int i = 0; i < n; i++) {
			fin.getline(temp1, 15);
			a[i].year = new char[strlen(temp1) + 1];
			strcpy_s(a[i].year, strlen(temp1) + 1, temp1);
			fin.getline(temp, 10);
			a[i].sem = new char[strlen(temp) + 1];
			strcpy_s(a[i].sem, strlen(temp) + 1, temp);
			fin >> a[i].status;
			fin.ignore(1);
		}
		fin.close();
	}
	char* year, * sem;
	year = new char[10];
	sem = new char[4];
	cin.get(year, 10);
	cin.ignore();
	cin.get(sem, 4);
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].year, year) == 0 && strcmp(a[i].sem, sem) == 0)
			a[i].status = '0';
			
	}
	fout.open("D:/TXT/semester.txt");
	if (!fout.is_open())
		cout << "Can not open file" << endl;
	else {
		fout << n << endl;
		for (int i = 0; i < n; i++) {
			fout << a[i].year << endl;
			fout << a[i].sem << endl;
			fout << a[i].status << endl;
		}
	}
	fout.close();
	delete[]a;
	delete[]year;
	delete[]sem;
}
void viewys( int& n, yearsem*& a) {
	ifstream fin;
	fin.open("D:/TXT/semester.txt");
	if (!fin.is_open())
		cout << "Can not open file" << endl;
	else {
		fin >> n;
		fin.ignore(1);
		a = new yearsem[n];
		char temp1[15];
		char temp[10];
		for (int i = 0; i < n; i++) {
			fin.getline(temp1, 15);
			a[i].year = new char[strlen(temp1) + 1];
			strcpy_s(a[i].year, strlen(temp1) + 1, temp1);
			fin.getline(temp, 10);
			a[i].sem = new char[strlen(temp) + 1];
			strcpy_s(a[i].sem, strlen(temp) + 1, temp);
			fin >> a[i].status;
			fin.ignore(1);
		}
		fin.close();
	}
	cout << "No" << setw(10) << "Year" << setw(20) << "Semester" << endl;
	for (int i = 0; i < n; i++) {
		if (a[i].status != '0')
		cout << i + 1 <<setw(16)<<a[i].year<<setw(10)<<a[i].sem<< endl;
	}
	delete[]a;
}

void addacourse(academicyear*& a, int& n)
{
	ifstream fin;
	ofstream fout;
	course c;
	char temp1[50];
	char temp[20];
	fin.open("D:/TXT/semester.txt");
	if (!fin.is_open())
		cout << "Can not open file" << endl;
	//load file from semester.txt
	else {
		fin >> n;
		fin.ignore(1);
		a = new academicyear[n];
		for (int i = 0; i < n; i++) {
			fin.getline(temp1, 50);
			a[i].year = new char[strlen(temp1) + 1];
			strcpy_s(a[i].year, strlen(temp1) + 1, temp1);
			fin >> a[i].numsem;
			fin.ignore(1);
			a[i].sem = new academicsem[a[i].numsem];
			for (int j = 0; j < a[i].numsem; j++) {
				fin.getline(temp1, 50);
				a[i].sem[j].semName = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].semName, strlen(temp1) + 1, temp1);
				fin >> a[i].sem[j].numcourse;
				fin.ignore(1);
				a[i].sem[j].cou = new course[a[i].sem[j].numcourse];
				for (int k = 0; k < a[i].sem[j].numcourse; k++) {
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].courseID = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].courseID, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].courseName = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].courseName, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].classname = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].classname, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].username = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].username, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].lecturerName = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].lecturerName, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].degree = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].degree, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].gender = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].gender, strlen(temp1) + 1, temp1);
					fin >> temp;
					a[i].sem[j].cou[k].start.year = new char[strlen(temp) + 1];
					strcpy_s(a[i].sem[j].cou[k].start.year, strlen(temp) + 1, temp);
					fin >> temp;
					a[i].sem[j].cou[k].start.day = new char[strlen(temp) + 1];
					strcpy_s(a[i].sem[j].cou[k].start.day, strlen(temp) + 1, temp);
					fin >> temp;
					a[i].sem[j].cou[k].start.month = new char[strlen(temp) + 1];
					strcpy_s(a[i].sem[j].cou[k].start.month, strlen(temp) + 1, temp);
					fin >> temp;
					a[i].sem[j].cou[k].end.year = new char[strlen(temp) + 1];
					strcpy_s(a[i].sem[j].cou[k].end.year, strlen(temp) + 1, temp);
					fin >> temp;
					a[i].sem[j].cou[k].end.day = new char[strlen(temp) + 1];
					strcpy_s(a[i].sem[j].cou[k].end.day, strlen(temp) + 1, temp);
					fin >> temp;
					a[i].sem[j].cou[k].end.month = new char[strlen(temp) + 1];
					strcpy_s(a[i].sem[j].cou[k].end.month, strlen(temp) + 1, temp);
					fin.ignore(1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].dayofweek = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].dayofweek, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].startHour = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].startHour, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].startMinute = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].startMinute, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].endHour = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].endHour, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].endMinute = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].endMinute, strlen(temp1) + 1, temp1);
					fin.getline(temp1, 50);
					a[i].sem[j].cou[k].room = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].room, strlen(temp1) + 1, temp1); fin.getline(temp1, 50);
					a[i].sem[j].cou[k].status = new char[strlen(temp1) + 1];
					strcpy_s(a[i].sem[j].cou[k].status, strlen(temp1) + 1, temp1);
				}
				fin.getline(temp1, 50);
				a[i].sem[j].status = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].status, strlen(temp1) + 1, temp1);
			}
			fin.getline(temp1, 50);
			a[i].status = new char[strlen(temp1) + 1];
			strcpy_s(a[i].status, strlen(temp1) + 1, temp1);
		}
		fin.close();
	}
	cout << "Infomation from file semester.txt has been taken to use in this task." << endl;
	cout << "Please enter some information of a course you want to add in: " << endl;
	cout << "Years: ";
	cin.get(temp1, 50);
	cin.ignore();
	cout << "Semester: ";
	cin.get(temp, 20);
	cin.ignore();
	int IndexY = -1, IndexS = -1; // luu vi tri years va semester (neu co)
	// tim co years va semester khong?
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].numsem; j++) {
			if (strcmp(a[i].year, temp1) == 0 && strcmp(a[i].status, "1") == 0 && strcmp(a[i].sem[j].semName, temp) == 0 && strcmp(a[i].sem[j].status, "1") == 0)
			{
				IndexY = i;
				IndexS = j;
				break;
			}
		}
	}
	if (IndexY == -1)
		cout << "This year/ semester does not exist or is not active anymore." << endl;
	// nhap thong tin couse can them vao va save course vo file semester.txt
	else {
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
		cout << "Gender: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.gender = new char[strlen(temp1) + 1];
		strcpy_s(c.gender, strlen(temp1) + 1, temp1);
		cout << "Start date: " << endl;
		cout << "Start year: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.start.year = new char[strlen(temp1) + 1];
		strcpy_s(c.start.year, strlen(temp1) + 1, temp1);
		cout << "Start day: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.start.day = new char[strlen(temp1) + 1];
		strcpy_s(c.start.day, strlen(temp1) + 1, temp1);
		cout << "Start month: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.start.month = new char[strlen(temp1) + 1];
		strcpy_s(c.start.month, strlen(temp1) + 1, temp1);
		cout << "End date: " << endl;
		cout << "End year: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.end.year = new char[strlen(temp1) + 1];
		strcpy_s(c.end.year, strlen(temp1) + 1, temp1);
		cout << "End day: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.end.day = new char[strlen(temp1) + 1];
		strcpy_s(c.end.day, strlen(temp1) + 1, temp1);
		cout << "End month: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.end.month = new char[strlen(temp1) + 1];
		strcpy_s(c.end.month, strlen(temp1) + 1, temp1);
		cout << "Day of week: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.dayofweek = new char[strlen(temp1) + 1];
		strcpy_s(c.dayofweek, strlen(temp1) + 1, temp1);
		cout << "Time: " << endl;
		cout << "Start hour: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.startHour = new char[strlen(temp1) + 1];
		strcpy_s(c.startHour, strlen(temp1) + 1, temp1);
		cout << "Start minute: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.startMinute = new char[strlen(temp1) + 1];
		strcpy_s(c.startMinute, strlen(temp1) + 1, temp1);
		cout << "End hour: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.endHour = new char[strlen(temp1) + 1];
		strcpy_s(c.endHour, strlen(temp1) + 1, temp1);
		cout << "End minute: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.endMinute = new char[strlen(temp1) + 1];
		strcpy_s(c.endMinute, strlen(temp1) + 1, temp1);
		cout << "Room: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.room = new char[strlen(temp1) + 1];
		strcpy_s(c.room, strlen(temp1) + 1, temp1);
		cout << "Status: ";
		cin.get(temp1, 50);
		cin.ignore();
		c.status = new char[strlen(temp1) + 1];
		strcpy_s(c.status, strlen(temp1) + 1, temp1);
		fout.open("D:/TXT/semester.txt");
		if (!fout.is_open())
			cout << "Can not open file." << endl;
		else {
			fout << n << endl;
			for (int i = 0; i < n; i++) {
				fout << a[i].year << endl;
				fout << a[i].numsem << endl;
				for (int j = 0; j < a[i].numsem; j++) {
					fout << a[i].sem[j].semName << endl;
					if (i == IndexY && j == IndexS)
						fout << a[i].sem[j].numcourse + 1 << endl;
					else
						fout << a[i].sem[j].numcourse << endl;
					for (int k = 0; k < a[i].sem[j].numcourse; k++) {
						fout << a[i].sem[j].cou[k].courseID << endl;
						fout << a[i].sem[j].cou[k].courseName << endl;
						fout << a[i].sem[j].cou[k].classname << endl;
						fout << a[i].sem[j].cou[k].username << endl;
						fout << a[i].sem[j].cou[k].lecturerName << endl;
						fout << a[i].sem[j].cou[k].degree << endl;
						fout << a[i].sem[j].cou[k].gender << endl;
						fout << a[i].sem[j].cou[k].start.year << " " << a[i].sem[j].cou[k].start.month << " " << a[i].sem[j].cou[k].start.day << endl;
						fout << a[i].sem[j].cou[k].end.year << " " << a[i].sem[j].cou[k].end.month << " " << a[i].sem[j].cou[k].end.day << endl;
						fout << a[i].sem[j].cou[k].dayofweek << endl;
						fout << a[i].sem[j].cou[k].startHour << endl;
						fout << a[i].sem[j].cou[k].startMinute << endl;
						fout << a[i].sem[j].cou[k].endHour << endl;
						fout << a[i].sem[j].cou[k].endMinute << endl;
						fout << a[i].sem[j].cou[k].room << endl;
						fout << a[i].sem[j].cou[k].status << endl;
					}
					if (i == IndexY && j == IndexS) {
						fout << c.courseID << endl;
						delete[]c.courseID;
						fout << c.courseName << endl;
						delete[]c.courseName;
						fout << c.classname << endl;
						delete[]c.classname;
						fout << c.username << endl;
						delete[]c.username;
						fout << c.lecturerName << endl;
						delete[]c.lecturerName;
						fout << c.degree << endl;
						delete[]c.degree;
						fout << c.gender << endl;
						delete[]c.gender;
						fout << c.start.year << " " << c.start.month << " " << c.start.day << endl;
						delete[]c.start.year;
						delete[]c.start.month;
						delete[]c.start.day;
						fout << c.end.year << " " << c.end.month << " " << c.end.day << endl;
						delete[]c.end.year;
						delete[]c.end.month;
						delete[]c.end.day;
						fout << c.dayofweek << endl;
						delete[]c.dayofweek;
						fout << c.startHour << endl;
						delete[]c.startHour;
						fout << c.startMinute << endl;
						delete[]c.startMinute;
						fout << c.endHour << endl;
						delete[]c.endHour;
						fout << c.endMinute << endl;
						delete[]c.endMinute;
						fout << c.room << endl;
						delete[]c.room;
						fout << c.status << endl;
						delete[]c.status;
					}
					fout << a[i].sem[j].status << endl;
				}
				fout << a[i].status << endl;
			}
		}
		cout << "Add a new course successfully!" << endl;
		fout.close();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].numsem; j++)
			delete[]a[i].sem[j].cou;
		delete[]a[i].sem;
	}
	delete[]a;
	cout << "Delete successfully" << endl;
}