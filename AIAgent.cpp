#include "AIAgent.h"


AIAgent::AIAgent() {}

AIAgent::~AIAgent() {}

void AIAgent::makeMove(GameGrid* grid)
{
	auto value = minimax(grid, 5, true);
}

int AIAgent::score(GameGrid* grid)
{
	GAME_STATE state = grid->getGameState();

	switch (state)
	{
		// P1 is a player
		case P1_WIN: 
			return -10;

		// P2 is the AI
		case P2_WIN:
			return 10;
	
		// continue, draw or default is 0
		case DRAW:
		case CONTINUE:
		default:
			return 0;
	}
}

int AIAgent::minimax(GameGrid* grid, int depth, bool playerMove)
{
	if (depth == 0 || grid->gameOver())
		return score(grid);

	if (playerMove)
	{
		int bestValue = -INFINITY;
		for (Int2 allMoves : grid->getAllAvailableMoves())
		{
			
		}

		return bestValue;
	}
	else
	{
		int bestValue = INFINITY;
		for (Int2 allMoves : grid->getAllAvailableMoves())
		{

		}

		return bestValue;
	}
}
