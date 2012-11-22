/*
 * AlphaProtocol.h
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#ifndef ALPHAPACKET_H_
#define ALPHAPACKET_H_

#include "Field.h"

class AlphaPacket : public Field
{
private:
	char mode;

public:
	AlphaPacket();

	//default: Z- appears to refer to "All Signs"
	AlphaPacket& updateTypeCode(char code = 'Z');

	//default: 00. appears to be broadcast address.
	AlphaPacket& updateAddress(char first = '0', char second = '0');

	//Gets the command and data field. These aren't used directly- the various
	//interfaces mange these themselves.
	Field& commandCode();
	Field& dataField();

	//Gets an interface to a mode. Switches to and initializes that mode, if
	//necessary
	template<class T>
	T Command()
	{
		T command(*this);
		if(mode != T::commandCode)
		{
			mode = T::commandCode;
			command.initCommand();
		}

		return command;
	}
};

#endif /* ALPHAPACKET_H_ */
