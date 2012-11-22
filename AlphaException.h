/*
 * AlphaException.h
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#ifndef ALPHAEXCEPTION_H_
#define ALPHAEXCEPTION_H_

#include <exception>
#include <string>

//TODO: Create true heirarchy
class AlphaException : public std::exception
{
private:
	std::string data;
public:
	AlphaException(const std::string& data);
	virtual ~AlphaException();

	virtual const char* what() override;
};

#endif /* ALPHAEXCEPTION_H_ */
