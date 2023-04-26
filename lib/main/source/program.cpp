#include "program.h"
#include "uniquePtr.h"
#include <iostream>

int* array(int* arr)
{
	return arr;
}

void Program::start()
{
	UniquePtr<int[]> u(new int[5]{ 1,2 });

	UniquePtr u2(new int(2));

	std::cout << *u << std::endl;
	std::cout << u.get() << std::endl;

	u2.release();

}