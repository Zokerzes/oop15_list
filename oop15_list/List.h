#pragma once
#include<iostream>
using namespace std;
struct Element
{
	//Данные
	int data;
	//Адрес следующего элемента списка
	Element* Next;
};
class List
{
	//Адрес головного элемента списка
	Element* Head;
	//Адрес концевого элемента списка
	Element* Tail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List();
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(int data);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void Print();
	//Получение количества элементов,
	//находящихся в списке
	int GetCount();
	int findOfNumber(int);
};




