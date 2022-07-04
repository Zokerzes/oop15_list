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
	node n;
	Forfeit f1("TB444O61", 29, 1500, "30.06.2022");
	n.setNumberCar(f.numberCar);
	n.addForfeit(f);
	n.setNumberCar(f1.numberCar);
	n.addForfeit(f1);
	node n1;
	Forfeit j("TB555O61", 9, 2500, "25.06.2022");
	n1.setNumberCar(j.numberCar);
	n1.addForfeit(j);




	tree.Insert(&n);
	//tree.Insert(&n1);

	//tree.Print(tree.Search(&n, "TB555O61"));
	//n.addForfeit(f1);
	

	tree.Print(&n);
	//cout << f.numberCar << " " << f.numOffense << " " << f.summ;

}

