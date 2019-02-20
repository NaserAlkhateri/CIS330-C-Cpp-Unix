//date.cpp
#include "cipher.hpp"
#include "date.hpp"
using namespace std;

DateCipher::DateCipher(int a[6]){
	m_date = a;
}

string
DateCipher::encrypt( string &inputText ) {
  string text = inputText;
  string::size_type len = text.length();


	int i,j,array2[100];
	int index = 0;
	
	//string text = inputText;
	string::size_type len = text.length();
	for (i = 0; i != len; ++i){
		if(text[i] == ' '){
			array2[i] = 0; // each space will be shifted by 0, so it stay the same
		}else if(text[i] >= 'a' && text[i] <= 'z'){
				if(index < 6){
					array2[i] = array[index];
					

					 for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'z'){
	                        text[i] = 'a';
	                     }
                	    else if ((text[i] + j) > 'z'){
	                         text[i] = text[i] - 25;
                	    }
	                else{
	                    text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}else{
				   
					index = 0;
					array2[i] = array[index];

					for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'z'){
	                        text[i] = 'a';
	                     }
                	    else if ((text[i] + j) > 'z'){
	                         text[i] = text[i] - 25;
                	    }
	                else{
	                    text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}
		}else if(text[i] >= 'A' && text[i] <= 'Z'){
		    	if(index < 6){
					array2[i] = array[index];

					for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'Z'){
	                        text[i] = 'A';
	                     }
                	    else if ((text[i] + j) > 'Z'){
	                         text[i] = text[i] - 25;
                	    }
	                     else{
	                         text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}else{
				   index=0;
					array2[i] = array[index];

										 for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'Z'){
	                        text[i] = 'A';
	                     }
                	    else if ((text[i] + j) > 'Z'){
	                         text[i] = text[i] - 25;
                	    }
	                else{
	                    text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}
		    
		    
		    }else{array2[i] = 0;}
		
	}
  
  
  
  return text;
  
}
string
DateCipher::decrypt( string &inputText ) {
  string text = inputText;
  string::size_type len = text.length();


	int i,j,array2[100];
	int index = 0;
	
	//string text = inputText;
	string::size_type len = text.length();
	for (i = 0; i != len; ++i){
		if(text[i] == ' '){
			array2[i] = 0; // each space will be shifted by 0, so it stay the same
		}else if(text[i] >= 'a' && text[i] <= 'z'){
				if(index < 6){
					array2[i] = array[index];
					

					 for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'z'){
	                        text[i] = 'a';
	                     }
                	    else if ((text[i] + j) > 'z'){
	                         text[i] = text[i] - 25;
                	    }
	                else{
	                    text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}else{
				   
					index = 0;
					array2[i] = array[index];

					for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'z'){
	                        text[i] = 'a';
	                     }
                	    else if ((text[i] + j) > 'z'){
	                         text[i] = text[i] - 25;
                	    }
	                else{
	                    text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}
		}else if(text[i] >= 'A' && text[i] <= 'Z'){
		    	if(index < 6){
					array2[i] = array[index];

					for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'Z'){
	                        text[i] = 'A';
	                     }
                	    else if ((text[i] + j) > 'Z'){
	                         text[i] = text[i] - 25;
                	    }
	                     else{
	                         text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}else{
				   index=0;
					array2[i] = array[index];

										 for (j = 0; j < array2[i]; ++j){
                    	if(array2[i] == 1 && text[i] == 'Z'){
	                        text[i] = 'A';
	                     }
                	    else if ((text[i] + j) > 'Z'){
	                         text[i] = text[i] - 25;
                	    }
	                else{
	                    text[i] = text[i] + 1;
            	    }
	
                    }
					index++;
				}
		    
		    
		    }else{array2[i] = 0;}
		
	}
  
  
  
  return text; 
}
