#pragma once
#include <iostream>
#include "Node.h"
#include "g_Data.h"
using namespace std;
class Wall
{
	char* m_str;
public:
	//************************************
	// Method:    Wall
	// Descrition:初始化墙体图案
	// Parameter: char * pstr
	//************************************
	Wall(char* pstr = "■");
	//************************************
	// Method:    ShowWall
	// Descrition:根据是否编辑地图显示所有
	//			  墙体
	// Parameter: int x
	// Parameter: int y
	// Parameter: int choice
	//************************************
	void ShowWall(int x, int y, int choice = 0);
	//************************************
	// Method:    EditWall
	// Descrition:编辑地图
	// Parameter: int x
	// Parameter: int y
	//************************************
	void EditWall(int x = 1, int y = 1);
	//************************************
	// Method:    isRunTime
	// Descrition:判断编辑地图时是否越界
	// Parameter: int x
	// Parameter: int y
	//************************************
	bool isRunTime(int x, int y);
};