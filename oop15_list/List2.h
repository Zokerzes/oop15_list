#pragma once
#include<iostream>
using namespace std;

struct Elem
{
	int data; //������
	Elem* next, * prev;
};

class List2
{
	//������, �����
	Elem* Head, * Tail;
	//���������� ���������
	int Count;
public:
	//�����������
	List2();
	//����������� �����������
	List2(const List2&);
	//����������
	~List2();
	//�������� ����������
	int GetCount();
	//�������� ������� ������
	Elem* GetElem(int);
	//������� ���� ������
	void DelAll();
	//�������� ��������, ���� �������� 
	//�� �����������,
	//�� ������� ��� �����������
	void Del(int pos = 0);
	//������� ��������, ���� �������� �� �����������,
 //�� ������� ��� �����������
	void Insert(int pos = 0);
	//���������� � ����� ������
	void AddTail(int n);
	//���������� � ������ ������
	void AddHead(int n);
	//������ ������
	void Print();
	//������ ������������� ��������
	void Print(int pos);
	List2& operator = (const List2&);
	//�������� ���� ������� (�����������)
	List2 operator + (const List2&);
	//��������� �� ���������
	bool operator == (const List2&);
	bool operator != (const List2&);
	bool operator <= (const List2&);
	bool operator >= (const List2&);
	bool operator < (const List2&);
	bool operator > (const List2&);
	//��������������� ������
	List2 operator - ();
};

