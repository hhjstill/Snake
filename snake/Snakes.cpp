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
	switch (m_vec[g_len - 1].GetDir())   //����β�ڵ�ȷ���½ڵ�λ��
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
	m_vec.push_back(newnode);          //�����½ڵ�       
	g_len++;
	g_score = g_len - 1;
	g_level = g_score / 10 + 1;
	static int TempSpeed = g_speed;
	g_speed = TempSpeed - 10 * (g_level - 1);
}
void Snake::SnakeMove(int speed) {
	Node temp = m_vec[0];
	for (auto& node : m_vec)          //��ӡ��
	{
		node.ShowNode(node.GetX(), node.GetY(), 0xef, "��");
	}
	Sleep(speed);
	for (auto& node : m_vec)          //������
	{
		ShowChar(node.GetX(), node.GetY(), 0x0f, "  ");
	}
	//��ͷ����ƶ����λ����Ϊ��ͷ��㣬ɾ��β�ڵ�
	m_vec.insert(m_vec.begin(), temp.NodeMove()); 
	m_vec.erase(m_vec.end() - 1);            
}


