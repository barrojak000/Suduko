#pragma once
#include <iostream>

class Suduko
{
public:

	// Dev Use
	
	
	// Game Use
	bool generateBoard();
	bool isValLocation(int row, int col, int testNum);
	bool spotFilled(int row, int col);
	int determineQuad(int row, int col);
	void printBoard();	// Done	
	void printGameBoard();
	void resetBoard();
	char requestDifficulty();
	void equateBoards();
	void buildBoard(int num, int n);

	
	// Unused
	bool checkRow(int i);	// Done
	bool checkCol(int j);	// Done
	bool check3x3(int rStart, int rEnd, int cStart, int cEnd); // Has Bugs but Works
	

	// Testing
	void startGame();
	void playingGame();
	void testNumber();
	void checkBoard();
	void clearBoard();
	void outputOptions();
	void insertNum();
	void removeNum();	

private:
	bool badBoard = false;
	int board[9][9] = { 0 };
	int gameBoard[9][9] = { 0 };
	int scrapBoard[9][9] = { 0 };
	int col = 0;
	int row = 0;
};

