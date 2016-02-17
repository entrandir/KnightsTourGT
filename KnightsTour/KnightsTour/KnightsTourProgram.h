#pragma once
#include <string>
#include "Board.h"
class KnightsTourProgram
{
public:
	Board Board;
	int maxTileCount = Board.BoardSize * Board.BoardSize;
	int currentTileCount = 0;

public:
	KnightsTourProgram();
	BoardTile* GetNextStep();
	~KnightsTourProgram();
};

