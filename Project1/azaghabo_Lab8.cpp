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
const string FILE_PATH = "cellphone.txt";
const int FILE_SIZE = 22;

const int MENU_ONE = 1, MENU_TWO = 2, MENU_THREE = 3;

//Structures

//Function Prototypes
void displayTitle();
void createStack(stack<CellPhone, vector<CellPhone>>&);
void buyPhone(stack <CellPhone , vector<CellPhone>>&, deque<Customer>&);

//Beginning of the program
int main()
{
	int menuOption;

	displayTitle();

	stack<CellPhone, vector<CellPhone>> cellPhoneInventory;
	deque<Customer> customerQueue;

	createStack(cellPhoneInventory);

	do
	{
		cout << "\n" << endl;
		cout << MENU_ONE << ". Buy Phone" << endl;
		cout << MENU_TWO << ". Customer Checkout" << endl;
		cout << MENU_THREE << ". Quit" << endl << endl;
		cout << "Enter the menu choice: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case MENU_ONE:
		{
			if (cellPhoneInventory.empty())
			{
				cout << "Sorry! This stack is empty." << endl;
			}
			else
			{
				buyPhone(cellPhoneInventory);
			}

			break;
		}
		case MENU_TWO:
		{

			break;
		}
		case MENU_THREE:
		{

			break;
		}

		default:
			cout << "Invalid choice! Try again:" << endl;
			break;
		}
	} while (menuOption != MENU_THREE);

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


	for (int i = 0; i < FILE_SIZE; i++)
	{
		inFile >> idNum >> phoneNum;

		CellPhone cell(idNum, phoneNum);

		cellphoneInventory.push(cell);

	}

	inFile.close();
}

void buyPhone(stack <CellPhone, vector<CellPhone>>& cellPhoneInventory, deque<Customer>& customerQueue)
{
	string name; 
	int phonesNum;

	cout << "Please enter in the customer name: ";
	getline(cin, name);
	cout << "Please enter in the number of phones to purchase(1 - 6): ";
	cin >> phonesNum;
	while (phonesNum < 1 || phonesNum < 6 || phonesNum > (cellPhoneInventory.size() / 2))
	{
		if ((cellPhoneInventory.size() / 2) >= 6)
		{
			cout << "Error - you can only pruchase 1 - 6 phones. Please reenter!" << endl;

			cout << "\nPlease enter in the number of phones to purchase(1 - 6): ";
			cin >> phonesNum;
		}
		if ((cellPhoneInventory.size() / 2) < 6)
		{
			cout << "Error - there are not enought phones in storage. Please reenter!" << endl;

			cout << "\nPlease enter in the number of phones to purchase(1 - 6): ";
			cin >> phonesNum;
		}
	}
	vector<CellPhone> phonesPurchased;
	for (int i = 0; i < phonesNum; i++)
	{
		CellPhone phone = cellPhoneInventory.top();
		cellPhoneInventory.pop();
		phonesPurchased.push_back(phone);
	}

	Customer customer(name, phonesPurchased);

	customerQueue.push_back(customer);

}