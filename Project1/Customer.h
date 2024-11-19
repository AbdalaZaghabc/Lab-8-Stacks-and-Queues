#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<iomanip>
#include<string>
#include"Cellphone.h"
using namespace std;


class Customer
{
private:
	string customerName;
	int phonesPurchased;
	double cost;
	CellPhone phoneObj[6];

public:
	Customer();
	Customer(string, int, double, CellPhone array[]);
	~Customer() {}

	//Getter Functions
	string getCustomerName();
	int getPhonesPurchased();
	double getCost();
	CellPhone getPhoneObj();

	//Setter Functions
	void setCustomerName(string);
	void setPhonesPurchased(int);
	void setCost(double);
	void setPhoneObj(CellPhone[]);

	void calculateCost();
};

#endif // !CUSTOMER_H

