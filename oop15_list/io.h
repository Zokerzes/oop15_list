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
	Forfeit tempForfeit;
	node tempNode;
public:
	io() {};
	~io() 
	{
		void Del(node * root);
	};
	void addForfeit() 
	{
		Forfeit tempForfeit;
		
		node tempNode;
		cout << "------------------" << endl;
		cout << "Adding a violation" << endl;
		cout << "------------------" << endl;
		cout << "Enter number car: " << endl;
		cin >> tempForfeit.numberCar;
		cout << "Enter date: " << endl;
		cin >> tempForfeit.date;
		cout << "Enter number forfeit: " << endl;
		cin >> tempForfeit.numOffense;
		cout << "Enter price forfeit: " << endl;
		cin >> tempForfeit.summ;
		tempNode.setNumberCar(tempForfeit.numberCar);
		tempNode.addForfeit(tempForfeit);

		tree.Insert(&tempNode);
		//cout << tempForfeit << endl;
	};
	void printTree() 
	{
		
		tree.Print(tree.GetRoot());
		
	};
};

