#include "Game.h"

Game::Game(IGameAgent* player1, IGameAgent* player2, GameGrid* grid)
{
	_player1 = player1;
	_player2 = player2;
	_grid = grid;
	_p1Turn = true;

	// Set the board characters appropiately
	_player1->setBoardCharacter(CROSS);
	_player2->setBoardCharacter(NOUGHT);
}

Game::~Game() {}

IGameAgent* Game::getNextPlayer()
{
	// if it's p1's turn, the agent is p1
	IGameAgent *agent = (_p1Turn) ? _player1 : _player2;
	return agent;
}

string Game::getNextTurnMsg() const
{
	return (_p1Turn) ? "Player 1's turn!" : "Player 2's turn!";
}

void Game::startGame()
{
	// print the grid
	_grid->printGrid();

	// game loop enter
	while (true)
	{
		// print the message saying who's turn it is next
		cout << endl << getNextTurnMsg() << endl;
		
		// get the next game turn agent
		IGameAgent *turnAgent = getNextPlayer();

		// let the turn agent make the next move
		turnAgent->makeMove(_grid);

		// print the grid again
		_grid->printGrid();

		// check the game state
		GAME_STATE state = _grid->getGameState();

		switch (state)
		{
			// the game has come to a draw, exit the loop
			case DRAW: 
				cout << endl << "The game has come to a draw!" << endl;
				return;
		
			// the game has ended, someone won, exit the loop
			case P1_WIN:
			case P2_WIN:
				// Print the complete game message for p1 or p2
				cout << "The game has been complete. ";
				// inverse _p1 bool as it's just been switched by getNextPlayer()
				cout << ((_p1Turn) ? "P1 " : "P2 ");
				cout << "has won the game!" << endl << endl;
				return;

			// if we're continuing, or if it felt to default.. continue
			case CONTINUE:
			default: 
				break;
		}

		// switch the flags so p2 goes next
		_p1Turn = !_p1Turn;
	}
}

bool Game::isP1Turn() const
{
	return _p1Turn;
}
