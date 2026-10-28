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
#include <iomanip>
#include <string>
#include "FamilyBST.h"
#include "tools.h"

using namespace std;

// ============================================================
// Constructors / Destructor
// ============================================================


Person* FamilyBST::findNode(Person* current, string targetName)
{
    if (current == nullptr) return nullptr;
    if (current->name == targetName) return current;

    Person* found = findNode(current->left, targetName);
    if (found != nullptr) return found;

    return findNode(current->right, targetName);
}

FamilyBST::~FamilyBST()
{

}


bool FamilyBST::add(string parentName, string childName, int childAge, bool isLeftChild)
{
    if (root == nullptr) 
    {
        root = new Person(childName, childAge);
        return true;
    }

    Person* parentNode = findNode(root, parentName);
    if (parentNode == nullptr) 
    {
        return false;
    }

    Person* newChild = new Person(childName, childAge);
    newChild->Parent = parentNode;

    if (isLeftChild && parentNode->left == nullptr) 
    {
        parentNode->left = newChild;
        return true;
    }

    else if (!isLeftChild && parentNode->right == nullptr) 
    {
        parentNode->right = newChild;
        return true;
    }

    delete newChild;
    return false;
}

// ============================================================
// Menu / Helper Functions

void displayMenu()
{

}

