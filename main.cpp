/*
 * main.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include <cstdlib> //for exit()
#include <iostream>

//Unix file handling
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//#include <boost/program_options.hpp>

#include "Field.h"
#include "AlphaPacket.h"
#include "Commands/WriteText.h"

using namespace std;

void test()
{
	cout << "Testing Fields...\n";

	cout << "Testing basic character append\n";
	Field field;
	field.appendCharacter('a').appendCharacter('b');
	cout << "\tShould be: 'ab'\n";
	cout << "\tResult   : '" << field.resolveToString() << "'\n";

	cout << "Testing variadic character append\n";
	field.appendCharacter('c', 'd', 'e', 'f', 'g');
	cout << "\tShould be: 'abcdefg'\n";
	cout << "\tResult   : '" << field.resolveToString() << "'\n";

	cout << "Testing character array append\n";
	field.appendCharacterArray("hijkl");
	cout << "\tShould be: 'abcdefghijkl'\n";
	cout << "\tResult   : '" << field.resolveToString() << "'\n";

	cout << "Testing clear\n";
	field.clear().appendCharacterArray("mnop");
	cout << "\tShould be: 'mnop'\n";
	cout << "\tResult   : '" << field.resolveToString() << "'\n";

	cout << "Testing subfield\n";
	field.clear()
			.appendCharacterArray("abcd")
			.appendField("middle")
			.appendCharacterArray("ijkl");
	field.getField("middle").appendCharacterArray("efgh");
	cout << "\tShould be: 'abcdefghijkl'\n";
	cout << "\tResult   : '" << field.resolveToString() << "'\n";

	cout << "Testing edit subfield\n";
	field.getField("middle").clear().appendCharacterArray("abcd");
	cout << "\tShould be: 'abcdabcdijkl'\n";
	cout << "\tResult   : '" << field.resolveToString() << "'\n";

	cout << "Testing Write Command\n";
	AlphaPacket packet;
	packet.command<WriteText>().setFileLabel('A').setMessage("Hello World!");
	cout << "Pretty Printing\n" << packet << '\n';
}

int main(int argc, char **argv)
{
	//TODO: use boost::program options

	if(argc == 2 && string(argv[1]) == "test")
		test();

	auto rawPacket = AlphaPacket()
			.command<WriteText>()
			.setFileLabel('A')
			.setMessage("Hello World!")
			.resolve();

	//TODO: move the ugly unix C code to a class
	auto serialPort = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
	if(serialPort == -1)
	{
		cout << "Something went wrong!\n";
		return errno;
	}

	int tryWrite = write(serialPort, rawPacket.data(), rawPacket.size());
	if(tryWrite == -1)
	{
		cout << "Something went wrong!\n";
		return errno;
	}
	close(serialPort);
}
