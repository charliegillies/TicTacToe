#pragma once
#include "IGameAgent.h"

class AIAgent : public IGameAgent
{
private:
	static int score(GameGrid* grid);
	static int minimax(GameGrid* grid, int depth, bool playerMove);

public:
	AIAgent();
	~AIAgent();

	void makeMove(GameGrid* grid) override;

};