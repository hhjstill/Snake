#pragma once
#include "Node.h"
#include <vector>
#include "g_Data.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
class Snake
{
	vector<Node> m_vec;
public:;
	//************************************
	// Method:    Snake
	// Descrition:��ʼ����ֻ��һ���ڵ㲢Ϊ
	//			  ��ָ������ͷ���
	// Parameter: Node node
	//************************************
	Snake(Node node = Node());
	vector<Node>& GetSnake();
	//************************************
	// Method:    GetHead
	// Descrition:�õ������ߵ�ͷ
	//************************************
	Node& GetHead();
	//************************************
	// Method:    AddNode
	// Descrition:����β����һ���ڵ�
	//************************************
	void AddNode();
	//************************************
	// Method:    SnakeMove
	// Descrition:�߰�ָ�������ƶ�һ��
	// Parameter: int speed
	//************************************
	void SnakeMove(int speed);
};
