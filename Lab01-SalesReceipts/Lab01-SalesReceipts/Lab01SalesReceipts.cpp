// Lab01SalesReceipts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string	lastName;
	string	firstName;
	char	transCode;
	double	price;
	int		qty;
	char	dollarSign = '$';

	string	fileName = "salesReceipts.txt";

	double	total = 0;
	double	grandTotal = 0;
	int		cnt = 0;
	
	ifstream	receiptFile;

	receiptFile.open(fileName);
	
	cout << endl;

	if (!receiptFile)
	{
		cout << endl << "Error opening input file." << endl << endl;
		system("pause");
		return -1;
	}

	receiptFile >> lastName;

	while (!receiptFile.eof())
	{
		receiptFile >> firstName >> transCode >> price >> qty;

		total = (price * qty);

		grandTotal += total;

		cnt++;

		cout << fixed << transCode << right << setw(7) << qty << "  @  " << dollarSign;
		cout << right << setw(9) << setprecision(2) << price << "  " << dollarSign;
		cout << setw(9) << total << "   ";
		cout << left << lastName << ", " << firstName << endl;

		dollarSign = ' ';

		receiptFile >> lastName;

	}
	
	receiptFile.close();

	cout << endl << "                         $" << setw(9) << right << grandTotal << endl;

	cout << endl << setw(8) << cnt << "  records processed" << endl << endl;

	system("pause");
	return 0;
}

