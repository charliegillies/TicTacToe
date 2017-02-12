#pragma once
#include "IGameAgent.h"
#include <string>

class Game
{
private:
	// flag indicating if it's p1 turn or p2's turn
	bool _p1Turn;

	IGameAgent *_player1;
	IGameAgent *_player2;
	GameGrid *_grid;

	IGameAgent* getNextPlayer();
	string getNextTurnMsg() const;

public:
	Game(IGameAgent *player1, IGameAgent *player2, GameGrid *grid);
	~Game();

	void startGame();

	bool isP1Turn() const;
};