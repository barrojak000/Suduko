#include <iostream>
#include "Suduko.h"
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	Suduko game;

	game.startGame();

	cout << endl;
	return 0;
} 