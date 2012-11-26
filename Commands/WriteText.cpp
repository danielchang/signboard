/*
 * WriteText.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: nathan
 */

#include "WriteText.h"

WriteText::WriteText(AlphaPacket& packet):
	Command(packet)
{}

void WriteText::initCommandSpecific()
{
	dataField()
			.clear()
			.appendField("File Label")
			.appendField("Mode Field")
			.appendField("Text");
	setFileLabel();
}

WriteText::~WriteText()
{}

WriteText& WriteText::setFileLabel(char label)
{
	dataField()
			.getField("File Label")
			.clear()
			.appendCharacter(label);
	return *this;
}

WriteText& WriteText::setMessage(const std::string& text)
{
	dataField().getField("Text")
			.clear()
			.appendCharacterArray(text.data());
	return *this;
}
