#pragma once
#include "IGameAgent.h"

const int MAX_DEPTH = 8;

class AIAgent : public IGameAgent
{
private:
	static int score(GameGrid grid, int depth);
	static int minimax(GameGrid grid, int depth, bool playerMove, Int2* move);
	static int getMaxIndex(vector<int> scores);
	static int getMinIndex(vector<int> scores);

public:
	AIAgent();
	~AIAgent();

	void makeMove(GameGrid* grid) override;

};