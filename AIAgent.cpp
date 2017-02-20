#include "AIAgent.h"
#include <algorithm>

AIAgent::AIAgent() {}
AIAgent::~AIAgent() {}

// make move override from IGameAgent
void AIAgent::makeMove(GameGrid* grid)
{
	// int2 reference pointer to pass into minimax
	Int2* move = new Int2(-1, -1);

	// check if initial move
	minimax(grid->createClone(), 0, false, move);

	// make the move using the move result..
	grid->markGridMove(move->X, move->Y, boardCharacter);

	// clean up
	delete move;
}

// get the score according to the grid state and the depth
int AIAgent::score(GameGrid grid, int depth)
{
	GAME_STATE state = grid.getGameState();

	switch (state)
	{
		// P1 is a player
		case P1_WIN: 
			return depth - 10;

		// P2 is the AI
		case P2_WIN:
			return 10 - depth;
	
		// continue, draw or default is 0
		case DRAW:
		case CONTINUE:
		default:
			return 0;
	}
}

int AIAgent::minimax(GameGrid grid, int depth, bool playerMove, Int2* move)
{
	// if we hit max depth, or the game has ended, stop
	if (depth == MAX_DEPTH || grid.gameOver())
		return score(grid, depth);

	// increase the depth by 1
	depth += 1;

	// define the scores & moves vectors
	vector<int> scores;
	vector<Int2> moves;

	// get all available moves from the grid
	for (Int2 testMove : grid.getAllAvailableMoves())
	{
		// create a child, play the test move
		GameGrid child = grid.createChild(testMove.X, testMove.Y, playerMove ? CROSS : NOUGHT);

		// add the score & moves into the array at the same time
		// so the indexes match
		scores.push_back(minimax(child, depth, !playerMove, move));
		moves.push_back(testMove);
	}

	// if the above loop didn't run, immediately exit
	if (scores.size() == 0)
		return score(grid, depth);

	// if we're a player, get the min index
	// if we're the ai, get the max index
	int i = playerMove ? getMinIndex(scores) : getMaxIndex(scores);
	// set the pointer info from the chosen move
	move->Set(moves[i]);
	return scores[i];
}

// sort to get the max scores array index
int AIAgent::getMaxIndex(vector<int> scores)
{
	int pos = 0;
	int score = -INFINITY;

	for (int i = 0; i < scores.size(); i++)
	{
		int tempScore = scores[i];
		if (tempScore > score)
		{
			pos = i;
			score = tempScore;
		}
	}

	return pos;
}

// sort to get the min scores array index
int AIAgent::getMinIndex(vector<int> scores)
{
	int pos = 0;
	int score = INFINITY;

	for (int i = 0; i < scores.size(); i++)
	{
		int tempScore = scores[i];
		if (tempScore < score)
		{
			pos = i;
			score = tempScore;
		}
	}

	return pos;
}