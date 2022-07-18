#include "Suduko.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void Suduko::resetBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = 0;
		}
	}
}

bool Suduko::generateBoard() {
	int iRand;
	int counter = 0;
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (spotFilled(i, j) == false) {
				iRand = (rand() % 9) + 1;
				if (isValLocation(i, j, iRand) == true) {
					board[i][j] = iRand;
				}
				counter++;
				if (counter > 1000) {
					badBoard = true;
					break;
				}
			}
		}
	}
		
	if (badBoard == true) {
		resetBoard();
		badBoard = false;
		return false;
	}
	else {
		return true;
	}
}

void Suduko::printBoard() {
	cout << endl;

	for (int i = 0; i <= 8; ++i) {
		
		for (int j = 0; j <= 8; ++j) {
			
			// Display Number
			cout << setw(3) << board[i][j] << setw(3);

			// Design Format Code
			if ((j + 1) % 3 == 0 && j != 8) {
				cout << "|";
			} //endif
		} //endfor(j)

		// Design Format Code
		cout << endl;
		if ((i + 1) % 3 == 0 && i != 8) {
			cout << " ----------+";
			cout << "-----------+";
			cout << "----------" << endl;
		} //endif
	} //endfor(i)
}

void Suduko::printGameBoard() {
	cout << endl;
	cout << "GameBoard\n";
	for (int i = 0; i <= 8; ++i) {

		for (int j = 0; j <= 8; ++j) {

			// Display Number
			cout << setw(3) << gameBoard[i][j] << setw(3);

			// Design Format Code
			if ((j + 1) % 3 == 0 && j != 8) {
				cout << "|";
			} //endif
		} //endfor(j)

		// Design Format Code
		cout << endl;
		if ((i + 1) % 3 == 0 && i != 8) {
			cout << " ----------+";
			cout << "-----------+";
			cout << "----------" << endl;
		} //endif
	} //endfor(i)
}

void Suduko::insertNum() {
	int num;
	int row;
	int col;
		
	cout << "\nWhat number would you like to insert?: ";
	cin >> num;

	cout << "\nWhere would you like to insert your number?\n";
	cout << "\tRow (1 - 9): ";
	cin >> row;
	cout << "\tCol (1 - 9): ";
	cin >> col;

	// - 1 because arr[9][9] goes (0 - 8)
	gameBoard[row - 1][col - 1] = num;
}

void Suduko::removeNum() {
	int num;
	int row;
	int col;

	cout << "\nWhat number would you like to remove?: ";
	cin >> num;

	cout << "\nWhere would you like to remove your number?\n";
	cout << "\tRow (1 - 9): ";
	cin >> row;
	cout << "\tCol (1 - 9): ";
	cin >> col;

	// - 1 because arr[9][9] goes (0 - 8)
	gameBoard[row - 1][col - 1] = 0;
}

bool Suduko::checkRow(int i) {
	// Compare to [i][0]
	int tempInt = board[i][0];

	for (int j = 1; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][1]
	tempInt = board[i][1];

	for (int j = 2; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][2]
	tempInt = board[i][2];

	for (int j = 3; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][3]
	tempInt = board[i][3];

	for (int j = 4; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][4]
	tempInt = board[i][4];

	for (int j = 5; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][5]
	tempInt = board[i][5];

	for (int j = 6; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][6]
	tempInt = board[i][6];

	for (int j = 7; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [i][7]
	tempInt = board[i][7];

	for (int j = 8; j <= 8; ++j) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	return true;
}

bool Suduko::checkCol(int j) {
	// Compare to [0][j]
	int tempInt = board[0][j];

	for (int i = 1; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [1][j]
	tempInt = board[1][j];

	for (int i = 2; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [2][j]
	tempInt = board[2][j];

	for (int i = 3; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [3][j]
	tempInt = board[3][j];

	for (int i = 4; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [4][j]
	tempInt = board[4][j];

	for (int i = 5; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [5][j]
	tempInt = board[5][j];

	for (int i = 6; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [6][j]
	tempInt = board[6][j];

	for (int i = 7; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	// Compare to [7][j]
	tempInt = board[7][j];

	for (int i = 8; i <= 8; ++i) {
		if (tempInt == board[i][j] && board[i][j] != 0) {
			return false;
		}
	}

	return true;
}

bool Suduko::check3x3(int rStart, int rEnd, int cStart, int cEnd) {
	
	// Compare [rStart][cStart]
	int tempInt = board[rStart][cStart];

	for (int r = rStart; r < (rStart + 3); ++r) {
		for (int c = (cStart + 1); c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart][cStart + 1]
	tempInt = board[rStart][cStart + 1];

	for (int r = rStart; r < (rStart + 3); ++r) {
		for (int c = (cStart + 2); c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart][cStart + 2]
	tempInt = board[rStart][cStart + 2];

	for (int r = (rStart + 1); r < (rStart + 3); ++r) {
		for (int c = cStart; c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart + 1][cStart]
	tempInt = board[rStart + 1][cStart];

	for (int r = (rStart + 1); r < (rStart + 3); ++r) {
		for (int c = (cStart + 1); c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart + 1][cStart + 1]
	tempInt = board[rStart + 1][cStart + 1];

	for (int r = (rStart + 1); r < (rStart + 3); ++r) {
		for (int c = (cStart + 2); c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart + 1][cStart + 2]
	tempInt = board[rStart + 1][cStart + 2];

	for (int r = (rStart + 2); r < (rStart + 3); ++r) {
		for (int c = cStart; c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart + 2][cStart]
	tempInt = board[rStart + 2][cStart];

	for (int r = (rStart + 2); r < (rStart + 3); ++r) {
		for (int c = (cStart + 1); c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	// Compare [rStart + 2][cStart + 1]
	tempInt = board[rStart + 2][cStart + 1];

	for (int r = (rStart + 2); r < (rStart + 3); ++r) {
		for (int c = (cStart + 2); c < (cStart + 3); ++c) {
			if (tempInt == board[r][c] && board[r][c] != 0) {
				return false;
			}
		}
	}

	return true;
}

bool Suduko::spotFilled(int row, int col) {
	if (board[row][col] != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Suduko::isValLocation(int row, int col, int testNum) {
	
	// Check Row
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == testNum) {
			return false;
		}
	}
	
	// Check Col
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == testNum) {
			return false;
		}
	}

	// Check 3x3
	int r, c;
	int quadrant = determineQuad(row, col);
	switch (quadrant) {
		case 1: {
			for (r = 0; r < 3; r++) {
				for (c = 0; c < 3; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 2: {
			for (r = 0; r < 3; r++) {
				for (c = 3; c < 6; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 3: {
			for (r = 0; r < 3; r++) {
				for (c = 6; c < 9; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 4: {
			for (r = 3; r < 6; r++) {
				for (c = 0; c < 3; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 5: {
			for (r = 3; r < 6; r++) {
				for (c = 3; c < 6; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 6: {
			for (r = 3; r < 6; r++) {
				for (c = 6; c < 9; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 7: {
			for (r = 6; r < 9; r++) {
				for (c = 0; c < 3; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 8: {
			for (r = 6; r < 9; r++) {
				for (c = 3; c < 6; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		case 9: {
			for (r = 6; r < 9; r++) {
				for (c = 6; c < 9; c++) {
					if (board[r][c] == testNum) {
						return false;
					}
				}
			}
			break;
		}
		default:
			cout << "Invalid Input";
			break;
	}
	
	// If all tests passed, it's a valid location
	return true;
}

void Suduko::checkBoard() {
	bool crawler = true;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (gameBoard[i][j] != board[i][j]) {
				crawler = false;
			}
		}
	}

	if (crawler == false) {
		crawler = true;		// Reset Crawler
		cout << "\nGameboard solution is incorrect.\n";
	}
	else {
		cout << "\nCongratulations! Gameboard solution is correct!!! :)\n";
	}

	/*

	// Check Columns
	for (int j = 0; j <= 8; ++j) {
		if (checkCol(j) == false) {
			return false;
		}
	}
	
	// Check Rows
	for (int i = 0; i <= 8; ++i) {
		if (checkRow(i) == false) {
			return false;
		}
	}

	// Check 3x3's (In rowStart, rowEnd, colStart, colEnd format)

	// Square 1 (0, 2, 0, 2)
	if (check3x3(0, 2, 0, 2) == false)
		return false;

	// Square 2 (0, 2, 3, 5)
	if (check3x3(0, 2, 3, 5) == false)
		return false;

	// Square 3 (0, 2, 6, 8)
	if (check3x3(0, 2, 6, 8) == false)
		return false;

	// Square 4 (3, 5, 0, 2)
	if (check3x3(3, 5, 0, 2) == false)
		return false;

	// Square 5 (3, 5, 3, 5)
	if (check3x3(3, 5, 3, 5) == false)
		return false;

	// Square 6 (3, 5, 6, 8)
	if (check3x3(3, 5, 6, 8) == false)
		return false;

	// Square 7 (6, 8, 0, 2)
	if (check3x3(6, 8, 0, 2) == false)
		return false;

	// Square 8 (6, 8, 3, 5)
	if (check3x3(6, 8, 3, 5) == false)
		return false;

	// Square 9 (6, 8, 6, 8)
	if (check3x3(6, 8, 6, 8) == false)
		return false;
		
	//cout << "\nGreat Job!!!\n";

	return true;
	
	*/
}

int Suduko::determineQuad(int row, int col) {
	// Quadrant 1
	if ((row >= 0 && row <= 2) && (col >= 0 && col <= 2)) {
		int i = 1;
		return i;
	}

	// Quadrant 2
	if ((row >= 0 && row <= 2) && (col >= 3 && col <= 5)) {
		int i = 2;
		return i;
	}

	// Quadrant 3
	if ((row >= 0 && row <= 2) && (col >= 6 && col <= 8)) {
		int i = 3;
		return i;
	}

	// Quadrant 4
	if ((row >= 3 && row <= 5) && (col >= 0 && col <= 2)) {
		int i = 4;
		return i;
	}

	// Quadrant 5
	if ((row >= 3 && row <= 5) && (col >= 3 && col <= 5)) {
		int i = 5;
		return i;
	}

	// Quadrant 6
	if ((row >= 3 && row <= 5) && (col >= 6 && col <= 8)) {
		int i = 6;
		return i;
	}

	// Quadrant 7
	if ((row >= 6 && row <= 8) && (col >= 0 && col <= 2)) {
		int i = 7;
		return i;
	}

	// Quadrant 8
	if ((row >= 6 && row <= 8) && (col >= 3 && col <= 5)) {
		int i = 8;
		return i;
	}

	// Quadrant 9
	if ((row >= 6 && row <= 8) && (col >= 6 && col <= 8)) {
		int i = 9;
		return i;
	}

	return 1;
}

void Suduko::startGame() {
	while (generateBoard() == false) {
		generateBoard();
	}

	char difficulty = requestDifficulty();
	equateBoards();
	
	switch (difficulty) {
		case '1': {
			buildBoard(28, 16);
			break;
		}
		case '2': {
			buildBoard(43, 8);
			break;
		}
		case '3': {
			buildBoard(58, 4);
			break;
		}
		case '4': {
			buildBoard(73, 2);
			break;
		}
	}

	printGameBoard();
	playingGame();
}

void Suduko::equateBoards() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			gameBoard[i][j] = board[i][j];
		}
	}
}

void Suduko::buildBoard(int num, int n) {
	int tester;
	int counter = 0;

	while (counter < num) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				tester = rand() % n;
				//cout << tester << endl;
				if (tester == 0 && counter <= num) {
					gameBoard[i][j] = 0;
					counter++;
				}
			}
		}
	}

	// Somehow change equateBoards() to get rid of chunck
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scrapBoard[i][j] = gameBoard[i][j];
		}
	}

}

char Suduko::requestDifficulty() {
	char difficulty;

	cout << "-----------------------------------";
	cout << "-----------------------------------";
	cout << "\nWhat level of difficulty would you like to play with?";
	cout << " (Enter a number)";
	cout << "\n\n\t1. Easy";
	cout << "\n\t2. Medium";
	cout << "\n\t3. Hard";
	cout << "\n\t4. Harder";
	cout << "\n\n-----------------------------------";
	cout << "-----------------------------------\n\n";

	cin >> difficulty;

	return difficulty;
}

void Suduko::testNumber() {
	int num;
	int row;
	int col;

	cout << "\nWhat number would you like to test?: ";
	cin >> num;

	cout << "\nWhere would you like to test your number?\n";
	cout << "\tRow (1 - 9): ";
	cin >> row;
	cout << "\tCol (1 - 9): ";
	cin >> col;

	// Can I make this easier with pointers?
	
	// Copying down what is in the test location
	int x = gameBoard[row - 1][col - 1];

	// Inserting test number
	gameBoard[row - 1][col - 1] = num;

	// Testing location for accuracy
	if (gameBoard[row - 1][col - 1] == board[row - 1][col - 1]) {
		cout << "\nThe number, " << num << ", fits in the location ";
		cout << "\n\tRow: " << row << "\n\tCol: " << col << endl;
	}
	else {
		cout << "\nThe number, " << num << ", does not fit in the location ";
		cout << "\n\tRow: " << row << "\n\tCol: " << col << endl;
	}	
}

void Suduko::outputOptions() {
	cout << endl;
	cout << "-------------------------------------------\n";
	cout << "|              Turn Options               |\n";
	cout << "|   -----------------------------------   |\n";
	cout << "|            C - Check Board              |\n";
	cout << "|            L - Clear Board              |\n";
	cout << "|            E - Exit Game                |\n";
	cout << "|            I - Insert Number            |\n";
	cout << "|            O - Output Turn Options      |\n";
	cout << "|            P - Print Board              |\n";
	cout << "|            S - Print Solution           |\n";
	cout << "|            R - Remove Number            |\n";
	cout << "|            T - Test Number              |\n";
	cout << "-------------------------------------------";
	cout << endl;
}

void Suduko::playingGame() {
	char userInput = 0;

	cout << "\n--- What would you like to do? ---\n";
	outputOptions();
	
	do {
		cin >> userInput;
		userInput = tolower(userInput);

		switch (userInput) {
		case 'c':
			checkBoard();
			break;
		case 'l':
			clearBoard();
			break;
		case 'e':
			break;
		case 'i':
			insertNum();
			break;
		case 'o':
			outputOptions();
			break;
		case 'p':
			printGameBoard();
			break;
		case 's':
			printBoard();
			break;
		case 'r':
			removeNum();
			break;
		case 't':
			testNumber();
			break;
		default:
			cout << "\nSorry, that didn't quite work. Let's try that again.";
		}
	} while (userInput != 'e' && userInput != 'E');
}

void Suduko::clearBoard() {
	// Somehow change equateBoards() to get rid of chunck
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			gameBoard[i][j] = scrapBoard[i][j];
		}
	}
}