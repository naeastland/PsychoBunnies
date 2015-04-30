/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#ifndef Wrapper_H
#define Wrapper_H

#include "CaesarCipher.h"
#include "SubCipher.h"
#include <time.h>

class Wrapper
{
public:
	Wrapper(int ex);
	Wrapper(Wrapper &copyObj);
	~Wrapper();

	void menu();
	void caesar();
	void sub();

	int getExit();
	
	void setExit(int newExit);

private:
	int exit;
};

#endif
