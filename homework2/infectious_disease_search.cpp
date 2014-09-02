/*infectious_disease_search.cpp
Description: (1) Creates and populates a linked list containing infectious diseases and their causes read in
				 from a flat file database.
			 (2) Allows user to display either (a) every infectious disease and cause (b) every infectious disease 
				 and cause starting from a user-specified letter (c) every infectious disease and cause up to a
				 user-specified letter (d) every infectious disease and cause in range (start,end).   




*/

#include "stdafx.h"
#include "Node.h"
#include <iostream>

#include <fstream>

#include <cstdlib>

using namespace std;

char lowerToUpper(char ch1);




int main()
{
	Node *root = new Node("A");
	 
	//read in flat file 
	ifstream infile;
	infile.open("diseaseNCause.txt");

	string line;

	
	//Weird characters appear before the first line. This fixes it.
	getline(infile, line);
	
	
	//while there is text left add to the linked list

	while (!infile.eof()){
		getline(infile, line);

		AddNode(root, line);

	}
	
	//Linked list created ask user what to do with it

	printf("Welcome to the database of infectious diseases.  How would you like to browse the database? \n");
	printf("1. View the whole database \n");
	printf("2. View all diseases in the database starting from a specified letter \n");
	printf("3. View all diseases in the database up to (not including) a specified letter \n");
	printf("4. View all diseases in the database starting from a specified letter up to (not including) a specified letter \n");
	
	int selection;

	scanf_s("%d", &selection);

	string u_letter, u_letter2;
	//char user_input[5], user_input2[5];
	char sanitized, sanitized2;

	switch (selection)
	{
	case 1:
		Traverse(root);
		break;
	case 2:
		printf("What letter would you like to start with? \n");
		
		cin >> u_letter;
		/*gets_s(user_input);
		u_letter = user_input;*/
		sanitized = toupper(int(u_letter[0]));
		u_letter[0] = char(sanitized);
		
		//No diseases start with J or X so switch them to the next letter
		if (u_letter[0] == 'J')
			u_letter[0] = 'K';

		else if (u_letter[0] == 'X')
			u_letter[0] = 'Y';
		
		TraverseStartingFrom(root, u_letter);
		break;
	case 3:
		printf("What letter would you like to stop on? \n");
		cin >> u_letter;
		/*gets_s(user_input);
		u_letter = user_input;*/
		sanitized = toupper(int(u_letter[0]));
		u_letter[0] = char(sanitized);

		if (u_letter[0] == 'J')
			u_letter[0] = 'K';

		else if (u_letter[0] == 'X')
			u_letter[0] = 'Y';

		
		TraverseUpTo(root, u_letter);
		break;
	case 4:
		printf("What letter would you like to start with? \n");
		
		cin >> u_letter;
		/*gets_s(user_input);
		u_letter = user_input;*/
		
		sanitized = toupper(int(u_letter[0]));
		u_letter[0] = char(sanitized);

		printf("What letter would you like to stop on? \n");

		cin >> u_letter2;
		/*gets_s(user_input2);
		u_letter2 = user_input2;*/
		
		sanitized = toupper(int(u_letter2[0]));
		u_letter2[0] = char(sanitized);

		if (u_letter[0] == 'J')
			u_letter[0] = 'K';

		else if (u_letter[0] == 'X')
			u_letter[0] = 'Y';

		if (u_letter2[0] == 'J')
			u_letter2[0] = 'K';

		else if (u_letter2[0] == 'X')
			u_letter2[0] = 'Y';


		TraverseFromUpTo(root, u_letter, u_letter2);

		break;

	default:

		printf("Sorry that is all the functionality this program has at this time.  Please select one of the avilable options.");

		break;
	}


	
	
	
	
	system("PAUSE");
	return 0;
}

