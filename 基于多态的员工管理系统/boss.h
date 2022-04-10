#pragma once
#include"worker.h"
#include<iostream>
using namespace std;
class Boss : public Worker
{
public:
	Boss(string name, int id, int did);
	~Boss();
	virtual string  getStaff();
	virtual void showit();
};