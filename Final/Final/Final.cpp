/*
	Kyle Riley
	SE124.22
	3/12/2018
	[Void] sortyBoy bubble sorts the array
	[Void] search Binary searches the array
	[String] data = 2D array that will store .txt data
	[String] tempString = String used to rearrange for Michael Buble Sort
	[String] searchVal = Value used for binary search
	[Int] i = records counter, reused for for loops. Also used for array selectment
	[Int] records = store value for max record num, used in for loop to print records
	[Int] sortNum = value that holds your sorting selection
	[Int] guess = used for binary search
	[Int] min = min search num
	[Int] max = max search num
	[Int] restorePoint = point at which sortNum falls back on
	[Int] Select is used for menu selection
	[Int] rando holds the random integer value.
*/
#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

void sortyBoy(int sortNum, int records);
void search(int sortNum);

string data[13][7];

void main()
{
	cout << fixed << setprecision(2);
	ifstream fin;
	fin.open("F:\\C++2\\Final\\final_file.txt");

	int i = 0, records, sortNum, select;
	double average;

	while(!fin.eof())
	{
		fin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3] >> data[i][4] >> data[i][5] >> data[i][6];
		i++;
	}
	records = i;
	cout << setw(6) << "REC#" << setw(15) << "ID#" << "  " << setw(12) << "First" << "  " << setw(3) << "Grades" << "  " << setw(3) <<"  " << setw(3) << "  " << setw(3) << "  " << setw(3) << "  " << setw(13) << "Average " << endl;
	for(i = 0; i < records; i++)
	{
		average = (stod(data[i][2]) + stod(data[i][3]) + stod(data[i][4]) + stod(data[i][5]) + stod(data[i][6]))/5;
		cout << setw(6) << "REC#" << setw(3) << i << setw(12) << data[i][0] << "  " << setw(12) << data[i][1] << "  " << setw(3) << data[i][2] << "  " << setw(3) << data[i][3] <<"  " << setw(3) <<  data[i][4] << "  " << setw(3) << data[i][5] << "  " << setw(3) << data[i][6] << "  " << setw(3) << "Average: " << average << endl;
	}
	cout << "Records processed: " << records;
	system("pause");
	system("cls");
	select = 0;
	while (select != 4)
	{
		cout << "1. Search by ID#" << endl << "2. Search by First name" << endl << "3. RANDOM ID# Search" << endl << "4. Exit" << endl;
		cin >> select;
		switch(select)
		{
			case 1:
				sortNum = 0;
				sortyBoy(sortNum, records);
				search(sortNum);
				system("cls");
				break;

			case 2:
				sortNum = 1;
				sortyBoy(sortNum, records);
				search(sortNum);
				system("cls");
				break;

			case 3:
				sortNum = 2;
				sortyBoy(sortNum, records);
				search(sortNum);
				system("cls");
				break;
		}
	}
	system("cls");
	cout << "Goodbye!" << endl;
	system("pause");
}
void sortyBoy(int sortNum, int records)
{
	string tempString;
	if(sortNum == 2)
		sortNum = 0;
	int restorePoint = sortNum;
	for(int i = 0; i < records - 1; i++)//Processing Array FOR LOOP
	{
		for(int k = 0; k < records - 1; k++)//SORTING LOOP
		{
			//IF statement is based on HOW YOU ARE ORDERING
			if(data[k][sortNum] > data[k + 1][sortNum])
			{
				//Last name or ID
				tempString = data[k][sortNum];
				data[k][sortNum] = data[k + 1][sortNum];
				data[k + 1][sortNum] = tempString;

				//First name or Date
				tempString = data[k][sortNum + 1];
				data[k][sortNum + 1] = data[k + 1][sortNum + 1];
				data[k + 1][sortNum + 1] = tempString;
				//Resets back to 0 position if ID is selected (reaches end of parametes)
				if(data[k][sortNum + 1] == data[k][4])
					sortNum = 0;
				else
					sortNum = 2;
				//ID or Last
				tempString = data[k][sortNum];
				data[k][sortNum] = data[k + 1][sortNum];
				data[k][sortNum] = tempString;
				//Date or First
				tempString = data[k][sortNum + 1];
				data[k + 1][sortNum + 1] = data[k + 1][sortNum + 1];
				data[k + 1][sortNum + 1] = tempString;
				sortNum = restorePoint;
			}
		}//end SORTING LOOP

	}//end PROCESSING LOOP
	cout << setw(6) << "REC#" << setw(15) << "ID#" << "  " << setw(12) << "First" << "  " << setw(3) << "Grades" << "  " << setw(3) <<"  " << setw(3) << "  " << setw(3) << "  " << setw(3) << "  " << setw(13) << "Average " << endl;
	for(int i = 0; i < records; i++)
	{
		double average = (stod(data[i][2]) + stod(data[i][3]) + stod(data[i][4]) + stod(data[i][5]) + stod(data[i][6]))/5;
		cout << setw(6) << "REC#" << setw(3) << i << setw(12) << data[i][0] << "  " << setw(12) << data[i][1] << "  " << setw(3) << data[i][2] << "  " << setw(3) << data[i][3] << "   " << setw(3) << data[i][4] << "  " << setw(3) << data[i][5] << "  " << setw(3) << data[i][6] << "  " << setw(3)<< "Average: " << average << endl;
	}
}
void search(int sortNum)
{
	srand(time(NULL * NULL));
	int guess, min = 0, max = 12, rando;
	string searchVal;
	if(sortNum == 2)
	{
		rando = (rand() % 12) + 1001;
		cout << "The random ID# is: " << rando << endl;
		system("pause");
		system("cls");
		sortNum = 0;
		stringstream ss;
		ss << rando;
		searchVal = ss.str();
	}
	else
	{
		cout << "Enter the record you are searching :" << endl;
		cin >> searchVal;
	}

	int restorePoint = sortNum;

	guess = (min + max) / 2;

	cout << "BINARY SEARCH------------------"<< endl;
	while (min < max && searchVal != data[guess][restorePoint])
	{
		cout << "MIN: " << min << " \t MAX: " << max << " \t GUESS: " << guess << endl;
		if(searchVal < data[guess][restorePoint])
		{
			max = guess - 1;
		}
		else if(searchVal > data[guess][restorePoint])
		{
			min = guess + 1;
		}
		guess = (min + max) / 2;
	}
	if(searchVal == data[guess][restorePoint])
	{
		cout << "The data you are looking for " << data[guess][restorePoint] << " was found in Record# " << guess << endl;
		double average = (stod(data[guess][2]) + stod(data[guess][3]) + stod(data[guess][4]) + stod(data[guess][5]) + stod(data[guess][6]))/5;
		cout << setw(6) << "REC#" << setw(15) << "ID#" << "  " << setw(12) << "First" << "  " << setw(3) << "Grades" << "  " << setw(3) <<"  " << setw(3) << "  " << setw(3) << "  " << setw(3) << "  " << setw(13) << "Average " << endl;
		cout << setw(6) << "REC#" << setw(3) << guess << setw(12) << data[guess][0] << "  " << setw(12) << data[guess][1] << "  " << setw(3) << data[guess][2] << "  " << setw(2) << data[guess][3] << data[guess][4] << "  " << data[guess][5] << "  " << data[guess][6] << "  " << average << endl;
	}
	else
	{
		cout << "ERROR!" << endl;
		cout << "The data you are looking for, " << searchVal << ", was not found." << endl;
	}
	system("pause");
}