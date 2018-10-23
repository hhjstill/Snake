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
	// Descrition:��ʼ��ǽ��ͼ��
	// Parameter: char * pstr
	//************************************
	Wall(char* pstr = "��");
	//************************************
	// Method:    ShowWall
	// Descrition:�����Ƿ�༭��ͼ��ʾ����
	//			  ǽ��
	// Parameter: int x
	// Parameter: int y
	// Parameter: int choice
	//************************************
	void ShowWall(int x, int y, int choice = 0);
	//************************************
	// Method:    EditWall
	// Descrition:�༭��ͼ
	// Parameter: int x
	// Parameter: int y
	//************************************
	void EditWall(int x = 1, int y = 1);
	//************************************
	// Method:    isRunTime
	// Descrition:�жϱ༭��ͼʱ�Ƿ�Խ��
	// Parameter: int x
	// Parameter: int y
	//************************************
	bool isRunTime(int x, int y);
};