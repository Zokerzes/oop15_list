#include "List2.h"

List2::List2()
{
	//���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List2::List2(const List2& L)
{
	Head = Tail = NULL;
	Count = 0;
	//������ ������, �� �������� ��������
	Elem* temp = L.Head;
	//���� �� ����� ������
	while (temp != 0)
	{
		//���������� ������
		AddTail(temp->data);
		temp = temp->next;
	}
}

List2::~List2()
{
	//������� ��� ��������
	DelAll();
}

int List2::GetCount()
{
	return Count;
}

Elem* List2::GetElem(int pos)
{
	Elem* temp = Head;
	//������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		//�������� �������
		cout << "Incorrect position !!!\n";
		return 0;
	}
	int i = 1;
	//���� ������ ��� �������
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}

void List2::DelAll()
{
	//���� �������� ��������, ������� �� ������ � ������
	while (Count != 0)
		Del(1);
}

void List2::Del(int pos)
{
	//���� �������� ����������� ��� ����� 0,
 //�� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		//�������� �������
		cout << "Incorrect position !!!\n";
		return;
	}
	//�������
	int i = 1;
	Elem* Del = Head;
	while (i < pos)
	{
		//������� �� ��������,
		//������� ���������
		Del = Del->next;
		i++;
	}
	//������� �� ��������,
	//������� ������������ ����������
	Elem* PrevDel = Del->prev;
	//������� �� ��������, ������� ������� �� ��������� 
	Elem* AfterDel = Del->next;
	//���� ������� �� ������
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	//���� ������� �� �����
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	//��������� �������?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;
	//�������� ��������
	delete Del;
	Count--;
}

void List2::Insert(int pos)
{
	//���� �������� ����������� ��� ����� 0,
	 //�� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//������� �� 1 �� Count?
	if (pos < 1 || pos > Count + 1)
	{
		//�������� �������
		cout << "Incorrect position !!!\n";
		return;
	}
	//���� ������� � ����� ������
	if (pos == Count + 1)
	{
		//����������� ������
		int data;
		cout << "Input new number: ";
		cin >> data;
		//���������� � ����� ������
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		//����������� ������
		int data;
		cout << "Input new number: ";
		cin >> data;
		//���������� � ������ ������
		AddHead(data);
		return;
	}
	//�������
	int i = 1;
	//����������� �� ������ n - 1 ���������
	Elem* Ins = Head;
	while (i < pos)
	{
		//������� �� ��������,
		//����� ������� �����������
		Ins = Ins->next;
		i++;
	}
	//������� �� ��������,
	//������� ������������
	Elem* PrevIns = Ins->prev;
	//������� ����� �������
	Elem* temp = new Elem;
	//������ ������
	cout << "Input new number: ";
	cin >> temp->data;
	//��������� ������
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	Count++;
}

void List2::AddTail(int n)
{
	//������� ����� �������
	Elem* temp = new Elem;
	//���������� ���
	temp->next = 0;
	//��������� ������
	temp->data = n;
	//���������� - ������ �����
	temp->prev = Tail;
	//���� �������� ����?
	if (Tail != 0)
		Tail->next = temp;
	//���� ������� ������, �� �� ������������
	//� ������ � �����
	if (Count == 0)
		Head = Tail = temp;
	else
		//����� ����� ������� - ���������
		Tail = temp;
	Count++;
}

void List2::AddHead(int n)
{
	//����� �������
	Elem* temp = new Elem;
	//����������� ���
	temp->prev = 0;
	//��������� ������
	temp->data = n;
	//��������� - ������ ������
	temp->next = Head;
	//���� �������� ����?
	if (Head != 0)
		Head->prev = temp;
	//���� ������� ������, �� �� ������������
 //� ������ � �����
	if (Count == 0)
		Head = Tail = temp;
	else
		//����� ����� ������� - ��������
		Head = temp;
	Count++;

}

void List2::Print()
{
	//���� � ������ ������������ ��������, 
 //�� ��������� �� ����
 //� �������� ��������, ������� � ��������� 
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}

void List2::Print(int pos)
{
	//������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		//�������� �������
		cout << "Incorrect position !!!\n";
		return;
	}
	Elem* temp;
	//���������� � ����� �������
	//������� ���������
	if (pos <= Count / 2)
	{
		//������ � ������
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			//��������� �� ������� ��������
			temp = temp->next;
			i++;
		}
	}
	else
	{
		//������ � ������
		temp = Tail;
		int i = 1;
		while (i <= Count - pos)
		{
			//��������� �� ������� ��������
			temp = temp->prev;
			i++;
		}
	}
	//����� ��������
	cout << pos << " element: ";
	cout << temp->data << endl;
}

List2& List2::operator=(const List2& L)
{
	//�������� ������������ �������� "������ ����" 
	if (this == &L)
		return *this;
	//�������� ������� ������
	this->~List2(); // DelAll();
	Elem* temp = L.Head;
	//�������� ��������
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

List2 List2::operator+(const List2& L)
{
	//������� �� ��������� ������ �������� �������
 //������
	List2 Result(*this);
	//List Result = *this;
	Elem* temp = L.Head;
	//��������� �� ��������� ������ �������� 
	//������� ������
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}

	
	return Result;
}

bool List2::operator==(const List2& L)
{
	//��������� �� ����������
	if (Count != L.Count)
		return false;
	Elem* t1, * t2;
	t1 = Head;
	t2 = L.Head;
	//��������� �� ����������
	while (t1 != 0)
	{
		//������� ������, �������
		//��������� �� ���������� ��������
		if (t1->data != t2->data)
			return false;
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}

bool List2::operator!=(const List2& L)
{
	//���������� ���������� ������� ���������
	return !(*this == L);
}
