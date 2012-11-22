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

/*
 *
 */
template<char code>
class Mode
{
private:
	friend class AlphaPacket;
	AlphaPacket* const packet;

	Mode(AlphaPacket& packet):
		packet(&packet)
	{}

	virtual void initModeSpecific() =0;

	//Called by the AlphaPacket, if it isn't in this mode at construction time
	void initMode()
	{
		packet->commandCode()
				.clear()
				.appendCharacter(code);
		initModeSpecific();
	}

protected:
	Field& dataField()
	{
		return packet->dataField();
	}

public:
	virtual ~Mode() {}

	const static char controlCode = code;
};

#endif /* MODE_H_ */
