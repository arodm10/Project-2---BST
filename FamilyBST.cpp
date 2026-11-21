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
    //MY CODE: BRANDON
    deleteSubtree(root);
    root = nullptr;
    //END OF MY CODE: BRANDON

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

//MY CODE: BRANDON
Person* FamilyBST::find(string targetName) {
    return findNode(root, targetName);
}

void FamilyBST::deleteSubtree(Person* current) {
    if (current == nullptr) {
        return;
    }

    deleteSubtree(current->left);
    deleteSubtree(current->right);

    delete current;
}


bool FamilyBST::remove(string targetName) {
    Person* member = findNode(root, targetName);

    if (member == nullptr) {
        return false;
    }

    Person* parent = member->Parent;

    if (parent == nullptr) {
        root = nullptr;
    }
    else if (parent->left == member) {
        parent->left = nullptr;
    }
    else if (parent->right == member) {
        parent->right = nullptr;
    }

    deleteSubtree(member);

    return true;
}


bool FamilyBST::update(string targetName, string newName, int newAge) {
    Person* member = findNode(root, targetName);

    if (member == nullptr) {
        return false;
    }

    // Prevent two members from having the same name
    Person* existing = findNode(root, newName);

    if (existing != nullptr && existing != member) {
        return false;
    }

    member->setName(newName);
    member->setAge(newAge);

    return true;
}


void FamilyBST::displayNode(Person* current, int level) {
    if (current == nullptr) {
        return;
    }

    for (int i = 0; i < level; i++) {
        cout << "    ";
    }

    cout << current->name
        << " (Age: " << current->age << ")"
        << endl;

    displayNode(current->left, level + 1);
    displayNode(current->right, level + 1);
}


void FamilyBST::display() {
    if (root == nullptr) {
        cout << "Family tree is empty" << endl;
        return;
    }

    displayNode(root, 0);
}

//END OF MY CODE: BRANDON


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
	cout << "-1. Exit" << endl;
}

//MY CODE: BRANDON
void addMember(FamilyBST& familyTree)
{
    string childName = getLine("Enter family member's name: ");
    int childAge = getBoundedInt("Enter age: ", 0, 120);

    if (familyTree.getRoot() == nullptr) {
        if (familyTree.add("", childName, childAge, true)) {
            cout << "Family member added successfully!" << endl;
        }
        else {
            cout << "Failed to add family member" << endl;
        }
        return;
    }
   string parentName = getLine("Enter parent's name: ");
   int position = getBoundedInt("Enter position (1 = Left, 2 = Right): ", 1, 2);
   bool isLeftChild = (position == 1);

   if (familyTree.add(parentName, childName, childAge, isLeftChild)) {
       cout << "Family member added successfully!" << endl;
   }
   else {
       cout << "Failed to add family member" << endl;
   }
}
void findMember(FamilyBST& familyTree)
{
    string name = getLine("Enter family member's name you want to find: ");
    Person* member = familyTree.find(name);

    if (member != nullptr) {
        cout << "Family member found!" << endl;
        cout << "Name: " << member->getName() << endl;
        cout << "Age: " << member->getAge() << endl;

        if (member->Parent != nullptr) {
            cout << "Parent: " << member->Parent->getName() << endl;
        }
        else {
            cout << "Parent: None (Root)" << endl;
        }
    }
    else {
        cout << "Family member not found" << endl;
    }
}
void removeMember(FamilyBST& familyTree)
{
    string childName = getLine("Enter family member's name you want to delete/remove: ");

    if (familyTree.remove(childName)) {
        cout << "Family member removed successfully!" << endl;
    }
    else {
        cout << "Failed to remove family member." << endl;
    }
}
void updateMember(FamilyBST& familyTree)
{
    string oldName = getLine("Enter family member's name to update: ");
    string newName = getLine("Enter new name: ");
    int newAge = getBoundedInt("Enter new age: ", 0, 120);

    if (familyTree.update(oldName, newName, newAge)) {
        cout << "Family member updated successfully!" << endl;
    }
    else {
        cout << "Failed to update family member" << endl;
    }
}
void displayFamilyTree(FamilyBST& familyTree)
{
    cout << "\n======== FAMILY TREE ========" << endl;
    familyTree.display();

    cout << "==============================" << endl;
}
//END OF MY CODE: BRANDON