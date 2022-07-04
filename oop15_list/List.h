#pragma once
#include<iostream>
#include"node.h"
#include"Forfeit.h"
using namespace std;
template<class N>
struct Element
{
	//Данные
	N data;
	//Адрес следующего элемента списка
	Element* Next;
};
template<class T>
class List
{
public:
	//Адрес головного элемента списка
	Element<T>* Head;
	//Адрес концевого элемента списка
	Element<T>* Tail;
	//Количество элементов списка
	int Count;

	//Конструктор
	List<T>() 
	{
		//Изначально список пуст
		Head = Tail = NULL;
		Count = 0;
	};
	//Деструктор
	~List<T>()
	{
		//Вызов функции удаления
		DelAll();
	};
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(T data)
	{
		//создание нового элемента
		Element<T>* temp = new Element<T>;
		//заполнение данными
		temp->data = data;
		//следующий элемент отсутствует
		temp->Next = NULL;
		//новый элемент становится последним элементом списка
		//если он не первый добавленный
		if (Head != NULL) {
			Tail->Next = temp;
			Tail = temp;
		}
		//новый элемент становится единственным
		//если он первый добавленный
		else {
			Head = Tail = temp;
		}
	};
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Del()
	{
		//запоминаем адрес головного элемента
		Element<T>* temp = Head;
		//перебрасываем голову на следующий элемент
		Head = Head->Next;
		//удаляем бывший головной элемент
		delete temp;
	};
	//Удаление всего списка
	void DelAll()
	{
		//Пока еще есть элементы 
		while (Head != 0)
			//Удаляем элементы по одному
			Del();
	};
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	
	void Print()
	{
		//запоминаем адрес головного элемента
		Element<T>* temp = Head;
		//Пока еще есть элементы
		while (temp != 0)
		{
			//Выводим данные
			cout << temp->data;
			//Переходим на следующий элемент
			temp = temp->Next;
		}
		cout << "\n\n";
	};

	

	template <typename T>
	void Print()
	{
		//запоминаем адрес головного элемента
		Element<T>* temp = Head;
		//Пока еще есть элементы
		while (temp != 0)
		{
			//Выводим данные
			cout << temp->data << " ";
			//Переходим на следующий элемент
			temp = temp->Next;
		}
		cout << "\n\n";
	};
	//Получение количества элементов,
	//находящихся в списке
	int GetCount()
	{
		//Возвращаем количество элементов
		return Count;
	};














	//int findOfNumber(T);

	//template<class T>
	//List<T>::List()
	//{
	//	//Изначально список пуст
	//	Head = Tail = NULL;
	//	Count = 0;
	//}

	//template<class T>
	//List<T>::~List()
	//{
	//	//Вызов функции удаления
	//	DelAll();
	//}

	//template<class T>
	//void List<T>::Add(T data)
	//{
	//	//создание нового элемента
	//	Element* temp = new Element;
	//	//заполнение данными
	//	temp->data = data;
	//	//следующий элемент отсутствует
	//	temp->Next = NULL;
	//	//новый элемент становится последним элементом списка
	//	//если он не первый добавленный
	//	if (Head != NULL) {
	//		Tail->Next = temp;
	//		Tail = temp;
	//	}
	//	//новый элемент становится единственным
	//	//если он первый добавленный
	//	else {
	//		Head = Tail = temp;
	//	}
	//}
	//template<class T>
	//void List<T>::Del()
	//{
	//	//запоминаем адрес головного элемента
	//	Element* temp = Head;
	//	//перебрасываем голову на следующий элемент
	//	Head = Head->Next;
	//	//удаляем бывший головной элемент
	//	delete temp;
	//}
	//template<class T>
	//void List<T>::DelAll()
	//{
	//	//Пока еще есть элементы 
	//	while (Head != 0)
	//		//Удаляем элементы по одному
	//		Del();
	//}
	//template<class T>
	//void List<T>::Print()
	//{
	//	//запоминаем адрес головного элемента
	//	Element* temp = Head;
	//	//Пока еще есть элементы
	//	while (temp != 0)
	//	{
	//		//Выводим данные
	//		cout << temp->data << " ";
	//		//Переходим на следующий элемент
	//		temp = temp->Next;
	//	}
	//	cout << "\n\n";
	//}
	//template<class T>
	//int List<T>::GetCount()
	//{
	//	//Возвращаем количество элементов
	//	return Count;
	//}


	//template<class T>
	//int List<T>::findOfNumber(T num)
	//{
	//	//запоминаем адрес головного элемента
	//	Element* temp = Head;
	//	int count = 1;
	//	while (temp != 0)
	//	{
	//		if (temp->data == num)
	//		{
	//			return count;
	//		}
	//		count++;
	//		//Переходим на следующий элемент
	//		temp = temp->Next;
	//	}
	//	cout << "\n\n";

	//	return NULL;
	//}
};




