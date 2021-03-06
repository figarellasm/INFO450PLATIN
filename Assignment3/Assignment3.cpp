// Assignment3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//initialize functions
int translateToPigLatin(char* buffer);
bool isVowel(char c);
bool isDigit(char c);
bool isArticle(char* buffer);
bool isConjunction(char* buffer);


int main()
{
	char buffer[50];//initialize input cstring

	bool done = false;


	while (!done)
	{
		cout << "Choose one: " << endl;
		cout << "\t 1.) Enter a word to translate." << endl;
		cout << "\t 2.) Quit." << endl;//presents user options

		cin.getline(buffer, 50);

		if (strcmp(buffer, "1") == 0)
		{
			cout << "Please enter a word: " << endl;//prompts user for input
			cin.getline(buffer, 50);

			translateToPigLatin(buffer);
			cout << "Your word in Pig Latin is: " << buffer << endl;//displays output in piglatin
		}
		else if (strcmp(buffer, "2") == 0)

		{
			done = true;
		}
		else
		{
			cout << "Invalid choice, try again." << endl;//output when user enters something other than a 1 or 2
		}

	}


    return 0;
}

int translateToPigLatin(char* buffer)
{
	int r = 0;
	
	if (strlen(buffer) == 2 || isConjunction(buffer) || isArticle(buffer))
	{
		return r;//do nothing if input is equal to 2 letters, a conjunction, or article
	}
	else if (isVowel(buffer[0]))
	{
		int i;

		for (i = 0; i < 50; i++)
			if (buffer[i] == '\0')
				break;//break for loop after locating the null

		buffer[i] = 'a'; //assign a to null
		i++;
		buffer[i] = 'y'; //assign y to spot after null
		i++;
		buffer[i] = '\0'; //assign new null
	}
	else if(!isdigit(buffer[0]))
	{
		int i;
		char t = buffer[0];
		for (i = 1; i < 50; i++)
		{
			buffer[i - 1] = buffer[i];

			if (buffer[i] == '\0')//variable i is now placed at the null
				break;
		}

		buffer[i - 1] = t;//placed temporary variable t to the left of the null, recall: i is at the null
		buffer[i] = 'a';//placed a at the null
		buffer[i + 1] = 'y';//placed y to the right of the null
		buffer[i + 2] = '\0';//new null location
	}
	else
	{
		r = -1;//returns a -1 if input value is invalid
	}

	return r;
}

bool isVowel(char c) //function that checks input for vowel 
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isDigit(char c) //function that checks input for digit
{
	return c >= 0x30 && c <= 0x39;
}

bool isArticle(char* buffer) //function that checks for article
{


	if (strcmp(buffer, "the") == 0 || strcmp(buffer, "a") == 0 || strcmp(buffer, "an")==0)
	{
		return true;
	}

	return false;
}

bool isConjunction(char* buffer) //function that checks for conjunction
{

	if (strcmp(buffer, "and") == 0 || strcmp(buffer, "but") == 0 || strcmp(buffer, "for") == 0 || strcmp(buffer, "nor") == 0 ||
		strcmp(buffer, "so") == 0 || strcmp(buffer, "yet") == 0 || strcmp(buffer, "or") == 0)
	{

		return true;
	}

	return false;

}