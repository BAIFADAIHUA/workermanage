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
	//�����������������
	Managerworker();
	~Managerworker();

	//չʾ�˵�
	void showMeau();

	//�˳�����
	void exitSystem();
	
	//���Ա����Ϣ
	void addWorker();

	//��������ָ�����Ա��
	Worker** m_AllWorker;
	int m_AllNum;

	//д���ļ�
	void writeFile();
	
	//���ļ�����Ҫ�ж��Ƿ����ļ���1.���ļ���2.���ļ���Ϊ�ա�3.���ļ�
	bool m_FileEmpty;
	int getNum();
	void readFile();

	//��ʾְ��
	void showWorker();
	
	//��ѯ�Ƿ����ĳ��Ա��
	int  findWorker(int id);

	//ɾ��Ա��
	void delWorker();

	//�޸�Ա����Ϣ
	void rewriteWorker();

	//����Ա��
	void searchWorker();

	//����
	void reArrary();

	//��ʽ��
	void delAll();
};//���ﲻҪ���˼ӷֺ�