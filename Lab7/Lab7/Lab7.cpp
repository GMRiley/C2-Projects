#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

void lottoRand();
void userNums();
void doWin();

int numSpread, parameter;
int* lottery, user;
void main()
{
	int answer;
	cout << "Select which number of spreads you would like to play" << endl;
	cout << "1) 5 numbers" << endl;
	cout << "2) 7 numbers" << endl;
	cout << "3) 10 numbers" << endl;
	cout << "4) Players Choice Spread" << endl;
	cout << "5) Exit" << endl;
	cin >> answer;
	while (answer != 5)
	{
		switch(answer)
		{
			case 1:
				numSpread = 5;
				cout << "Enter the parameter for the numbers generated" << endl;
				cin >> parameter;
				lottoRand();
				userNums();
				break;

			case 2:
				numSpread = 7;
				lottoRand();
				userNums();
				break;

			case 3:
				numSpread = 10;
				lottoRand();
				userNums();
				break;

			case 4:
				cout << "Enter your amount of spreads" << endl;
				cin >> numSpread;
				lottoRand();
				userNums();
				break;
		
			default:
				cout << "That was an incorrect value" << endl;
				break;
		}
	}
	cout << "Goodbye" << endl;
	system("pause");
}
void lottoRand()
{
	srand(time(NULL * NULL));
	lottery = new int[numSpread];
	for(int counter = 0; counter < numSpread; counter++)
	{
		rand() % parameter >> lottery[counter];
	}
}
void userNums()
{
	user = new int[numSpread];
	for(int counter = 0; counter < numSpread; counter++)
	{
		int userNum;
		cout << "Enter your spread #" << counter << " value." << endl;
		cin >> userNum;
		userNum >> user[counter];
	}
}
void doWin()
{
	int kenoCount = 0;
	for (int counterOne = 0; counterOne < numSpread; counterOne++)
	{
		for(int counterTwo = 0; counterTwo < numSpread; counterTwo++)
		{
			if(user[counterOne] == lottery[counterTwo])
			{
				kenoCount++;
			}
		}
	}
	if (kenoCount == numSpread)
	{
		cout << "You Win!" << endl;
	}
	else
	{
		cout << "You Lose!" << endl;
	}
}
