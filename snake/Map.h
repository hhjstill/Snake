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
	// Descrition:���Ƿ�༭��ͼ�ķ�ʽ��ʾǽ��
	// Parameter: int edit
	//************************************
	void ShowWall(int edit);
	//************************************
	// Method:    eat
	// Descrition:û��ʳ��������ƶ�������
	//�����߳Ե�ʳ���˳�����
	// Parameter: int choice
	//************************************
	bool eat(int choice = 0);
	//************************************
	// Method:    HitWall
	// Descrition:�ж��Ƿ�ײǽ
	//************************************
	bool HitWall();
	//************************************
	// Method:    EatSelf
	// Descrition:�ж��Ƿ�ײ���Լ�
	//************************************
	bool EatSelf();
	//************************************
	// Method:    IsDie
	// Descrition:�ж��Ƿ�����
	//************************************
	bool IsDie();
	//************************************
	// Method:    SaveFile
	// Descrition:�浵
	//************************************
	bool SaveFile();
};
