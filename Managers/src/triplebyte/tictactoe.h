#pragma once
#include "problem_group.h"
#include <vector>

class TicTacToe : public ProblemGroup
{
public:
	TicTacToe();
	~TicTacToe();

	virtual void InitProblemGroup();
};

void playgame();


struct Pos
{
	char val;
	Pos(char v) : val(v) {}
};

class TicTacToeGame
{
public:
	TicTacToeGame();

	vector<vector<char>> board;
	bool is_board_full();
	void print_board();
	void make_move(char m, int x, int y);
	void ai_turn();
};