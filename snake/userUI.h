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
	// Descrition:��ʼ������̨����
	//************************************
	void ControlDesk();
	//************************************
	// Method:    ShowInfo
	// Descrition:��ʾ��Ϸ�ȼ����÷ֵ�����
	//************************************
	void ShowInfo();
	//************************************
	// Method:    ShowMenu
	// Descrition:��ʾ��Ϸ�˵�
	// Parameter: int choice
	//************************************
	void ShowMenu(int choice = 0);
	//************************************
	// Method:    GetChoice
	// Descrition:�����û�ѡ��
	//************************************
	int GetChoice();
	void ShowSpecial();
};
