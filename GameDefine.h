#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define MapRow 20
#define MapCol 16
#define FIRSTROW 4
#include <Windows.h>

typedef char const (* const pMapData)[MapCol];
struct BlockPoint
{
	int row, col;
};

enum GameMenu 
{
	Mainmenu,
	GM_start,
	GM_rank,
	GM_over,
};

