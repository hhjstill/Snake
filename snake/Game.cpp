#include "Game.h"
void Game::UserUI() {
	m_ui.ControlDesk();
	m_ui.ShowMenu();
}
void Game::GameShow() {
	PlaySoundA("sound\\background.wav", NULL, SND_ASYNC | SND_NODEFAULT);//���ű�������
	int isEdit = 0;
	int nChoice = 0;
	int RealChoice = 0;
	nChoice = m_ui.GetChoice();
	while (nChoice != '\r')        //�������룬��갴��Ӧ������ʾѡ��
	{
		m_ui.ShowMenu(nChoice);
		RealChoice = nChoice;
		nChoice = m_ui.GetChoice();
	}
	if (RealChoice == '2')         //�����������룬��������ִ����Ӧ����
		g_speed = 200;
	else if (RealChoice == '4')
	{
		if (!ReadFile())
		{
			ShowChar(15, 35, 0x0e, "�ļ������ڣ�������������Ϸ...");
			Sleep(2000);
		}
	}
	else if (RealChoice == '5')
		isEdit = 1;
	system("cls");
	m_map.ShowWall(isEdit);
	m_ui.ShowInfo();
	while (1)       //��Ϸ������Ҫ����
	{
		if (m_map.eat(RealChoice))
			return;
		m_ui.ShowInfo();
	}
}
int Game::StartGame() {
	system("cls");
	UserUI();
	GameShow();
	char nChoice = 0;
	ShowChar(4, 12, 0x0b, "�Ƿ����¿�ʼ------(y/n)?", true);
	while ((nChoice = getchar()) == '\n')
		;
	while (nChoice != 'n' && nChoice != 'y')
	{
		ShowChar(4, 13, 0x0b, "��������y/n�������������룺", true);
		nChoice = getchar();
	}
	if (nChoice == 'n')
	{
		ShowChar(4, 13, 0x0b, "�ټ�!!!", true);
		ShowChar(4, 14, 0x0b, "", true);
		return 0;
	}
	return 1;
}
bool Game::ReadFile()
{
	ShowChar(15, 33, 0x0e, "�򿪵ڼ����浵��",true);
	int nChoice = 0;
	//cin >> nChoice;
	while (!(cin >> nChoice) || nChoice < 1 || nChoice > 5)  //����Ƿ�����
	{
		ShowChar(15, 34, 0x0e, "��ౣ��5��!�������룺",true);
		cin.clear();
		while (getchar() != '\n')
			;
	}
	FILE* fpFile = nullptr;
	if (fopen_s(&fpFile, filename[nChoice - 1], "rb"))
		return false;
	int myDir = 0;
	fread(&g_FileCnt, sizeof(g_FileCnt), 1, fpFile);
	fread(&myDir, sizeof(myDir), 1, fpFile);
	fread(&g_len, sizeof(g_len), 1, fpFile);
	fread(&g_level, sizeof(g_level), 1, fpFile);
	fread(&g_score, sizeof(g_score), 1, fpFile);
	fread(&g_speed, sizeof(g_speed), 1, fpFile);
	fread(&g_wall[0][0], sizeof(g_wall), 1, fpFile);
	Snake& MySnake = m_map.GetSnake();
	MySnake.GetSnake().clear();
	for (int i = 0; i < g_len; i++)
	{
		Node temp;
		short x = temp.GetX(), y = temp.GetY();
		fread(&x, sizeof(x), 1, fpFile);
		fread(&y, sizeof(x), 1, fpFile);
		temp.SetX(x);
		temp.SetY(y);
		MySnake.GetSnake().push_back(temp);
	}
	MySnake.GetHead() = MySnake.GetSnake()[0];
	MySnake.GetHead().SetDir(myDir);
	fclose(fpFile);
	return true;
}