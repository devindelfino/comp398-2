#include "stdafx.h"
#include "Node.h"



using namespace std;


Node::Node()
{
	
}

Node::Node(string diseaseNCause)
{
	dataMember = diseaseNCause;
}


void traverse(Node* root){

	Node *traverse;
	traverse = root;

	if (traverse != 0) {
		while ((*traverse).next != 0){
			cout << (*traverse).dataMember << endl;
			traverse = (*traverse).next;
		}
		cout << (*traverse).dataMember << endl;
	}

}

void traverseUpTo(Node* root, string end){
	Node *traverse;
	traverse = root;

	if (traverse != 0) {
		while ((*traverse).dataMember != end){
			cout << (*traverse).dataMember << endl;
			traverse = (*traverse).next;
		}
		
	}

}


void traverseStartingFrom(Node* root, string start){

	Node *traverse;
	traverse = root;
	
	if ((*traverse).dataMember != start){
		while ((*traverse).dataMember != start){
			traverse = (*traverse).next;
		}

	}

	if (traverse != 0) {
		while ((*traverse).next != 0){
			cout << (*traverse).dataMember << endl;
			traverse = (*traverse).next;
		}
		cout << (*traverse).dataMember << endl;
	}

}

void traverseFromUpTo(Node* root, string start,string end){

	Node *traverse;
	traverse = root;

	if ((*traverse).dataMember != start){
		while ((*traverse).dataMember != start){
			traverse = (*traverse).next;
		}

	}

	if (traverse != 0) {
		while ((*traverse).dataMember != end){
			cout << (*traverse).dataMember << endl;
			traverse = (*traverse).next;
		}
	}

}


void addNode(Node* root,string diseaseNCause){
	
	Node *traverse;
	traverse = root;

	if (traverse != 0) {
		while ((*traverse).next != 0){
			traverse = (*traverse).next;
		}
	}
	(*traverse).next = new Node(diseaseNCause);
	traverse = (*traverse).next;
	(*traverse).next = 0;
	
	(*traverse).dataMember = diseaseNCause;


}




Node::~Node()
{
	Node* current = next;
	while (current != 0) {
		Node* nextNode = (*current).next;
		delete current;
		current = next;
	}
	next = 0;




}