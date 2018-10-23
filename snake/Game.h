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
	// Descrition:��ʾ��Ϸ���˵��Լ������û�����
	//************************************
	void UserUI();
	//************************************
	// Method:    GameShow
	// Descrition:��Ϸ������Ҫ��������
	//************************************
	void GameShow();
	//************************************
	// Method:    StartGame
	// Descrition:������ʼ�����ݣ��û�������������Ϸ����
	//************************************
	int StartGame();
	//************************************
	// Method:    ReadFile
	// Descrition:�������д浵
	//************************************
	bool ReadFile();
};

