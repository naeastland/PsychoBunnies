/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#include "CaesarCipher.h"

/*******************************************************
  Function:  CaesarCipher()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Constructor                               
  Input parameters: string message, bool stat                                  
  Returns: nada                                        
********************************************************/ 
CaesarCipher::CaesarCipher(string message, bool stat) : Cipher(message, stat)
{
}

/*******************************************************
  Function: CaesarCipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Copy Constructor                                
  Input parameters: CaesarCipher &copyObj                                  
  Returns: nothing                                         
********************************************************/ 
CaesarCipher::CaesarCipher(CaesarCipher &copyObj)
{
	key = copyObj.key;
	this->stat = copyObj.stat;
	this->message = copyObj.message;
}

/*******************************************************
  Function: ~CaesarCipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Destructor                                
  Input parameters: nothing                                 
  Returns:  nothing                                       
********************************************************/ 
CaesarCipher::~CaesarCipher()
{
}

/*******************************************************
  Function: decrypt()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function decrypts a message with a key                                
  Input parameters: int key                                  
  Returns: bool value, indicating success or failure                                        
********************************************************/ 
bool CaesarCipher::decrypt(int key)
{
	if(this->key == key && Cipher::stat && Cipher::message.length() > 0)
	{
		caeserShift(-key);
		Cipher::stat = false;

		return true;
	}

	return false;
}

/*******************************************************
  Function: bruteDecrypt()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function attempts a brute force decryption of
			a shifted message. Outputs all possible shift key results.
  Input parameters: none                                  
  Returns: nothing                                        
********************************************************/ 
bool CaesarCipher::bruteDecrypt()
{
	int i;
	string base;

	if(Cipher::stat && Cipher::message.length() > 0 )
	{
		cout << "All possible shift keys:" << endl;

		for(i = 1; i < 26; i++)
		{
			cout << i << ". ";
			base =  message;

			CaesarCipher cc(base, true);

			cc.caeserShift(-i);

			cout << endl;
		}

		Cipher::stat = false;

		return true;
	}

	return false;
}

/*******************************************************
  Function: encrypt()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function calls an encryption function 
			to encrypt a message by shifting with a key                                
  Input parameters:  int key                                 
  Returns: boolean value indicating success or failure                                        
********************************************************/ 
bool CaesarCipher::encrypt(int key)
{
	if(!Cipher::stat && Cipher::message.length() > 0)
	{
		caeserShift(key);
		Cipher::stat = true;
		this->key = key;
		return true;
	}

	return false;
}

/*******************************************************
  Function: caeserShift()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function performs the caeser shift encryption on
			the message input by the user.
  Input parameters:  int key                                 
  Returns: nothing                                        
********************************************************/ 
void CaesarCipher::caeserShift(int key)
{
	int size = 0, i = 0, j = 0, index = 0;
	char* temp;
	char array[26];

	for(int i = 0, j = 65; i < 26; i++, j++)
	{
		array[i] = char(j);
	}

	size = (int)Cipher::message.length();
	
	for(i = 0; i < size; i++)
	{
		if(isalpha(message[i]))
		{
			index = toupper(message[i]) - 65 + key;

			while(index < 0)
			{
				index = index + 26;
			}
			message[i] = array[index % 26];
		}
	}
	
	cout << Cipher::message;
}
