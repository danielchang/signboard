/*
 * FixedCodes.h
 *
 *  Created on: Nov 22, 2012
 *      Author: nathan
 */

#ifndef FIXEDCODES_H_
#define FIXEDCODES_H_

//TODO: replace with enums

namespace commandCodes
{
	const char WRITETEXT = 'A';
	const char READTEXT = 'B';
	const char WRITESPECIAL = 'E';
	const char READSPECIAL = 'F';
	const char WRITESTRING = 'G';
	const char READSTRING = 'H';
	const char WRITESMALLDOTS = 'I';
	const char READSMALLDOTS = 'J';
	const char WRITERGBDOTS = 'K';
	const char READRGBDOTS = 'L';
	const char WRITELARGEDOTS = 'M';
	const char READLARGEDOTS = 'N';
}

namespace displayPositionCodes
{
	const char MIDDLELINE = ' ';
	const char TOPLINE = '"';
	const char BOTTOMLINE = '&';
	const char FILL = '0';
	const char LEFT = '1';
	const char RIGHT = '2';
}

namespace modeCodes
{
	const char ROTATE = 'a';
	const char HOLD = 'b';
	const char FLASH = 'c';
	const char ROLLUP = 'e';
	const char ROLLDOWN = 'f';
	const char ROLLLEFT = 'g';
	const char ROLLRIGHT = 'h';
	const char WIPEUP = 'i';
	const char WIPEDOWN = 'j';
	const char WIPELEFT = 'k';
	const char WIPERIGHT = 'l';
	const char SCROLL = 'm';
	const char AUTOMODE = 'o';
	const char ROLLIN = 'p';
	const char ROLLOUT = 'q';
	const char WIPEIN = 'r';
	const char WIPEOUT = 's';
	const char COMPRESSEDROTATE = 't';
	const char EXPLODE = 'u';
	const char CLOCK = 'v';
	const char SPECIAL = 'n';

	namespace special
	{
		//Keep this character the same as the min special
		const char min = '0';

		const char TWINKLE = '0';
		const char SPARKLE = '1';
		const char SNOW = '2';
		const char INTERLOCK = '3';
		const char SWITCH = '4';
		const char SLIDE = '5';
		const char SPRAY = '6';
		const char STARBURST = '7';
		const char WELCOME = '8';
		const char SLOTMACHINE = '9';
		const char NEWSFLASH = 'A';
		const char TRUMPETANIMATION = 'B';
		const char CYCLECOLORS = 'C';

		//Keep this character the same as the max special
		const char max = 'C';
	}
}

//TODO: make this not like this
//TODO: move this function to the modeCodes namespace
bool isSpecial(char code);

#endif /* FIXEDCODES_H_ */
