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

class Person
{
public:
    std::string  name;
    int     age;
    Person* Parent;
    Person* left;
    Person* right;

    Person(std::string n, int a)
    {
        name = n;
        age = a;
        Parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    ~Person() { }

    std::string  getName() const        { return name; }
    void         setName(std::string n) { name = n; }
    int          getAge() const         { return age; }
    void         setAge(int a)          { age = a; }
};

class FamilyBST
{
private:
    Person* root;

    Person* findNode(Person* current, std::string targetName);

public:
    FamilyBST()
    {
        root = nullptr;
    }

    ~FamilyBST();

    Person* getRoot() const { return root; }

    bool add(std::string parentName, std::string childName, int childAge, bool isLeftChild);
};



// Helper Functions // 

void displayMenu();


// Menu Functions //


#endif