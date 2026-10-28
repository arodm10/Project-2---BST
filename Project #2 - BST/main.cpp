/*
	Name: Aaron Madrigal
	Course: CMPR 131 - Fall 2026
	Date: October 24, 2026
	Assignment: Group Project #2 - Team Sakura Labs

	Collaboration:
		Matthew Montoura
		Brandon Morgado De La Rosa

	Resources/AI Tools Used:
		None
*/
#include <iostream>
#include "tools.h"
#include "FamilyBST.h"

using namespace std;

int main()
{
		int userInput = 0;
		// FamilyBST familyBST;

		// Display Input Options
		displayMenu();

		while (userInput != -1)
		{
			// Get Int Input
			userInput = getBoundedInt("Enter number to perform an action: ", -1, 5);

			// Perform action
			switch (userInput)
			{
			case 0: displayMenu();					break;
			case -1: cout << "Exiting program...";	break;

			default:
				cout << "Invalid Input. Try again" << endl;	break;
			}
		}

	return 0;
}