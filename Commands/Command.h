/*
 * Mode.h
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 *
 *  The mode class is the base for all packet modes. Every packet has its own
 *  behavior, so the mode class is fairly lightweight- it stores the mode
 *  character, and provides a few protected helper methods
 *
 */

#ifndef MODE_H_
#define MODE_H_

#include "../AlphaPacket.h"

template<char command>
class Command
{
private:
	friend class AlphaPacket;
	AlphaPacket* const packet;

	virtual void initCommandSpecific() =0;

	//Called by the AlphaPacket, if it isn't in this mode at construction time
	void initCommand()
	{
		packet->commandCode()
				.clear()
				.appendCharacter(command);
		initCommandSpecific();
	}

protected:
	//Constructor is protected, so inherited classes can invoke it
	Command(AlphaPacket& packet):
		packet(&packet)
	{}

	Field& dataField()
	{
		return packet->dataField();
	}

public:
	virtual ~Command() {}

	const static char commandCode = command;
};

#endif /* MODE_H_ */
