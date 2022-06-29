#include <iostream>
#include<iostream>
#include"List.h"
using namespace std;
// List шаблон
// Shtraf
// Node вершина дерева(класс или структура)
// Tree

int main()
{
	//Создаем объект класса List
	List<int> lst;
	
	for (int i = 0; i < 10; i++)	lst.Add(i*2);

	lst.Print();
	
	cout <<"elemrnt 8 - " << lst.findOfNumber(8);
	cout << "elemrnt 3 - " << lst.findOfNumber(3);


}

