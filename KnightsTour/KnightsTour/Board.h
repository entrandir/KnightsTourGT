#pragma once

#include<vector>
#include<iostream>
#include "BoardTile.h"

class Board
{
public:

	int BoardSize;
	std::vector<std::vector<BoardTile>> boardTiles;
	BoardTile *CurrentTile = &boardTiles[0][0];

public:
	Board();
	std::vector<BoardTile*> GetNeighbours(BoardTile& tile);
	void RecalculateNeighbours();
	void DrawBoard();
	void DrawLine();
	void DrawValues(int& yPos);
	~Board();
};

