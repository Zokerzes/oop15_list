#pragma once
#include<iostream>
#include "List.h"
#include"Forfeit.h"
#include<string>
#include"node.h"
#include"Tree.h"
using namespace std;

class io
{
	Tree tree;
public:
	io() {};
	~io() 
	{
		void Del(node * root);
	};
	void addForfeit() 
	{
		Forfeit temp;
		cout << "------------------" << endl;
		cout << "Adding a violation" << endl;
		cout << "------------------" << endl;
		cout << "Enter number car: " << endl;
		cin >> temp.numberCar;

	};
};

