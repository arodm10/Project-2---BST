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
	// Base case: if current is nullptr, return nullptr
    if (current == nullptr) return nullptr;

	// If the current node's name matches the target name, return the current node
    if (current->name == targetName) return current;

	// Recursively search the left and right subtrees
    Person* found = findNode(current->left, targetName);
    if (found != nullptr) return found;

	// If not found in the left subtree, search the right subtree
    return findNode(current->right, targetName);
}

FamilyBST::~FamilyBST()
{

}


bool FamilyBST::add(string parentName, string childName, int childAge, bool isLeftChild)
{
	// Base case - if the tree is empty, create the root node
    if (root == nullptr) 
    {
        root = new Person(childName, childAge);
        return true;
    }

	// Find the parent node, if it exists, 
    // add the child node to the left or 
    // right based on isLeftChild
    Person* parentNode = findNode(root, parentName);

    if (parentNode == nullptr) 
    {
        return false;
    }

    // If it exists, add the child node to 
    // the left or right based on isLeftChild

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
    for (int count = 0; count <= 13; count++)
    {
        cout << "*";

        if (count == 6)
            cout << " Family Tree Menu ";
    }

    indent();

    for (int count = 0; count <= 31; count++)
		cout << "-";

    indent();

    cout << "1. Add a Family Member" << endl;
	cout << "2. Find Family Member" << endl;
	cout << "3. Remove Family Member" << endl;
    cout << "4. Update Family Member" << endl;
	cout << "5. Display family tree" << endl;
	cout << "6. Exit" << endl;
}
void addMember()
{

}
void findMember()
{

}
void removeMember()
{

}
void updateMember()
{

}
void displayFamilyTree()
{

}
