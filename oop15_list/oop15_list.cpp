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
	Forfeit j1("TB555O61", 12, 500, "24.06.2022");
	n1.setNumberCar(j1.numberCar);
	n1.addForfeit(j1);

	node n2;
	Forfeit g("CT111H77", 21, 5000, "21.05.2022");
	n2.setNumberCar(g.numberCar);
	n2.addForfeit(g);




	tree.Insert(&n);
	tree.Insert(&n1);
	tree.Insert(&n2);
	cout << "__________print__all______________" << endl;
	tree.Print(&n);
	cout << "__________seаrch__CT111H77________" << endl;
	tree.Print(tree.Search("CT111H77"));
	

	
	

}

