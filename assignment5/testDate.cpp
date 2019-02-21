//testDate.cpp

//testDate.cpp
#include <iostream>
#include <string>
#include "date.hpp"
#include "ioutils.hpp"
using namespace std;


int main(int argc, const char *argv[]){
  
  string name = "12/18/46";
  int m_numbers[6] = {name[0]-48,name[1]-48,name[3]-48,name[4]-48,name[6]-48,name[7]-48};
  int i,j,m_shift[100];
  int index = 0;
  cout << name << endl;
  IOUtils io;
  io.openStream(argc,argv);
  string input, encrypted, decrypted;
  input = io.readFromStream();
  cout << "Original text:" << endl << input;
  //this part makes an array for ints, for each letter in text
  //a number based on the date will be placed accordingly
  //this array will then be used to encrypt or decrypt 
  string::size_type len = input.length();
  for (i = 0; i != len; ++i){
    if(input[i] == ' '){
      m_shift[i] = 0;
    }else if(input[i] >= 'a' && input[i] <= 'z'){
      if(index == 6){//when index reachs 6, reset back to zero, so it begin with the first index in the array
	//because it needs to stay between (0-5)
	index = 0;
	m_shift[i] = m_numbers[index];
	index++;
      }else{
	
	
	m_shift[i] = m_numbers[index];
	index++;
      }
    }else if(input[i] >= 'A' && input[i] <= 'Z'){
      if(index == 6){
	index = 0;
	m_shift[i] = m_numbers[index];
	
	index++;
      }else{
	
	m_shift[i] = m_numbers[index];
	index++;
      }
      
      
    }else{m_shift[i] = 0;}//non alphabets will be shifted by 0 so they dont change,(if shifted) 
  }
  //prints out the numbers
  for(i=0;i<len;i++){
    if(m_shift[i] == 0)
      cout << " ";
    else
      cout<<m_shift[i];
  }
  cout<<endl;
  DateCipher ci(m_numbers,m_shift);//both number date array and the array that will be used to shift
  //will be initialized in the constructor.
	
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
