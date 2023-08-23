#pragma once
#include "GameDefine.h"

class Block
{
public:
	Block();
	~Block();
public:
	void Init();
	bool change(pMapData pmapdata);
	bool leftM(pMapData pmapdata);
	bool rightM(pMapData pmapdata);
	bool downM(pMapData pmapdata);
	void downQ(pMapData pmapdata);
public:
	BlockPoint const* const getBlockData();
protected:
	BlockPoint BlockData[4];
	int statu;
	int kinds;
};

