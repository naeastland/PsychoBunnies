/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#include "Wrapper.h"

/*******************************************************
  Function:  Wrapper()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Wrapper constructor                               
  Input parameters: int ex                                  
  Returns: nothing                                        
********************************************************/ 
Wrapper::Wrapper(int ex)
{
	exit = ex;
}

/*******************************************************
  Function: Wrapper()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Wrapper object copy constructor                                
  Input parameters: Wrapper &copyObj                                  
  Returns: nothing                                        
********************************************************/ 
Wrapper::Wrapper(Wrapper &copyObj)
{
	exit = copyObj.exit;
}

/*******************************************************
  Function: ~Wrapper()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: Destructor                                
  Input parameters: none                                
  Returns: nothing                                        
********************************************************/ 
Wrapper::~Wrapper()
{
}

/*******************************************************
  Function: menu()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: menu funtion through which the user interfaces with
				the program, and the main function from which the code runs
  Input parameters: none                                  
  Returns: nothing                                        
********************************************************/ 
void Wrapper::menu()
{
	int option = 0;
	
	while(option != 3)
	{
		cout << "\nWelcome to the Cipher Meister" <<endl;
		cout << "1. Caeser Cipher" <<endl;
		cout << "2. Substitution Cipher"<<endl;
		cout << "3. Exit" <<endl;
		cout << "Enter an option" << endl;
		cin >> option;

		switch (option)
		{
			case 1://caesar shift
				this->caesar();
				break;
			case 2://substitutiion cipher
				this->sub();
				break;
			case 3:
				cout<< "Goodbye!" <<endl;
				exit = 1;
				break;
			default:
				cout << "Invalid entry. Please try again." << endl;
				break;
		}
	}
}

/*******************************************************
  Function: caesar()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function provides options for the user to select based
			upon the caeser cipher functionality. Prompting the user for a message,
			giving the options to encode, decode, or return to the main menu.
  Input parameters: none                                 
  Returns: nothing                                      
********************************************************/ 
void Wrapper::caesar()
{
	int option = 0, key = 0;
	string message;
	bool encrypt = false;

	getline(cin, message);
	cout << "Please enter a message: " << endl;
	getline(cin, message);

	CaesarCipher cc(message, encrypt);

	while(option != 3)
	{
		cout << "\nCaeser Cipher Menu" << endl;
		cout << "1. Encrypt" << endl;
		cout << "2. Decrypt" << endl;
		cout << "3. Return to Main Menu" << endl;

		cout << "Choose a menu option: " << endl;
		cin >> option;

		switch(option)
		{
			case 1:
				cout << "Please enter a key (an integer 1 through 25)" << endl;
				cin >> key;
				cc.encrypt(key);
				break;
			case 2:
				cout << "1. Use Key" << endl;
				cout << "2. Break without Key (this will display all possible shifts)" << endl;
				cin >> option;

				if(option == 1)
				{
					cout << "Please enter a key (an integer 1 through 25)" << endl;
					cin >> key;
					cc.decrypt(key);
				}
				else
				{
					cc.bruteDecrypt();
				}
				break;
			case 3:
				break;
			default: 
				cout << "Invalid entry. Please try again" << endl;
				break;
		}
	}
}

/*******************************************************
  Function:  sub()                
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: This function provides a menu for the user to interact
			with the substitution cipher aspect of the program. Providing
			encryption, decryption, and exit options.
  Input parameters: none                                  
  Returns: nothing                                         
********************************************************/ 
void Wrapper::sub()
{
	int option = 0, key = 0;
	string message;
	bool encrypt = false;

	getline(cin, message);
	cout << "Please enter a message: " << endl;
	getline(cin, message);

	SubCipher sc(message, encrypt);

	while(option != 3)
	{
		cout << "\nSubstitution Cipher Menu" << endl;
		cout << "1. Encrypt" << endl;
		cout << "2. Decrypt" << endl;
		cout << "3. Return to Main Menu" << endl;

		cout << "Choose a menu option: " << endl;
		cin >> option;

		switch(option)
		{
			case 1:
				encrypt = sc.substitute();
				
				if(encrypt)
				{
					cout << "\nEncryption successful" << endl;
				}
				else
				{
					cout << "Encryption failed" << endl;
				}
				break;
			case 2:
				if(sc.getStat())
				{
					cout << "This function will perform frequency analysis on the encoded message." << endl;
					cout << "Fair warning, there is a 99% chance this will be gibberish." << endl;
					sc.decrypt();
				}
				else
				{
					cout << "This option is not available" << endl;
				}					
				break;
			case 3:
				break;
			default: 
				cout << "Invalid entry. Please try again" << endl;
				break;
		}
	}
}

/*******************************************************
  Function: getExit()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description: getter for exit value                                
  Input parameters: none                                 
  Returns: int exit, determines continuation of the program                                        
********************************************************/ 
int Wrapper::getExit()
{
	return exit;
}

/*******************************************************
  Function: setExit()                 
  Date Created: 4/29/15                                          
  Date Last Modified: 4/29/15                                     
  Description:  setter for the exit value                                
  Input parameters: int newExit                                  
  Returns:  nothing                                       
********************************************************/ 
void Wrapper::setExit(int newExit)
{
	exit = newExit;
}
