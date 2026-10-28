# Project #2 - BST

## Intro
  I think the first suggestion for a **Family Tree Manager** would be the simplest. However, a tree doesn't exactly portray the relationship between siblings or parents.
  For example, parents would be two nodes, but each child node should only point to one node above it. 
  Can't really have this
~~~
Robert      Maria
      \    /     
      James
~~~

So, we should have something like this that records the parent's pointers
~~~
struct Person
{
// Details
    string name;
    int age;

// Pointers to parent (For simplicity, each child will point to only one parent, one parent can point to at most 2 children)
    Person* Parent;

// Next child nodes
    Person* left;
    Person* right;
};
~~~

## Functions
// Main Functions
  1. Add Family Member
  2. Find Family Member
  3. Remove Family Member
  4. Update Family Member
  5. Display All Family Members

## Design
### 1st Part - Creating BST Class and new node
A member should have the following characteristics  
	&emsp;- Name
	&emsp;- Age
	&emsp;- Parent (For simplicity, each child will point to only one parent, one parent can point to at most 2 children)
	&emsp;- Children

Create a Family Member class  
	&emsp;- constructor / destructor
	&emsp;- getter / setter functions

Implement Functions:  
	&emsp;- add()
	
### 2nd Part - Traversing / Removing the Tree
Creating the relationships between nodes  
	&emsp;- Child 1 = Left, Child 2 = Right

Recursion and Reallocating memory  
	&emsp;- able to traverse through the tree to find and/or delete a node  
	&emsp;- memory cleanup, updating parent/child relationship

Implement Functions:  
	&emsp;- search()  
	&emsp;- remove()  
	&emsp;- displayFamilyMembers()

### 3rd Part - Menu / Integrating / Testing
Creating the menu in main.cpp  
	&emsp;- design, functionality

Testing that the member functions correctly integrates with the tree  
	&emsp;- Big-Five implementation support?  
	&emsp;- Function interface

## Assignments
Aaron:  
  &emsp;TBD
Matthew:  
  &emsp;TBD
Brandon:  
  &emsp;TBD
