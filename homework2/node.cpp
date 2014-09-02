/*node.cpp
Description: (1)Creates nodes for use in linked list using two different contructors.  The default contstructor makes an empty node while the other					 contstructor creates a node with a specified data_member_. (2) Adds nodes to the linked list by starting at the root and continuing until              a node points to zero.  This node's next_ member is then updated to point to the new node. (3) Prints every data memebrs by traversing				 every node in the list.  Prints every data member in the linked list from user specified start letter to the end of list by traversing to			 the start letter before printing data members.  Prints every data member in the linked list up to user specified end letter by stopping			 navigation through the list once the end letter is reached.  Prints every data member in linked list in user specified range (start,end)			 by traversing to the start letter before printing data members and by stopping navigation through the list once the end letter is reached.
*/



#include "stdafx.h"
#include "Node.h"



using namespace std;


Node::Node()
{
	data_member_ = "";
	next_ = 0;
}

Node::Node(string disease_cause)
{
	data_member_ = disease_cause;
	next_ = 0;
}

//Print every node in the list by starting at the root and stopping when a node's next member points to zero
void Traverse(Node* root){

	Node *traverse = root;
	

	string to_print;

	if (traverse != 0) {
		while ((*traverse).next_ != 0){
			to_print = (*traverse).data_member_;
			puts(to_print.c_str());
			traverse = (*traverse).next_;
		}
		to_print = (*traverse).data_member_;
		puts(to_print.c_str());
	}

}

//Navigate each node printing its data member until the end node is reached
void TraverseUpTo(Node* root, string end){
	Node *traverse = root;
	string to_print;

	if (traverse != 0) {
		while ((*traverse).data_member_ != end){
			to_print = (*traverse).data_member_;
			puts(to_print.c_str());
			traverse = (*traverse).next_;
		}

	}

}

//Naviagte to start letter and print rest of list
void TraverseStartingFrom(Node* root, string start){

	Node *traverse = root;
	string to_print;

	if ((*traverse).data_member_ != start){
		while ((*traverse).data_member_ != start){
			traverse = (*traverse).next_;
		}

	}

	if (traverse != 0) {
		while ((*traverse).next_ != 0){
			to_print = (*traverse).data_member_;
			puts(to_print.c_str());
		}
		to_print = (*traverse).data_member_;
		puts(to_print.c_str());
	}

}

//Navigate to start letter and print until you get to the end letter
void TraverseFromUpTo(Node* root, string start, string end){

	Node *traverse = root;
	string to_print;

	if ((*traverse).data_member_ != start){
		while ((*traverse).data_member_ != start){
			traverse = (*traverse).next_;
		}

	}

	if (traverse != 0) {
		while ((*traverse).data_member_ != end){
			to_print = (*traverse).data_member_;
			puts(to_print.c_str());
			traverse = (*traverse).next_;
		}
	}

}

//Add node by navigating to end of list and updating last pointer to point to the new node
void AddNode(Node* root, string disease_cause){

	Node *traverse = root;


	if (traverse != 0) {
		while ((*traverse).next_ != 0){
			traverse = (*traverse).next_;
		}
	}
	(*traverse).next_ = new Node(disease_cause);
	traverse = (*traverse).next_;
	(*traverse).next_ = 0;

	(*traverse).data_member_ = disease_cause;


}

//Frees memory by navigating the end of list and keeping track of the last two members of the list freeing memory whiel mving back to the start of the list
Node::~Node()
{
	Node* current = next_;
	while (current != 0) {
		Node* next_Node = (*current).next_;
		delete current;
		current = next_;
	}
	next_ = 0;




}


