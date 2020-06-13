#include "Course.h"

int main()
{
	std::ifstream fi;
	std::ofstream fo;
	course* cou = nullptr;
	int num = 0;
	std::string academicyear, seme;
	enterinfo(fi, academicyear, seme);
	load_data_course(fi, cou, num);
	create_allfile_course(fi, fo, cou, num, academicyear, seme);
	create_data_file(fi, fo, cou, num, academicyear, seme);
	delete[] cou;
	return 0;
}