#include "KnightsTourProgram.h"
#include<iostream>
#include<time.h>
#include <algorithm>

KnightsTourProgram::KnightsTourProgram()
	:maxTileCount(Board.BoardSize* Board.BoardSize),currentTileCount(0)
{
	srand(time(0));
	printf("Hey there we will now show a solution for a 5x5 board\n\n\n");
	Board.CurrentTile->visited = true;
	Board.CurrentTile->tileValue = "01";
	currentTileCount++;

	while (currentTileCount < maxTileCount)
	{
		Board.DrawBoard();
		currentTileCount++;
		Board.CurrentTile = GetNextStep();
		if (currentTileCount >= 10)
			Board.CurrentTile->tileValue = std::to_string(currentTileCount);
		else
			Board.CurrentTile->tileValue = "0" + std::to_string(currentTileCount);
		Board.CurrentTile->visited = true;
		printf("press enter for next step\n");
		//NOTE: Slowmode disabled for teachers
		//std::string str;
		//std::getline(std::cin, str);
	}

	printf("Tour finished with tour:\n");
	Board.DrawBoard();
	std::string str;
	std::getline(std::cin, str);
}

BoardTile* KnightsTourProgram::GetNextStep()
{
	Board.RecalculateNeighbours();
	std::vector<BoardTile*> neighbours = Board.CurrentTile->neighbours;
	BoardTile* lowestTile = neighbours[0];
	for (auto& tile : neighbours)
	{
		if (tile->neighbours.size() < lowestTile->neighbours.size())
		{
			lowestTile = tile;
		}
		else if (tile->neighbours.size() == lowestTile->neighbours.size())
		{
			if (rand() % 2 == 1)
			{
				lowestTile = tile;
			}
		}
	}
	neighbours.erase(std::remove(neighbours.begin(), neighbours.end(), lowestTile), neighbours.end());
	return lowestTile;
}


KnightsTourProgram::~KnightsTourProgram()
{
}
