#pragma once
#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2
#define ESC 27
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "g_Data.h"
using namespace std;
class Node
{
	short m_x;
	short m_y;
	int m_dir;
public:
	Node(short x = 1, short y = 1, int dir = -2);
	short GetX();
	
	void SetX(short x);
	short GetY();
	void SetY(short y);
	int GetDir();
	void SetDir(int dir);
	//************************************
	// Method:    NodeMove
	// Descrition:根据不同的键盘输入对一个
	//            节点执行不同的操作
	//************************************
	Node& NodeMove();
	//************************************
	// Method:    ShowNode
	// Descrition:显示该节点
	// Parameter: short x
	// Parameter: short y
	// Parameter: WORD color
	// Parameter: char * pstr
	//************************************
	void ShowNode(short x, short y, WORD color, char* pstr);
};

