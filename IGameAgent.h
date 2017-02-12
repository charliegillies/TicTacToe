#pragma once
#include "GameGrid.h"

class IGameAgent
{
public:
	IGameAgent();
	virtual ~IGameAgent();

	// Overrideable method for the base classes
	virtual void makeMove(GameGrid* grid) = 0;

	void setBoardCharacter(char boardChar);

protected:
	// the board character
	char boardCharacter;
};