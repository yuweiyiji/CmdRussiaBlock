#include "Manager.h"
#include <conio.h>
#include <iostream>
#include "Map.h"
#include "Block.h"
#include "GameDefine.h"
#include <stdio.h>
#pragma comment(lib,"winmm.lib")

Manager::Manager()
{
	srand(timeGetTime());
	isRun = false;
	getKeyDown = 0;
	scroce = 0;
	memset(tempscroce, 0, sizeof(tempscroce));

	frameStartTime = 0.0f;
	frameEndTime = 0.0f;
	frameTime = 0.0f;
	passTime = 0.0f;
	blockdowntime = 0.0f;
	nocleartime = 0;

	STH_Run = Mainmenu;
	MMS = GM_start;
}

Manager::~Manager()
{

}

void Manager::Init() 
{
	isRun = true;
	getKeyDown = 0;

	MMS = 1;
	STH_Run = Mainmenu;

	frameStartTime = timeGetTime() / 1000.0f;
	frameEndTime = 0.0f;
	frameTime = 0.0f;
	passTime = 0.0f;

	nocleartime = 0;

	printf("Russia Blocks\n_Game Start\n Rank\n Game Over");
}
bool Manager::Updata()
{
	_ProcessTime();
	_ProcessInput();
	
	switch (STH_Run)
	{
	//菜单键盘
	case Mainmenu:
	{
		switch (getKeyDown)
		{
		case 'w':
		case 'W':
		{
			MMS -= 1;
			break;
		}
		case 's':
		case 'S':
		{
			MMS += 1;
			break;
		}
		case '\r':
		{
			switch (MMS)
			{
			case GM_start:
			{
				map.Init();
				block.Init();
				blockdowntime = 0.0f;
				STH_Run = GM_start;
				break;
			}
			case GM_rank:
			{
				STH_Run = GM_rank;
				break;
			}
			case GM_over:
			{
				isRun = false;
				break;
			}
			}
			break;
		}
		}
		break;
	}
	//游戏键盘
	case GM_start:
	{
		switch (getKeyDown)
		{
		case 'w':
		case 'W':
		{
			block.change(map.getMapData());
			break;
		}
		case 's':
		case 'S':
		{
			if (!block.downM(map.getMapData()))
			{
				map.setBlocksData(block.getBlockData());
			if (map.gameover())
			{
				STH_Run = Mainmenu;
			}
			block.Init();
			}
			break;
		}
		case 'a':
		case 'A':
		{
			block.leftM(map.getMapData());
			break;
		}
		case 'd':
		case 'D':
		{
			block.rightM(map.getMapData());
			break;
		}
		case 'q':
		case 'Q':
		{
			block.downQ(map.getMapData());
			map.setBlocksData(block.getBlockData());
			break;
		}
		case 'r':
		case 'R':
		{
			if (scroce >= 50)
			{
				scroce -= 50;
				map.reward();
			}
			break;
		}
		case 'h':
		case 'H':
		{
			if (scroce >= 10)
			{
				scroce -= 10;
				map.randcreate();
			}
			break;
		}

		}
		blockdowntime += frameTime;
		while (blockdowntime > 1.0f)
		{
			if (!block.downM(map.getMapData()))
			{
				map.setBlocksData(block.getBlockData());
				switch (map.clsFloor())
				{
				case 1:
				{
					scroce += 10;
				}
				break;
				case 2:
				{
					scroce += 30;
				}
				break;
				case 3:
				{
					scroce += 60;
				}
				break;
				case 4:
				{
					scroce += 100;
				}
				break;
				}
				scroce += 2;

				if (map.gameover())
				{
					STH_Run = GM_start;
				}
				block.Init();
			}
			blockdowntime -= 1.0f;
		}
		break;
	}
	case GM_rank:
	{
		switch(getKeyDown)
		{
		case 'f':
		case 'F':
		{
			STH_Run = Mainmenu;
			break;
		}
		}
	}
	}
	if (STH_Run == Mainmenu)
	{
		for (int i=0;i<3;++i)
		{
			if (tempscroce[i] == 0)
			{
				tempscroce[i] = scroce;
				break;
			}
			if (tempscroce[i] != 0)
			{
				int temp = 0;
				for (int i = 0; i < 3; i++) 
					for (int j = 0; j < i; j++) { 
						if (tempscroce[j] > tempscroce[j + 1]) {
							temp = tempscroce[j];
							tempscroce[j] = tempscroce[j + 1];
							tempscroce[j + 1] = temp;
						}
					}
				if (tempscroce[i] < scroce)
				{
					tempscroce[i] = scroce;
					break;
				}
			}
		}
		FILE* file = fopen("tempscroce.txt", "w");

		scroce = 0;
	}
	if (MMS < 1)MMS = 1;
	if (MMS > 3)MMS = 3;
	return isRun;
}
void Manager::Render() 
{
	Sleep(20);
	system("cls");
	switch (STH_Run)
	{
	case Mainmenu:
	{
		switch (MMS)
		{
		case GM_start:
		{
			printf("Russia Blocks\n_Game Start\n Rank\n Game Over");
			break;
		}
		case GM_rank:
		{
			printf("Russia Blocks\n Game Start\n_Rank\n Game Over");
			break;
		}
		case GM_over:
		{
			printf("Russia Blocks\n Game Start\n Rank\n_Game Over");
			break;
		}
		}
		break;
	}
	case GM_start:
	{
		printf("当前得分 : %d\n当分数超过50点击R键可使最低层清空\n", scroce);
		printf("当分数超过10点击H键追梦\n（！有概率生成方块或消除方块）\n");
		map.setBlocksData(block.getBlockData());
		map.Render();
		map.clsBlocksData(block.getBlockData());
		break;
	}
	case GM_rank:
	{
		int a[3] = { 3,2,1 };
		for (int i = 2; i >= 0; --i) 
		{
			printf("第%d名为%d\n", a[i], tempscroce[i]);
		}
		printf("按F键返回主菜单");
	}
	break;
	}
}
	//主菜单
void Manager::_ProcessTime()
{
	frameEndTime = timeGetTime() / 1000.0f;
	frameTime = frameEndTime - frameStartTime;
	frameStartTime = frameEndTime;
	passTime += frameTime;
}

void Manager::_ProcessInput()
{
	getKeyDown = 0;
	if (_kbhit())
	{
		getKeyDown = _getch();
	}
}

