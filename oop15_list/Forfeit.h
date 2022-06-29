#pragma once
#include<iostream>
#include "List.h"
#include<string>
using namespace std;

class Forfeit
{
public:

	int number;
	int numOffense;
	float summ;
	string date;

	Forfeit() {
		number = 0 ;
		numOffense = 0;
		summ = 0;
		date = " ";
	};

	Forfeit(int number, int numOffense, float summ, string date) {
		this->number=number;
		this->numOffense=numOffense;
		this->summ=summ;
		this->date=date;
	};

	~Forfeit() {};
};

