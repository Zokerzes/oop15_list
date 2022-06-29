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
	//печать от указанного узла
	void Print(node* Node) 
	{
		if (Node != 0)
		{
			Print(Node->left);
			Node->sh.Print();				
			Print(Node->right);
		}
	
	};
	//поиск от указанного узла
	node* Search(node* Node, string key) 
	{
		//дописать !!!
		//Пока есть узлы и ключи не совпадают
		while (Node != 0 && key.compare(Node->numberCar)) != 0)
		{
			if (strcmp(k, Node->Name) < 0)
				Node = Node->left;
			else
				Node = Node->right;
		}
		return Node
	
	};
	//min от указанного узла
	node* Min(node* Node);
	//max от указанного узла
	node* Max(node* Node);
	//следующий для указанного узла
	node* Next(node* Node);
	//предыдущий для указанного узла
	node* Previous(node* Node);
	//вставка узла
	void Insert(node* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(node* z = 0);
	//получить корень
	node* GetRoot();
};

