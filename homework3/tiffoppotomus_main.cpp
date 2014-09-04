//  main.cpp
//  hw02
//
//  Created by Tiff Sze on 8/31/14.
//  Copyright (c) 2014 Tiff Sze. All rights reserved.
//

/* Summary:  This main.cpp will create an empty linked list, populate the linked list with contents from a file opened in the main.cpp and create single nodes at the end of the list if the linked list is full and needs more room at the end of the linked list.  A struct is created before main() so that nodes may be created for the linked list.  main.cpp will output into stdout a plain text list of the contents of the linked list.
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

struct Node
{
	//Text is used to store the lines from the file opened later
	string text;

	//next will carry the next node in the linked list
	Node *next;
};


int main()
{
	//The variable "i" is used to keep track of each line in the while loop
	short i = 0;

	//These pointer structures are used to make the linked list.
	//The header_node pointer points to the beginning of the linked list.
	//The tail_node pointer points to the end of the linked list.
	//The current_node pointer points to the current node the code is on/looking at.
	Node *header_node, *tail_node, *current_node;

	//These creates variables to open a pathway the file the code is grabbing from
	//and out putting to.
	ifstream file_in;
	ofstream file_out;

	//This creates a variable to put the name of the file in, in string format.
	string file_name = "statesAndAbb.csv";

	//line_in_file is used to store a line from the file to put into the linked list
	string line_in_file;

	//This opens files and creates pathways for the code to grab at and print to.
	file_in.open(file_name.c_str());
	string file_out_name = "newStatesAndAbb.csv";
	file_out.open(file_out_name.c_str());


	//If the file fails to open, a warning will be printed: "ERROR! File called
	//ListOfBeyonceFilms.txt failed to open, or whatever file name is in the
	//varaiable, file_name failed to open.
	if (file_in.fail()&& file_out.fail())
	{
		cout << "ERROR! File called " << file_name << " failed to open." << endl;
		exit(-1);
	}

	//A new Node is created using the pointer node, current_node
	//Because it is currently the only node in the linked list,
	//it is both the header_node and the tail_node.
	current_node = new Node;
	header_node = current_node;
	tail_node = current_node;

	//To create a set of 5 nodes in a linked list
	for (short y = 0; y<5; y++)
	{
		current_node = new Node;
		tail_node->next = current_node;
		tail_node = tail_node->next;
	}

	current_node = header_node;

	//Gets the first line in the file
	getline(file_in, line_in_file);


	//This runs while there are still lines to read in the file
	//This will populate the linked list and write to a file
	//the contents of the linked list as well as to print
	//to std out the linked list contents.
	while (file_in)
	{
		//This will populate the linked list if the list is not full.
		if (current_node->next != tail_node->next)
		{
			current_node->text = line_in_file;

			cout << current_node->text << endl;
			file_out << line_in_file << endl;

			current_node = current_node->next;
		}//end if

		//If the list is full, this will create single nodes at the end
		//of the list.
		else
		{
			current_node = new Node;
			current_node->text = line_in_file;

			cout << current_node->text << endl;
			file_out << line_in_file << endl;

			tail_node->next = current_node;
			tail_node = tail_node->next;
		}//end else

		i++;
		getline(file_in, line_in_file);


	}//end while

	//closes the files the code opened in the beginning
	file_in.close();
	file_out.close();

	system("PAUSE");
	return 0;

}//end main


