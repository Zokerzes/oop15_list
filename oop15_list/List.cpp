#include "List.h"

List::List()
{
	//���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	//����� ������� ��������
	DelAll();
}

void List::Add(int data)
{
	//�������� ������ ��������
	Element* temp = new Element;
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
}

void List::Del()
{
	//���������� ����� ��������� ��������
	Element* temp = Head;
	//������������� ������ �� ��������� �������
	Head = Head->Next;
	//������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	//���� ��� ���� �������� 
	while (Head != 0)
		//������� �������� �� ������
		Del();
}

void List::Print()
{
	//���������� ����� ��������� ��������
	Element* temp = Head;
	//���� ��� ���� ��������
	while (temp != 0)
	{
		//������� ������
		cout << temp->data << " ";
		//��������� �� ��������� �������
		temp = temp->Next;
	}
	cout << "\n\n";
}

int List::GetCount()
{
	//���������� ���������� ���������
	return Count;
}

int List::findOfNumber(int num)
{
	//���������� ����� ��������� ��������
	Element* temp = Head;
	int count = 1;
	while (temp != 0)
	{
		if (temp->data == num) 
		{
			return count;
		}
		count++;
		//��������� �� ��������� �������
		temp = temp->Next;
	}
	cout << "\n\n";
	
	return NULL;
}
