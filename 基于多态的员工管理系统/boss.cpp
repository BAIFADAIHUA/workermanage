#include"boss.h"
Boss::Boss(string name, int id, int did)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_Did = did;
}
Boss::~Boss()
{

}
 void Boss::showit()
{
	 cout << "姓名：" << this->m_Name << "\t工号：" << this->m_Id << "\t岗位：" << this->getStaff() << "\t职责：" << "规划方向" << endl;
}
string Boss::getStaff()
{
	return "老板";
}