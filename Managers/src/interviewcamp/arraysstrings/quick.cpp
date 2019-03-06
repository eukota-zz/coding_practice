#include <iostream>
#include <vector>
#include "../arraysstrings.h"

namespace{
    using namespace std;
}

vector<vector<char>> initGame()
{
    vector<char> row = {'-','-','-'};
    vector<vector<char>> game;
    for(int i=0; i<3; i++)
        game.push_back(row);
    return game;
}

void printgame(const vector<vector<char>>& game)
{
    for(int i=0; i<3; i++)
        cout << game[i][0] << "|" << game[i][1] << "|" << game[i][2] << endl;
}

void move(vector<vector<char>>& game, char move, int x, int y)
{
    game[x][y] = move;
}

int main()
{
    vector<vector<char>> game = initGame();
    printgame(game);
    cout << endl;
    move(game,'X',0,1);
    printgame(game);
    cout << endl;
    return 0;
}