#pragma once
#include<string>
#include<vector>
class BoardTile
{

public:
	std::string tileValue;
	bool visited;
	int xPos;
	int yPos;
	std::vector<BoardTile*> neighbours;
public:
	BoardTile();
	~BoardTile();
};

