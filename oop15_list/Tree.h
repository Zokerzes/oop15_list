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
	node* Search(string key) 
	{
		node* Node = root;
		
		//Пока есть узлы и ключи не совпадают
		while (Node != 0 && (key.compare(Node->numberCar)) != 0)
		{
			if (key.compare(Node->numberCar) < 0)
				Node = Node->left;
			else
				Node = Node->right;
		}
		return Node;
	
	};
	//min от указанного узла
	node* Min(node* Node) 
	{
		//Поиск самого "левого" узла
		if (Node != 0)
			while (Node->left != 0)
				Node = Node->left;
		return Node;
	};
	//max от указанного узла
	node* Max(node* Node) 
	{
		//Поиск самого "правого" узла
		if (Node != 0)
			while (Node->right != 0)
				Node = Node->right;
		return Node;
	};
	//следующий для указанного узла
	node* Next(node* Node) 
	{
		node* y = 0;
		if (Node != 0)
		{
			//если есть правый потомок
			if (Node->right != 0)
				return Min(Node->right);
			//родитель узла
			y = Node->parent;
			//если Node не корень и Node справа
			while (y != 0 && Node == y->right)
			{
				//Движемся вверх
				Node = y;
				y = y->parent;
			}
		}
		return y;
	};
	//предыдущий для указанного узла
	node* Previous(node* Node) 
	{
		node* y = 0;
		if (Node != 0)
		{
			//если есть левый потомок
			if (Node->left != 0)
				return Max(Node->left);
			//родитель узла
			y = Node->parent;
			//если Node не корень и Node слева
			while (y != 0 && Node == y->left)
			{
				//Движемся вверх
				Node = y;
				y = y->parent;
			}
		}
		return y;

	};
	//вставка узла
	void Insert(node* z) 
	{
		//потомков нет
		z->left = NULL;
		z->right = NULL;
		node* y = NULL;
		node* Node = root;
		//поиск места
		while (Node != 0)
		{
			//будущий родитель
			y = Node;
			if (z->numberCar.compare(Node->numberCar) < 0)
				Node = Node->left;
			else
				Node = Node->right;
		}
		//заполняем родителя
		z->parent = y;
		if (y == 0) //элемент первый (единственный)
			root = z;
		//чей ключ больше?
		else if (z->numberCar.compare(y->numberCar) < 0)
			y->left = z;
		else
			y->right = z;
	};
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(node* z = 0)
	{
		//удаление куста
		if (z != 0)
		{
			node* Node, * y;
			//не 2 ребенка
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
			//Удаляется корневой узел?
			if (y->parent == 0)
				root = Node;
			else if (y == y->parent->left)
				//слева от родителя?
				y->parent->left = Node;
			else
				//справа от родителя?
				y->parent->right = Node;
			if (y != z)
			{
				//Копирование данных узла
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
	//получить корень
	node* GetRoot()
	{ 
		return root; 
	};


};

