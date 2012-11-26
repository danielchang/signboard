/*
 * FixedCodes.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: nathan
 */

#include "FixedCodes.h"

bool isSpecial(char code)
{
	return code >= modeCodes::special::min && code <= modeCodes::special::max;
}
