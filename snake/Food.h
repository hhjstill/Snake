#pragma once
#include <time.h>
#include <cstdlib>
#include "Node.h"
#include "Snakes.h"
class Food
{
	Node m_food;
	char* m_char;
public:
	Food(char* pstr = "��");
	short GetX();
	short GetY();
	//************************************
	// Method:    ShowFood
	// Descrition:�ڵ�ͼ��Χ���������һ��ʳ��
	// Parameter: Snake snake
	//************************************
	void ShowFood(Snake snake);
	void ShowBadFood(Snake snake);
};
