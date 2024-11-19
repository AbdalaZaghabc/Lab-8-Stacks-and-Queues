#include<iostream>
#include<iomanip>
#include<string>
#include"Cellphone.h"
using namespace std;


//Constructors
CellPhone::CellPhone()
{
	idNum = "0";
	phoneNum = "0";
}

CellPhone::CellPhone(string idNumber, string phoneNumber)
{
	idNum = idNumber;
	phoneNum = phoneNumber;
}

//Getter Functions
string CellPhone::getIdNum()
{
	return idNum;
}

string CellPhone::getPhoneNum()
{
	return phoneNum;
}

//Setter Functions
void CellPhone::setIdNum(string id)
{
	idNum = id;
}

void CellPhone::setPhoneNum(string num)
{
	phoneNum = num;
}
