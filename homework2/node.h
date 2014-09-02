/*node.h
//Description: Creates nodes for use in linked list, adds nodes to linked list, and prints data member
               for specified range of linked list

*/



#ifndef NODE_H_
#define NODE_H_

#include <string>


using namespace std;

class Node
{
public:
	Node(); //Default CTOR

	Node(string disease_cause);
	
	string data_member_;
	Node* next_;
	~Node(); //Destructor



};

void Traverse(Node* root); //Print the data member of every node in the linked list
void TraverseUpTo(Node* root, string end); //Print the data member of every node in the list up to end
void TraverseStartingFrom(Node* root, string start); //Print the data member of every node in the list beginning at start
void TraverseFromUpTo(Node* root, string start, string end); //Print the data member of every node in range (start,end)
void AddNode(Node* root, string disease_cause); //Add node onto linked list











#endif