#pragma once
#include <Windows.h>
#include <iostream>
extern const char* filename[5];
extern int g_FileCnt;
extern int g_level;
extern int g_score;
extern int g_speed;
extern int g_len;
extern int g_FileRecord;
extern const int wide;
extern const int height;
extern int g_wall[40][40];
//************************************
// Method:    ShowChar
// Descrition:在指定光标处显示指定字符串，可控制光标可见与否
// Parameter: short x
// Parameter: short y
// Parameter: WORD color
// Parameter: char * pstr
// Parameter: bool visual
//************************************
void ShowChar(short x, short y, WORD color, char* pstr, bool visual = false);


