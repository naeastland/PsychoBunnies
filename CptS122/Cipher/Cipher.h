/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: PA 7
Date: 4/29/15
Description: This is a Cipher program. It allows you to encrypt a message via 
			a shift or substitution cipher, and provides solutions for decryption.
*************************************************************/

#ifndef Cipher_H
#define Cipher_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Cipher
{
public:
	Cipher();
	Cipher(string message, bool stat);
	~Cipher(); 
	Cipher(Cipher &copyObj);

	string getMessage();
	bool getStat();

	void setMessage(string newMessage);
	void setStatus(bool newStat);

protected:
	string message;
	bool stat;
};

#endif
