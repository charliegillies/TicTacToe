#include <iostream>
#include "GameGrid.h"
#include "Game.h"
#include "UserAgent.h"
#include "AIAgent.h"
using namespace std;

// Method declarations
int readInput();
Game createGame(GameGrid *grid);

const int USER_OPTION = 1;
const int AI_OPTION = 2;

// Program entry point
int main()
{
	// introduce self
	cout << "WELCOME TO ABERTAYS TIC TAC TOE NATIONAL CHAMPIONSHIPS" << endl;

	// create the grid	
	GameGrid *grid = new GameGrid();
	// create the game
	Game game = createGame(grid);
	// start the game
	game.startGame();

	// wait for key entry, exit
	system("pause");
	return 0;
}

Game createGame(GameGrid *grid)
{
	// Player 1 is always a user agent
	UserAgent *player1 = new UserAgent();
	
	// Player 2 can be a user or an AI agent, use the base definition
	IGameAgent *player2;

	// Ask the player who player2 is
	while (true)
	{
		cout << endl << "Who is player 2?" << endl;
		cout << USER_OPTION << ": A user" << endl;
		cout << AI_OPTION << ": AI" << endl;

		int input = readInput();

		// If we're creating a user, create the user agent
		if (input == USER_OPTION)
		{
			player2 = new UserAgent();
			break;
		}

		// if we're creating AI, create the AI agent
		if (input == AI_OPTION)
		{
			player2 = new AIAgent();
			break;
		}
	}

	return Game(player1, player2, grid);
}

int readInput()
{
	cout << "Please input an option: ";
	
	// read the option
	int option;
	cin >> option;

	return option;
}