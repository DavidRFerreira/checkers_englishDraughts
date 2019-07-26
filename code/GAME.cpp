#include "GAME.h"

GAME::GAME()
{
}

GAME::GAME(int newGame, int botexist)
{
	this->symbol = 'O';
	this->numCurrentPlayer = 0;
	this->numNextPlayer = 1;
	this->newMatch = newGame;
	this->bot = botexist;
}

GAME::~GAME()
{
}

char GAME::getRound(void)
{
	return this->symbol;
}

int GAME::getNumCurrentPlayer(void)
{
	return this->numCurrentPlayer;
}

int GAME::getNumNextPlayer(void)
{
	return this->numNextPlayer;
}

void GAME::changeRound(void)
{
	if (this->symbol == 'O')
	{
		this->symbol = 'X';
		this->numCurrentPlayer = 1;
		this->numNextPlayer = 0;
	}
	else if (this->symbol == 'X')
	{
		this->symbol = 'O';
		this->numCurrentPlayer = 0;
		this->numNextPlayer = 1;
	}
}

int GAME::playMatch(string file_name)
{
	REALPLAYER player[2];
	BOARD board;
	string name1, name2;
	int xo, yo, xf, yf;
	bool flag1;
	bool flag2;
	bool flag3;
	bool flag4;
	int space_question = 0, numPieceMove = 0, answer;
	string verify_file, player1_file, player2_file, board_file, pieces_file, game_file;
	int numCapture = -1, numCaptured = -1, xCaptured = -1, yCaptured = -1;


	if (this->newMatch) //True if the game is a new match.
	{
		do
		{
			clear();

			gotoxy(5, 5);
			cout << ">Insert the name for Player 1: ";
			cin >> name1;
			gotoxy(7, 6);
			cout << "Player 1 is going to play with the pieces 'O'.";
			gotoxy(5, 10);
			cout << ">Insert the name for Player 2: ";
			cin >> name2;
			gotoxy(7, 11);
			cout << "Player 2 is going to play with the pieces 'X'.";

			do
			{
				gotoxy(5, 15 + space_question);
				print_slow(">Insert the name for the files where the game is going to be saved (without .txt)? ", 30);
				cin >> file_name;
				verify_file = file_name + "_game.txt";
				ifstream ifile(verify_file);

				if (ifile.is_open()) //True if there is already a file with the same name.
				{
					flag3 = false;
					gotoxy(7, 16 + space_question);
					cout << "Attention: there is already a file with the same name!";
					gotoxy(10, 17 + space_question);
					cout << "|1| .......... I want to choose another name for the files.";
					gotoxy(10, 18 + space_question);
					cout << "|2| .......... I want to delete the old files.";
					gotoxy(7, 19 + space_question);
					cout << ">Insert your option: ";
					cin >> answer;

					if (answer != 2) //If player chose 1 or an invalid option, he is asked to choose a name again.
					{
						space_question = space_question + 7;
						flag3 = true;
					}
					else
					{
						flag3 = false;
					}
					ifile.close();
				}
				else
					flag3 = false;

			} while (flag3);

			gotoxy(5, 21 + space_question);
			print_slow("Do you confirm the information previously inserted? ", 30);
			gotoxy(8, 22 + space_question);
			cout << "|1| .......... Yes.";
			gotoxy(8, 23 + space_question);
			cout << "|2| .......... No.";
			gotoxy(5, 24 + space_question);
			cout << ">Insert your option: ";
			cin >> answer;

		} while (answer != 1);

		player[0].setNameSymbol(0, name1);
		player[1].setNameSymbol(1, name2);

		player[0].definePieces();
		player[1].definePieces();
		board.newGameOccupyPos();
	}
	else //If it is a match previously played (starting an old match from files).
	{
		player1_file = file_name + "_player1_info.txt";
		player2_file = file_name + "_player2_info.txt";
		board_file = file_name + "_board.txt";
		pieces_file = file_name + "_pieces.txt";
		game_file = file_name + "_game.txt";


		//Read the name of the players from the files.
		ifstream i1, i2, i3, i4;

		i1.open(player1_file);
		player[0].readFile(i1, 0);
		i1.close();

		i2.open(player2_file);
		player[1].readFile(i2, 1);
		i2.close();

		//Mark the occupied position in the board.
		i3.open(board_file);
		board.ReadFile(i3);
		i3.close();

		//Determine which player is going to play first.
		i4.open(game_file);
		this->readFile(i4);
		i4.close();
	}


	do
	{
		do
		{
			do
			{
				flag1 = flag2 = flag3 = flag4 = false;
				numCapture = 0;

				clear();
				board.drawBoard();
				player[0].drawPieces();
				player[1].drawPieces();


				gotoxy(85, 3);
				if (this->getRound() == 'O')
					cout << "PLAYER 1";
				else
					cout << "PLAYER 2";

				//Ask player to insert the source and destination coordinates. 
				gotoxy(85, 4);
				cout << player[this->getNumCurrentPlayer()].getName() << ", it is your turn to play...";
				gotoxy(89, 6);
				player[this->getNumCurrentPlayer()].askSourcePosition(&xo, &yo);
				gotoxy(89, 7);
				player[this->getNumCurrentPlayer()].askDestinationPosition(&xf, &yf);


				if (player[this->getNumCurrentPlayer()].doesPlayerOwnIt(xo, yo)) //True if the piece belongs to the player.
				{

					if (board.isPosFree(xf, yf)) //True if the destination-coordinate is free.
					{

						numPieceMove = findNumPeca(player[this->getNumCurrentPlayer()].getPieces(), xo, yo); //Piece that the player wants to move.


						if (player[this->getNumCurrentPlayer()].canPlayerCapture(-1, player[this->getNumNextPlayer()].getPieces())) //True if there is a possible capture.
						{

							flag2 = true;

							//True if the move choosed by the player captures a piece.
							if (player[this->getNumCurrentPlayer()].doesPlayerMoveCapture(numPieceMove, xf, yf, player[this->getNumNextPlayer()].getPieces(), &numCaptured, &xCaptured, &yCaptured))
							{
								player[this->getNumNextPlayer()].deletePiece(numCaptured);
								board.freePosition(xCaptured, yCaptured);

								flag1 = flag3 = true;
							}
							else
							{
								gotoxy(89, 9);
								cout << "....................................................";
								gotoxy(89, 10);
								cout << "Invalid Move: capturing a piece is always mandatory!";
								Sleep(1000);
								gotoxy(89, 11);
								print_slow("<<Press ENTER to try again!", 30);
								cin.get();
								cin.get();
							}
						}
						else
						{
							//True if the move is valid when there is no available capture.
							if (player[this->getNumCurrentPlayer()].getPiece(numPieceMove).isMoveValidwithout(xf, yf, player[this->getNumCurrentPlayer()].getPieces(), player[this->getNumNextPlayer()].getPieces()))
							{
								flag1 = true;
							}

						}
					}
				}


				if (flag1 == true)
				{
					player[this->getNumCurrentPlayer()].movePiece(numPieceMove, xf, yf);

					board.freePosition(xo, yo);
					board.occupyPosition(xf, yf);

					player[this->getNumCurrentPlayer()].didPlayerTurnQueen(numPieceMove);
				}
				else if (!flag1 && !flag2)
				{
					gotoxy(89, 9);
					cout << ".........................................";
					gotoxy(89, 10);
					cout << "Invalid Move: it is not possible to perform that move!";
					Sleep(1000);
					gotoxy(89, 11);
					print_slow("<<Press ENTER to try again!", 30);
					cin.get();
					cin.get();
				}

				//True if it is possible to do a second capture (after a capture already was made).
			} while (flag3 && player[this->getNumCurrentPlayer()].canPlayerCapture(numPieceMove, player[this->getNumNextPlayer()].getPieces()));

		} while (!flag1);

		//saves the information about the board to a file.
		ofstream os;
		board_file = file_name + "_board.txt";
		os.open(board_file);
		board.SaveFile(os);
		os.close();

		//saves the information about the current round to a file.
		game_file = file_name + "_game.txt";
		os.open(game_file);
		this->saveFile(os);
		os.close();

		//saves the name of the player to different files.
		player1_file = file_name + "_player1_info.txt";
		os.open(player1_file);
		player[0].saveFile(os);
		os.close();

		player2_file = file_name + "_player2_info.txt";
		os.open(player2_file);
		player[1].saveFile(os);
		os.close();


		this->changeRound();

		if ((player[0].checkIfPlayerHasNoPieces()) || (player[1].checkIfPlayerHasNoPieces()))
			flag4 = true;

	} while (!flag4);


	if (flag4) //a player lost.
	{
		clear();
		gotoxy(10, 5);

		if (player[0].checkIfPlayerHasNoPieces())
			cout << "PLAYER 1, " << player[0].getName() << ", lost!";
		else
			cout << "PLAYER 2, " << player[1].getName() << ", lost!";

		gotoxy(10, 6);
		cout << "<<Press ENTER to return to the Main Menu>>";
		cin.get();
		cin.get();
	}

	return 0;
}

int GAME::playMatchBot(string file_name)
{

	REALPLAYER player0;
	BOTPLAYER player1;
	BOARD board;
	string name1;
	int xo, yo, xf, yf;
	bool flag1;
	bool flag2;
	bool flag3;
	bool flag4;
	int space_question = 0, numPieceMove = 0, answer;
	string verify_file, player1_file, player2_file, board_file, piece_file, game_file;
	int numCapture = -1, numCaptured = -1, xCaptured = -1, yCaptured = -1;


	if (this->newMatch) //True se o jogo é uma partida nova.
	{
		do
		{
			clear();

			gotoxy(5, 5);
			cout << ">Insert the name for Player 1 (real): ";
			cin >> name1;
			gotoxy(7, 6);
			cout << "Player 1 is going to play with the pieces 'O'.";
			gotoxy(5, 10);
			cout << ">The name of Player 2 is (bot): BOT";
			gotoxy(7, 11);
			cout << "Player 2 is going to play with the pieces 'X'.";

			do
			{
				gotoxy(5, 15 + space_question);
				print_slow(">Insert the name for the files where the game is going to be saved (without .txt)? ", 30);
				cin >> file_name;
				verify_file = file_name + "_game.txt";
				ifstream ifile(verify_file);

				if (ifile.is_open()) //True if there is already a file with the same name.
				{
					flag3 = false;
					gotoxy(7, 16 + space_question);
					cout << "Attention: there is already a file with the same name!";
					gotoxy(10, 17 + space_question);
					cout << "|1| .......... I want to choose another name for the files.";
					gotoxy(10, 18 + space_question);
					cout << "|2| .......... I want to delete the old files";
					gotoxy(7, 19 + space_question);
					cout << ">Insert your option: ";
					cin >> answer;

					if (answer != 2) 
					{
						space_question = space_question + 7;
						flag3 = true;
					}
					else
					{
						flag3 = false;
					}
					ifile.close();
				}
				else
					flag3 = false;

			} while (flag3);

			gotoxy(5, 21 + space_question);
			print_slow("Do you confirm the information previously inserted? ", 30);
			gotoxy(8, 22 + space_question);
			cout << "|1| .......... Yes.";
			gotoxy(8, 23 + space_question);
			cout << "|2| .......... No.";
			gotoxy(5, 24 + space_question);
			cout << ">Insert your option: ";
			cin >> answer;

		} while (answer != 1);

		player0.setNameSymbol(0, name1);

		player0.definePieces();
		player1.definePieces();
		board.newGameOccupyPos();
	}
	else //if it is an "old" match (previously saved).
	{

		player1_file = file_name + "_player1_info.txt";
		player2_file = file_name + "_player2_info.txt";
		board_file = file_name + "_board.txt";
		piece_file = file_name + "_pieces.txt";
		game_file = file_name + "_game.txt";

		ifstream i1, i2, i3, i4;

		i1.open(player1_file);
		player0.readFile(i1, 0);
		i1.close();

		i2.open(player2_file);
		player1.readFile(i2, 1);
		i2.close();

		i3.open(board_file);
		board.ReadFile(i3);
		i3.close();

		i4.open(game_file);
		this->readFile(i4);
		i4.close();
	}

	srand((unsigned)time(NULL));

	do
	{

		do
		{
			clear();
			board.drawBoard();
			player0.drawPieces();
			player1.drawPieces();

			flag1 = flag2 = flag3 = flag4 = false;
			numCapture = 0;

			if (this->getRound() == 'O')
			{
				do
				{

					gotoxy(85, 3);
					cout << "PLAYER 1";

					//Ask the real player for the source and destination coordinates.
					gotoxy(85, 4);
					cout << player0.getName() << ", it is is your turn to play...";
					gotoxy(89, 6);
					player0.askSourcePosition(&xo, &yo);
					gotoxy(89, 7);
					player0.askDestinationPosition(&xf, &yf);

					if (player0.doesPlayerOwnIt(xo, yo)) //True if the piece belongs to the player.
					{

						if (board.isPosFree(xf, yf)) //True if the destination is free.
						{

							numPieceMove = findNumPeca(player0.getPieces(), xo, yo); //Piece which the player wants to move.


							if (player0.canPlayerCapture(-1, player1.getPieces())) //True if there is a capture available to the player.
							{

								flag2 = true;

								//True if the move captures a piece.
								if (player0.doesPlayerMoveCapture(numPieceMove, xf, yf, player1.getPieces(), &numCaptured, &xCaptured, &yCaptured))
								{
									player1.deletePiece(numCaptured);
									board.freePosition(xCaptured, yCaptured);

									flag1 = flag3 = true;
								}
								else 
								{
									gotoxy(89, 9);
									cout << "....................................................";
									gotoxy(89, 10);
									cout << "Invalid Move: it is not possible to perform that move!";
									Sleep(1000);
									gotoxy(89, 11);
									print_slow("<<Press ENTER to try again!", 30);
									cin.get();
									cin.get();
								}
							}
							else
							{
								//True if the move is valid when there is no available capture.
								if (player0.getPiece(numPieceMove).isMoveValidwithout(xf, yf, player0.getPieces(), player1.getPieces()))
								{
									flag1 = true;
								}

							}
						}
					}
				
					if (flag1 == true)
					{
						player0.movePiece(numPieceMove, xf, yf);

						board.freePosition(xo, yo);
						board.occupyPosition(xf, yf);

						player0.didPlayerTurnQueen(numPieceMove);
					}
					else if (!flag1 && !flag2)
					{
						gotoxy(89, 9);
						cout << ".........................................";
						gotoxy(89, 10);
						cout << "Invalid Move : it is not possible to perform that move!";
						Sleep(1000);
						gotoxy(89, 11);
						print_slow("<<Press ENTER to try again!", 30);
						cin.get();
						cin.get();
					}

					//True if it is possible to do a second capture (after a capture was already made).
				} while (flag3 && player0.canPlayerCapture(numPieceMove, player1.getPieces()));
			}
			else //if it is bot's turn. Bot is dumb. He just randomly chooses a move until one that is valid is found.
			{
				gotoxy(85, 3);
				cout << "PLAYER 2";
				gotoxy(85, 4);
				cout << player1.getName() << " is planning his move...";
				Sleep(1500);

				do
				{
					
					player1.randomPosition(&xo, &yo);
					player1.randomPosition(&xf, &yf);

					if (player1.doesPlayerOwnIt(xo, yo)) 
					{

						if (board.isPosFree(xf, yf))
						{

							numPieceMove = findNumPeca(player1.getPieces(), xo, yo); 

							if (player1.canPlayerCapture(-1, player0.getPieces())) 
							{
								if (player1.doesPlayerMoveCapture(numPieceMove, xf, yf, player0.getPieces(), &numCaptured, &xCaptured, &yCaptured))
								{
									player0.deletePiece(numCaptured);
									board.freePosition(xCaptured, yCaptured);

									flag1 = true;
								}
							}
							else
							{
								if (player1.getPiece(numPieceMove).isMoveValidwithout(xf, yf, player1.getPieces(), player0.getPieces()))
								{
									flag1 = true;
								}

							}

							if (flag1 == true)
							{
								player1.movePiece(numPieceMove, xf, yf);

								board.freePosition(xo, yo);
								board.occupyPosition(xf, yf);

								player1.didPlayerTurnQueen(numPieceMove);
							}
						}
					}
				} while (!flag1);
			}
		} while (!flag1);

		ofstream os;
		board_file = file_name + "_board.txt";
		os.open(board_file);
		board.SaveFile(os);
		os.close();

		game_file = file_name + "_game.txt";
		os.open(game_file);
		this->saveFile(os);
		os.close();

		player1_file = file_name + "_player1_info.txt";
		os.open(player1_file);
		player0.saveFile(os);
		os.close();

		player2_file = file_name + "_player2_info.txt";
		os.open(player2_file);
		player1.saveFile(os);
		os.close();


		this->changeRound();

		if ((player0.checkIfPlayerHasNoPieces()) || (player1.checkIfPlayerHasNoPieces()))
			flag4 = true;

	} while (!flag4);


	if (flag4) //if a player lost the game.
	{
		clear();
		gotoxy(10, 5);

		if (player0.checkIfPlayerHasNoPieces())
			cout << "PLAYER 1, " << player0.getName() << ", lost the game!";
		else
			cout << "PLAYER 2, " << player1.getName() << ", lost the game!";

		gotoxy(10, 6);
		cout << "<<Press ENTER to return to the Main Menu>>";
		cin.get();
		cin.get();
	}

	return 0;
}

void GAME::saveFile(ofstream &os)
{
	if (!os)
		return;

	os << this->getRound() << ";";
}

void GAME::readFile(ifstream &is)
{
	char aux[5];
	is.getline(aux, sizeof(aux), ';');
	this->symbol = *aux;

	this->changeRound();
}