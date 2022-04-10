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
	cout << "姓名：" << this->m_Name << "\t工号：" << this->m_Id << "\t岗位：" << this->getStaff() << "\t职责：" << "完成工作任务" << endl;
}
 string Employee::getStaff()
{
	 return "员工";
}