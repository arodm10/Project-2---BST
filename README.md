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

// Pointers to parents
    Person* mother;
    Person* father;

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

## Assignments
Aaron:
  TBD
Matthew: 
  TBD
Brandon: 
  TBD
