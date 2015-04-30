/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#ifndef SubCipher_H
#define SubCipher_H

#include "Cipher.h"

class SubCipher : public Cipher
{
public:
	SubCipher(string message, bool stat);
	~SubCipher();
	SubCipher(SubCipher &copyObj);

	bool substitute();
	bool decrypt();


private:
	string key;
};

#endif
