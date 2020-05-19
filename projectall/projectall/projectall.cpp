#include "function.h"

int main()
{
	std::ifstream fi;
	student* stu = nullptr;
	int num = 0;
	load_data_student(fi, stu, num);
	for (int i = 0; i < num-1; i++)
	{
		std::cout << stu[i].id << std::endl;
		std::cout << stu[i].name << std::endl;
		std::cout << stu[i].date.year << "-" << stu[i].date.month << "-" << stu[i].date.day << std::endl;
		std::cout << stu[i].classname << std::endl;
	}
	delete_data_student(stu, num);
	return 0;
}
