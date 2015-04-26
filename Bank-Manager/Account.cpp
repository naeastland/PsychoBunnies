/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: 
Date: 2-8-2015
Description: This program simulates a bank account management program.
*************************************************************/

#include "Account.h"


/*******************************************************
  Function: Account()                  
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: A default constructor for an Account object, sets all
				fields in the object to their null values.
  Input parameters: None                                    
  Returns: Nothing                                          
********************************************************/  
Account::Account()
{
	this->acctBal = 0.0;
	this->acctNum = 0;
	this->custName = '\0';
	this->dateOpened = '\0';
	this->mpNext = NULL;
}


/*******************************************************
  Function: Account()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Constructor for a new Account object. If a value for the initial
				balance is < 0, an error message is displayed and the starting 
				balance is set to 0.
  Input parameters: double newBal - initial balance given to account
					int newNum - randomly generated number for new account
					string newCust - name of customer for account
					string newDate - input date for the account creation                                 
  Returns: Nothing                                         
********************************************************/  
Account::Account(double newBal, int newNum, string newCust, string newDate)
{
	if(newBal < 0)
	{
		cout << "Invalid initial balance. Balance set to 0." << endl;
		this->acctBal = 0;
	}
	else
	{
		this->acctBal = newBal;
	}

	this->acctNum = newNum;

	this->custName = newCust;

	this->dateOpened = newDate;

	this->mpNext = NULL;
}


/*******************************************************
  Function: Account()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Copy constructor.....not sure why I have this here.                                 
  Input parameters: Account &copyObject                                    
  Returns: Nothing                                         
********************************************************/  
Account::Account(Account &copyObject)
{
	this->acctBal = copyObject.acctBal;
	this->acctNum = copyObject.acctNum;
	this->custName = copyObject.custName;
	this->dateOpened = copyObject.dateOpened;
}


/*******************************************************
  Function: getBal() const                    
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: retrieves account balance                                  
  Input parameters:  none                                  
  Returns: nothing                                         
********************************************************/  
double Account::getBal() const
{
	return this->acctBal;
}


/*******************************************************
  Function: getAcctNum() const                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: retrieves account number                                   
  Input parameters: none                                   
  Returns: nothing                                        
********************************************************/  
int Account::getAcctNum() const
{
	return this->acctNum;
}


/*******************************************************
  Function: getCust() const                 
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: retrieves the customer name                                  
  Input parameters: none                                   
  Returns: nothing                                         
********************************************************/  
string Account::getCust() const
{
	return this->custName;
}


/*******************************************************
  Function: getAcctDate() const                  
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: retrieves the open date for the account                                  
  Input parameters: none                                   
  Returns: nothing                                        
********************************************************/  
string Account::getAcctDate() const
{
	return this->dateOpened;
}


/*******************************************************
  Function: getNext() const                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: retrieves the pointer for the next member object in the list.                                  
  Input parameters: none                                   
  Returns: nothing                                         
********************************************************/  
Account *Account::getNext() const
{
	return this->mpNext;
}


/*******************************************************
  Function: setBal()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: sets a new value for the account balance                                  
  Input parameters:double newBal - the new balance of the account                                  
  Returns: nothing                                         
********************************************************/  
void Account::setBal(double newBal)
{
	this->acctBal = newBal;
}


/*******************************************************
  Function: setAcctNum()                    
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: sets the account number to a new value                                   
  Input parameters: int newNum - the new account number for the account                                   
  Returns: nothing                                         
********************************************************/  
void Account::setAcctNum(int newNum)
{
	this->acctNum = newNum;
}


/*******************************************************
  Function: setCustName()                    
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: sets the name of the customer on an account                                   
  Input parameters: string newName - the new name to be assigned to the account                                   
  Returns: nothing                                        
********************************************************/  
void Account::setCustName(string newName)
{
	this->custName = newName;
}


/*******************************************************
  Function: setAcctDate()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: sets a new account creation date                                 
  Input parameters: string newDate - the new creation date of an account                                    
  Returns: nothing                                         
********************************************************/  
void Account::setAcctDate(string newDate)
{
	this->dateOpened = newDate;
}
