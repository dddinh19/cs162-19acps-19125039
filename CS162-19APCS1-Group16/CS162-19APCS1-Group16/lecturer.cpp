#include "function.h"

//LECTURER VIEW LIST COURSE

void lecturer_course_data(std::string filename, course*& p, int& n) {
	std::ifstream fi(filename);
	if (!fi.is_open()) std::cout << "Data do not exist" << std::endl;
	else {
		fi >> n;
		p = new course[n];
		for (int i = 0; i < n; ++i) {
			fi >> p[i].courseID;
			fi >> p[i].numclass;
			p[i].p_class = new class_name[p[i].numclass];
			for (int j = 0; j < p[i].numclass; ++j) {
				fi >> p[i].p_class[j].classname;
			}
		}
		fi.close();
	}
}
void lecturer_view_list_course(lecturer* p, int k) {
	semester* p_year = nullptr;
	int n_year = 0;
	semester_data(p_year, n_year);
	int i, j;
	j = check_semester(p_year, n_year, i);
	if (i != -1 && j != -1) {
		course* p_course = nullptr;
		int n_course = 0;
		std::string filename = "Data/Login/lecturer/" + p[k].username + "/" + p_year[i].year + "/";
		if (j == 1) filename += p_year[i].sem1 + "/course.txt";
		if (j == 2) filename += p_year[i].sem2 + "/course.txt";
		if (j == 3) filename += p_year[i].sem3 + "/course.txt";
		lecturer_course_data(filename, p_course, n_course);
		if (p_course != nullptr) {
			for (int q = 0; q < n_course; ++q) {
				for (int m = 0; m < p_course[q].numclass; ++m) {
					filename = "Data/Courses/" + p_year[i].year + "/";
					if (j == 1) filename += p_year[i].sem1 + "/" + p_course[q].courseID + "/" + p_course[q].p_class[m].classname + "/info.txt";
					if (j == 2) filename += p_year[i].sem2 + "/" + p_course[q].courseID + "/" + p_course[q].p_class[m].classname + "/info.txt";
					if (j == 3) filename += p_year[i].sem3 + "/" + p_course[q].courseID + "/" + p_course[q].p_class[m].classname + "/info.txt";
					course* a = nullptr;
					course_info_data(filename, a);
					view_course_info_data(a);
					delete a->p_class;
					delete a;
				}
			}
			for (int q = 0; q < n_course; ++q) delete[]p_course[q].p_class;
			delete[]p_course;
		}
	}
	delete[]p_year;
}