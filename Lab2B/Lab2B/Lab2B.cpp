/*
	Kyle Riley
	SE 124.22
	Lab 2B
	1/27/2018
	letterGrade is the char function that takes the average and returns the lettergrade
	String name will hold the name, then be used to svae all of the other values so that it can print as one string.
	grade1-grade5 will take in the fin values
	average will hold the average of grade1-grade5
	grade will hold the returned char value from lettergrade
	counter will hold the number of records processed.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

char letterGrade(double average);

void main()
{
	ostringstream oss;
	cout << fixed << setprecision(0);
	ifstream fin;
	fin.open("F:\\C++2\\Lab2B\\tests.txt");
	string name = "";
	int grade1, grade2, grade3, grade4, grade5, counter = 0;
	char grade;
	while (!fin.eof())
	{
		fin >> name >> grade1 >> grade2 >> grade3 >> grade4 >> grade5;
		double average = (grade1 + grade2 + grade3 + grade4 + grade5)/5;
		grade = letterGrade(average);
		oss << name << " " << average << " " << grade << "\n";
		counter++;
	}
	name = oss.str();
	cout << name << endl;
	cout << "Number of records processed: " << counter << endl;
	system("pause");
}
char letterGrade(double average)
{
	char letter;
	if (average >= 90)
		letter = 'A';
	else if (average >= 80)
		letter = 'B';
	else if (average >= 70)
		letter = 'C';
	else if (average >= 60)
		letter = 'D';
	else
		letter = 'F';
	return letter;
}