/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#include "Wrapper.h"


int main()
{
	srand(time(0));

	Wrapper w(0);

	while(!w.getExit())
	{
		w.menu();
	}

	return 0;
}
