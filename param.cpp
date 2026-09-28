/**
 *  param.h
 *  
 *  Thomas Reichherzer
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */
#include <iostream>
#include <cstring>
#include "param.hpp"
using namespace std;

// The Param object stores the shell command metadata that is later used by the
// process layer. It tracks the executable, arguments, redirect targets, and
// whether the command should run in the background.
Param::Param() 
{
	inputRedirect = outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
}

// Release the dynamically allocated redirect filenames owned by this object.
Param::~Param()
{
	delete[] inputRedirect;
	delete[] outputRedirect;
}

// Store a borrowed argument pointer unless the input is NULL or the list is full.
void Param::addArgument (char* newArgument)
{
	if (newArgument == NULL || argumentCount >= MAXARGS)
		return;

	argumentVector[argumentCount] = newArgument;
	argumentCount++;
}

// Return a caller-owned copy of the argument pointers with a NULL terminator.
char** Param::getArguments()
{
	char **arguments = new char*[argumentCount + 1];

	for (int i = 0; i < argumentCount; i++)
		arguments[i] = argumentVector[i];

	arguments[argumentCount] = NULL;
	return arguments;
}

// Replace the input filename with an owned copy of the supplied string.
// It is made like this to avoid memory leaks when the input redirect is changed multiple times.
void Param::setInputRedirect(char *newInputRedirect)
{
	delete[] inputRedirect;
	inputRedirect = NULL;

	if (newInputRedirect != NULL)
	{
		inputRedirect = new char[strlen(newInputRedirect) + 1];
		strcpy(inputRedirect, newInputRedirect);
	}
}

// Replace the output filename with an owned copy of the supplied string.
// It is made like this to avoid memory leaks when the output redirect is changed multiple times.
void Param::setOutputRedirect(char *newOutputRedirect)
{
	delete[] outputRedirect;
	outputRedirect = NULL;

	if (newOutputRedirect != NULL)
	{
		outputRedirect = new char[strlen(newOutputRedirect) + 1];
		strcpy(outputRedirect, newOutputRedirect);
	}
}
		
void Param::setBackground(int newBackground)
{
	background = newBackground;
}

char* Param::getInputRedirect()
{
	return inputRedirect;
}
		
		
char* Param::getOutputRedirect()
{
	return outputRedirect;
}
		
int Param::getBackground()
{
	return background;
}


void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != NULL ? inputRedirect : "NULL");
	cout << "]" 
	     << endl 
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != NULL ? outputRedirect : "NULL");
	cout << "]" 
	     << endl 
		 << "Background: [" 
		 << background 
		 << "]" 
		 << endl 
		 << "ArgumentCount: [" 
		 << argumentCount 
		 << "]" 
		 << endl;
	for (int i = 0; i < argumentCount; i++)
		cout << "ArgumentVector[" 
			 << i 
			 << "]: [" 
			 << argumentVector[i] 
			 << "]" 
			 << endl;
}
