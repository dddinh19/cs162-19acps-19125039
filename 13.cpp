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

void addacourse(yearsem*& a, course*& c, int& na, int& nc) {
	ifstream fin;
	ofstream fout;
	fin.open("D:/TXT/semester.txt");
	if (!fin.is_open())
		cout << "Can not open file" << endl;
	else {
		fin >> na;
		fin.ignore(1);
		a = new yearsem[na];
		char temp1[15];
		char temp[10];
		for (int i = 0; i < na; i++) {
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
}