/*
	Kyle Riley
	2/20/2018
	SE124.22
	[String] data = 2D array that will store .txt data
	[String] search_name = name that will be binary searched
	[Int] guess = used for binary search
	[Int] min = min search num
	[Int] max = max search num
	[Int] i = increments for array selectment
	[Char] answer = used to stop/continue while loop
*/
#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

void main()
{
	string data[26][3];
	
	string search_name;
	int guess, min = 0, max = 25;
	char answer = 'y';
	ifstream fin;

	fin.open("./Lab5.txt");
	int i = 0;
	while(!fin.eof())
	{
		fin >> data[i][0] >> data[i][1] >> data[i][2];
		i++;
	}
	while (answer == 'y' || answer == 'Y')
	{
		cout << "Enter the last name you are searching for: " << endl;
		cin >> search_name;
		min = 0;
		max = 25;
		guess = (min + max) / 2;

		cout << "BINARY SEARCH------------------"<< endl;
		while (min < max && search_name != data[guess][0])
		{
			cout << "MIN: " << min << " \t MAX: " << max << " \t GUESS: " << guess << endl;
			if(search_name < data[guess][0])
			{
				max = guess - 1;
			}
			else if(search_name > data[guess][0])
			{
				min = guess + 1;
			}
			guess = (min + max) / 2;
		}
		if(search_name == data[guess][0])
		{
			cout << "The name you are looking for " << data[guess][0] << " was found in Record# " << guess << endl;
		}
		else
		{
			cout << "ERROR!" << endl;
			cout << "The name you are looking for, " << search_name << ", was not found." << endl;

		}
		cout << "Would you like to search again? (y/n)" << endl;
		cin >> answer;
		system("cls");
	}

}