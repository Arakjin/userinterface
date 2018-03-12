#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cstdlib>

void pause(std::string str)
{
	std::cout << str << "\nPress any key to continue" << std::endl;
	_getch();
}