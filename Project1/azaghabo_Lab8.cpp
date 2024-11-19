//Abdala Zaghab
//CellPhone kiosk 
//11/21/2024

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include"Cellphone.h"
using namespace std;

//Constants

//Structures

//Function Prototypes
void displayTitle();

//Beginning of the program
int main()
{
	displayTitle();

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