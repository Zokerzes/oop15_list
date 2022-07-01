#pragma once
#include<iostream>
#include "List.h"
#include<string>
#include"node.h"
using namespace std;

class Forfeit
{
public:

	string numberCar;
	int numOffense;
	float summ;
	string date;

	Forfeit() {
		numberCar = "Null";
		numOffense = 0;
		summ = 0;
		date = " ";
	};

	Forfeit(string numberCar , int numOffense, float summ, string date) {
		this->numberCar = numberCar;
		this->numOffense=numOffense;
		this->summ=summ;
		this->date=date;
	};

	~Forfeit() {};
};

