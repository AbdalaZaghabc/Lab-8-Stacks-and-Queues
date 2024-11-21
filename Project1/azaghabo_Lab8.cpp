//Abdala Zaghab
//CellPhone kiosk 
//11/21/2024

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<stack>
#include<deque>
#include"CellPhone.h"
#include"Customer.h"
using namespace std;

//Constants
const string FILE_PATH = "C:\\Users\\zagha\\source\\repos\\AbdalaZaghabc\\Lab - 8 - Stacks - and -Queues\\Project1\\cellphone.txt";

//Structures

//Function Prototypes
void displayTitle();
void createStack(stack<CellPhone, vector<CellPhone>>&);

//Beginning of the program
int main()
{
	displayTitle();

	stack<CellPhone> cellPhoneInventory;
	deque<Customer> customerQueue;

	createStack(cellPhoneInventory);

	cout << "\n" << endl;
	system("pause");
	return 0;
}

void displayTitle()
{
	cout << right << setw(50) << "CMSY 171 Lab 8" << endl;
	cout << "Copyright 2024 - Howard Community College All rights reservedl Unauthorized duplication prohibited." << endl << endl;
	cout << right << setw(65) << "Welcome to CMSY-171 Cell Phone Purchase Program" << endl;
}

void createStack(stack<CellPhone, vector<CellPhone>>& cellphoneInventory)
{
	ifstream inFile(FILE_PATH);

	if (!inFile)
	{
		cout << "Error - this file does not exist." << endl;
	}

	string idNum, phoneNum;
	int counter = 0;

	while (inFile >> idNum >> phoneNum)
	{
		CellPhone cell(idNum, phoneNum);

		cellphoneInventory.push(cell);

		counter++;
	}

	inFile.close();
}