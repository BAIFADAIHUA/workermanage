#include"employee.h"
Employee::Employee(string name, int id, int did)
{
	this->m_Name = name;
	this->m_Id = id;
	this->m_Did = did;
}
Employee::~Employee()
{

}
void Employee::showit()
{
	cout << "������" << this->m_Name << "\t���ţ�" << this->m_Id << "\t��λ��" << this->getStaff() << "\tְ��" << "��ɹ�������" << endl;
}
 string Employee::getStaff()
{
	 return "Ա��";
}