#include "Node.h"
#include "Snakes.h"
#include "Food.h"
#include "Map.h"
#include "Wall.h"
#include "userUI.h"
#include "Game.h"

int main()
{
	while (1)
	{
		{
			Game game;
			if (!(game.StartGame()))
				break;
		}
		g_level = 1;
		g_score = 0;
		g_speed = 300;
		g_len = 1;
		for (int i = 0; i < wide; i++)
		{
			for (int j = 0; j < height; j++)
				g_wall[i][j] = 0;
		}
	}
	return 0;
}