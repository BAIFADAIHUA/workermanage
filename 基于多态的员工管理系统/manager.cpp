#include"manager.h"
Manager::Manager(string name, int id, int did)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_Did = did;
}
Manager::~Manager()
{

}
void Manager::showit()
{
	cout << "姓名：" << this->m_Name << "\t工号：" << this->m_Id << "\t岗位：" << this->getStaff() << "\t职责：" << "管理员工任务协调" << endl;
}
string Manager::getStaff()
{
	return "经理";
}