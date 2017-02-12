#pragma once
#include "IGameAgent.h"

class UserAgent : public IGameAgent
{
public:
	UserAgent();
	~UserAgent();

	void makeMove(GameGrid* grid) override;

	int readCoordinate(char coordPrefix, int maxSize);
};