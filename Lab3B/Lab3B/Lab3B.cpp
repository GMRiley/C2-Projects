/*
	Kyle Riley
	SE 124.22
	Lab 3B
	1/30/2018
	[int] roll(); is the function that rolls the dice and returns the total
	[double] countWin is your win counter
	[double] countLoss is your loss counter
	[double] winLoss is the variable that will hold the win loss ratio
	[int] total will hold the total dice value
	[int] point is what holds the "point" value
	[int] totalP is a different total that will be saved for holding a total while a point is active
	[int] die1 holds the first die value
	[int[ die2 holds the second die value

*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int roll();
void main()
{
	cout << fixed << setprecision(2);

	double countWin = 0, countLoss = 0, winLoss;

	int point = 0, total, totalP=0;

	srand(time(NULL * NULL));

	for (int i = 0; i < 10000; i++)
	{
		//One run here is one sim
		total = roll();
		if(total == 7 || total == 11)
		{
			countWin++;
		}
		else if(total == 2 || total == 3 || total == 12)
		{
			countLoss++;
		}
		else if (total >= 4 &&  total <= 10)
		{
			point = total;
		}
		if(point == total)
		{
			while (total != 7 && totalP != point)
			{
				totalP = roll();
				if (totalP == point)
					countWin++;
				if (totalP == 7)
					countLoss++;
			}
		}
	}
	winLoss = countWin/(countWin+countLoss);
	winLoss = winLoss * 100;
	cout << "Wins: " << countWin << endl;
	cout << "Loss: " << countLoss << endl;
	cout << "Your Win/Loss is: " << winLoss << "%" << endl;
	system("pause");
}
int roll()
{
	int die1, die2, total;
	die1 = (rand() % 6) + 1;
	die2 = (rand() % 6) + 1;
	total = die1+die2;
	return total;
}