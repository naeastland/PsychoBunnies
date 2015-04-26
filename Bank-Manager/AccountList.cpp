/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: 
Date: 2-8-2015
Description: This program simulates a bank account management program.
*************************************************************/

#include "AccountList.h"

/*******************************************************
  Function: AccountList()                    
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Default constructor for an AccountList object, setting
				the pointer's initial value to NULL.
  Input parameters: None                                   
  Returns: Nothing                                        
********************************************************/  
AccountList::AccountList()
{
	this->pHead = NULL;
}


/*******************************************************
  Function: ~AccountList()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Um.....it's supposed to deconstruct things....
				but at the moment....
  Input parameters: None                                   
  Returns: Nothing                                        
********************************************************/  
AccountList::~AccountList()
{
	//iunnno...
}


/*******************************************************
  Function: ostream & operator << ()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Operator overloading function for the insertion operator.                                  
  Input parameters: ostream &lhs - the output data stream
					AccountList &rhs - an AccountList object to be inserted into 
						the output stream
  Returns: lhs ostream object                                         
********************************************************/  
ostream & operator << (ostream &lhs, AccountList &rhs)
{
	Account *pCur = rhs.pHead;

	while(pCur != NULL)
	{
		lhs << pCur->acctNum << endl;
		lhs << pCur->custName << endl;
		lhs << pCur->acctBal << endl;
		lhs << pCur->dateOpened << endl;

		pCur = pCur->mpNext;
	}
	
	return lhs;
}


/*******************************************************
  Function: makeNode()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Makes a node, an Account object, that will be passed to
				an AccountList object
  Input parameters: double balance - initial balance for account
					int number - generated account number
					string name - name on the account
					string date - input date of account creation              
  Returns:                                          
********************************************************/  
Account *AccountList::makeNode (double balance, int number, string name, string date)
{
	Account *pMem = NULL;

	pMem = new Account (balance, number, name, date);

	return pMem;
}


/*******************************************************
  Function: insertOrder()                    
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: This funciton takes in the fields required for creating an
				Account object. The function creates a new node from this data
				and inserts it into the list in alphabetical order.
  Input parameters: double balance - initial balance for account
					int number - generated account number
					string name - name on the account
					string date - input date of account creation                                   
  Returns: bool success - returns true if the memory for the new node was 
			successfully allocated.
********************************************************/  
bool AccountList::insertOrder(double balance, int number, string name, string date)
{
	Account *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	bool success = false;

	pMem = makeNode(balance, number, name, date);

	if(pMem != NULL)
	{
		success = true;

		if(pHead == NULL)
		{
			pHead = pMem;
		}
		else
		{
			pCur = pHead;

			//sorts in order of customer name by default
			while((pCur != NULL) && (pCur->custName < name))
			{
				pPrev = pCur;
				pCur = pCur->mpNext;
			}

			if(pPrev != NULL)//not at front of list
			{
				pPrev->mpNext = pMem;
				pMem->mpNext = pCur;
			}
			else
			{
				pMem->mpNext = pCur;
				pHead = pMem;
			}
		}
	}

	return success;
}



/*******************************************************
  Function: deleteAcct()                  
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: This function deletes an account from the list based on
				an integer input indicating its position.
  Input parameters: int pos
  Precondition: The list is not empty
  Returns: bool success - returns true if the specified account was
			found and deleted.
********************************************************/  
bool AccountList::deleteAcct(int pos)
{
	Account *pCur = NULL, *pPrev = NULL;
	int index = 1;
	bool success = false;

	pCur = this->pHead;

	while((pCur != NULL) && (index < pos))
	{
		pPrev = pCur;
		pCur = pCur->mpNext;

		index++;
	}

	if(pCur != NULL)
	{
		//deleting from front of the list
		if(pPrev == NULL)
		{
			pHead = pCur->mpNext;
		}
		else
		{
			pPrev->mpNext = pCur->mpNext;
		}

		delete pCur;

		success = true;
	}
	else
	{
		cout << "Item not found." << endl;
	}

	return success;
}


/*******************************************************
  Function: credit()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: This function adds an amount to the balance of an Account.                                   
  Input parameters: double addBal - amount to be added to balance.                                 
  Returns: Nothing                   
********************************************************/  
void AccountList::credit(double addBal)
{
	double temp = 0.0;

	temp = this->pHead->acctBal + addBal;

	this->pHead->setBal(temp);
}


/*******************************************************
  Function: debit()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: This function deducts an amount from the balance of an
				Account. If the amount passed in exceeds the current balance
				in the account, an error message is returned.
  Input parameters: double subBal - the amount to be deducted.                                   
  Returns: Nothing                                         
********************************************************/  
void AccountList::debit(double subBal)
{
	double temp = 0.0;

	if(this->pHead->acctBal >= subBal)
	{
		temp = this->pHead->acctBal - subBal;

		this->pHead->setBal(temp);
	}
	else
	{
		cout << "Cannot withdraw that amount." << endl;
	}
}


/*******************************************************
  Function: printAcctInfo()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Prints out the information contained in the Account 
				object passed to it.
  Input parameters: Account *Node - address of the account                                    
  Returns: Nothing                                         
********************************************************/  
void AccountList::printAcctInfo(Account *Node)
{
	cout << "Account number: " << Node->getAcctNum() << endl;
	cout << "Customer Name: " << Node->getCust() << endl;
	cout << "Current balance: " << Node->getBal() << endl;
	cout << "Date opened: " << Node->getAcctDate() << endl;
}


/*******************************************************
  Function: getPointer()                    
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Retrieves the pHead address of the AccountList                                 
  Input parameters: None                                    
  Returns: Nothing                                         
********************************************************/  
Account* AccountList::getPointer()
{
	return this->pHead;
}


/*******************************************************
  Function: printAll()                   
  Date Created: 2-8-2015                                            
  Date Last Modified: 2-8-2015                                      
  Description: Prints the data contained in each account held in
				the AccountList object begining from the address passed to it.
  Input parameters: Account *Node - the address of an Account object
					(should be the front of the linked list in this implimentation)
  Returns: Nothing                                       
********************************************************/  
void AccountList::printAll(Account *Node)
{
	Account *temp;

	temp = Node;
	
	while(temp)
	{
		putchar('\n');
		cout << "Account number: " << temp->getAcctNum() << endl;
		cout << "Customer Name: " << temp->getCust() << endl;
		cout << "Current balance: " << temp->getBal() << endl;
		cout << "Date opened: " << temp->getAcctDate() << endl;

		temp = temp->mpNext;
	}
}
