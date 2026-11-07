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

#ifndef FamilyBST_H
#define FamilyBST_H

#include <string>
using namespace std;

class Person
{
public:
    string  name;
    int     age;
    Person* Parent;
    Person* left;
    Person* right;

    Person(string n, int a)
    {
        name    = n;
        age     = a;
        Parent  = nullptr;
        left    = nullptr;
        right   = nullptr;
    }

    ~Person() { }

    string       getName() const        { return name; }
    void         setName(string n)      { name = n; }
    int          getAge() const         { return age; }
    void         setAge(int a)          { age = a; }
};

class FamilyBST
{
private:
    Person* root;

    Person* findNode(Person* current, string targetName);

public:
    FamilyBST()
    {
        root = nullptr;
    }

    ~FamilyBST();

    Person* getRoot() const { return root; }
    bool    add(string parentName, string childName, int childAge, bool isLeftChild);
};



// Helper Functions // 



// Menu Functions //
void displayMenu();
void addMember(FamilyBST& familyTree);
void findMember();
void removeMember();
void updateMember();
void displayFamilyTree();

#endif