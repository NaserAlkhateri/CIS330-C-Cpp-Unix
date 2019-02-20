//date.cpp
#include "cipher.hpp"
#include "date.hpp"
using namespace std;

DateCipher::DateCipher(int a[6],int b[100]){

  m_numbers = a;
  m_shift=b;
}

string
DateCipher::encrypt( string &inputText ) {
  string text = inputText;
  string::size_type len = text.length();


  int i,j;
  
  //shift
      for (i = 0; i != len; ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      for (j = 0; j < m_shift[i]; ++j){
	if(text[i] + 1 == '{'){
	  text[i] = 'a';  
	}
	else{
	  text[i] = text[i] + 1; 
	  
	}
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      for (j = 0; j < m_shift[i]; ++j){
	if(text[i] + 1 == '['){
	  text[i] = 'A';
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
DateCipher::decrypt( string &inputText ) {
  string text = inputText;
  string::size_type len = text.length();



  int i,j;
  //shift
      for (i = 0; i != len; ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      for (j = 0; j < m_shift[i]; ++j){
	if(text[i] - 1 == '`'){
	  text[i] = 'z';  
	}
	else{
	  text[i] = text[i] - 1; 
	  
	}
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      for (j = 0; j < m_shift[i]; ++j){
	if(text[i] - 1 == '@'){
	  text[i] = 'Z';
	}
	else{
	  text[i] = text[i] - 1;
	}
	
      }
    }
    
  }
  
  return text; 
}
