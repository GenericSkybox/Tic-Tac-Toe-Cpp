#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Grid {
private:
	vector<vector<char>> vector_grid;

public:
	Grid();

	void PrintGrid();
	bool PlaceMark(int square_position, bool isPlayer1Turn);
	bool CheckForWinState();
};