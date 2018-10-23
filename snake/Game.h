#pragma once
#include "userUI.h"
#include "Map.h"
#include <cstdio>
class Game
{
	UserUI m_ui;
	Map m_map;
public:
	//************************************
	// Method:    UserUI
	// Descrition:显示游戏主菜单以及接收用户输入
	//************************************
	void UserUI();
	//************************************
	// Method:    GameShow
	// Descrition:游戏部分主要控制流程
	//************************************
	void GameShow();
	//************************************
	// Method:    StartGame
	// Descrition:包含初始化数据，用户交互和整个游戏流程
	//************************************
	int StartGame();
	//************************************
	// Method:    ReadFile
	// Descrition:加载已有存档
	//************************************
	bool ReadFile();
};

