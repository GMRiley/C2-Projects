/*
	Kyle Riley
	2/27/2018
	SE124.22
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
*/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<array>

using namespace std;

void main()
{
	ifstream fin;
	fin.open("F:\\C++2\\Lab6\\Lab6\\lab6b.txt");

	string data[10][4];
	string tempString;
	string searchVal;
	int i = 0, records, sortNum, guess, min = 0, max = 9, restorePoint;
	while(!fin.eof())
	{
		fin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3];
		i++;
	}
	records = i;
	cout << "ORIGINAL FILE-----------------" << endl;
	for(i = 0; i < records; i++)
	{
		cout << setw(6) << "REC#" << setw(3) << i << setw(12) << data[i][0] << "  " << setw(12) << data[i][1] << "  " << setw(3) << data[i][2] << "  " << setw(2) << data[i][3] << endl;
	}
	cout << endl << endl;
	cout << "Select which way you are sorting:" << endl << "1) By last name" << endl << "2) By ID Num" << endl;
	cin >> sortNum;
	if (sortNum == 1)
	{
		sortNum = 0;
	}
	restorePoint = sortNum;
	for(i = 0; i < records - 1; i++)//Processing Array FOR LOOP
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
	cout << "RESORTED ARRAY DATA-----------------------" << endl;
	for(i = 0; i < records; i++)
	{
		cout << setw(6) << "REC#" << setw(3) << i << setw(12) << data[i][0] << "  " << setw(12) << data[i][1] << "  " << setw(3) << data[i][2] << "  " << setw(2) << data[i][3] << endl;
	}
	cout << "Enter the record you are searching :" << endl;
	cin >> searchVal;
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
	}
	else
	{
		cout << "ERROR!" << endl;
		cout << "The data you are looking for, " << searchVal << ", was not found." << endl;
	}
	system("pause");
}