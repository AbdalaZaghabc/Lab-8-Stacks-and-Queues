#include<iostream>
#include<iomanip>
#include<string>
#include"CellPhone.h"
using namespace std;


//Constructors to initialize variables
CellPhone::CellPhone()
{
	idNum = "none";
	phoneNum = "none";
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
