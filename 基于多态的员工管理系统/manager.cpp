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
	cout << "������" << this->m_Name << "\t���ţ�" << this->m_Id << "\t��λ��" << this->getStaff() << "\tְ��" << "����Ա������Э��" << endl;
}
string Manager::getStaff()
{
	return "����";
}