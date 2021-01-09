#include <iostream>
#include "GameFunctions.h"
using namespace std;


int main() {
	// variable declarations
	int game_status = 0;	// 1 = player1 wins, 2 = player2 wins, 3 = tie, 0 = unfinished
	bool is_there_a_tie = false;
	const int NUMBER_OF_ROWS = 3;
	const int NUMBER_OF_COLUMNS = 3;
	char game_board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] =
	{ '1', '2', '3',
	 '4', '5', '6',
	 '7', '8', '9' };

	// intoduction to the game and its rules
	cout << "Welcome to the game Tic-Tac-Toe!\n";
	cout << "You guys know the rules, no need for me to explain them.\n";
	cout << "Player 1 wil be 'X' and player 2 will be 'O'\n";
	cout << "Player 1 goes first; decide between the two of you who will be player 1 and 2...\n";
	system("pause"); // pauses terminal window
	system("cls");   // clears terminal window

	// this is where the game executes and where much of the work/playing is done
	while (game_status == 0) {
		// player 1 goes first; the game board is shown, the player makes their move, 
		// and the program checks for a win, for a tie, or for the next player to go
		showGameBoard(game_board);
		playerOneInput(game_board);
		game_status = checkForWin(game_board, NUMBER_OF_ROWS, NUMBER_OF_COLUMNS);
		// check if there is a win
		if (game_status == 1 || game_status == 2)
			break;

		// determine if the game can continue or if there is a tie
		is_there_a_tie = checkForTie(game_board);
		if (is_there_a_tie) {
			game_status = 3;
			break;
		}
		system("cls");

		// player 2 then makes their move; entire process is repeated 
		showGameBoard(game_board);
		playerTwoInput(game_board);
		game_status = checkForWin(game_board, NUMBER_OF_ROWS, NUMBER_OF_COLUMNS);
		// check if there is a win
		if (game_status == 1 || game_status == 2)
			break;

		// determine if the game can continue or if there is a tie
		is_there_a_tie = checkForTie(game_board);
		if (is_there_a_tie) {
			game_status = 3;
			break;
		}
		system("cls");
	}

	system("cls");
	showGameBoard(game_board);
	// display results of the game
	switch (game_status) {
	case 3:
		cout << "\nThere is a tie. Neither of you idiots won. What a great waste of time.\n";
		break;
	case 1:
		cout << "\nPlayer 1, WINS!!!\n";
		break;
	case 2:
		cout << "\nPlayer 2, is VICTORIOUS!!!\n";
	}

	return 0;
}

