//date.hpp
#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
    DateCipher(int a[6]); // constructor

	// Default destructor 
    
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	int m_date[6];

};

#endif /* CAESAR_HPP_ */