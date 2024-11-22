#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<iomanip>
#include<string>
#include"CellPhone.h"
using namespace std;


class Customer
{
private:

	//constants to calculate costs
	static const int MAX_SIZE = 6;
	const double PHONE_COST = 199.99, SALES_TAX = 0.06;
	double totalCost = 0;

	string customerName;
	int phonesPurchased;
	double cost;
	CellPhone phoneObj[MAX_SIZE];

public:
	//Customer Constructors
	Customer();
	Customer(string, int, double, CellPhone array[]);
	~Customer() {}

	//Getter Functions
	string getCustomerName();
	int getPhonesPurchased();
	double getCost();
	CellPhone getPhoneObj(int);

	//Setter Functions
	void setCustomerName(string);
	void setPhonesPurchased(int);
	void setCost(double);
	void setPhoneObj(CellPhone[]);

	//Other function to calculate the cost.
	void calculateCost();
};

#endif // !CUSTOMER_H

