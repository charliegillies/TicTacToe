#include "UserAgent.h"


UserAgent::UserAgent() {}
UserAgent::~UserAgent() {}

void UserAgent::makeMove(GameGrid* grid)
{
	while (true)
	{
		int x = readCoordinate('x', NUM_ROWS);
		int y = readCoordinate('y', NUM_COLUMNS);

		// check if the move is valid, if so, mark it & move on..
		if (grid->isValidMove(y, x))
		{
			grid->markGridMove(y, x, boardCharacter);
			return;
		}
		else
			cout << endl << "That move could not be made, try again." << endl;
	}
}

int UserAgent::readCoordinate(char coordPrefix, int maxSize)
{
	while (true)
	{
		int coord;
		// print the coordPrefix, which could be 'x' or 'y'
		cout << "Please enter an " << coordPrefix << " co-ordinate: ";
		cin >> coord;

		if (coord < 1 || coord > maxSize)
		{
			cout << endl << "That co-ordinate is not valid. Please enter between 1 and " << maxSize << endl;
			continue;
		}

		// If it passed the test, translate from user friendly coords
		// to array index coords
		return coord - 1;
	}
}
