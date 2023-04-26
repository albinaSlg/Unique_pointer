#include "program.h"
#include <Windows.h>
#include <stdexcept>

int main()
{
	try
	{
		//auto program = std::make_unique<Program>();
		Program program;
		program.start();
	}
	catch (std::runtime_error& err)
	{
		MessageBoxA(nullptr, err.what(), "runtime error", MB_OK);
	}
	catch (std::exception& err)
	{
		MessageBoxA(nullptr, err.what(), "std error", MB_OK);
	}
	catch (...)
	{
		MessageBoxA(nullptr, "", "undefined error", MB_OK);
	}
	return 0;
}