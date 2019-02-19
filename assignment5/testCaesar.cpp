//testCaeser.cpp

#include <iostream>
#include <string>
#include "caesar.hpp"
#include "ioutils.hpp"
using namespace std;


int main(int argc, const char *argv[]){
	
	
	IOUtils io;
	io.openStream(argc,argv);
	string input, encrypted, decrypted;
	input = io.readFromStream();
	cout << "Original text:" << endl << input;
	
	CaesarCipher ci;
	encrypted = ci.encrypt(input);
	cout << "Encrypted text:" << endl << encrypted;
	decrypted = ci.decrypt(encrypted);
	cout << "Decrypted text:" << endl << decrypted;
	if (decrypted == input) cout << "Decrypted text matches input!" << endl;
	else {
		cout << "Oops! Decrypted text doesn't match input!" << endl;
		return 1;   // Make sure to return a non-zero value to indicate failure
	}
	
	return 0;
}