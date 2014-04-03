/*
* David Adam Perez
* CS570 -- Assignment 1
* Dual User Tic-Tac-Toe
*/

#include <iostream>
#include <vector>

using namespace std;

//create tictactoe gameBoard
//char gameBoard[10] = {'0','1','2','3','4','5','6','7','8','9'};
vector<char> gameBoard(9, ' ');
bool game_over = false;


//method to check win / loss
void checkwin(bool player)
{
	bool win = false;
	if (gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2] && gameBoard[0] != ' ')
		win = true;
	else if (gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5] && gameBoard[3] != ' ')
		win = true;
	else if (gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8] && gameBoard[6] != ' ')
		win = true;
	else if (gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6] && gameBoard[0] != ' ')
		win = true;
	else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7] && gameBoard[1] != ' ')
		win = true;
	else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8] && gameBoard[2] != ' ')
		win = true;
	else if (gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8] && gameBoard[0] != ' ')
		win = true;
	else if (gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6] && gameBoard[2] != ' ')
		win = true;

	if (win == true)
	{
		if (player)
		{
			cout << "\nPlayer 1 wins!" << endl;
		}
		else if (!player)
		{
			cout << "\nPlayer 2 wins!" << endl;
		}
		game_over = true;
	}
}

void board()
{
	cout << "\n" << endl;
	cout << "  1   2   3" << endl;
	cout << "1 " << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << endl;
	cout << " ---+---+---" << endl;
	cout << "2 " << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << endl;
	cout << " ---+---+---" << endl;
	cout << "3 " << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << endl;
}

void playermove(int row, int col, int player)
{
	if (player == 1)
	{
		if (row == 1 && col == 1)
			gameBoard[0] = 'X';
		else if (row == 1 && col == 2)
			gameBoard[1] = 'X';
		else if (row == 1 && col == 3)
			gameBoard[2] = 'X';

		else if (row == 2 && col == 1)
			gameBoard[3] = 'X';
		else if (row == 2 && col == 2)
			gameBoard[4] = 'X';
		else if (row == 2 && col == 3)
			gameBoard[5] = 'X';

		else if (row == 3 && col == 1)
			gameBoard[6] = 'X';
		else if (row == 3 && col == 2)
			gameBoard[7] = 'X';
		else if (row == 3 && col == 3)
			gameBoard[8] = 'X';
	}

	else if (player == 2)
	{
		if (row == 1 && col == 1)
			gameBoard[0] = 'O';
		else if (row == 1 && col == 2)
			gameBoard[1] = 'O';
		else if (row == 1 && col == 3)
			gameBoard[2] = 'O';

		else if (row == 2 && col == 1)
			gameBoard[3] = 'O';
		else if (row == 2 && col == 2)
			gameBoard[4] = 'O';
		else if (row == 2 && col == 3)
			gameBoard[5] = 'O';

		else if (row == 3 && col == 1)
			gameBoard[6] = 'O';
		else if (row == 3 && col == 2)
			gameBoard[7] = 'O';
		else if (row == 3 && col == 3)
			gameBoard[8] = 'O';
	}
}

int main()
{
	int movecount = 0;
	bool currPlayer = true;
	int row_in;
	int col_in;

	board(); //draw initial board
	while (game_over != true)
	{
		if (movecount == 9)	//fail safe exit condition
		{
			cout << "\nNo winner, play again!" << endl;
			return 0;
		}


		if (currPlayer)
		{
			cout << "\n=== Player 1's turn ===" << endl;

			cout << "Please input row: ";
			cin >> row_in;
			while (row_in < 1 || row_in > 3)
			{
				cout << "\nEnter a number from 1 to 3.\n";
				cout << "Please input row: ";
				cin >> row_in;
			}

			cout << "Please input column: ";
			cin >> col_in;
			while (col_in < 1 || col_in > 3)
			{
				cout << "\nEnter a number from 1 to 3.\n";
				cout << "Please input column: ";
				cin >> col_in;
			}

			playermove(row_in, col_in, 1); 	//insert move
			movecount++;
			board();						//draw updated board
			checkwin(currPlayer);			//check win for current player
			currPlayer = false;				//switch player
		}

		else
		{
			cout << "\n=== Player 2's turn ===" << endl;

			cout << "Please input row: ";
			cin >> row_in;
			while (row_in < 1 || row_in > 3)
			{
				cout << "\nEnter a number from 1 to 3.\n";
				cout << "Please input row: ";
				cin >> row_in;
			}

			cout << "Please input column: ";
			cin >> col_in;
			while (col_in < 1 || col_in > 3)
			{
				cout << "\nEnter a number from 1 to 3.\n";
				cout << "Please input column: ";
				cin >> col_in;
			}

			playermove(row_in, col_in, 2);	//insert move
			movecount++;
			board();						//draw updated board
			checkwin(currPlayer);			//check win for current player
			currPlayer = true;				//switch player
		}

	}

	return 0;
}