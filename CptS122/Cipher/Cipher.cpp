/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#include "Cipher.h"

/*******************************************************
  Function: Cipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Default constructor                                
  Input parameters: none                                   
  Returns: nothing                                        
********************************************************/ 
Cipher::Cipher()
{
	message = "";
	stat = false;
}

/*******************************************************
  Function: Cipher()                  
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Constructor for Cipher object                                
  Input parameters: string message, bool stat                                  
  Returns: nothing                                         
********************************************************/ 
Cipher::Cipher(string message, bool stat):message(message), stat(stat)
{
}

/*******************************************************
  Function: ~Cipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Destructor                               
  Input parameters:  none                                 
  Returns: nothing                                        
********************************************************/ 
Cipher::~Cipher()
{
}

/*******************************************************
  Function: Cipher()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Copy constructor                                
  Input parameters: Cipher &copyObj                                    
  Returns: nothing                                       
********************************************************/ 
Cipher::Cipher(Cipher &copyObj)
{
	this->stat = copyObj.stat;
	this->message = copyObj.message;
}

/*******************************************************
  Function: getMessage()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: getter                                
  Input parameters: none                                  
  Returns: string message                                         
********************************************************/ 
string Cipher::getMessage()
{
	return message;
}

/*******************************************************
  Function: getStat()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: getter                                
  Input parameters: none                                  
  Returns: bool stat                                       
********************************************************/ 
bool Cipher::getStat()
{
	return stat;
}

/*******************************************************
  Function: setMessage()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: setter for Cipher object message                               
  Input parameters: string newMessage                                 
  Returns:  nothing                                       
********************************************************/ 
void Cipher::setMessage(string newMessage)
{
	message = newMessage;
}

/*******************************************************
  Function:  setStatus()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: setter for Cipher object's status                                
  Input parameters: bool newStat                                  
  Returns: nothing                                       
********************************************************/ 
void Cipher::setStatus(bool newStat)
{
	stat = newStat;
}
