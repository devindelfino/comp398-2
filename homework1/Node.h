#ifndef _NODE_
#define _NODE_

#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
	Node();

	Node(string diseaseNCause);
	
	string dataMember;
	Node* next;
	~Node();



};

void traverse(Node* root);
void traverseUpTo(Node* root, string end);
void traverseStartingFrom(Node* root, string start);
void traverseFromUpTo(Node* root, string start, string end);
void addNode(Node* root, string diseaseNCause);











#endif