//date.hpp
#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
    DateCipher(int a[6], int b[100]); // constructor

	// Default destructor 
    
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:

	int *m_numbers;
	int *m_shift;
};

#endif /* CAESAR_HPP_ */