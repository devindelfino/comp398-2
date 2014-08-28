#include "stdafx.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

char lowerToUpper(char ch1);




int main()
{
	Node *root;       
	 
	//read in flat file 
	ifstream infile;
	infile.open("diseaseNCause.txt");

	string line;

	
	//Weird characters appear before the first line. This fixes it.
	getline(infile, line);
	root = new Node("A");  

	(*root).next = 0;  
	
	
	//while there is text left add to the linked list

	while (!infile.eof()){
		getline(infile, line);

		Node* newNode;
		newNode = new Node();

		addNode(root, line);


	}

	//traverseFromUpTo(root, "A", "K");
	
	

	//Linked list created ask user what to do with it

	cout << "Welcome to the database of infectious diseases.  How would you like to browse the database?" << endl;
	cout << "1. View the whole database" << endl << "2. View all diseases in the database starting from a specified letter" << endl << "3. View all diseases in the database up to (not including) a specified letter" << endl<<"4. View all diseases in the database starting from a specified letter up to (not including) a specified letter" << endl;
	
	short selection;

	cin >> selection;

	char uLetter, uLetter2;
	char sanitized, sanitized2;
	string toString, toString2;
	stringstream ss, ss2;

	switch (selection)
	{
	case 1:
		traverse(root);
		break;
	case 2:
		cout << "What letter would you like to start with?" << endl;
			
		cin >> uLetter;
		sanitized=lowerToUpper(uLetter);
		
		//No diseases start with J or X so switch them to the next letter
		if (sanitized == 'J')
			sanitized = 'K';

		else if (sanitized == 'X')
			sanitized = 'Y';
		
		ss << sanitized;
		ss >> toString;
		traverseStartingFrom(root, toString);
		break;
	case 3:
		cout << "What letter would you like to stop on?" << endl;
		cin >> uLetter;
		sanitized=lowerToUpper(uLetter);

		if (sanitized == 'J')
			sanitized = 'K';

		else if (uLetter == 'X')
			sanitized = 'Y';

		ss << sanitized;
		ss >> toString;
		traverseUpTo(root, toString);
		break;
	case 4:
		cout << "What letter would you like to start with?" << endl; 
		cin >> uLetter;

		cout << "and what letter would you like to stop on ? " << endl;
		cin >> uLetter2;
		sanitized=lowerToUpper(uLetter);
		sanitized2=lowerToUpper(uLetter2);
		if (sanitized == 'J')
			sanitized = 'K';

		else if (sanitized == 'X')
			sanitized = 'Y';

		if (sanitized2 == 'J')
			sanitized2 = 'K';

		else if (sanitized2 == 'X')
			sanitized2 = 'Y';

		ss << sanitized;
		ss >> toString;

		ss2 << sanitized2;
		ss2 >> toString2;

		traverseFromUpTo(root, toString, toString2);

		break;

	default:

		cout << "Sorry that is all the functionality this program has at this time.  Please select one of the avilable options." << endl;

		break;
	}


	
	
	
	
	system("PAUSE");
	return 0;
}

char lowerToUpper(char ch1)
{
	char ch2;

	if (ch1 >= 'a' && ch1 <= 'z'){
		ch2 = ('A' + ch1 - 'a');
		return ch2;
	}
	else{
		ch2 = ch1;
		return ch2;
	}
}