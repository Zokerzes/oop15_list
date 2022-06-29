#include "List.h"
template<class T>
List<T>::List()
{
	//Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

template<class T>
List<T>::~List()
{
	//Вызов функции удаления
	DelAll();
}

template<class T>
void List<T>::Add(T data)
{
	//создание нового элемента
	Element* temp = new Element;
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
}
template<class T>
void List<T>::Del()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	//удаляем бывший головной элемент
	delete temp;
}
template<class T>
void List<T>::DelAll()
{
	//Пока еще есть элементы 
	while (Head != 0)
		//Удаляем элементы по одному
		Del();
}
template<class T>
void List<T>::Print()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//Пока еще есть элементы
	while (temp != 0)
	{
		//Выводим данные
		cout << temp->data << " ";
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}
template<class T>
int List<T>::GetCount()
{
	//Возвращаем количество элементов
	return Count;
}

template<class T>
int List<T>::findOfNumber(T num)
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	int count = 1;
	while (temp != 0)
	{
		if (temp->data == num) 
		{
			return count;
		}
		count++;
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
	
	return NULL;
}
