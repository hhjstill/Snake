#include "g_Data.h"
const char* filename[5] = {
	"snakeone.txt",
	"snaketwo.txt",
	"snakethree.txt",
	"snakefour.txt",
	"snakefive.txt"
};
int g_FileCnt = 0;
int g_level = 1;
int g_score = 0;
int g_speed = 300;
int g_len = 1;
int g_FileRecord = 0;
const int wide = 40;
const int height = 40;
int g_wall[40][40] = { 0 };
void ShowChar(short x, short y, WORD color, char* pstr, bool visual) {
	HANDLE outhand = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 2 * x, y };
	CONSOLE_CURSOR_INFO cci = { 1, visual };
	SetConsoleCursorInfo(outhand, &cci);
	SetConsoleCursorPosition(outhand, pos);
	SetConsoleTextAttribute(outhand, color);
	std::cout << pstr;
}
//Game game;
//void SaveFile(Game game)
//{
//	FILE* fpFile = nullptr;
//	if (fopen_s(&fpFile, "snake.txt", "wb"))
//		return;
//	fwrite(&g_level, sizeof(g_level), 1, fpFile);
//	fwrite(&g_score, sizeof(g_score), 1, fpFile);
//	fwrite(&g_speed, sizeof(g_speed), 1, fpFile);
//	fwrite(&game, sizeof(game), 1, fpFile);
//	fclose(fpFile);
//}