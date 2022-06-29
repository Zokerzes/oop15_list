#pragma once
#include<iostream>
#include "List.h"
#include"Forfeit.h"
#include<string>

struct node
{
	string numberCar;
	List<Forfeit> sh;
	node* left, * right, * parent;
};

class Tree
{
	node* root;

public:

	Tree() { root = NULL; };
	~Tree() { Del(); };
	//������ �� ���������� ����
	void Print(node* Node) 
	{
		if (Node != 0)
		{
			Print(Node->left);
			Node->sh.Print();				
			Print(Node->right);
		}
	
	};
	//����� �� ���������� ����
	node* Search(node* Node, string key) 
	{
		//�������� !!!
		//���� ���� ���� � ����� �� ���������
		while (Node != 0 && key.compare(Node->numberCar)) != 0)
		{
			if (strcmp(k, Node->Name) < 0)
				Node = Node->left;
			else
				Node = Node->right;
		}
		return Node
	
	};
	//min �� ���������� ����
	node* Min(node* Node);
	//max �� ���������� ����
	node* Max(node* Node);
	//��������� ��� ���������� ����
	node* Next(node* Node);
	//���������� ��� ���������� ����
	node* Previous(node* Node);
	//������� ����
	void Insert(node* z);
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(node* z = 0);
	//�������� ������
	node* GetRoot();
};

