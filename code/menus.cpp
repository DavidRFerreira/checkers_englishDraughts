#include "menus.h"

void openProgram(void)
{
	int i;

	clear();
	Sleep(2000);


	for (i = 0; i < 11; i++)
	{
		gotoxy(15, 10 + i);
		Sleep(65);

		if ((i == 0) || (i == 10))
			cout << "  ************";
		if ((i == 1) || (i == 9))
			cout << " *";
		else
			cout << "*";
	}

	for (i = 0; i < 11; i++)
	{
		gotoxy(33, 10 + i);
		Sleep(65);

		if (i == 5)
			cout << "**************";
		else
			cout << "*            *";
	}

	for (i = 0; i < 11; i++)
	{
		gotoxy(50, 10 + i);
		Sleep(65);

		if ((i == 0) || (i == 10) || (i == 5))
			cout << "**************";
		else
			cout << "*";
	}

	for (i = 0; i < 11; i++)
	{
		gotoxy(67, 10 + i);
		Sleep(65);

		if ((i == 0) || (i == 10))
			cout << "  ************";
		if ((i == 1) || (i == 9))
			cout << " *";
		else
			cout << "*";
	}

	for (i = 0; i < 11; i++)
	{
		gotoxy(87, 10 + i);
		Sleep(65);

		cout << "*";

		if (i == 5)
			cout << "**";
		if ((i == 6) || (i == 4))
			cout << " **";
		if ((i == 7) || (i == 3))
			cout << "  **";
		if ((i == 8) || (i == 2))
			cout << "   **";
		if ((i == 9) || (i == 1))
			cout << "    **";
		if ((i == 10) || (i == 0))
			cout << "     **";
	}

	for (i = 0; i < 11; i++)
	{
		gotoxy(99, 10 + i);
		Sleep(65);

		if ((i == 0) || (i == 10) || (i == 5))
			cout << "**************";
		else
			cout << "*";
	}
	
	for (i = 0; i < 11; i++)
	{
		gotoxy(119, 10 + i);
		Sleep(65);
		
		if (i == 0)
			cout << " ************";
		else if (i == 5)
			cout << " ******** ";
		else if ((i == 1) || (i == 10))
			cout << "*            *";
		else if ((i == 2) || (i == 9))
			cout << "*           *";
		else if ((i == 3) || (i == 8))
			cout << "*          *";
		else if ((i == 4) || (i == 7))
			cout << "*         *";
		else if (i == 6)
			cout << "*        *";
	
	}

	for (i = 0; i < 11; i++)
	{
		gotoxy(139, 10 + i);
		Sleep(75);

		if (i == 0)
			cout << "  *************";
		else if (i == 1)
			cout << "***";
		else if ((i == 2) || (i == 3))
			cout << "*";
		else if (i == 4)
			cout << " ***";
		else if (i == 5)
			cout << "   **********";
		else if (i == 6)
			cout << "            ***";
		else if ((i == 7) || (i == 8))
			cout << "              *";
		else if (i == 9)
			cout << "            ***";
		else
			cout << "*************";
	}

	Sleep(1500);
	gotoxy(74, 22);
	cout << "*** The Game ***";
	Sleep(2200);
	gotoxy(67, 22);
	cout << "*** With the American Rules ***";
	Sleep(2200);
	gotoxy(69, 26);
	print_slow("<<Press ENTER to Proceed>>", 50);
	gotoxy(81, 29);
	cin.get();
	mainMenu();
}

void mainMenu(void)
{
	int option_choosed;
	
	clear();

	gotoxy(51, 6);
	print_slow("|1| .......... Start a New Match - 2 Real Players.", 30);
	gotoxy(51, 8);
	print_slow("|2| .......... Start a New Match - Against a Bot.", 30);
	gotoxy(51, 10);
	print_slow("|3| .......... Restart from a Saved Match.", 30);
	gotoxy(51, 12);
	print_slow("|4| .......... Exit.", 30);
	gotoxy(53, 15);
	print_slow(">Insert your option: ", 30);
	cin >> option_choosed;

	switch (option_choosed)
	{
	case 1:
	{
		GAME startGame(1,0);
		startGame.playMatch("");
		mainMenu();
		break;
	}
	case 2:
	{
		GAME startGame(1, 1);
		startGame.playMatchBot("");
		mainMenu();
		break;
	}
	case 3:
	{
		string file_name, player2_file;
		char aux[100];

		clear();
		gotoxy(5, 5);
		cout << ">Insert the name of the file you want to open: ";
		cin >> file_name;
		player2_file = file_name + "_player2_info.txt";
		ifstream is;
		is.open(player2_file);
		is.getline(aux, sizeof(aux), ';');
		clear();

		if (*aux == 'B')
		{
			GAME startGame(0, 1);
			startGame.playMatchBot(file_name);
		}
		else if (*aux == 'R')
		{
			GAME startJogo(0, 0);
			startJogo.playMatch(file_name);
		}

		mainMenu();
		break;
	}
	case 4:
	{
		exitConfirmation();
		break;
	}
	}
}

void exitConfirmation(void)
{
	int answer;

	clear();

	gotoxy(20, 5);
	cout << "Do you really want to leave?";
	gotoxy(23, 6);
	cout << "|1| .......... Yes.";
	gotoxy(23, 7);
	cout << "|2| .......... No.";
	gotoxy(20, 10);
	cout << ">Insert your option: ";
	cin >> answer;

	if (answer == 1)
	{
		Sleep(200);
		clear();
		print_slow("!Closing the program ...", 40);
		Sleep(300);
		print_slow("\n!The Program was Closed.", 40);
		Sleep(100);
		exit(0);
	}
	else
	{
		clear();
		mainMenu();
	}
}


