/*
	Kyle Riley
	SE 124.22
	Lab 2A
	1/23/2018
	maleNum is the number of males unable to vote
	femNum is the number of females unable to vote
	maleOldNo is the number of males who are old enough, but not registered
	femOldNo is the number of females who old enough, but not registered
	voteYes is the number of people who voted
	voteNo is the number of people not voting
	ID holds id num, age holds age, gender holds gender, registered holds y/n, votes holds y/n
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	ifstream fin;
	fin.open("F:\\C++2\\Lab2A\\vote.txt");
	int maleNum = 0, femNum = 0, maleOldNo = 0, femOldNo = 0; 
	int voteNo = 0, voteYes = 0, record = 0;
	string id = "",age = "", gender = "", registered = "", votes = "";
	while (!fin.eof())
	{
		/*
		cout << "What is your ID number?" << endl;
		getline(cin,id);
		cout << "What is your age?" << endl;
		getline(cin,age);
		cout << "What is your gender?(M/F)" << endl;
		getline(cin,gender);
		cout << "Are you registered to vote?(Y/N)" << endl;
		getline(cin,registered);
		cout<< "Are you voting?(Y/N)" << endl;
		getline(cin, votes);
		*/
		fin >> id >> age >> gender >> registered >> votes;
		if(stoi(age,nullptr, 10) >= 18)
		{
			if(registered == "y"|| registered == "Y")
			{
				if(votes == "y"|| votes == "Y")
				{
					voteYes++;
				}
				else
				{
					voteNo++;
				}
			}
			else
			{
				if (gender == "m" || gender =="M")
				{
					maleOldNo++;
				}
				if (gender == "f" || gender =="F")
				{
					femOldNo++;
				}
			}
		}
		else
		{
			if (gender == "m" || gender =="M")
				{
					maleNum++;
				}
				if (gender == "f" || gender =="F")
				{
					femNum++;
				}
		}
		record++;
	}
	cout << "1.  Number of males not eligible to register." << maleNum <<endl;
	cout << "2.  Number of females not eligible to register."<< femNum <<endl;
	cout << "3.  Number of males who are old enough to vote but have not registered."<< maleOldNo<<endl;
	cout << "4.  Number of females who are old enough to vote but have not registered."<< femOldNo <<endl;
	cout << "5.  Number of individuals who are eligible to vote but did not vote."<< voteNo <<endl;
	cout << "6.  Number of individuals who did vote."<< voteYes <<endl;
	cout << "7.  Number of records processed."<< record <<endl;
	system("pause");
}