#pragma once

#include <iostream>
using namespace std;

// global variable to hold number of columns of the game board
const int COLS = 3;

// showGameBoard function prints the game board to the players
void showGameBoard(char board[][COLS]) {
	// prints the game board
	cout << "  GAME BOARD\n--------------\n\n";
	cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << " ---|---|---" << endl;
	cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << " ---|---|---" << endl;
	cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl << endl;
}


// checkForWin function determines if player 1 or 2 has won the game
int checkForWin(char board[][COLS], int rows, int cols) {
	// variable to hold status of a win; automatically set to 0 to indicate there is no win
	int win_status = 0;
	// holds index value of the row of the game board that is being processed
	int row_index = 0;
	// holds index value of the column of the game board that is being processed
	int column_index = 0;

	// loop to iterate through each row of the game board and see if there is a match
	while (row_index < rows) {
		// proceeds to check if the first, second, and third index are equal to each other
		if (board[row_index][0] == board[row_index][1] && board[row_index][0] == board[row_index][2]) {
			// check if either player 1 or player 2 won
			if (board[row_index][0] == 'X')
				win_status = 1;
			else
				win_status = 2;
		}
		// increment lcp by one to iterate through each row of the game board
		row_index++;
	}

	// loop to iterate through each column of the board and see if there is a match
	while (column_index < cols) {
		// checks if the first, second, and third index are equal
		if (board[0][column_index] == board[1][column_index] && board[0][column_index] == board[2][column_index]) {
			// check if either player 1 or player 2 won
			if (board[0][column_index] == 'X')
				win_status = 1;
			else
				win_status = 2;
		}
		// increment lcp by one to iterate through each column of the board
		column_index++;
	}

	// checks if there is a back-slash diagonal match
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		// check if either player 1 or player 2 won
		if (board[0][0] == 'X')
			win_status = 1;
		else
			win_status = 2;
	}
	// checks if there is a forward-slash diagonal match if there isn't a back-slash match
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		// check if either player 1 or player 2 won
		if (board[0][2] == 'X')
			win_status = 1;
		else
			win_status = 2;
	}

	return win_status;
}

// playerOneInput function gets input from player one on where they want to place
// their mark and checks that it has not been filled already
void playerOneInput(char board[][COLS]) {
	int input = 1;

	// prompt user to enter where they want to place their mark/piece
	cout << "Player 1, enter which number you would like to place your mark:\n";
	cin >> input;

	// determine where on the board the user has decided to make their move; make sure that it is a spot
	// that has not been used up already and that the user inputs a valid number
	if (input == 1 && board[0][0] == '1') {
		board[0][0] = 'X';
	}
	else if (input == 2 && board[0][1] == '2') {
		board[0][1] = 'X';
	}
	else if (input == 3 && board[0][2] == '3') {
		board[0][2] = 'X';
	}
	else if (input == 4 && board[1][0] == '4') {
		board[1][0] = 'X';
	}
	else if (input == 5 && board[1][1] == '5') {
		board[1][1] = 'X';
	}
	else if (input == 6 && board[1][2] == '6') {
		board[1][2] = 'X';
	}
	else if (input == 7 && board[2][0] == '7') {
		board[2][0] = 'X';
	}
	else if (input == 8 && board[2][1] == '8') {
		board[2][1] = 'X';
	}
	else if (input == 9 && board[2][2] == '9') {
		board[2][2] = 'X';
	}
	else {
		cout << "Invalid input idiot. You just lost a turn\n";
	}
}

// playerTwoInput function gets input from player two on where they want to place
// their mark and checks that it has not been filled already
void playerTwoInput(char board[][COLS]) {
	int input = 0;

	// prompt user to enter where they want to place their mark/piece
	cout << "Okay player 2, enter which number you would like to place your mark:\n";
	cin >> input;

	// determine where on the board the user has decided to make their move; make sure that it is a spot
	// that has not been used up already and that the user inputs a valid number
	if (input == 1 && board[0][0] == '1') {
		board[0][0] = 'O';
	}
	else if (input == 2 && board[0][1] == '2') {
		board[0][1] = 'O';
	}
	else if (input == 3 && board[0][2] == '3') {
		board[0][2] = 'O';
	}
	else if (input == 4 && board[1][0] == '4') {
		board[1][0] = 'O';
	}
	else if (input == 5 && board[1][1] == '5') {
		board[1][1] = 'O';
	}
	else if (input == 6 && board[1][2] == '6') {
		board[1][2] = 'O';
	}
	else if (input == 7 && board[2][0] == '7') {
		board[2][0] = 'O';
	}
	else if (input == 8 && board[2][1] == '8') {
		board[2][1] = 'O';
	}
	else if (input == 9 && board[2][2] == '9') {
		board[2][2] = 'O';
	}
	else {
		cout << "Invalid input dumbass. You just lost your turn\n";
	}
}

// checkForTie function checks the game board for a tie
bool checkForTie(char board[][COLS]) {
	// check if the game board is filled with X's and O's
	if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' && board[1][1] != '5'
		&& board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9') {
		// if the above is true there is a tie and the game is over	
		return true;
	}
	// above is not true, game can continue
	else {
		return false;
	}
}
