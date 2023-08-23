#include "Block.h"
#include <memory.h>
#include "GameDefine.h"
#include <stdlib.h>


Block::Block() {
	kinds = 0;
	statu = 0;
	memset(BlockData, 0, sizeof(BlockData));
}
Block::~Block() {

}
//初始化方块
void Block::Init(){
	kinds = rand() % 8 + 1;
	statu = 1;
	switch (kinds)
	{
		//横条
	case 1:
	{
		BlockData[0].row = FIRSTROW;
		BlockData[0].col = MapCol / 2 - 1;

		BlockData[1].row = FIRSTROW;
		BlockData[1].col = MapCol / 2;

		BlockData[2].row = FIRSTROW;
		BlockData[2].col = MapCol / 2 + 1;

		BlockData[3].row = FIRSTROW;
		BlockData[3].col = MapCol / 2 + 2;
		break;
	}

	//方
	case 2:
	{
		BlockData[0].row = FIRSTROW;
		BlockData[0].col = MapCol / 2;

		BlockData[1].row = FIRSTROW;
		BlockData[1].col = MapCol / 2 + 1;

		BlockData[2].row = FIRSTROW + 1;
		BlockData[2].col = MapCol / 2;

		BlockData[3].row = FIRSTROW + 1;
		BlockData[3].col = MapCol / 2 + 1;
		break;
	}

	//Z
	case 3:
	{
		BlockData[0].row = FIRSTROW + 1;
		BlockData[0].col = MapCol / 2;

		BlockData[1].row = FIRSTROW + 1;
		BlockData[1].col = MapCol / 2 - 1;

		BlockData[2].row = FIRSTROW;
		BlockData[2].col = MapCol / 2;

		BlockData[3].row = FIRSTROW;
		BlockData[3].col = MapCol / 2 + 1;
		break;
	}
	//Z2
	case 4:
	{
		BlockData[0].row = FIRSTROW;
		BlockData[0].col = MapCol / 2 - 1;

		BlockData[1].row = FIRSTROW;
		BlockData[1].col = MapCol / 2;

		BlockData[2].row = FIRSTROW + 1;
		BlockData[2].col = MapCol / 2;

		BlockData[3].row = FIRSTROW + 1;
		BlockData[3].col = MapCol / 2 + 1;
		break;
	}

	//L
	case 5:
	{
		BlockData[0].row = FIRSTROW;
		BlockData[0].col = MapCol / 2 - 1;

		BlockData[1].row = FIRSTROW + 1;
		BlockData[1].col = MapCol / 2 - 1;

		BlockData[2].row = FIRSTROW + 1;
		BlockData[2].col = MapCol / 2;

		BlockData[3].row = FIRSTROW + 1;
		BlockData[3].col = MapCol / 2 + 1;
		break;
	}

	//L2
	case 6:
	{
		BlockData[0].row = FIRSTROW;
		BlockData[0].col = MapCol / 2 + 1;

		BlockData[1].row = FIRSTROW + 1;
		BlockData[1].col = MapCol / 2 - 1;

		BlockData[2].row = FIRSTROW + 1;
		BlockData[2].col = MapCol / 2;

		BlockData[3].row = FIRSTROW + 1;
		BlockData[3].col = MapCol / 2 + 1;
		break;
	}

	//三角
	case 7:
	{
		BlockData[0].row = FIRSTROW;
		BlockData[0].col = MapCol / 2;

		BlockData[1].row = FIRSTROW + 1;
		BlockData[1].col = MapCol / 2 - 1;

		BlockData[2].row = FIRSTROW + 1;
		BlockData[2].col = MapCol / 2;

		BlockData[3].row = FIRSTROW + 1;
		BlockData[3].col = MapCol / 2 + 1;
		break;
	}
	}
}

//移动
bool Block::downM(pMapData pmapdata) {
	bool CDmove = true;
	for (int i = 0; i < 4; ++i)
	{
		if (pmapdata[BlockData[i].row + 1][BlockData[i].col] != 0)
		{
			CDmove = false;
			break;
		}
	}
	if (CDmove)
	{
		for (int i = 0; i < 4; ++i)
		{
			++BlockData[i].row;
		}
	}
	
	return CDmove;
}
bool Block::leftM(pMapData pmapdata) {
	bool CDmove = true;
	for (int i = 0; i < 4; ++i)
	{
		if (pmapdata[BlockData[i].row][BlockData[i].col - 1] != 0)
		{
			CDmove = false;
			break;
		}
	}
	if (CDmove)
	{
		for (int i = 0; i < 4; ++i)
		{
			--BlockData[i].col;
		}
	}
	
	return CDmove;
}
bool Block::rightM(pMapData pmapdata) {
	bool CDmove = true;
	for (int i = 0; i < 4; ++i)
	{
		if (pmapdata[BlockData[i].row][BlockData[i].col + 1] != 0)
		{
			CDmove = false;
			break;
		}
	}
	if (CDmove)
	{
		for (int i = 0; i < 4; ++i)
		{
			++BlockData[i].col;
		}
	}
	
	return CDmove;

}
void Block::downQ(pMapData pmapdata) {
	while (downM(pmapdata));
}
//变化
//bool Block::change(pMapData pmapdata) {
//	switch (kinds)
//	{
//	case 1:
//	{
//		switch (statu)
//		{
//		case 1:
//		{
//			if ((pmapdata[BlockData[1].row - 1][BlockData[1].col - 1] == 0) &&
//				(pmapdata[BlockData[1].row - 1][BlockData[1].col] == 0) &&
//				(pmapdata[BlockData[1].row + 1][BlockData[1].col] == 0) &&
//				(pmapdata[BlockData[1].row + 1][BlockData[1].col + 1] == 0) &&
//				(pmapdata[BlockData[1].row + 1][BlockData[1].col + 2] == 0) &&
//				(pmapdata[BlockData[1].row + 2][BlockData[1].col] == 0) &&
//				(pmapdata[BlockData[1].row + 2][BlockData[1].col + 1] == 0))
//			{
//				BlockData[0].row = BlockData[1].row - 1;
//				BlockData[0].col = BlockData[1].col;
//
//				BlockData[2].row = BlockData[1].row + 1;
//				BlockData[2].col = BlockData[1].col;
//
//				BlockData[3].row = BlockData[1].row + 2;
//				BlockData[3].col = BlockData[1].col;
//
//				statu = 2;
//				return true;
//			}
//		}
//		break;
//		case 2:
//		{
//			if ((pmapdata[BlockData[1].row - 1][BlockData[1].col - 1] == 0) &&
//				(pmapdata[BlockData[1].row][BlockData[1].col - 1] == 0) &&
//				(pmapdata[BlockData[1].row][BlockData[1].col + 1] == 0) &&
//				(pmapdata[BlockData[1].row][BlockData[1].col + 2] == 0) &&
//				(pmapdata[BlockData[1].row + 1][BlockData[1].col + 1] == 0) &&
//				(pmapdata[BlockData[1].row + 1][BlockData[1].col + 2] == 0) &&
//				(pmapdata[BlockData[1].row + 2][BlockData[1].col + 1] == 0))
//			{
//				BlockData[0].row = BlockData[1].row;
//				BlockData[0].col = BlockData[1].col - 1;
//
//				BlockData[2].row = BlockData[1].row;
//				BlockData[2].col = BlockData[1].col + 1;
//
//				BlockData[3].row = BlockData[1].row;
//				BlockData[3].col = BlockData[1].col + 2;
//
//				statu = 1;
//				return true;
//			}
//		}
//		break;
//		}
//	}
//	break;
//	case 2:
//	{
//	}
//	break;
//	case 3:
//	{
//		switch (statu)
//		{
//		case 1:
//		{
//			if ((pmapdata[BlockData[2].row - 1][BlockData[2].col - 1] == 0) &&
//				(pmapdata[BlockData[2].row - 1][BlockData[2].col + 1] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col + 1] == 0))
//			{
//				BlockData[0].row = BlockData[2].row;
//				BlockData[0].col = BlockData[2].col + 1;
//
//				BlockData[1].row = BlockData[2].row - 1;
//				BlockData[1].col = BlockData[2].col;
//
//				BlockData[3].row = BlockData[2].row + 1;
//				BlockData[3].col = BlockData[2].col;
//
//				statu = 2;
//				return true;
//			}
//		}
//		break;
//		case 2:
//		{
//			if ((pmapdata[BlockData[2].row - 1][BlockData[2].col + 1] == 0) &&
//				(pmapdata[BlockData[2].row][BlockData[2].col - 1] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col - 1] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col + 1] == 0))
//			{
//				BlockData[0].row = BlockData[2].row + 1;
//				BlockData[0].col = BlockData[2].col;
//
//				BlockData[1].row = BlockData[2].row;
//				BlockData[1].col = BlockData[2].col + 1;
//
//				BlockData[3].row = BlockData[2].row;
//				BlockData[3].col = BlockData[2].col - 1;
//
//				statu = 3;
//				return true;
//			}
//		}
//		break;
//		case 3:
//		{
//			if ((pmapdata[BlockData[2].row - 1][BlockData[2].col - 1] == 0) &&
//				(pmapdata[BlockData[2].row - 1][BlockData[2].col] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col - 1] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col + 1] == 0))
//			{
//				BlockData[0].row = BlockData[2].row;
//				BlockData[0].col = BlockData[2].col - 1;
//
//				BlockData[1].row = BlockData[2].row + 1;
//				BlockData[1].col = BlockData[2].col;
//
//				BlockData[3].row = BlockData[2].row - 1;
//				BlockData[3].col = BlockData[2].col;
//
//				statu = 4;
//				return true;
//			}
//		}
//		break;
//		case 4:
//		{
//			if ((pmapdata[BlockData[2].row - 1][BlockData[2].col - 1] == 0) &&
//				(pmapdata[BlockData[2].row - 1][BlockData[2].col + 1] == 0) &&
//				(pmapdata[BlockData[2].row][BlockData[2].col + 1] == 0) &&
//				(pmapdata[BlockData[2].row + 1][BlockData[2].col - 1] == 0))
//			{
//				BlockData[0].row = BlockData[2].row - 1;
//				BlockData[0].col = BlockData[2].col;
//
//				BlockData[1].row = BlockData[2].row;
//				BlockData[1].col = BlockData[2].col - 1;
//
//				BlockData[3].row = BlockData[2].row;
//				BlockData[3].col = BlockData[2].col + 1;
//
//				statu = 1;
//				return true;
//			}
//		}
//		break;
//		}
//	}
//	break;
//	}
//	return false;
//}
bool Block::change(pMapData pmapdata) {
	BlockPoint newPos[4];
	for (int i = 0; i < 4; i++) {
		newPos[i].row = BlockData[i].col - BlockData[0].col + BlockData[0].row;
		newPos[i].col = BlockData[0].row + BlockData[0].col - BlockData[i].row;
	}

		// 检查旋转后的位置是否合法
		for (int i = 0; i < 4; i++) {
			if (newPos[i].row < 0 || newPos[i].row >= MapRow || newPos[i].col < 0 ||
				newPos[i].col >= MapCol || pmapdata[newPos[i].row][newPos[i].col] != 0) {
				return false;
			}
		}

	// 更新方块的位置
	for (int i = 0; i < 4; i++) {
		BlockData[i].row = newPos[i].row;
		BlockData[i].col = newPos[i].col;
	}

	return true;

}

BlockPoint const* const Block::getBlockData() {
	return BlockData;
}