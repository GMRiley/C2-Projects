/*
	Kyle Riley
	SE124.22
	Midterm Practical
	2/5/2018
	[int] add() add function, returns the total.
	[void] multiply() multiply function, takes in the num1 and num2 values and multiplies.
	[int] counter will increment for each process, counting the processes for batch.
	[int] choice will hold your choice for wanting to add, multiply, or go to the next section.
	[int] total will hold the total value that will be returned from add(), is also used to hold num1 * num2 in multiply().
	[int] num1/num2 are your num values that you are inputing for the add() and multiply() functions.
	[char] answer will hold a 'y' value, will be the boolean statement for the while loop, continuing it only if it answer == 'y' || 'Y'
	[string] first/last/age/gend will hold the batch file's data of first name, last name, age, and gender, respectively.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int add();
void multiply(int num1,int num2);

void main()
{
	ifstream fin;
	fin.open("F:\\C++2\\Midterm\\se124_midterm.txt");
	int counter = 0, choice = 0, total, num1, num2;
	char answer = 'y';
	string first = "", last = "" , age = "" , gend = "";
	srand(time(NULL * NULL));
	while(!fin.eof())
	{
		fin >> first >> last >> age >> gend;
		cout << first << " " << last << " " << age << " " << gend << endl;
		counter++;
	}
	cout << counter << " records have been processed." << endl;
	system("pause");
	system("cls");
	while (choice != 3)
	{
		cout << "1. Add" << endl;
		cout << "2. Multiply" << endl;
		cout << "3. Section 3" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				total = add();
				cout << "Your total is: " << total << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "Enter your first  num: " << endl;
				cin >> num1;
				cout << "Enter your second num: " << endl;
				cin >> num2;
				multiply(num1, num2);
				break;
			case 3:
				break;
			default:
				cout << "That was an incorrect value" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
	system("cls");
	while (answer == 'y' || answer == 'Y')
	{
		int rando = (rand() % 50) + 25;
		cout << rando << endl;
		cout << "Would you like to see another number?(y/n)" << endl;
		cin >> answer;
	}
	system("cls");
	cout << "Goodbye" << endl;
	system("pause");
}
int add()
{
	int num1, num2, total;
	cout << "Enter your first  num: " << endl;
	cin >> num1;
	cout << "Enter your second num: " << endl;
	cin >> num2;
	total = num1 + num2;
	return total;
}
void multiply(int num1, int num2)
{
	int total = num1 * num2;
	cout << "Your total num is: " << total << endl;
	system("pause");
	system("cls");
}