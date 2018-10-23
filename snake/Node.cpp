#include "Node.h"
Node::Node(short x, short y, int dir) :m_x(x), m_y(y), m_dir(dir) {}
short Node::GetX() {
	return m_x;
}
void Node::SetX(short x) {
	m_x = x;
}
short Node::GetY() {
	return m_y;
}
void Node::SetY(short y) {
	m_y = y;
}
int Node::GetDir() {
	return m_dir;
}
void Node::SetDir(int dir) {
	m_dir = dir;
}
Node& Node::NodeMove() {
	int nKey = m_dir;
	if (_kbhit())
		nKey = _getch();
	if (nKey == ' ')
	{
		ShowChar(wide, 10, 0x0b, "游戏暂停!");
		ShowChar(wide, 11, 0x0b, "按空格回到游戏");
		while (_getch() != ' ')
		{
			;
		}
		ShowChar(wide, 10, 0x0f, "         ");
		ShowChar(wide, 11, 0x0f, "              ");
		nKey = m_dir;
	}
	else if (nKey == ESC) {
		g_FileRecord = 1;
		nKey = m_dir;
	}
	else if (nKey == '+')
	{
		if (g_speed >= 150)
			g_speed -= 100;
		else
			g_speed = 50;
		nKey = m_dir;
	}
	else if (nKey == '-')
	{
		g_speed += 100;
		nKey = m_dir;
	}
	switch (nKey)
	{
	case 'w':case 'W':
		nKey = UP;
		break;
	case 's':case 'S':
		nKey = DOWN;
		break;
	case 'a':case 'A':
		nKey = LEFT;
		break;
	case 'd':case 'D':
		nKey = RIGHT;
		break;
	default:
		nKey = m_dir;
		break;
	}
	if (nKey == -m_dir)       //方向冲突
		nKey = m_dir;
	switch (nKey) {
	case UP:
		m_y--;
		break;
	case DOWN:
		m_y++;
		break;
	case LEFT:
		m_x--;
		break;
	case RIGHT:
		m_x++;
		break;
	default:
		break;
	}
	m_dir = nKey;
	return *this;
}
void Node::ShowNode(short x, short y, WORD color, char* pstr) {
	ShowChar(x, y, color, pstr);
}