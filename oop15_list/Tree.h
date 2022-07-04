#pragma once
#include<iostream>
#include "List.h"
#include"Forfeit.h"
#include<string>
#include"node.h"
class node
{
public:
	string numberCar;
	List<Forfeit> sh;
	node* left=nullptr;
	node* right = nullptr;
	node* parent = nullptr;
	node() 
	{
		numberCar = "NULL";
	}
	node(string numberCar, List<Forfeit> sh) 
	{
		this->numberCar = numberCar;
		this->sh = sh;
		node* left = nullptr, * right = nullptr, * parent = nullptr;
	}
	~node(){};
	string getNumberCar() { return numberCar; };
	List<Forfeit> getForfeit() 
	{
		sh.Print();
		return sh;
	}
	void setNumberCar(string numberCar) 
	{
		this->numberCar = numberCar;
	}
	void addForfeit(Forfeit sht)
	{
		sh.Add(sht);
	};

};

class Tree
{
public:
	node* root;
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
	node* Search(string key) 
	{
		node* Node = root;
		
		//���� ���� ���� � ����� �� ���������
		while (Node != 0 && (key.compare(Node->numberCar)) != 0)
		{
			if (key.compare(Node->numberCar) < 0)
				Node = Node->left;
			else
				Node = Node->right;
		}
		return Node;
	
	};
	//min �� ���������� ����
	node* Min(node* Node) 
	{
		//����� ������ "������" ����
		if (Node != 0)
			while (Node->left != 0)
				Node = Node->left;
		return Node;
	};
	//max �� ���������� ����
	node* Max(node* Node) 
	{
		//����� ������ "�������" ����
		if (Node != 0)
			while (Node->right != 0)
				Node = Node->right;
		return Node;
	};
	//��������� ��� ���������� ����
	node* Next(node* Node) 
	{
		node* y = 0;
		if (Node != 0)
		{
			//���� ���� ������ �������
			if (Node->right != 0)
				return Min(Node->right);
			//�������� ����
			y = Node->parent;
			//���� Node �� ������ � Node ������
			while (y != 0 && Node == y->right)
			{
				//�������� �����
				Node = y;
				y = y->parent;
			}
		}
		return y;
	};
	//���������� ��� ���������� ����
	node* Previous(node* Node) 
	{
		node* y = 0;
		if (Node != 0)
		{
			//���� ���� ����� �������
			if (Node->left != 0)
				return Max(Node->left);
			//�������� ����
			y = Node->parent;
			//���� Node �� ������ � Node �����
			while (y != 0 && Node == y->left)
			{
				//�������� �����
				Node = y;
				y = y->parent;
			}
		}
		return y;

	};
	//������� ����
	void Insert(node* z) 
	{
		//�������� ���
		z->left = NULL;
		z->right = NULL;
		node* y = NULL;
		node* Node = root;
		//����� �����
		while (Node != 0)
		{
			//������� ��������
			y = Node;
			if (z->numberCar.compare(Node->numberCar) < 0)
				Node = Node->left;
			else
				Node = Node->right;
		}
		//��������� ��������
		z->parent = y;
		if (y == 0) //������� ������ (������������)
			root = z;
		//��� ���� ������?
		else if (z->numberCar.compare(y->numberCar) < 0)
			y->left = z;
		else
			y->right = z;
	};
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(node* z = 0)
	{
		//�������� �����
		if (z != 0)
		{
			node* Node, * y;
			//�� 2 �������
			if (z->left == 0 || z->right == 0)
				y = z;
			else
				y = Next(z);
			if (y->left != 0)
				Node = y->left;
			else
				Node = y->right;
			if (Node != 0)
				Node->parent = y->parent;
			//��������� �������� ����?
			if (y->parent == 0)
				root = Node;
			else if (y == y->parent->left)
				//����� �� ��������?
				y->parent->left = Node;
			else
				//������ �� ��������?
				y->parent->right = Node;
			if (y != z)
			{
				//����������� ������ ����
				/*
				string numberCar;
				List<Forfeit> sh;
				*/
				z->numberCar = y->numberCar;
				z->sh = y->sh;

			}
			delete y;
		}
	};
	//�������� ������
	node* GetRoot()
	{ 
		return root; 
	};


};

