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
const string FILE_PATH = "C:\\Users\\zagha\\source\\repos\\AbdalaZaghabc\\Lab-8-Stacks-and-Queues\\Project1\\cellphone.txt";
const int FILE_SIZE = 22;
const int MENU_ONE = 1, MENU_TWO = 2, MENU_THREE = 3;


//Function Prototypes
void displayTitle();
void createStack(stack<CellPhone, vector<CellPhone>>&);						//creates the stack based on the file provided
void buyPhone(stack <CellPhone , vector<CellPhone>>&, deque<Customer>&);	//Function when user selects to buy phones
void checkoutCustomer(deque<Customer>&);									//Function when user wants to check out customer

//Beginning of the program
int main()
{
	int menuOption;

	cout << fixed << setprecision(2) << showpoint;

	displayTitle();//Display my title here

	stack<CellPhone, vector<CellPhone>> cellPhoneInventory;//Create a stack
	deque<Customer> customerQueue;//Create a queue

	createStack(cellPhoneInventory);//call function to fill the stack with data.

	//Menu switch case
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
		case MENU_ONE: //Fill information of the customer to pruchase no more than 6 phones
		{
			if (cellPhoneInventory.empty())//if no data was added to the stack.
			{
				cout << "Sorry! This stack is empty." << endl;
			}
			else
			{
				buyPhone(cellPhoneInventory, customerQueue);
			}
			break;
		}

		case MENU_TWO://Checkout one customer at the time with the queue
		{
			checkoutCustomer(customerQueue);
			break;
		}

		case MENU_THREE://Quit the program only if the queue is empty
		{
			if (!customerQueue.empty())//if the queue is not empty, then iterate again the program.
			{
				cout << "\nError - there are still customers in the checkout queue!" << endl;
				cout << "Please return to main menu and check out all of the customers!" << endl;
				menuOption = 0;
			}
			else//goodbye message
			{
				cout << "\n\nThank you for using our program today." << endl;
			}
			break;
		}

		default://Default message if user inputs wrong option.
			cout << "Invalid choice! Try again:" << endl;
			break;
		}
	} while (menuOption != MENU_THREE);//when 3 is selected, the program attempts to quit.

	cout << "\n" << endl;
	system("pause");//End of the program
	return 0;
}

//Display copyright statement
void displayTitle()
{
	cout << right << setw(50) << "CMSY 171 Lab 8" << endl;
	cout << "Copyright 2024 - Howard Community College All rights reservedl Unauthorized duplication prohibited." << endl << endl;
	cout << right << setw(65) << "Welcome to CMSY-171 Cell Phone Purchase Program" << endl;
}

//Fill the data in the stack created
void createStack(stack<CellPhone, vector<CellPhone>>& cellphoneInventory)
{
	ifstream inFile(FILE_PATH);
	string idNum, phoneNum;
	int counter = 0;

	//If file does not exist, display eror message.
	if (!inFile)
	{
		cout << "Error - this file does not exist." << endl;
	}

	//store the information from the txt file to the stack.
	for (int i = 0; i < FILE_SIZE; i++)
	{
		inFile >> idNum >> phoneNum;

		CellPhone cell(idNum, phoneNum);// Create the object with id number and phone number, and push it to the stack

		cellphoneInventory.push(cell);
	}
	inFile.close();
}

//Create a customer profile with an order.
void buyPhone(stack <CellPhone, vector<CellPhone>>& cellPhoneInventory, deque<Customer>& customerQueue)
{
	string name; 
	int phonesNum;

	//User inputs name and phones' amount.
	cin.ignore();
	cout << "Please enter in the customer name: ";
	getline(cin, name);
	cout << "Please enter in the number of phones to purchase(1 - 6): ";
	cin >> phonesNum;

	//If the user inputs less than 1, more than 6, or more than the inventory at the time, it will be an error.
	while (phonesNum < 1 || phonesNum > 6 || phonesNum > cellPhoneInventory.size())
	{
		if (phonesNum > cellPhoneInventory.size())//If the user inputed more than the current inventory number
		{
			cout << "Error - there are not enought phones in storage. Please reenter!" << endl;
		}
		else if (phonesNum > 6)//If the user inputs a number higher than 6, or less than 1.
		{
			cout << "Error - you can only pruchase 1 - 6 phones. Please reenter!" << endl;
		}

		cout << "\nPlease enter in the number of phones to purchase(1 - 6): ";
		cin >> phonesNum;
	}

	//Create array with the phones purchased, and push it to the stack
	CellPhone phonesPurchased[6];
	for (int i = 0; i < phonesNum; i++)
	{
		phonesPurchased[i] = cellPhoneInventory.top();
		cellPhoneInventory.pop();
	}

	//Create custromer object and calculate the cost and push it to the customer queue.
	Customer customer(name, phonesNum, 0, phonesPurchased);

	customer.calculateCost();

	customerQueue.push_back(customer);

}

//Check out the customers queue by order
void checkoutCustomer(deque<Customer>& customerQueue)
{
	//Make sure that the queue has customers.
	if (customerQueue.empty())
	{
		cout << "There are no customer left to check out" << endl;
	}
	else
	{
		//store the first customer from the queue in a place, adn delete the customer from the queue.
		Customer customer = customerQueue.front();
		customerQueue.pop_front();

		//Display Receipt
		cout << "Customer Receipt:" << endl;
		cout << "Customer name   : " << customer.getCustomerName() << endl;
		cout << "Number phones   : " << customer.getPhonesPurchased() << endl;
		cout << "Total amount due: $" << customer.getCost() << endl;

		cout << "\nPhone(s) id and number:" << endl;

		//Display Id numbers and phone numbers
		for (int i = 0; i < customer.getPhonesPurchased(); i++)
		{
			CellPhone phone = customer.getPhoneObj(i);//Create cellphone object with customer order.
			cout << "ID Number: " << phone.getIdNum() << "\tPhone Number: " << phone.getPhoneNum() << endl;
		}
	}
}