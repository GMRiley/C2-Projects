#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>

using namespace std;

void main()
{
	ifstream fin;
	fin.open("F:\\C++2\\Lab4A\\Lab4A-1.txt");
	cout << fixed << setprecision(2);

	int num[30];
	double largeNum=0, smallNum=1000, average=0;
	int c = 0;
	while(!fin.eof())
	{
		fin >> num[c];
		
		c++;
	}
	fin.close();

	for(int i = 0; i < c; i++)
	{
		if (largeNum < num[i])
			largeNum = num[i];
		if (smallNum > num[i])
			smallNum = num[i];
		average = average + num[i];
	}
	average = average / c;
	cout << "Large Num: " << largeNum << endl;
	cout << "Small Num: " << smallNum << endl;
	cout << "Average:   " << average << endl;
	system("Pause");
}