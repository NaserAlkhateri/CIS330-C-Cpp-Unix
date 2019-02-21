//testCaeser.cpp

#include <iostream>
#include <string>
#include "caesar.hpp"
#include "ioutils.hpp"
using namespace std;


int main(int argc, const char *argv[]){
	
  int num;
  cout << "Please enter the Caesar shift parameter (positive integer number): ";
  cin >> num;
  //makes sure its positive.
  while(num<0){
    cout << "Please enter the Caesar shift parameter (positive integer number): ";
    cin >> num;
  }
  //will result in a number between 0-26 that result in the same output of the
  //given number
  num = num % 26;
  IOUtils io;
  io.openStream(argc,argv);
  string input, encrypted, decrypted;
  input = io.readFromStream();
  cout << "Original text:" << endl << input;
  //saves the number in the constructor
  CaesarCipher ci(num);
  //the string variable is sent to be encrypted
  encrypted = ci.encrypt(input);
  cout << "Encrypted text:" << endl << encrypted;
  decrypted = ci.decrypt(encrypted);
  cout << "Decrypted text:" << endl << decrypted;
  //checks if decrypted matched the original
  if (decrypted == input) cout << "Decrypted text matches input!" << endl;
  else {
    cout << "Oops! Decrypted text doesn't match input!" << endl;
    return 1;   // Make sure to return a non-zero value to indicate failure
  }
  
  return 0;
}
