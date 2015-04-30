/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#include "SubCipher.h"

/*******************************************************
  Function: SubCipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Constructor for SubCipher                     
  Input parameters: string message, bool stat                                  
  Returns: nothing                                        
********************************************************/ 
SubCipher::SubCipher(string message, bool stat) : Cipher(message, stat)
{
}

/*******************************************************
  Function: ~SubCipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Destructor                                
  Input parameters:  none                                 
  Returns: nothing                               
********************************************************/ 
SubCipher::~SubCipher()
{
}

/*******************************************************
  Function:  SubCipher()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Copy constructor                                
  Input parameters: SubCipher &copyObj                                  
  Returns: nothing                                        
********************************************************/ 
SubCipher::SubCipher(SubCipher &copyObj)
{
	key = copyObj.key;
	this->stat = copyObj.stat;
	this->message = copyObj.message;
}

/*******************************************************
  Function: substitute()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function generates a random substitution key
			for encrypting the input message.
  Input parameters: none                                  
  Returns: bool value indicating success or failure                                      
********************************************************/ 
bool SubCipher::substitute()
{
	int option = 0, num = 0, i = 0, size = 0, index = 0;
	char base[26], key[26], temp = '\0';
	bool encrypt = false;

	for(i = 0; i < 26; i++)
	{
		base[i] = i + 65;
	}

	for(; i > 0; i--)
	{
		num = rand() % i;
		key[i-1] = base[num];

		base[num] = '-';
		temp = base[i-1];
		base[i-1] = base[num];
		base[num] = temp;
	}

	size = (int)Cipher::message.length();

	for(i = 0; i < size; i++)
	{
		if(isalpha(message[i]))
		{
			message[i] = toupper(message[i]);

			index = message[i] - 65;

			message[i] = key[index];
		}
	}

	cout << endl;

	for(i = 0; i < size; i++)
	{
		cout << message[i];
	}

	Cipher::stat = true;

	return true;
}

/*******************************************************
  Function: decrypt()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function executes a frequency analysis of the 
				encrypted message and attempts to decrypt it based on the
				determined frequencies.
  Input parameters: none                                  
  Returns: bool value indicating success or failure                                        
********************************************************/ 
bool SubCipher::decrypt()
{
	char base[26],
		stdFreq[] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'C', 'U',
		'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'};
	int i = 0, j = 0, index = 0, size = 0, freq[26], map[26];
	double freqRank[26] = {12.7, 9.1, 8.2, 7.5, 7.0, 6.7, 6.3, 6.1, 6.0, 4.3, 4.0, 2.8, 2.8, 2.4, 2.4,
		2.2, 2.0, 2.0, 1.9, 1.5, 1.0, 0.8, 0.15, 0.15, 0.10, 0.07};

	for(i = 0; i < 26; i++)
	{
		base[i] = i + 65;
		freq[i] = 0;
		map[i] = 0;
	}

	size = (int)Cipher::message.length();

	for(i = 0; i < size; i++)
	{
		index = message[i] - 65;

		freq[index] += 1;
	}

	cout << "Frequency in message:           Standard Frequency:  " << endl;

	for(i = 0; i < 26; i++)
	{
		cout << base[i] << " " << freq[i] << "                             ";
		cout << stdFreq[i] << " " << setprecision(4) << freqRank[i] << endl;
	}

	//this implementation is limiting, only being able to recognize 25 occurences
	//also, I have no clue what I was doing here
	for(index = 0, i = 0; index < 26 && i < 26; index++)
	{
		for(j = 0; j < 26; j++)
		{
			if(freq[j] == index)
			{
				map[(25 - i)] = j;
				i++;
			}
		}
	}

	for(index = 0; index < size; index++)
	{
		if(isalpha(message[index]))
		{
			message[index] = (map[(message[index] - 65)] + 65);
		}		
	}

	cout << "Program's guess: " << endl;

	cout << message << endl;

	Cipher::stat = false;
	return true;
}
