//testDate.cpp


#include <iostream>
#include <string>
#include "date.hpp"
#include "ioutils.hpp"
using namespace std;


int main(int argc, const char *argv[]){
	
	string name = "12/18/46";
    int array[6] = {name[0]-48,name[1]-48,name[3]-48,name[4]-48,name[6]-48,name[7]-48};
    cout << name << endl;
	IOUtils io;
	io.openStream(argc,argv);
	string input, encrypted, decrypted;
	input = io.readFromStream();
	cout << "Original text:" << endl << input;
	
	DateCipher ci(array);
	//ci.array = array;
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