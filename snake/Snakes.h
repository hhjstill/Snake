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
	// Descrition:初始化蛇只有一个节点并为
	//			  其指定坐标和方向
	// Parameter: Node node
	//************************************
	Snake(Node node = Node());
	vector<Node>& GetSnake();
	//************************************
	// Method:    GetHead
	// Descrition:得到整条蛇的头
	//************************************
	Node& GetHead();
	//************************************
	// Method:    AddNode
	// Descrition:在蛇尾增加一个节点
	//************************************
	void AddNode();
	//************************************
	// Method:    SnakeMove
	// Descrition:蛇按指定方向移动一步
	// Parameter: int speed
	//************************************
	void SnakeMove(int speed);
};
