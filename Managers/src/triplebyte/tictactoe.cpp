#include "Triplebyte.h"
#include "tictactoe.h"
#include "problem_group.h"
#include <iostream>
#include <sstream>
#include <set>
#include <vector>


TicTacToe::TicTacToe() :
	ProblemGroup(++TB_PROBLEM_GROUP_IDX, "Triplebyte")
{}

TicTacToe::~TicTacToe()
{}

void TicTacToe::InitProblemGroup()
{
	int idx = 0;
	AddProblem(++idx, &playgame, "Game");
}


TicTacToeGame::TicTacToeGame()
{
	vector<char> line = { '-','-','-' };
	for (int i = 0; i < 3; i++)
		board.push_back(line);
}


void TicTacToeGame::print_board()
{
	for (size_t i = 0; i < 3; i++)
		cout << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << endl;
}

void TicTacToeGame::make_move(char m, int x, int y)
{
	board[x][y] = m;
}

bool TicTacToeGame::is_board_full()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == '-')
				return false;
		}
	}
	return true;
}

void TicTacToeGame::ai_turn()
{
	if (is_board_full())
		throw;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == '-')
			{
				make_move('O', i, j);
				return;
			}
		}
	}
}

void playgame()
{
	TicTacToeGame* game = new TicTacToeGame();
	cout << (game->is_board_full() ? "FULL" : "NOT FULL") << endl;
	game->make_move('X', 0, 1);
	game->make_move('O', 2, 2);
	game->print_board();
	cout << (game->is_board_full() ? "FULL" : "NOT FULL") << endl;
	for (int i = 0; i < 7; i++)
		game->ai_turn();
	game->print_board();
	cout << (game->is_board_full() ? "FULL" : "NOT FULL") << endl;
	game->ai_turn();
}