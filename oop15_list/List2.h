#pragma once
#include<iostream>
using namespace std;

struct Elem
{
	int data; //данные
	Elem* next, * prev;
};

class List2
{
	//Голова, хвост
	Elem* Head, * Tail;
	//Количество элементов
	int Count;
public:
	//Конструктор
	List2();
	//Конструктор копирования
	List2(const List2&);
	//Деструктор
	~List2();
	//Получить количество
	int GetCount();
	//Получить элемент списка
	Elem* GetElem(int);
	//Удалить весь список
	void DelAll();
	//Удаление элемента, если параметр 
	//не указывается,
	//то функция его запрашивает
	void Del(int pos = 0);
	//Вставка элемента, если параметр не указывается,
 //то функция его запрашивает
	void Insert(int pos = 0);
	//Добавление в конец списка
	void AddTail(int n);
	//Добавление в начало списка
	void AddHead(int n);
	//Печать списка
	void Print();
	//Печать определенного элемента
	void Print(int pos);
	List2& operator = (const List2&);
	//сложение двух списков (дописывание)
	List2 operator + (const List2&);
	//сравнение по элементам
	bool operator == (const List2&);
	bool operator != (const List2&);
	bool operator <= (const List2&);
	bool operator >= (const List2&);
	bool operator < (const List2&);
	bool operator > (const List2&);
	//переворачивание списка
	List2 operator - ();
};

