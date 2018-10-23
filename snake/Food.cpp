#include "Food.h"
Food::Food(char* pstr) :m_char(pstr) {}
short Food::GetX() {
	return m_food.GetX();
}
short Food::GetY() {
	return m_food.GetY();
}
void Food::ShowFood(Snake snake) {
	srand((unsigned)time(0));
	int TempX, TempY;
	TempX = rand() % (wide - 2) + 1;
	TempY = rand() % (height - 2) + 1;
	for (int i = 0; i < g_len; i++)
	{
		if (TempX == snake.GetSnake()[i].GetX() &&
			TempY == snake.GetSnake()[i].GetY() ||
			g_wall[TempY][TempX] == 1)
		{
			TempX = rand() % (wide - 2) + 1;
			TempY = rand() % (height - 2) + 1;
			i = -1;
		}
	}
	m_food.SetX(TempX);
	m_food.SetY(TempY);
	ShowChar(m_food.GetX(), m_food.GetY(), 0x4f, m_char);
}
void Food::ShowBadFood(Snake snake) {
	srand((unsigned)time(0));
	int TempX, TempY;
	TempX = rand() % (wide - 2) + 1;
	TempY = rand() % (height - 2) + 1;
	for (int i = 0; i < g_len; i++)
	{
		if (TempX == snake.GetSnake()[i].GetX() &&
			TempY == snake.GetSnake()[i].GetY() ||
			TempX == m_food.GetX() && TempY == m_food.GetY() ||
			g_wall[TempY][TempX] == 1)
		{
			TempX = rand() % (wide - 2) + 1;
			TempY = rand() % (height - 2) + 1;
			i = -1;
		}
	}
	ShowChar(TempX, TempY, 0x5f, "กอ");
	g_wall[TempY][TempX] = 1;
}