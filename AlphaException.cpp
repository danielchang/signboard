/*
 * AlphaException.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include "AlphaException.h"

AlphaException::AlphaException(const std::string& data):
	data(data)
{}

AlphaException::~AlphaException()
{}

const char* AlphaException::what()
{
	return data.data();
}
