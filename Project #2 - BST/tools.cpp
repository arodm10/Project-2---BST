/*
	Name: Aaron Madrigal
	Course: CMPR 131 - Fall 2026
	Date: October 24, 2026
	Assignment: Group Project #2 - Team Sakura

	Collaboration:
		Matthew Montoura
		Brandon Morgado De La Rosa

	Resources/AI Tools Used:
		None
*/

#include"tools.h"
#include<iostream>
#include<string>

using namespace std;

////////////////////

int getInt(string prompt)
{
	while (true)
	{
		int userInput;
		cout << prompt;
		cin >> userInput;
		flushInput();
		if (!cin.fail())
			return userInput; // exit loop
		cin.clear();
		flushInput();
		cout << "\tPlease enter an integer" << endl;
	}
}

int getBoundedInt(string prompt, int lowBound, int highBound)
{
	while (true)
	{
		int userInput = getInt(prompt);
		if (userInput >= lowBound && userInput <= highBound)
			return userInput;

		cout << "Value out of range - it should be in ["
			<< lowBound
			<< ".."
			<< highBound
			<< "]."
			<< endl;
	}
}

string getString(string prompt)
{
	while (true)
	{
		string userInput;
		cout << prompt;
		cin >> userInput;
		flushInput();
		if (!cin.fail()) return userInput;

		cin.clear();
		flushInput();
		cout << "Input failure: Try again." << endl;
	}
}

string getLine(string prompt)
{
	while (true)
	{
		string userInput;
		cout << prompt;
		getline(cin, userInput);
		if (!cin.fail()) return userInput;

		cin.clear();
		flushInput();
		cout << "Input failure: Try again." << endl;
	}
}

void flushInput(void)
{
	cin.ignore(999, '\n');
}

void indent()
{
	cout << endl;
}

void indent(int indents)
{
	for (int i = 0; i < indents; i++)
		cout << endl;
}

void pause(void)
{
	cout << "Press ENTER to continue...";
	cin.ignore(999, '\n');
}