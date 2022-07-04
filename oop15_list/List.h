#pragma once
#include<iostream>
#include"node.h"
#include"Forfeit.h"
using namespace std;
template<class N>
struct Element
{
	//������
	N data;
	//����� ���������� �������� ������
	Element* Next;
};
template<class T>
class List
{
public:
	//����� ��������� �������� ������
	Element<T>* Head;
	//����� ��������� �������� ������
	Element<T>* Tail;
	//���������� ��������� ������
	int Count;

	//�����������
	List<T>() 
	{
		//���������� ������ ����
		Head = Tail = NULL;
		Count = 0;
	};
	//����������
	~List<T>()
	{
		//����� ������� ��������
		DelAll();
	};
	//���������� �������� � ������
	//(����� ������� ���������� ���������)
	void Add(T data)
	{
		//�������� ������ ��������
		Element<T>* temp = new Element<T>;
		//���������� �������
		temp->data = data;
		//��������� ������� �����������
		temp->Next = NULL;
		//����� ������� ���������� ��������� ��������� ������
		//���� �� �� ������ �����������
		if (Head != NULL) {
			Tail->Next = temp;
			Tail = temp;
		}
		//����� ������� ���������� ������������
		//���� �� ������ �����������
		else {
			Head = Tail = temp;
		}
	};
	//�������� �������� ������
	//(��������� �������� �������)
	void Del()
	{
		//���������� ����� ��������� ��������
		Element<T>* temp = Head;
		//������������� ������ �� ��������� �������
		Head = Head->Next;
		//������� ������ �������� �������
		delete temp;
	};
	//�������� ����� ������
	void DelAll()
	{
		//���� ��� ���� �������� 
		while (Head != 0)
			//������� �������� �� ������
			Del();
	};
	//���������� ����������� ������
	//(���������� ���������� � ��������� ��������) 
	
	void Print()
	{
		//���������� ����� ��������� ��������
		Element<T>* temp = Head;
		//���� ��� ���� ��������
		while (temp != 0)
		{
			//������� ������
			cout << temp->data;
			//��������� �� ��������� �������
			temp = temp->Next;
		}
		cout << "\n\n";
	};

	

	template <typename T>
	void Print()
	{
		//���������� ����� ��������� ��������
		Element<T>* temp = Head;
		//���� ��� ���� ��������
		while (temp != 0)
		{
			//������� ������
			cout << temp->data << " ";
			//��������� �� ��������� �������
			temp = temp->Next;
		}
		cout << "\n\n";
	};
	//��������� ���������� ���������,
	//����������� � ������
	int GetCount()
	{
		//���������� ���������� ���������
		return Count;
	};














	//int findOfNumber(T);

	//template<class T>
	//List<T>::List()
	//{
	//	//���������� ������ ����
	//	Head = Tail = NULL;
	//	Count = 0;
	//}

	//template<class T>
	//List<T>::~List()
	//{
	//	//����� ������� ��������
	//	DelAll();
	//}

	//template<class T>
	//void List<T>::Add(T data)
	//{
	//	//�������� ������ ��������
	//	Element* temp = new Element;
	//	//���������� �������
	//	temp->data = data;
	//	//��������� ������� �����������
	//	temp->Next = NULL;
	//	//����� ������� ���������� ��������� ��������� ������
	//	//���� �� �� ������ �����������
	//	if (Head != NULL) {
	//		Tail->Next = temp;
	//		Tail = temp;
	//	}
	//	//����� ������� ���������� ������������
	//	//���� �� ������ �����������
	//	else {
	//		Head = Tail = temp;
	//	}
	//}
	//template<class T>
	//void List<T>::Del()
	//{
	//	//���������� ����� ��������� ��������
	//	Element* temp = Head;
	//	//������������� ������ �� ��������� �������
	//	Head = Head->Next;
	//	//������� ������ �������� �������
	//	delete temp;
	//}
	//template<class T>
	//void List<T>::DelAll()
	//{
	//	//���� ��� ���� �������� 
	//	while (Head != 0)
	//		//������� �������� �� ������
	//		Del();
	//}
	//template<class T>
	//void List<T>::Print()
	//{
	//	//���������� ����� ��������� ��������
	//	Element* temp = Head;
	//	//���� ��� ���� ��������
	//	while (temp != 0)
	//	{
	//		//������� ������
	//		cout << temp->data << " ";
	//		//��������� �� ��������� �������
	//		temp = temp->Next;
	//	}
	//	cout << "\n\n";
	//}
	//template<class T>
	//int List<T>::GetCount()
	//{
	//	//���������� ���������� ���������
	//	return Count;
	//}


	//template<class T>
	//int List<T>::findOfNumber(T num)
	//{
	//	//���������� ����� ��������� ��������
	//	Element* temp = Head;
	//	int count = 1;
	//	while (temp != 0)
	//	{
	//		if (temp->data == num)
	//		{
	//			return count;
	//		}
	//		count++;
	//		//��������� �� ��������� �������
	//		temp = temp->Next;
	//	}
	//	cout << "\n\n";

	//	return NULL;
	//}
};




