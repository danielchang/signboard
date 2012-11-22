/*
 * AlphaPacket.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include "AlphaPacket.h"

AlphaPacket::AlphaPacket()
{
	appendCharacter(0, 0, 0, 0, 0, 1);
	appendField("Type Code");
	appendField("Sign Address");
	appendCharacter(2);
	appendField("Command Code");
	appendField("Data Field");
	appendCharacter(4);

	updateTypeCode();
	updateAddress();
}

AlphaPacket& AlphaPacket::updateTypeCode(char code)
{
	getField("Type Code")
			.clear()
			.appendCharacter(code);

	return *this;
}

AlphaPacket& AlphaPacket::updateAddress(char first, char second)
{
	getField("Sign Address")
			.clear()
			.appendCharacter(first, second);

	return *this;
}

Field& AlphaPacket::commandCode()
{
	return getField("Command Code");
}

Field& AlphaPacket::dataField()
{
	return getField("Data Field");
}
