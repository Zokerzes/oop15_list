#pragma once
#include<iostream>
#include "List.h"
#include"Forfeit.h"
#include<string>

struct node
{
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
	node* Search(node* Node, char* key);
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

