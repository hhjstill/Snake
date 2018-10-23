#include "userUI.h"
void UserUI::ControlDesk() {
	system("title 贪吃蛇");
	system("mode con cols=100 lines=40");
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	ShowSpecial();
}
void UserUI::ShowInfo() {
	ShowChar(wide, 0, 0x0f, "功能：");
	ShowChar(wide, 1, 0x0f, "◆暂停-【空格】");
	ShowChar(wide, 2, 0x0f, "◆存档-【ESC】");
	ShowChar(wide, 3, 0x0f, "◆加速-【+】");
	ShowChar(wide, 4, 0x0f, "◆减速-【-】");
	ShowChar(wide, 5, 0x0f, "等级：");
	cout << g_level;
	ShowChar(wide, 6, 0x0f, "得分：");
	cout << g_score;
	ShowChar(wide, 7, 0x4f, "食物：");
	ShowChar(wide + 4, 7, 0x4f, "◎");
	ShowChar(wide, 8, 0x5f, "毒药：");
	ShowChar(wide + 4, 8, 0x5f, "⊥");
}
void UserUI::ShowMenu(int choice) {
	ShowChar(17, 7, 0x0e, "  ~贪吃蛇~ ");
	ShowChar(17, 8, 0x0e, " 1.简单难度. ");
	ShowChar(17, 9, 0x0e, " 2.普通难度. ");
	ShowChar(17, 10, 0x0e, " 3.困难模式. ");
	ShowChar(17, 11, 0x0e, " 4.载入游戏. ");
	ShowChar(17, 12, 0x0e, " 5.编辑地图. ");
	if ('1' == choice)
		ShowChar(17, 8, 0x04, ">1.简单难度.<");
	else if ('2' == choice)
		ShowChar(17, 9, 0x04, ">2.普通难度.<");
	else if ('3' == choice)
		ShowChar(17, 10, 0x04, ">3.困难模式.<");
	else if ('4' == choice)
		ShowChar(17, 11, 0x04, ">4.载入游戏.<");
	else if ('5' == choice)
		ShowChar(17, 12, 0x04, ">5.编辑地图.<");
}
int UserUI::GetChoice() {
	int nChoice = _getch();
	return nChoice;
}
void UserUI::ShowSpecial() {
	ShowChar(1, 1, 0x0f, "");
	int i, j;
	for (i = 1; i < wide - 1; i++)
	{
		ShowChar(i, i, 0x4f, "●");
		Sleep(5);
	}
	ShowChar(1, height - 1, 0x0f, "");
	for (i = 1; i < wide - 1; i++)
	{
		ShowChar(i, wide - i - 1, 0x4f, "●");
		Sleep(10);
	}
	for (i = 0; i < wide; i++)
	{
		for (j = 0; j < height; j++)
		{
			if (i == 0 || i == wide - 1
				|| j == 0 || j == height - 1)
			{
				ShowChar(i, j, 0x4f, "★");
				Sleep(10);
			}
		}
	}
}