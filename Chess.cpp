#include <iostream>
#include "windows.h"
#include <conio.h>

using namespace std;

enum Move { LEFT = 97, RIGHT = 100, UP = 119, DOWN = 115, TP_UP = 113, TP_DOWN = 101, QUIT = 112 };

void Recogn_Input(Move& selection)
{
	//Функция преобразует нежелательный способ ввода в желательный (для enum)
	//Move selection = player.GetMove();

	switch (selection)
	{
	case 68:	//Введено 'D' или 'В' или 'в'
	case 130:
	case 162:
	{
		//player.SetMove(RIGHT);
		selection = RIGHT;
		break;
	}
	case 65:	//Введено 'A' или 'Ф' или 'ф'
	case 148:
	case 228:
	{
		//player.SetMove(LEFT);
		selection = LEFT;
		break;
	}
	case 87:	//Введено 'W' или 'Ц' или 'ц'
	case 150:
	case 230:
	{
		//player.SetMove(UP);
		selection = UP;
		break;
	}
	case 83:	//Введено 'S' или 'Ы' или 'ы'
	case 155:
	case 235:
	{
		//player.SetMove(DOWN);
		selection = DOWN;
		break;
	}
	case 81:	//Введено 'Q' или 'Й' или 'й'
	case 137:
	case 169:
	{
		//player.SetMove(TP_UP);
		selection = TP_UP;
		break;
	}
	case 69:	//Введено 'E' или 'У' или 'у'
	case 147:
	case 227:
	{
		//player.SetMove(TP_DOWN);
		selection = TP_DOWN;
		break;
	}
	case 80:	//Введено 'P' или 'з' или 'З'
	case 167:
	case 135:
	{
		//player.SetMove(QUIT);
		selection = QUIT;
		break;
	}
	}
}

void Print_Main_Screen(char elem_1, char elem_2)
{
	cout << endl;
	cout << "       CHESS" << endl << endl;

	cout << "    " << char(201);
	for (int i = 0; i < 8; i++)
		cout << char(205);
	cout << char(187) << endl;

	cout << "   " << elem_1 << char(186) << "  play  " << char(186) << endl;

	cout << "    " << char(200);
	for (int i = 0; i < 8; i++)
		cout << char(205);
	cout << char(188) << endl;

	cout << "    " << char(201);
	for (int i = 0; i < 8; i++)
		cout << char(205);
	cout << char(187) << endl;

	cout << "   " << elem_2 << char(186) << "  quit  " << char(186) << endl;

	cout << "    " << char(200);
	for (int i = 0; i < 8; i++)
		cout << char(205);
	cout << char(188) << endl;

	cout << endl;
	cout << "use W, S to switch";
}

bool Main_Screen()
{
	//Функция отвечает за взаимодействие с главным экраном

	Move selection = Move(0);	//Возможность выбора

	int choice = 1;				//Выбранный элемент
	char elem_1, elem_2;		//Символы, показывающие какой элемент выбран

	Print_Main_Screen(char(254), ' ');	//Вывод главного экрана

	//Ожидание нажатия Enter
	while (_kbhit && selection != 13)
	{
		selection = (Move)_getch();

		if (selection != 13)
			Recogn_Input(selection);	//Опознание вводимых данных
		else
			break;

		//Перемещение между полями выбора
		if (selection == UP || selection == DOWN)
			choice == 1 ? choice = 2 : choice = 1;

		//Присвоение показывающим выбранный элемент символам нужные коды для отображения
		if (choice == 1)
		{
			elem_1 = 254;
			elem_2 = ' ';
		}
		else
		{
			elem_1 = ' ';
			elem_2 = 254;
		}

		system("cls");
		Print_Main_Screen(elem_1, elem_2);	//Вывод главного экрана
	}

	system("cls");

	if (choice == 1)
	{
		return false;
	}
	return true;
}

void PrintBoard()
{

}

int main()
{
	system("chcp 65001");
	system("cls");
	cout << "\n\n";
	cout << u8"  \u2656 \u2658 \u2657 \u2655 \u2654 \u2657 \u2658 \u2656" << endl;
	cout << u8"  \u2659 \u2659 \u2659 \u2659 \u2659 \u2659 \u2659 \u2659" << endl;
	cout << "\n\n\n\n";
	cout << u8"  \u265F\u265F\u265F\u265F\u265F\u265F\u265F\u265F" << endl;
	cout << u8"  \u265C \u265E \u265D \u265A \u265B \u265D \u265E \u265C" << endl;
	cout << "\n\n\n\n";
	//cout << u8"\u2654 \u2655 \u2656 \u2657 \u2658 \u2659 \u265A \u265B \u265C \u265D \u265E \u265F";


	/*bool quitGame;
	quitGame = Main_Screen();
	if (!quitGame)
	{
		cout << '+';
	}*/

	/*for (int i = 0; i < 512; i++)
	{
		cout << char(i) << " " << i << endl;
	}*/
}