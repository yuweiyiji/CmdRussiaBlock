#include "Map.h"
#include <memory.h>
#include <iostream>

Map::Map() {
	memset(MapData, 0, sizeof(MapData));
}
Map::~Map() {

}

void Map::Init() {
	for (int r = 0; r < MapRow; ++r) {
		for (int c = 0; c < MapCol; ++c) {
			if (c == 0 || c == MapCol - 1 || r == MapRow - 1) {
				MapData[r][c] = 1;
			}
			else {
				MapData[r][c] = 0;
			}
		}
	}
}

void Map::Render() 
{
	for (int r = 4; r < MapRow; ++r) {
		for (int c = 0; c < MapCol; ++c) {
			switch (MapData[r][c])
			{
			case 0: {
				printf(" ");
				break;
			}
			case 1: {
				printf("x");
				break;
			}
			case 2: {
				printf("¡ö");
				break;
			}
			}
		}
		printf("\n");
	}
}

pMapData Map::getMapData() {
	return MapData;
}

void Map::setBlocksData(BlockPoint const* const pblockdata)
{
	for (int i = 0; i < 4; ++i)
	{
		MapData[pblockdata[i].row][pblockdata[i].col] = 2;
	}
}
void Map::reward()
{
	for (int i = 1; i < MapCol-1; ++i)
	{
		MapData[MapRow - 2][i] = 2;
	}
}

void Map::clsBlocksData(BlockPoint const* const pblockdata)
{
	for (int i = 0; i < 4; ++i)
	{
		MapData[pblockdata[i].row][pblockdata[i].col] = 0;
	}
}

void Map::randcreate()
{
	int lucky = 0;
	lucky = rand() % 2 + 1;
	switch (lucky)
	{
	case 1:
	{
		for (int i = 1; i < MapCol - 1; ++i)
		{
			MapData[MapRow - 2][i] = 2;
			MapData[MapRow - 3][i] = 2;
		}
		break;
	}
	case 2:
	{
	for (int i = MapRow - 5; i < MapRow-1; ++i)
		{
			for (int randon = 1; randon < MapCol-1; randon++)
			{
				randon = rand() % (MapCol-2)+1;
				MapData[i][randon] = 0;
				randon = rand() % (MapCol - 2) + 1;
				MapData[i][randon] = 2;
			}
		}
	break;
	}
	}
}

int Map::clsFloor()
{
	int clearfloornum = 0;

	for (int r = 0; r < MapRow - 1; ++r)
	{
		int c = 1;
		for (; c < MapCol - 1; ++c)
		{
			if (MapData[r][c] == 0)
			{
				break;
			}
		}

		if (c >= MapCol - 1)
		{
			for (int cr = r; cr > 0; --cr)
			{
				for (c = 1; c < MapCol - 1; ++c)
				{
					MapData[cr][c] = MapData[cr - 1][c];
				}
			}
			for (c = 1; c < MapCol - 1; ++c)
			{
				MapData[0][c] = 0;
			}
			++clearfloornum;
			if (clearfloornum >= 4)
			{
				break;
			}
		}
	}

	return clearfloornum;
}

bool Map::gameover() 
{
	for (int c = 1; c < MapCol - 1; ++c)
	{
		if (MapData[FIRSTROW][c] != 0)
		{
			return true;
		}
	}
	return false;
}

