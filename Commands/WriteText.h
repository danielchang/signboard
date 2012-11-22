/*
 * WriteText.h
 *
 *  Created on: Nov 22, 2012
 *      Author: nathan
 */

#ifndef WRITETEXT_H_
#define WRITETEXT_H_

#include <string>

#include "FixedCodes.h"
#include "Command.h"

class WriteText : Command<commandCodes::WRITETEXT>
{
private:
	friend class AlphaPacket;
	WriteText(AlphaPacket& packet);

	void initCommandSpecific() override;

public:
	virtual ~WriteText();

	WriteText& setFileLabel(char label = 'A');

	//TODO: Custom modes

	//This will drop off any trailing newline
	WriteText& setMessage(const std::string& str);
};

#endif /* WRITETEXT_H_ */
