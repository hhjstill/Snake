#pragma once
#include <cstdlib>
#include <iostream>
#include "g_Data.h"
#include <conio.h>
using namespace std;
class UserUI
{
public:
	//************************************
	// Method:    ControlDesk
	// Descrition:初始化控制台数据
	//************************************
	void ControlDesk();
	//************************************
	// Method:    ShowInfo
	// Descrition:显示游戏等级，得分等数据
	//************************************
	void ShowInfo();
	//************************************
	// Method:    ShowMenu
	// Descrition:显示游戏菜单
	// Parameter: int choice
	//************************************
	void ShowMenu(int choice = 0);
	//************************************
	// Method:    GetChoice
	// Descrition:接收用户选择
	//************************************
	int GetChoice();
	void ShowSpecial();
};
