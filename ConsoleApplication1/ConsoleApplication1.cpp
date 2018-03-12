#include "stdafx.h"
#include "kirjastot.h"
#include "Snake.h"
#include <locale.h>
#include "tictac.h"

int main()
{
	setlocale(LC_ALL, "");
	int i = 0;
	std::string str;
	while (i != 5)
	{
		std::cout << "Choose game:\n(1) Poker\n(2) Tic-Tac-Toe\n(3) Snake\n(4) Some game\n(5) Quit program" << std::endl;
		std::cin >> i;
		switch (i)
		{
		case 1:
			std::cout << "not ready yet" << std::endl;
			break;
		case 2:
			tictac();
			system("cls");
			break;
		case 3:
			Snake();
			system("cls");
			break;
		case 4:
			std::cout << "no game here" << std::endl;
			break;
		case 5:
			str = "Quitting program";
			break;
		default:
			std::cout << "no game here" << std::endl;
			break;
		}
	}
	pause(str);
	return 0;
}