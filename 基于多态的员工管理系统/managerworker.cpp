#include"managerworker.h"
Managerworker::Managerworker()//所有只声名未初始化的变量需要在构造函数中初始化 
{
	ifstream ifs(FILE, ios::in);
	//文件不存在
	if (!ifs.is_open())//is_open()是一个函数
	{
		cout << "文件不存在" << endl;
		this->m_FileEmpty = true;
		this->m_AllNum = 0;
		this->m_AllWorker = NULL;
		ifs.close();
		return;
	}
	//文件存在但为空
	char c;
	ifs >> c;
    if (ifs >> c)
	{
		cout << "文件存在但为空" << endl;
		this->m_FileEmpty = true;
		this->m_AllNum = 0;
		this->m_AllWorker = NULL;
		ifs.close();
		return;
	}
	//文件存在
	cout << "文件存在" << endl;
	this->m_AllNum = this->getNum();
	this->m_AllWorker = new Worker * [m_AllNum];
	this->readFile();
}
Managerworker::~Managerworker()
{
		if (this->m_AllWorker != NULL)
		{
			delete[] this->m_AllWorker;
		}
}
//菜单程序
void Managerworker::showMeau()
{
	cout << "*****************************" << endl;
	cout << "***** 0：退出程序 *****" << endl;
	cout << "***** 1：添加员工 *****" << endl;
    cout << "***** 2：显示员工 *****" << endl;
	cout << "***** 3：删除员工 *****" << endl;
	cout << "***** 4：修改员工 *****" << endl;
	cout << "***** 5：查找员工 *****" << endl;
	cout << "***** 6：按照序号排序 *****" << endl;
	cout << "***** 7：清空所有文档 *****" << endl;
	cout << "*****************************" << endl;
}

//退出程序
void Managerworker::exitSystem()
{
	cout << "正在退出程序" << endl;
	system("pause");
	exit(0);
}
//添加程序
void Managerworker::addWorker()
{
	int addNum = 0;
	cout << "请输入添加的人数" << endl;
	cin >> addNum;
	//判断添加人数是否合法
	if (addNum > 0)
	{
		int newSize = m_AllNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		//判断是否已有数据，有则迁移
		if (this->m_AllWorker != NULL)
		{
			for (int i = 0; i < this->m_AllNum; i++)
			{
				newSpace[i] = this->m_AllWorker[i];
			}
		}

		//开始添加信息
		for (int j = 0; j < addNum ; j++)
		{
			cout << "请输入员工姓名：" << endl;
			string name;
			cin >> name;

			cout << "请输入员工工号" << endl;
			int id;
			cin >> id;


			cout << "请输入员工岗位" << endl;
			cout << "1：员工" << endl;
			cout << "2：经理" << endl;
			cout << "3：老板" << endl;
			int did;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(name, id, 1);
				break;
			case 2:
				worker = new Manager(name, id, 2);
				break;
			case 3:
				worker = new Boss(name, id, 3);
				break;
			default:
				cout << "输入错误" << endl;
			}
			newSpace[this->m_AllNum + j] = worker;
		}
		//重置变量
		delete[] m_AllWorker;
		this->m_AllNum = newSize;
		this->m_AllWorker = newSpace;
	}
	else
	{
		cout << "添加人数有误" << endl;
	}
	this->m_FileEmpty = false;
	cout << "输入成功" << endl;
	system("pause");
	system("cls");
}

//写入文件
void Managerworker::writeFile()
{
	ofstream ofs(FILE, ios::out);
	for (int i = 0; i < m_AllNum; i++)
	{
		ofs << m_AllWorker[i]->m_Name << m_AllWorker[i]->m_Id << m_AllWorker[i]->getStaff() << endl;
	}
	ofs.close();
}

//读文件
void Managerworker::readFile()
{
	ifstream ifs(FILE,ios::in);
	string name;
	int id;
	int did;
	int index = 0;

	while (ifs >> name && ifs >> id && ifs >> did)
	{
		Worker* worker = NULL;
		switch (did)
		{
		case 1:
			worker = new Employee(name,id,did);
			break;
		case 2:
			worker = new Manager(name, id, did);
			break;
		case 3:
			worker = new Boss(name, id, did);
			break;
		default:
			break;
		}
		this->m_AllWorker[index] = worker;
		index++;
	}
}

//统计人数
int Managerworker::getNum()
{
	ifstream ifs(FILE,ios::in);
	string name;
	int id;
	int did;
	int num = 0;
	while (ifs >> name && ifs >> id && ifs >> did)
	{
		num++;
	}
	return num;
}

//显示员工
void Managerworker::showWorker()
{
	if (this->m_FileEmpty)
	{
		cout << "无员工可查询" << endl;
	}
	else
	{
		for (int i = 0; i < m_AllNum; i++)
		{
			this->m_AllWorker[i]->showit();
		}
	}
	system("pause");
	system("cls");
}

//查询是否存在某个员工
int Managerworker::findWorker(int id)
{
	for (int i = 0; i < this->m_AllNum; i++)
	{
		if (m_AllWorker[i]->m_Id == id)
		{
			return i;

		}
		else
		{
			return -1;
		}
	}
}

//删除员工
void Managerworker::delWorker()
{
	cout << "请输入您想要删除的员工的工号" << endl;
	int id;
	cin >> id;
	int j = this->findWorker(id);
	if (j != -1)
	{
		cout << "确定删除此人吗？" << endl;
		cout << "1: 确定" << endl;
		cout << "2: 返回" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int a = j; a < m_AllNum; a++)
			{
				this->m_AllWorker[a] = this->m_AllWorker[a + 1];
			}
			this->writeFile();
			cout << "删除成功" << endl;
			break;
		case2:
			system("pause");
			system("cls");
			break;
		default:
			cout << "选择错误" << endl;
			break;
		}
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改员工信息
void Managerworker::rewriteWorker()
{
	cout << "请输入您想要修改的员工的工号" << endl;
	int id;
	cin >> id;
	int j = this->findWorker(id);
	if (j!=-1)
	{
		cout << "确定修改此人吗？" << endl;
		cout << "1: 确定" << endl;
		cout << "2: 返回" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入员工姓名：" << endl;
			string name;
			cin >> name;

			cout << "请输入员工工号" << endl;
			int m_id;
			cin >> m_id;


			cout << "请输入员工岗位" << endl;
			cout << "1：员工" << endl;
			cout << "2：经理" << endl;
			cout << "3：老板" << endl;
			int did;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(name, m_id, 1);
				break;
			case 2:
				worker = new Manager(name, m_id, 2);
				break;
			case 3:
				worker = new Boss(name, m_id, 3);
				break;
			default:
				cout << "输入错误" << endl;
			}
			m_AllWorker[j] = worker;
			this->writeFile();
			break;
		}
		case2:
			system("pause");
			system("cls");
			break;
		default:
			cout << "选择错误" << endl;
			break;
		}
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找员工
void Managerworker::searchWorker()
{
	cout << "请输入您想要查找的员工的工号" << endl;
	int id;
	cin >> id;
	int j = this->findWorker(id);
	if (j!= -1)
	{
		this->m_AllWorker[j]->showit();
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//格式化
void Managerworker::delAll()
{
	cout << "确定格式化吗？" << endl;
	cout << "1: 确定" << endl;
	cout << "2： 返回" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		this->m_AllNum = NULL;
		this->m_AllWorker = NULL;
		cout << "格式化成功" << endl;
		break;
	}
	case2:
		system("pause");
		system("cls");
		break;
	default:
		cout << "输入错误" << endl;
		break;
	}
	system("pause");
	system("cls");
}

//排序
void Managerworker::reArrary()
{

	cout << "请输入选择的排序格式" << endl;
	cout << "1: 升序" << endl;
	cout << "2：降序" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < m_AllNum - 1; i++)
		{
			for (int j = 0; j < m_AllNum - 1 - i; j++)
			{
				if (this->m_AllWorker[j]->m_Id > this->m_AllWorker[j + 1]->m_Id)
				{
					int  temp = this->m_AllWorker[j]->m_Id;
					this->m_AllWorker[j]->m_Id = this->m_AllWorker[j + 1]->m_Id;
					this->m_AllWorker[j + 1]->m_Id = temp;
				}
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < m_AllNum - 1; i++)
		{
			for (int j = 0; j < m_AllNum - 1 - i; j++)
			{
				if (this->m_AllWorker[j]->m_Id < this->m_AllWorker[j + 1]->m_Id)
				{
					int temp = this->m_AllWorker[j]->m_Id;
					this->m_AllWorker[j]->m_Id = this->m_AllWorker[j + 1]->m_Id;
					this->m_AllWorker[j + 1]->m_Id = temp;
				}
			}
		}
		break;
	}
	default:
		cout << "输入错误" << endl;
		break;
	}
	system("pause");
	system("cls");
}