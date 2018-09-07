/*
	Kyle Riley
	SE 124.22
	Lab 3A
	1/30/2018
	num is what stores the fin
	store holds the values in a total from each loop
	low is what will hold the lowest value, it is said to a value greater then every integer due to an if < low, guarantees functionality in the if
	high holds the highest integer value, is set to 0. Same reasoning for low.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void main()
{
	cout << fixed << setprecision(0);
	ifstream fin;
	fin.open("F:\\C++2\\Lab3A\\numbers.txt");
	int counter = 0;
	double num, average, store = 0, low = 200, high = 0;
	while(!fin.eof())
	{
		fin >> num;
		store = store + num;
		if(num > high)
			high = num;
		if(num < low)
			low = num;
		counter++;
	}
	average = store / counter;
	cout << "High: " << high << endl << "Low: " << low << endl << "Average: " << average << endl;
	cout << "Amount of numbers processed: " << counter << endl;
	system("pause");
}