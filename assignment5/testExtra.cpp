//testExtra.cpp

#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "rot13cipher.hpp"


int main(int argc, const char *argv[]) {

	//this is a copy of rot13, but takes encrypted text to decrypt
	//from the user

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Encrypted text:" << std::endl << input;

	Rot13Cipher rot13;

	//only decrypts
	decrypted = rot13.decrypt(input);
	std::cout << "Decrypted text:" << std::endl << decrypted;

	return 0;
}
