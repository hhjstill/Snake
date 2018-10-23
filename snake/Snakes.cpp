#include "Snakes.h"
Snake::Snake(Node node) {
	m_vec.push_back(node);
}
vector<Node>& Snake::GetSnake() {
	return m_vec;
}
Node& Snake::GetHead() {
	return m_vec[0];
}
void Snake::AddNode() {
	Node newnode;
	switch (m_vec[g_len - 1].GetDir())   //根据尾节点确定新节点位置
	{
	case UP:
		newnode.SetX(m_vec[g_len - 1].GetX());
		newnode.SetY(m_vec[g_len - 1].GetY() + 1);
		newnode.SetDir(m_vec[g_len - 1].GetDir());
		break;
	case DOWN:
		newnode.SetX(m_vec[g_len - 1].GetX());
		newnode.SetY(m_vec[g_len - 1].GetY() - 1);
		newnode.SetDir(m_vec[g_len - 1].GetDir());
		break;
	case LEFT:
		newnode.SetX(m_vec[g_len - 1].GetX() + 1);
		newnode.SetY(m_vec[g_len - 1].GetY());
		newnode.SetDir(m_vec[g_len - 1].GetDir());
		break;
	case RIGHT:
		newnode.SetX(m_vec[g_len - 1].GetX() - 1);
		newnode.SetY(m_vec[g_len - 1].GetY());
		newnode.SetDir(m_vec[g_len - 1].GetDir());
		break;
	default:
		break;
	}
	m_vec.push_back(newnode);          //插入新节点       
	g_len++;
	g_score = g_len - 1;
	g_level = g_score / 10 + 1;
	static int TempSpeed = g_speed;
	g_speed = TempSpeed - 10 * (g_level - 1);
}
void Snake::SnakeMove(int speed) {
	Node temp = m_vec[0];
	for (auto& node : m_vec)          //打印蛇
	{
		node.ShowNode(node.GetX(), node.GetY(), 0xef, "　");
	}
	Sleep(speed);
	for (auto& node : m_vec)          //擦除蛇
	{
		ShowChar(node.GetX(), node.GetY(), 0x0f, "  ");
	}
	//将头结点移动后的位置作为新头结点，删除尾节点
	m_vec.insert(m_vec.begin(), temp.NodeMove()); 
	m_vec.erase(m_vec.end() - 1);            
}


