/*
	Kyle Riley
	SE124.02
	1/16/18

	Variable Dict.

	tax() is the calculating tax function while totalTax holds its return value.
	tip() is the calculating tip function while totalTip holds its return value.
	pbj is the amount of the pbj costs
	steak is the amount that the steak costs.
	bullet is used to convert a decimal value into whole number values, and uses math to get total bullet num.
	food is going to hold the meal cost value.
	bill will be used to calculate the tip quantity and show the total end amount.
	pay holds how much you are paying with.
	change is the amount left over after you pay.

*/
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void goto_xy(int c, int r);
double tax(double food), tip(double bill);
double pbj = 35, steak = 45;

int column = 16, row = 8;
void main()
{
	int x, bullet;
	cout << fixed << setprecision(2);
	double mealCost, pay, change;
	double taxTotal, tipTotal, bill;
	goto_xy(column,row);
	cout << "Diner's Menu" << endl << endl;
	goto_xy(column,row+1);
	cout << "1. Peanut Butter & Jelly with water          $35.00" << endl;
	goto_xy(column,row+2);
	cout << "2. Steak, Fries, Vegetable, coffee or soda   $45.00" << endl << endl;
	goto_xy(column,row+4);
	cout << "Enter your selection (1/2)" << endl;
	goto_xy(column+27,row+4);
	cin >> x;
	switch(x)
	{
		case 1:
			system("cls");
			mealCost = pbj;
			taxTotal = tax(pbj);
			tipTotal = tip(pbj);
			bill = pbj + taxTotal + tipTotal;
			system("cls");
		break;
		case 2:
			system("cls");
			mealCost = steak;
			taxTotal = tax(steak);
			tipTotal = tip(steak);
			bill = steak + taxTotal + tipTotal;
			system("cls");
		break;
	}
	goto_xy(column,row);
	cout << "Your food cost is $" << mealCost << endl;
	goto_xy(column,row+1);
	cout << "Food tax is       $" << taxTotal << endl;
	goto_xy(column,row+2);
	cout << "Your tip is       $" << tipTotal << endl << endl;
	goto_xy(column,row+3);
	cout << "Your food bill is $" << bill << endl << endl;
	goto_xy(column,row+4);
	cout << "How much money do you have?" << endl;
	goto_xy(column+30,row+4);
	cin >> pay;
	change = pay - bill;
	goto_xy(column,row+6);
	cout << "You have $" << change << " left over." << endl << endl;
	bullet = change;
	bullet = bullet * 5;
	goto_xy(column,row+8);
	cout << "You can afford to buy " << bullet << " rounds of ammo." << endl;
	goto_xy(column,row+9);
	system("pause");



}
double tax(double food)
{
	double taxTotal = food * .1;
	return taxTotal;
}
double tip(double bill)
{
	double tipTotal;
	int x;
	goto_xy(column,row);
	cout << "Tip" << endl;
	goto_xy(column,row+1);
	cout << "1. Excellent" << endl;
	goto_xy(column,row+2);
	cout << "2. Good" << endl;
	goto_xy(column,row+3);
	cout << "3. Fair" << endl;
	goto_xy(column,row+4);
	cout << "4. Poor" << endl << endl;
	goto_xy(column,row+6);
	cout << "How was the service?" << endl;
	goto_xy(column+23,row+6);
	cin >> x;
	if (x == 1)
		tipTotal = bill * .2;
	if (x == 2)
		tipTotal = bill *.15;
	if (x == 3)
		tipTotal = bill *.1;
	if (x == 4)
		tipTotal = bill *.05;
	return tipTotal;
}
	void goto_xy(int c, int r)
{
	COORD coord;
	coord.X = c;
	coord.Y = r;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	return;
}