#include "stdafx.h"
#include "Snake.h"

bool gameOver;
const int width = 20; // pelikent‰n leveys
const int height = 20; // ja korkeus
int x, y; // madon h‰nt‰p‰iden sijainnit
int fruitX, fruitY; // hedelmien sijainnit
int score; // peliss‰ ker‰tyt pisteet
int nTail; // h‰nn‰n pituus
int tailX[100], tailY[100]; // h‰nn‰n koordinaatit
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; // suunnat, mihin matoa voidaan liikuttaa
eDirection dir; // madon suunta

void Setup()
{
	gameOver = false; // peli k‰ynnistyy
	dir = STOP; // mato ei liiku mihink‰‰n, ennenkuin painetaan n‰pp‰int‰
	x = width / 2; // h‰nn‰n sijainti kent‰n keskelle 
	y = height / 2;
	fruitX = rand() % width; // asetetaan hedelm‰ randomisti pelikent‰lle
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	//system("cls"); // tyhj‰t‰‰n n‰yttˆ (aiheuttaa vilkkumisen)

				   // piirret‰‰n kent‰n rajat

				   // ensin "yl‰raja"

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		// tarkistaa, onko rivin eka
		for (size_t j = 0; j < width; j++)
		{
			// jos on -> piirret‰‰n aita vasemmalle
			if (j == 0)
				std::cout << "#";
			if (i == y && j == x)
				std::cout << "O"; // madon p‰‰
			else if (i == fruitY && j == fruitX)
				std::cout << "F"; // piirret‰‰n hedelm‰
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						std::cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					std::cout << " "; // piirret‰‰n tyhj‰
				}
			}


			// jos ollaan melkein rivin lopussa
			if (j == width - 1)
				std::cout << "#";
		}
		std::cout << std::endl;
	}

	// viimeisen‰ "alaraja"
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	std::cout << "Score: " << score << std::endl;
	std::cout << "Use asdw keys to move the snake" << std::endl;
	std::cout << "Press x to end the game" << std::endl;
}

void Input()
{
	// jos n‰pp‰int‰ painetaan, palautetaan positiivinen arvo
	// jos ei -> palautetaan 0
	if (_kbhit())
	{
		switch (_getch()) // palauttaa painetun n‰pp‰imen ASCIIn
		{
		case 'a':
			dir = LEFT; // kun painetaan a:ta -> menn‰‰n vasemmalle
			break;
		case 'd':
			dir = RIGHT; // kun painetaan d:ta -> menn‰‰n oikealle
			break;
		case 'w':
			dir = UP; // kun painetaan w:ta -> menn‰‰n ylˆs
			break;
		case 's':
			dir = DOWN; // kun painetaan a:ta -> menn‰‰n alas
			break;
		case 'x':
			std::cout << "Quitting game" << std::endl;
			Sleep(1500);
			gameOver = true; // lopetetaan peli
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT: // liikutaan x-akselilla vasemmalle
		system("cls");
		Draw();
		x--;
		break;
	case RIGHT: // liikutaan x-akselilla oikealle
		system("cls");
		Draw();
		x++;
		break;
	case UP: // liikutaan y-akselilla ylˆs
		system("cls");
		Draw();
		y--;
		break;
	case DOWN: // liikutaan y-akselilla alas
		system("cls");
		Draw();
		y++;
		break;
	default:
		break;
	}
	// tarkistaa, osuuko mato pelikent‰n reunoihin
	// jos osuu -> game over
	if (x > width || x < 0 || y > height || y < 0)
	{
		std::cout << "Game Over!" << std::endl;
		Sleep(1500);
		gameOver = true;
	}
	// jos mato osuu omaan h‰nt‰‰ns‰ -> gameover
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			std::cout << "Game Over!" << std::endl;
			Sleep(1500);
			gameOver = true;
		}
	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

Snake::Snake()
{
	Setup(); // metodi, joka alustaa pelin
	Draw(); // metodi, joka "piirt‰‰" madon
			// kun peli on k‰ynniss‰
	while (!gameOver)
	{
		//Draw(); // 
		Input(); // metodi, joka lukee painetut n‰pp‰imet
		Logic(); // metodi, joka sis‰lt‰‰ pelin logiikan = miten matoa liikutetaan
		Sleep(150);
	}
}

Snake::~Snake()
{

}