#pragma once
#include "Food.h"
#include "Snakes.h"
#include "Wall.h"
#include "userUI.h"
class Map
{
	Food m_food;
	Snake m_snake;
	Wall m_wall;
public:
	Snake& GetSnake();
	Food GetFood();
	//************************************
	// Method:    ShowWall
	// Descrition:以是否编辑地图的方式显示墙体
	// Parameter: int edit
	//************************************
	void ShowWall(int edit);
	//************************************
	// Method:    eat
	// Descrition:没吃食物就正常移动，蛇死
	//亡或者吃到食物退出函数
	// Parameter: int choice
	//************************************
	bool eat(int choice = 0);
	//************************************
	// Method:    HitWall
	// Descrition:判断是否撞墙
	//************************************
	bool HitWall();
	//************************************
	// Method:    EatSelf
	// Descrition:判断是否撞到自己
	//************************************
	bool EatSelf();
	//************************************
	// Method:    IsDie
	// Descrition:判断是否死亡
	//************************************
	bool IsDie();
	//************************************
	// Method:    SaveFile
	// Descrition:存档
	//************************************
	bool SaveFile();
};
