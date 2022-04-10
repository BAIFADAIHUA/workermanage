#pragma once
#include<iostream>
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILE "TEXT.txt"
#include<string>
using namespace std;

class Managerworker
{
public:
	//创建构造和析构函数
	Managerworker();
	~Managerworker();

	//展示菜单
	void showMeau();

	//退出程序
	void exitSystem();
	
	//添加员工信息
	void addWorker();

	//创建数组指针接受员工
	Worker** m_AllWorker;
	int m_AllNum;

	//写入文件
	void writeFile();
	
	//读文件，需要判断是否有文件：1.无文件。2.有文件但为空。3.有文件
	bool m_FileEmpty;
	int getNum();
	void readFile();

	//显示职工
	void showWorker();
	
	//查询是否存在某个员工
	int  findWorker(int id);

	//删除员工
	void delWorker();

	//修改员工信息
	void rewriteWorker();

	//查找员工
	void searchWorker();

	//排序
	void reArrary();

	//格式化
	void delAll();
};//这里不要忘了加分号