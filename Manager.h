#pragma once
#include "Map.h"
#include "Block.h"

class Manager
{
public:
	Manager();
	~Manager();
public:
	void Init();
	bool Updata();
	void Render();
protected:
	Map map;
	Block block;
	float blockdowntime;

protected:
	bool isRun;
	char getKeyDown;
	int MMS;
	int STH_Run;
	float frameStartTime;
	float frameEndTime;
	float frameTime;
	float passTime;
	int scroce;
	int tempscroce[3];
	int nocleartime;

protected:
	void _ProcessTime();
	void _ProcessInput();
};

