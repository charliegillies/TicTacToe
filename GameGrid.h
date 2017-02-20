#pragma once

#include <iostream>
#include <vector>
#include "Int2.h"
using namespace std;

// Board characters
const char EMPTY = ' ';
const char NOUGHT = 'O';
const char CROSS = 'X';

// Grid settings
const int NUM_ROWS = 3;
const int NUM_COLUMNS = 3;

// Enum defining the game state
enum GAME_STATE
{
	// The games state is 'continuing' nothing has changed.
	CONTINUE,

	// Neither agent can win.
	DRAW,

	// Agent P1 has won the game
	P1_WIN,

	// Agent P2 has won the game
	P2_WIN,
};

class GameGrid
{
private:
	char _grid[NUM_ROWS][NUM_COLUMNS];

	bool validCoords(int x, int y);
	bool inLine(int x, int y, char nodeValue);
	bool compareNodes(int x, int y, char nodeValue) const;


public:
	GameGrid();
	~GameGrid();

	GAME_STATE getGameState();

	bool isValidMove(int x, int y);

	vector<Int2> getAllAvailableMoves();

	void markGridMove(int x, int y, char value);

	bool gameOver();

	void printGrid();

	GameGrid createClone();
	GameGrid createChild(int x, int y, char value);
};