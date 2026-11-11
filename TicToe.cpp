#include <iostream>
#include <string>
using namespace std;

const string MARGIN(25, ' ');

void printBoard(char board[3][3]) {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		cout << MARGIN << "         |         |\n";
		cout << MARGIN;
		for (int j = 0; j < 3; j++) {
			cout << "    " << board[i][j] << "    ";
			if (j < 2) cout << "|";
		}
		cout << "\n";
		cout << MARGIN << "         |         |\n";
		if (i < 2) cout << MARGIN << "---------+---------+---------\n";
	}
	cout << "\n";
}

bool checkWin(char board[3][3], char player) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return true;
	}

	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return true;

	return false;
}

bool isBoardFull(char board[3][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return false;
	return true;
}

int main() {
	cout << MARGIN << "=============================\n";
	cout << MARGIN << "   Welcome to Tic Tac Toe!   \n";
	cout << MARGIN << "=============================\n";

	char board[3][3];
	int counter = 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '0' + counter;
			counter++;
		}
	}

	cout << "\nPlayer 1 is X and Player 2 is O\n";
	cout << "Player 1 starts first.\n";
	cout << "Enter a number (1-9) to place your mark.\n";

	char player = 'X';
	bool won = false;

	while (!won && !isBoardFull(board)) {
		printBoard(board);

		string input;
		cout << "Player " << player << ", enter your move (1-9): ";

		if (!getline(cin, input)) {
			cout << "\nNo more input. Goodbye!\n";
			return 0;
		}

		if (input.length() != 1 || input[0] < '1' || input[0] > '9') {
			cout << "Invalid input. Please enter only one number from 1 to 9.\n";
			continue;
		}

		int choice = input[0] - '0';
		int row = (choice - 1) / 3;
		int col = (choice - 1) % 3;

		if (board[row][col] == 'X' || board[row][col] == 'O') {
			cout << "That spot is already taken. Try again.\n";
			continue;
		}

		board[row][col] = player;

		if (checkWin(board, player)) {
			won = true;
		} else {
			player = (player == 'X') ? 'O' : 'X';
		}
	}

	printBoard(board);

	if (won) {
		cout << "Player " << player << " wins!\n";
	} else {
		cout << "It's a tie!\n";
	}

	return 0;
}