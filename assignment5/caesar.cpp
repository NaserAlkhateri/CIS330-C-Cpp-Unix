//caesar.cpp
#include "cipher.hpp"
#include "caesar.hpp"

using namespace std;

CaesarCipher::CaesarCipher(int x) : Cipher() {
  m_key = x;
}

string
CaesarCipher::encrypt( string &inputText ) {
	
  string text = inputText;
  string::size_type len = text.length();

  int j, i;
  /*
    Here a loop will iterate through the text and shift 
    by the number given by the user in order to encrypt.
  */
  for (i = 0; i != len; ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      for (int j = 1; j <= m_key; ++j){
	if(text[i] == ' '){//if it was after z, the ' ' space, go to a.
	  text[i] = 'a';
	}
	else if(text[i] + 1 == '{'){//when the next shift is after z, make it ' '
	  text[i] = ' ';  
	}
	else{
	  text[i] = text[i] + 1; //keeps shifting by the number of times given.
	  
	}
      }
    }
	//same as the above but no space after Z.
    if (text[i] >= 'A' && text[i] <= 'Z') {
      for (j = 0; j < m_key; ++j){
	if(m_key == 1 && text[i] == 'Z'){
	  text[i] = 'A';
	}
	else if ((text[i] + j) > 'Z'){
	  text[i] = text[i] - 25;
	}
	else{
	  text[i] = text[i] + 1;
	}
	
      }
    }
    
  }
  return text;
}

string
CaesarCipher::decrypt( string &inputText ) {

  string text = inputText;
  string::size_type len = text.length();
  int i,j;
  //same logic in encrypt but shifting the other way
  for (i = 0; i != len; ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      for (int j = 1; j <= m_key; ++j){
        if(text[i] == ' '){
          text[i] = 'z';
        }
        else if(text[i] - 1 == '`'){
          text[i] = ' ';
        }
        else{
          text[i] = text[i] - 1;

        }
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      for (j = 0; j < m_key; ++j){
        if(m_key == 1 && text[i] == 'Z'){
          text[i] = 'A';
        }
        else if ((text[i] - j) < 'A'){
          text[i] = text[i] + 25;
        }
        else{
          text[i] = text[i] - 1;
        }

      }
    }
  }
  return text;
}
