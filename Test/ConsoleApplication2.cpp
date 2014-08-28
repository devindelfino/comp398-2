// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include "Node.h"
#include <iostream>
#include <fstream>

int main()
{
	Node *root;

	//read in flat file 
	ifstream infile;
	infile.open("SandA.csv");

	string line;


	//Weird characters appear before the first line. This fixes it.
	//getline(infile, line);
	root = new Node();

	(*root).next = 0;


	//while there is text left add to the linked list

	while (!infile.eof()){
		getline(infile, line);

		Node* newNode;
		newNode = new Node();

		addNode(root, line);


	}
	
	traverse(root);
	
	system("PAUSE");
	return 0;
}

