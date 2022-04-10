#pragma once
#include"worker.h"
#include<iostream>
using namespace std;
class Employee : public Worker
{
public:
	Employee(string name, int id, int did);
	~Employee();
	virtual string  getStaff();
	virtual void showit();
};