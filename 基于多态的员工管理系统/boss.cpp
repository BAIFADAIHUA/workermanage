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
	 cout << "������" << this->m_Name << "\t���ţ�" << this->m_Id << "\t��λ��" << this->getStaff() << "\tְ��" << "�滮����" << endl;
}
string Boss::getStaff()
{
	return "�ϰ�";
}