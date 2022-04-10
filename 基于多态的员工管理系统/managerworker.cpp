#include"managerworker.h"
Managerworker::Managerworker()//����ֻ����δ��ʼ���ı�����Ҫ�ڹ��캯���г�ʼ�� 
{
	ifstream ifs(FILE, ios::in);
	//�ļ�������
	if (!ifs.is_open())//is_open()��һ������
	{
		cout << "�ļ�������" << endl;
		this->m_FileEmpty = true;
		this->m_AllNum = 0;
		this->m_AllWorker = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڵ�Ϊ��
	char c;
	ifs >> c;
    if (ifs >> c)
	{
		cout << "�ļ����ڵ�Ϊ��" << endl;
		this->m_FileEmpty = true;
		this->m_AllNum = 0;
		this->m_AllWorker = NULL;
		ifs.close();
		return;
	}
	//�ļ�����
	cout << "�ļ�����" << endl;
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
//�˵�����
void Managerworker::showMeau()
{
	cout << "*****************************" << endl;
	cout << "***** 0���˳����� *****" << endl;
	cout << "***** 1�����Ա�� *****" << endl;
    cout << "***** 2����ʾԱ�� *****" << endl;
	cout << "***** 3��ɾ��Ա�� *****" << endl;
	cout << "***** 4���޸�Ա�� *****" << endl;
	cout << "***** 5������Ա�� *****" << endl;
	cout << "***** 6������������� *****" << endl;
	cout << "***** 7����������ĵ� *****" << endl;
	cout << "*****************************" << endl;
}

//�˳�����
void Managerworker::exitSystem()
{
	cout << "�����˳�����" << endl;
	system("pause");
	exit(0);
}
//��ӳ���
void Managerworker::addWorker()
{
	int addNum = 0;
	cout << "��������ӵ�����" << endl;
	cin >> addNum;
	//�ж���������Ƿ�Ϸ�
	if (addNum > 0)
	{
		int newSize = m_AllNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		//�ж��Ƿ��������ݣ�����Ǩ��
		if (this->m_AllWorker != NULL)
		{
			for (int i = 0; i < this->m_AllNum; i++)
			{
				newSpace[i] = this->m_AllWorker[i];
			}
		}

		//��ʼ�����Ϣ
		for (int j = 0; j < addNum ; j++)
		{
			cout << "������Ա��������" << endl;
			string name;
			cin >> name;

			cout << "������Ա������" << endl;
			int id;
			cin >> id;


			cout << "������Ա����λ" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
				cout << "�������" << endl;
			}
			newSpace[this->m_AllNum + j] = worker;
		}
		//���ñ���
		delete[] m_AllWorker;
		this->m_AllNum = newSize;
		this->m_AllWorker = newSpace;
	}
	else
	{
		cout << "�����������" << endl;
	}
	this->m_FileEmpty = false;
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}

//д���ļ�
void Managerworker::writeFile()
{
	ofstream ofs(FILE, ios::out);
	for (int i = 0; i < m_AllNum; i++)
	{
		ofs << m_AllWorker[i]->m_Name << m_AllWorker[i]->m_Id << m_AllWorker[i]->getStaff() << endl;
	}
	ofs.close();
}

//���ļ�
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

//ͳ������
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

//��ʾԱ��
void Managerworker::showWorker()
{
	if (this->m_FileEmpty)
	{
		cout << "��Ա���ɲ�ѯ" << endl;
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

//��ѯ�Ƿ����ĳ��Ա��
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

//ɾ��Ա��
void Managerworker::delWorker()
{
	cout << "����������Ҫɾ����Ա���Ĺ���" << endl;
	int id;
	cin >> id;
	int j = this->findWorker(id);
	if (j != -1)
	{
		cout << "ȷ��ɾ��������" << endl;
		cout << "1: ȷ��" << endl;
		cout << "2: ����" << endl;
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
			cout << "ɾ���ɹ�" << endl;
			break;
		case2:
			system("pause");
			system("cls");
			break;
		default:
			cout << "ѡ�����" << endl;
			break;
		}
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�Ա����Ϣ
void Managerworker::rewriteWorker()
{
	cout << "����������Ҫ�޸ĵ�Ա���Ĺ���" << endl;
	int id;
	cin >> id;
	int j = this->findWorker(id);
	if (j!=-1)
	{
		cout << "ȷ���޸Ĵ�����" << endl;
		cout << "1: ȷ��" << endl;
		cout << "2: ����" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������Ա��������" << endl;
			string name;
			cin >> name;

			cout << "������Ա������" << endl;
			int m_id;
			cin >> m_id;


			cout << "������Ա����λ" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
				cout << "�������" << endl;
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
			cout << "ѡ�����" << endl;
			break;
		}
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//����Ա��
void Managerworker::searchWorker()
{
	cout << "����������Ҫ���ҵ�Ա���Ĺ���" << endl;
	int id;
	cin >> id;
	int j = this->findWorker(id);
	if (j!= -1)
	{
		this->m_AllWorker[j]->showit();
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//��ʽ��
void Managerworker::delAll()
{
	cout << "ȷ����ʽ����" << endl;
	cout << "1: ȷ��" << endl;
	cout << "2�� ����" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		this->m_AllNum = NULL;
		this->m_AllWorker = NULL;
		cout << "��ʽ���ɹ�" << endl;
		break;
	}
	case2:
		system("pause");
		system("cls");
		break;
	default:
		cout << "�������" << endl;
		break;
	}
	system("pause");
	system("cls");
}

//����
void Managerworker::reArrary()
{

	cout << "������ѡ��������ʽ" << endl;
	cout << "1: ����" << endl;
	cout << "2������" << endl;
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
		cout << "�������" << endl;
		break;
	}
	system("pause");
	system("cls");
}