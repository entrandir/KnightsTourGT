#include "Board.h"



Board::Board()
	:BoardSize(10), boardTiles(BoardSize,std::vector<BoardTile>(BoardSize))
{
	for (int x = 0; x < BoardSize; x++)
	{
		for (int y = 0; y < BoardSize; y++)
		{
			boardTiles[x][y].xPos = x;
			boardTiles[x][y].yPos = y;
			boardTiles[x][y].neighbours = GetNeighbours(boardTiles[x][y]); // not really neccesary as we regenerate this everytime, but we are looping anyway
		}
	}
	CurrentTile = &boardTiles[0][0];
}

std::vector<BoardTile*> Board::GetNeighbours(BoardTile& tile)
{

	//Code spagethi should clean this up, but rather work on prototype
	if (tile.yPos - 2 >= 0) // north
	{
		if (tile.xPos - 1 >= 0)
		{
			if (boardTiles[tile.xPos - 1][tile.yPos - 2].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos - 1][tile.yPos - 2];
			}
		}
		if (tile.xPos + 1 < BoardSize)
		{
			if (boardTiles[tile.xPos + 1][tile.yPos - 2].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos + 1][tile.yPos - 2];
			}
		}
	}
	if (tile.xPos + 2 < BoardSize)//east side
	{
		if (tile.yPos - 1 >= 0)
		{
			if (boardTiles[tile.xPos + 2][tile.yPos - 1].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos + 2][tile.yPos - 1];
			}
		}
		if (tile.yPos + 1 < BoardSize)
		{
			if (boardTiles[tile.xPos + 2][tile.yPos + 1].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos + 2][tile.yPos + 1];
			}
		}
	}

	if (tile.yPos + 2 < BoardSize) // south
	{
		if (tile.xPos - 1 >= 0)
		{
			if (boardTiles[tile.xPos - 1][tile.yPos + 2].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos - 1][tile.yPos + 2];
			}
		}
		if (tile.xPos + 1 < BoardSize)
		{
			if (boardTiles[tile.xPos + 1][tile.yPos + 2].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos + 1][tile.yPos + 2];
			}
		}
	}
	if (tile.xPos - 2 >= 0)//west side
	{
		if (tile.yPos - 1 >= 0)
		{
			if (boardTiles[tile.xPos - 2][tile.yPos - 1].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos - 2][tile.yPos - 1];
			}
		}
		if (tile.yPos + 1 < BoardSize)
		{
			if (boardTiles[tile.xPos - 2][tile.yPos + 1].visited == false)
			{
				tile.neighbours.resize(tile.neighbours.size() + 1);
				tile.neighbours[tile.neighbours.size() - 1] = &boardTiles[tile.xPos - 2][tile.yPos + 1];
			}
		}
	}
	return tile.neighbours;
}

//recalculates the neighbours
void Board::RecalculateNeighbours()
{
	for (int x = 0; x < BoardSize; x++)
	{
		for (int y = 0; y < BoardSize; y++)
		{
			boardTiles[x][y].neighbours.clear();
			boardTiles[x][y].neighbours = GetNeighbours(boardTiles[x][y]);
		}
	}
}

void Board::DrawBoard()
{
	for (int i = 0; i < BoardSize; i++)
	{
		DrawLine();
		DrawValues(i);
	}
	DrawLine();
}


void Board::DrawLine()
{
	for (int x = 0; x < BoardSize; x++)
	{
		std::printf("---");
	}
	std::printf("-\n");
}

void Board::DrawValues(int& yPos)
{
	for (int x = 0; x < BoardSize; x++)
	{
		std::printf("|%s",boardTiles[x][yPos].tileValue.c_str());
	}
	std::printf("|\n");
}

Board::~Board()
{
}
