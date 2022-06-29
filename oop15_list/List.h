#pragma once
#include<iostream>
using namespace std;
template<class T>
struct Element
{
	//Данные
	T data;
	//Адрес следующего элемента списка
	Element* Next;
};
template<class T>
class List
{
	//Адрес головного элемента списка
	Element<T>* Head;
	//Адрес концевого элемента списка
	Element<T>* Tail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List<T>();
	//Деструктор
	~List<T>();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(T data);
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
	int findOfNumber(T);
};




