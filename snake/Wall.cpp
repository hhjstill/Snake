#include "Wall.h"
Wall::Wall(char* pstr) : m_str(pstr) {}
void Wall::ShowWall(int x, int y, int choice) {
	for (int i = 0; i < x; i++)        //填充二维数组数据，1表示墙
	{
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
				g_wall[i][j] = 1;
		}
	}
	for (int i = 0; i < x; i++)        //根据二维数组数据打印围墙
	{
		for (int j = 0; j < y; j++)
		{
			if (g_wall[i][j] == 1)
			{
				ShowChar(j, i, 0x04, m_str);
				Sleep(10);
			}
		}
	}
	if (1 == choice)           //判断是否编辑地图
		EditWall();
}
void Wall::EditWall(int x, int y) {
	ShowChar(wide, 0, 0x0f, "控制光标移动:");
	ShowChar(wide, 1, 0x0f, "【W】【S】");
	ShowChar(wide, 2, 0x0f, "【A】【D】");
	ShowChar(wide, 4, 0x0f, "增加障碍物：【1】");
	ShowChar(wide, 6, 0x0f, "开始游戏：【ESC】");
	ShowChar(x, y, 0x04, "", true);
	char dir = 0;
	do {
		dir = _getch();
		switch (dir)
		{
		case 'w':case'W':
			if (isRunTime(x, y - 1))
				break;
			else
			{
				ShowChar(x, --y, 0x04, "", true);
			}
			break;
		case 's':case'S':
			if (isRunTime(x, y + 1))
				break;
			else
			{
				ShowChar(x, ++y, 0x04, "", true);
			}
			break;
		case 'a':case'A':
			if (isRunTime(x - 1, y))
				break;
			else
			{
				ShowChar(--x, y, 0x04, "", true);
			}
			break;
		case 'd':case'D':
			if (isRunTime(x + 1, y))
				break;
			else
			{
				ShowChar(++x, y, 0x04, "", true);
			}
			break;
		case '1':
			g_wall[y][x] = 1;
			cout << m_str;
			if (isRunTime(x + 1, y))
				ShowChar(x, y, 0x04, "", true);
			else
				x++;
			break;
		default:
			break;
		}
	} while (dir != ESC);    //ESC保存地图并开始游戏

	ShowChar(wide, 0, 0x0f, "             ");
	ShowChar(wide, 1, 0x0f, "          ");
	ShowChar(wide, 2, 0x0f, "          ");
	ShowChar(wide, 4, 0x0f, "                 ");
	ShowChar(wide, 6, 0x0f, "                 ");
}
bool Wall::isRunTime(int x, int y) {
	if (x >= 1 && x <= wide - 2 && y >= 1 && y <= height - 2)
		return false;
	return true;
}