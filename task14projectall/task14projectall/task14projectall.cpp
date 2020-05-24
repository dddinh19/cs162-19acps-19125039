#include "Course.h"

int main()
{
	std::ifstream fi;
	course* cou = nullptr;
	int num = 0;
	enterinfo(fi);
	load_data_course(fi, cou, num);
	for (int i = 0; i < num - 1; i++)
	{
		std::cout << cou[i].id << ",";
		std::cout << cou[i].name << ",";
		std::cout << cou[i].classname << ",";
		std::cout << cou[i].dayofweek << ",";
		std::cout << cou[i].startdate.year << ",";
		std::cout << cou[i].startdate.month << ",";
		std::cout << cou[i].startdate.day << ",";
		std::cout << cou[i].enddate.year << ",";
		std::cout << cou[i].enddate.month << ",";
		std::cout << cou[i].enddate.day << ",";
		std::cout << cou[i].room << ",";
		std::cout << cou[i].lec.username << ",";
		std::cout << cou[i].lec.lecturerName << ",";
		std::cout << cou[i].lec.sex << ",";
		std::cout << cou[i].starthour << ",";
		std::cout << cou[i].startminute << ",";
		std::cout << cou[i].endhour << ",";
		std::cout << cou[i].endminute << ",";
		std::cout << cou[i].lec.degree << std::endl;
	}
	delete_data_course(cou, num);
	return 0;
}