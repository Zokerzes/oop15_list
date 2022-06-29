#pragma once
#include<iostream>
using namespace std;
template<class T>
struct Element
{
	//������
	T data;
	//����� ���������� �������� ������
	Element* Next;
};
template<class T>
class List
{
	//����� ��������� �������� ������
	Element<T>* Head;
	//����� ��������� �������� ������
	Element<T>* Tail;
	//���������� ��������� ������
	int Count;
public:
	//�����������
	List<T>();
	//����������
	~List<T>();
	//���������� �������� � ������
	//(����� ������� ���������� ���������)
	void Add(T data);
	//�������� �������� ������
	//(��������� �������� �������)
	void Del();
	//�������� ����� ������
	void DelAll();
	//���������� ����������� ������
	//(���������� ���������� � ��������� ��������) 
	void Print();
	//��������� ���������� ���������,
	//����������� � ������
	int GetCount();
	int findOfNumber(T);
};




