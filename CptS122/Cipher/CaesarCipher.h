/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#ifndef CaesarCipher_H
#define CasarCipher_H

#include "Cipher.h"

class CaesarCipher : public Cipher
{
public:
	CaesarCipher(string message, bool stat);
	CaesarCipher(CaesarCipher &copyObj);
	~CaesarCipher();

	bool decrypt(int key);
	bool bruteDecrypt();
	bool encrypt(int key);
	void caeserShift(int key);
private:
	int key;
};

#endif
