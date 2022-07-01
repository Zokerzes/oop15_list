#include <iostream>
#include<iostream>
#include"List.h"
#include"Forfeit.h"
#include"Tree.h"
#include"node.h"
#include<string>
using namespace std;
// List шаблон
// Shtraf
// Node вершина дерева(класс или структура)
// Tree

int main()
{
	Tree tree;
	Forfeit f("TB444O61", 28, 500, "28.06.2022");
	//node n;
	//n.setNumberCar(f.numberCar);
	//n.addForfeit(f);
	//tree.Insert(&n);
	//tree.Print(&n);
	cout << f.numberCar << " " << f.numOffense << " " << f.summ;

}

