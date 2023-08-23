#pragma once
#include "GameDefine.h"

class Map
{
public:
	Map();
	~Map();
public:
	void Init();
	void Render();
public:
	pMapData getMapData();
	void setBlocksData(BlockPoint const* const pblockdata);
	void clsBlocksData(BlockPoint const* const pblockdata);
	void randcreate();
	void reward();
	bool gameover();
	int clsFloor();
protected:
	char MapData[MapRow][MapCol];
};

