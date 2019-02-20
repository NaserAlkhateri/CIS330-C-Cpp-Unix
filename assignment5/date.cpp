//date.cpp
#include "cipher.hpp"
#include "date.hpp"
using namespace std;

DateCipher::DateCipher(int a[6]){
  //m_date = a;
  array = a;
}

string
DateCipher::encrypt( string &inputText ) {
  string text = inputText;
  string::size_type len = text.length();


  int i,j,array2[100];
  int index = 0;
	int curr = 0;

  for (i = 0; i != len; ++i){
    if(text[i] == ' '){
      array2[i] = 0; // each space will be shifted by 0, so it stay the same
    }else if(text[i] >= 'a' && text[i] <= 'z'){
      if(index < 6){
	array2[i] = array[index];
	index++;
      }else{
	
	index = 0;
	array2[i] = array[index];
	index++;
      }
    }else if(text[i] >= 'A' && text[i] <= 'Z'){
      if(index < 6){
	array2[i] = array[index];
	
	index++;
      }else{
	index=0;
	array2[i] = array[index];
	index++;
      }
      
      
    }else{array2[i] = 0;}
   

   
  }
  
  //shift
      for (i = 0; i != len; ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      for (j = 0; j < array2[i]; ++j){
	if(text[i] + 1 == '{'){
	  text[i] = 'a';  
	}
	else{
	  text[i] = text[i] + 1; 
	  
	}
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      for (j = 0; j < array2[i]; ++j){
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



  int i,j,array2[100];
  int index = 0;
	int curr = 0;

  for (i = 0; i != len; ++i){
    if(text[i] == ' '){
      array2[i] = 0; // each space will be shifted by 0, so it stay the same
    }else if(text[i] >= 'a' && text[i] <= 'z'){
      if(index < 6){
	array2[i] = array[index];
	index++;
      }else{
	
	index = 0;
	array2[i] = array[index];
	index++;
      }
    }else if(text[i] >= 'A' && text[i] <= 'Z'){
      if(index < 6){
	array2[i] = array[index];
	
	index++;
      }else{
	index=0;
	array2[i] = array[index];
	index++;
      }
      
      
    }else{array2[i] = 0;}
   

   
  }
  
  //shift
      for (i = 0; i != len; ++i) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      for (j = 0; j < array2[i]; ++j){
	if(text[i] - 1 == '`'){
	  text[i] = 'z';  
	}
	else{
	  text[i] = text[i] - 1; 
	  
	}
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      for (j = 0; j < array2[i]; ++j){
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
