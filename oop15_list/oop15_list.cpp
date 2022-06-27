#include <iostream>
#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	//Создаем объект класса List
	List lst;
	
	for (int i = 0; i < 10; i++)	lst.Add(i*2);

	lst.Print();
	
	cout <<"elemrnt 8 - " << lst.findOfNumber(8);
	cout << "elemrnt 3 - " << lst.findOfNumber(3);
}

