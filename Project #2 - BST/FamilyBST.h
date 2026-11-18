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

class FamilyBST
{
public:

    struct Person
    {
        string  name;
        int     age;
        Person* Parent;
        Person* left;
        Person* right;
        
        // Constructor
        Person(string n, int a)
        : name(n), age(a), Parent(nullptr), left(nullptr), right(nullptr) {}

        // Destructor
        ~Person() {}

        // Getters and Setters
        string       getName() const { return name; }
        void         setName(string n) { name = n; }
        int          getAge() const { return age; }
        void         setAge(int a) { age = a; }
    };

private:
    // 
    Person* root;
    Person* findNode(Person* current, string targetName);
    void    deleteTree(Person* current);
    void    displayTreeHelper(Person* current, int depth) const;

public:
	// Constructor
    FamilyBST()
    {
        root = nullptr;
    }

	// Destructor
    ~FamilyBST();


	// Getters
    Person* getRoot() const { return root; }

	// Add a new child to the family tree
    bool add(string parentName, string childName, int childAge, bool isLeftChild);
    bool find(string targetName);
    void displayTree() const;
};



// Helper Functions // 



// Menu Functions //
void displayMenu();
void addMember(FamilyBST& familyTree);
void findMember(FamilyBST& familyTree);
void removeMember();
void updateMember();
void displayFamilyTree(FamilyBST& familyTree);

#endif