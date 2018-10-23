#include "Map.h"
Snake& Map::GetSnake() {
	return m_snake;
}
Food Map::GetFood() {
	return m_food;
}
void Map::ShowWall(int edit) {
	m_wall.ShowWall(wide, height, edit);
}
bool Map::eat(int choice) {
	Node SnakeHead = m_snake.GetHead();
	m_food.ShowFood(m_snake);
	if (choice == '3')
	{
		m_food.ShowBadFood(m_snake);
		m_food.ShowBadFood(m_snake);
		g_speed = 200;
	}
	while (SnakeHead.GetX() != m_food.GetX()
		|| SnakeHead.GetY() != m_food.GetY())
	{
		m_snake.SnakeMove(g_speed);
		if (IsDie())
		{
			PlaySoundA("sound\\die.wav", NULL, SND_ASYNC | SND_NODEFAULT);
			ShowChar(4, 11, 0x0b, "游戏结束!!!");
			return true;
		}
		SnakeHead = m_snake.GetHead();
		if (g_FileRecord == 1)
		{
			if (SaveFile())
				ShowChar(wide, 20, 0x0b, "存档成功!");
			g_FileRecord = 0;
			g_FileCnt++;
			Sleep(1000);
			ShowChar(wide, 20, 0x0b, "         ");
		}
	}
	m_snake.AddNode();
	return false;
}
bool Map::IsDie() {
	if (HitWall() || EatSelf())
		return true;
	return false;
}
bool Map::HitWall() {
	Node SnakeHead = m_snake.GetHead();
	int HeadX = SnakeHead.GetX();
	int HeadY = SnakeHead.GetY();
	if (g_wall[HeadY][HeadX] == 1)
		return true;
	return false;
}
bool Map::EatSelf() {
	Node SnakeHead = m_snake.GetHead();
	vector<Node> snake = m_snake.GetSnake();
	for (int i = 1; i < g_len; i++)
	{
		if (SnakeHead.GetX() == snake[i].GetX() &&
			SnakeHead.GetY() == snake[i].GetY())
			return true;
	}
	return false;
}
bool Map::SaveFile()
{
	FILE* fpFile = nullptr;
	if (g_FileCnt >= 5)
	{
		ShowChar(wide, 18, 0x0b, "存档数量已到上限!");
		Sleep(1000);
		ShowChar(wide, 18, 0x0b, "                 ");
		return false;
	}
	if (fopen_s(&fpFile, filename[g_FileCnt], "wb"))
		return false;
	int myDir = 0;
	myDir = m_snake.GetHead().GetDir();
	int FileCnt = g_FileCnt + 1;
	fwrite(&FileCnt, sizeof(FileCnt), 1, fpFile);
	fwrite(&myDir, sizeof(myDir), 1, fpFile);
	fwrite(&g_len, sizeof(g_len), 1, fpFile);
	fwrite(&g_level, sizeof(g_level), 1, fpFile);
	fwrite(&g_score, sizeof(g_score), 1, fpFile);
	fwrite(&g_speed, sizeof(g_speed), 1, fpFile);
	fwrite(&g_wall[0][0], sizeof(g_wall), 1, fpFile);
	for (int i = 0; i < g_len; i++)
	{
		short x = m_snake.GetSnake()[i].GetX();
		short y = m_snake.GetSnake()[i].GetY();
		fwrite(&x, sizeof(x), 1, fpFile);
		fwrite(&y, sizeof(y), 1, fpFile);
	}
	fclose(fpFile);
	return true;
}
