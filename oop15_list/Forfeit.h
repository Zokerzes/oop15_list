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
	
	friend std::ostream& operator<< (std::ostream& os, const Forfeit& p)
	{
		return os << "date - " << p.date << " number car - " << p.numberCar << " point of Forfeite  - " << p.numOffense << " summ - " << p.summ << endl << endl;
	}
	~Forfeit() {};
};

//std::ostream& operator<< (std::ostream& os, const Forfeit& p)
//{
//	return os << "date - "<<p.date<<" number car - "<<p.numberCar<<" point of Forfeite  - "<<p.numOffense<<"summ - "<<p.summ;
//}

