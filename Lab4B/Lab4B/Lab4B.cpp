#include <iostream>
#include <array>
#include <string>

using namespace std;

void seatChange();
string seats[7][4] = {{"A","B","C","D"},
					  {"A","B","C","D"},
					  {"A","B","C","D"},
					  {"A","B","C","D"},
					  {"A","B","C","D"},
					  {"A","B","C","D"},
					  {"A","B","C","D"}};
void main()
{
	char answer = 'y';
	while(answer == 'y' || answer == 'Y')
	{
		for(int i = 0; i < 7; i++)
		{
			cout << (i+1) << " ";
			for(int o = 0; o < 4; o++)
			{
				cout << seats[i][o] << " ";
				if(o == 1)
					cout << "     ";
			}
			cout << endl;
		}
		seatChange();
		cout << "Would you like another seat? (y/n)" << endl;
		cin >> answer;
		system("cls");
	}
}
void seatChange()
{
	int x = 0, y = 0;
	char seat;
	cout << "Enter your row (ex. 1-7): " << endl;
	cin >> x;
	x = x - 1;
	cout << "Enter your seat (ex. A-D): " << endl;
	cin >> seat;
	seat = toupper(seat);
	switch(seat)
	{
		case 'A':
			y = 0;
			break;
		case 'B':
			y = 1;
			break;
		case 'C':
			y = 2;
			break;
		case 'D':
			y = 3;
			break;
	}
	if(seats[x][y] == "X")
	{
		cout << "That seat is taken." << endl;
	}
	else
	{
		seats[x][y] = "X";
	}
}