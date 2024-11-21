#ifndef CELLPHONE_H
#define CELLPHONE_H

#include<iostream>
#include<iomanip>
#include<string>
#include"CellPhone.h"
using namespace std;

class CellPhone
{
private:
	
	string idNum = "";
	string phoneNum = "";

public:
	CellPhone();
	CellPhone(string idNum, string phoneNum);
	~CellPhone() {}

	//Getters
	string getIdNum();
	string getPhoneNum();

	//Setters
	void setIdNum(string);
	void setPhoneNum(string);
};

#endif // !CELLPHONE_H

#pragma once
