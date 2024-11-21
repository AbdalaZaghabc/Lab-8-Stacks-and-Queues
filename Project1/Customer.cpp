#include<iostream>
#include<iomanip>
#include<string>
#include"Customer.h"
using namespace std;

Customer::Customer()
{
	customerName = "none";
	phonesPurchased = 0;
	cost = 0.0;
	phoneObj[0] = CellPhone();
}

Customer::Customer(string name, int phoneCount, double costNum, CellPhone array[])
{
	customerName = name;
	phonesPurchased = phoneCount;
	cost = costNum;

	for (int i = 0; i < 6; i++)
	{
		phoneObj[i] = array[i];
	}

	calculateCost();
}

//Getter funtions
string Customer::getCustomerName()
{
	return customerName;
}

int Customer::getPhonesPurchased()
{
	return phonesPurchased;
}

double Customer::getCost()
{
	return cost;
}

CellPhone Customer::getPhoneObj(int index)
{
	if (index > 0 && index < 6)
	{
		return phoneObj[index];
	}
}

//Setter Functions

void Customer::setCustomerName(string name)
{
	customerName = name;
}

void Customer::setPhonesPurchased(int num)
{
	if (num >= 1 && num <= 6)
	{
		phonesPurchased = num;
	}
}

void Customer::setCost(double num)
{
	cost = num;
}

void Customer::setPhoneObj(CellPhone array[])
{
	for (int i = 0; i < 6; i++)
	{
		phoneObj[i] = array[i];
	}
}

void Customer::calculateCost()
{
	double costBeforeTax;

	costBeforeTax = phonesPurchased * PHONE_COST;
	cost = costBeforeTax + (costBeforeTax * SALES_TAX);
}