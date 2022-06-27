#pragma once
#include<iostream>
using namespace std;
struct Element
{
	//������
	int data;
	//����� ���������� �������� ������
	Element* Next;
};
class List
{
	//����� ��������� �������� ������
	Element* Head;
	//����� ��������� �������� ������
	Element* Tail;
	//���������� ��������� ������
	int Count;
public:
	//�����������
	List();
	//����������
	~List();
	//���������� �������� � ������
	//(����� ������� ���������� ���������)
	void Add(int data);
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
	int findOfNumber(int);
};




