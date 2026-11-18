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


FamilyBST::Person* FamilyBST::findNode(Person* current, string targetName)
{
    // Base case: if current is nullptr, return nullptr
    if (current == nullptr)
        return nullptr;


    // If the current node's name matches the target name, return the current node
    if (targetName == current->name)
        return current;


    // Recursively search the left and right subtrees
    // ?? Fix This ??
    Person* found 
        = findNode(current->left, targetName);

    if (found != nullptr)
        return found;


    // If not found in the left subtree, search the right subtree
    return findNode(current->right, targetName);
}

FamilyBST::~FamilyBST()
{
    deleteTree(root);
}

void FamilyBST::deleteTree(Person* current)
{   
    // Base case
    if (current == nullptr) 
        return;

    deleteTree(current->left);
    deleteTree(current->right);

    delete current;
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

    // check this // if (findNode(root, childName) != nullptr) return false;


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

bool FamilyBST::find(string targetName)
{
    return findNode(root, targetName) != nullptr;
}

// ============================================================
// Helper Functions

void FamilyBST::displayTreeHelper(Person* current, int depth) const
{
    if (current == nullptr)
        return;

    indent();

    cout << string(depth * 4, ' ') << current->name
        << " (Age: " << current->age << ")";

    if (current->Parent != nullptr)
        cout << " - Parent: " << current->Parent->name;

    indent();

    displayTreeHelper(current->left, depth + 1);
    displayTreeHelper(current->right, depth + 1);
}

void FamilyBST::displayTree() const
{
    if (root == nullptr)
    {
        cout << "Family tree is empty." << endl;
        indent();

        return;
    }

    displayTreeHelper(root, 0);
}

// ============================================================
// Menu Functions

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

    indent(2);

    cout << "1. Add a Family Member" << endl;
	cout << "2. Find Family Member" << endl;
	cout << "3. Remove Family Member" << endl;
    cout << "4. Update Family Member" << endl;
	cout << "5. Display family tree" << endl;
	cout << "6. Exit" << endl;

	indent();
}
void addMember(FamilyBST& familyTree)
{
	// Get user input for the new family member
    string childName 
        = getLine("Enter family member's name: ");

    int childAge 
        = getBoundedInt("Enter age: ", 0, 120);

    string parentName 
        = getLine("Enter parent's name: ");

    int position 
        = getBoundedInt("Enter position (1 = Left, 2 = Right): ", 1, 2);

    indent();

	// Determine if the new member is a left or right child
    bool isLeftChild 
        = (position == 1);


	// Add the new family member to the tree
    if (familyTree.add(parentName, childName, childAge, isLeftChild))
    {
        cout << "Family member added successfully!" << endl;
        indent();
    }
    else
    {
        cout << "Failed to add family member." << endl;
        indent();
    }
}

void findMember(FamilyBST& familyTree)
{
	// Get user input for the family member to find
	string targetName 
        = getLine("Enter family member's name to find: ");

    indent();

	// Search for the family member in the tree
    if (familyTree.find(targetName))
    {
        cout << "Found " << targetName << endl;
        indent();
    }

    else
    {
        cout << "Family member " << targetName << " does not exist" << endl;
        indent();
    }

}

void removeMember()
{
	// Get user input for the family member to remove
}

void updateMember()
{
	// Get user input for the family member to update
}

void displayFamilyTree(FamilyBST& familyTree)
{
	// Display the family tree in a structured format
    familyTree.displayTree();
}
