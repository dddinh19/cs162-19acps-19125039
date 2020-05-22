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

void loadSMTfile(ifstream& fin, int& n, academicyear*& a) {
	char temp1[50];
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
				fin >> temp1;
				a[i].sem[j].cou[k].start.year = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].cou[k].start.year, strlen(temp1) + 1, temp1);
				fin >> temp1;
				a[i].sem[j].cou[k].start.day = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].cou[k].start.day, strlen(temp1) + 1, temp1);
				fin >> temp1;
				a[i].sem[j].cou[k].start.month = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].cou[k].start.month, strlen(temp1) + 1, temp1);
				fin >> temp1;
				a[i].sem[j].cou[k].end.year = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].cou[k].end.year, strlen(temp1) + 1, temp1);
				fin >> temp1;
				a[i].sem[j].cou[k].end.day = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].cou[k].end.day, strlen(temp1) + 1, temp1);
				fin >> temp1;
				a[i].sem[j].cou[k].end.month = new char[strlen(temp1) + 1];
				strcpy_s(a[i].sem[j].cou[k].end.month, strlen(temp1) + 1, temp1);
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
	cout << "Start date: " << endl;
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
	cout << "End date: " << endl;
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
	cout << "Time: " << endl;
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
	fout << c.courseID << endl;
	fout << c.courseName << endl;
	fout << c.classname << endl;
	fout << c.username << endl;
	fout << c.lecturerName << endl;
	fout << c.degree << endl;
	fout << c.gender << endl;
	fout << c.start.year << " " << c.start.month << " " << c.start.day << endl;
	fout << c.end.year << " " << c.end.month << " " << c.end.day << endl;
	fout << c.dayofweek << endl;
	fout << c.startHour << endl;
	fout << c.startMinute << endl;
	fout << c.endHour << endl;
	fout << c.endMinute << endl;
	fout << c.room << endl;
	fout << c.status << endl;
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
void addacourse(academicyear*& a, int& n)
{
	ifstream fin;
	ofstream fout;
	course c;
	char temp1[50];
	fin.open("D:/TXT/semester.txt");
	if (!fin.is_open())
		cout << "Can not open file" << endl;
	else {
		loadSMTfile(fin, n, a);
	}
	cout << "Infomation from file semester.txt has been taken to use in this task." << endl;
	cout << "Please enter some information of a course you want to add in: " << endl;
	cout << "Years: ";
	cin.get(temp1, 50);
	cin.ignore();
	char temp[20];
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
		inputaCourse(c);
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
						saveaCourse(fout, a[i].sem[j].cou[k]);
					}
					if (i == IndexY && j == IndexS) {
						saveaCourse(fout, c);
						deleteaCourseinMemory(c);
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
			for (int k = 0; k < a[i].sem[j].numcourse; k++)
				deleteaCourseinMemory(a[i].sem[j].cou[k]);
		delete[]a[i].sem;
	}
	delete[]a;
	cout << "Delete successfully." << endl;
}