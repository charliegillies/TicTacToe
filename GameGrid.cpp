#include "GameGrid.h"
#include <iostream>

GameGrid::GameGrid()
{
	// Set all of the characters to the EMPTY const
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLUMNS; col++)
		{
			_grid[row][col] = EMPTY;
		}
	}
}

GameGrid::~GameGrid() {}

bool GameGrid::validCoords(int x, int y)
{
	if (x < 0 || y < 0) return false;
	if (x >= NUM_ROWS || y >= NUM_COLUMNS) return false;

	return true;
}

bool GameGrid::inLine(int x, int y, char nodeValue)
{
	// check horizontal
	if (validCoords(x - 1, y) && validCoords(x + 1, y))
		if (compareNodes(x - 1, y, nodeValue) && compareNodes(x + 1, y, nodeValue))
			return true;

	// check vertical
	if (validCoords(x, y - 1) && validCoords(x, y + 1))
		if (compareNodes(x, y - 1, nodeValue) && compareNodes(x, y + 1, nodeValue))
			return true;

	// check bot left to top right
	if (validCoords(x - 1, y + 1) && validCoords(x + 1, y - 1))
		if (compareNodes(x - 1, y + 1, nodeValue) && compareNodes(x + 1, y - 1, nodeValue))
			return true;

	// check bot right to top left
	if (validCoords(x + 1, y + 1) && validCoords(x - 1, y - 1))
		if (compareNodes(x + 1, y + 1, nodeValue) && compareNodes(x - 1, y - 1, nodeValue))
			return true;

	return false;
}

bool GameGrid::compareNodes(int x, int y, char nodeValue) const
{
	return _grid[x][y] == nodeValue;
}

bool GameGrid::gameOver()
{
	GAME_STATE state = getGameState();
	return state == P1_WIN || state == P2_WIN;
}

GAME_STATE GameGrid::getGameState()
{
	bool emptyFound = false;

	// Calculate the game state.....
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLUMNS; col++)
		{
			// get the current node
			char node = _grid[row][col];
			
			// if the node is EMPTY, no match
			if (node == EMPTY)
			{
				emptyFound = true;
				continue;
			}

			// check if this node is in a line, if it is - someone won
			if (inLine(row, col, node))
			{
				return (node == CROSS) ? P1_WIN : P2_WIN;
			}
		}
	}

	// if no empty spots were found, the grid is full
	return emptyFound ? CONTINUE : DRAW;
}

bool GameGrid::isValidMove(int x, int y)
{
	// check co-ordinates are within range
	if (!validCoords(x, y)) 
		return false;
	
	// we know the coords are in range, check the element
	char element = _grid[x][y];

	// if the space is empty, we can 
	return element == EMPTY;
}

vector<Int2> GameGrid::getAllAvailableMoves()
{
	// create a dynamic array
	vector<Int2> moves;

	// loop through every board element, looking for all moves
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLUMNS; col++)
		{
			if (!isValidMove(row, col)) continue;

			Int2 move(row, col);
			moves.push_back(move);
		}
	}

	return moves;
}

void GameGrid::markGridMove(int x, int y, char value)
{
	// throw exception if we're out of range, this should NEVER happen.
	if (!validCoords(x, y))
		throw("markGridMove(x,y,value) has invalid x and or y co-ordinates.");

	// otherwise, set the value inside of the grid.
	_grid[x][y] = value;
}

void GameGrid::printGrid()
{
	cout << endl;

	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLUMNS; col++)
		{
			char c = _grid[row][col];
			cout << c << " ";
		
			// check if we should print the vertical border
			if (col != (NUM_COLUMNS - 1))
				cout << "| ";
		}
		
		// end the line
		cout << endl;
		
		// if we're not on the last iteration, print the horizontal border
		if (row != (NUM_ROWS - 1))
			cout << "---------" << endl;
	}
}

GameGrid GameGrid::createClone()
{

}
