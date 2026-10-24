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

#ifndef TOOLS_H
#define TOOLS_H

#include<string>

int		getInt(std::string prompt);

std::string getString(std::string prompt);
std::string getLine(std::string prompt);

int		getBoundedInt(std::string prompt,
	int lowBound, int highBound);

void	indent();
void	indent(int numSpaces);
void	pause(void);
void	flushInput(void);

#endif