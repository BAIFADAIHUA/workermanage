#pragma once
#include"worker.h"
#include<iostream>
using namespace std;
class Manager : public Worker
{
public:
	Manager(string name, int id, int did);
	~Manager();
	virtual string  getStaff();
	virtual void showit();
};