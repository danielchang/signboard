/*
 * main.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include <iostream>

//#include <boost/program_options.hpp>

#include "Field.h"
#include "AlphaPacket.h"
#include "Commands/WriteText.h"
#include "Serial/SerialPort.h"
#include "AlphaException.h"

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

void send(Field& packet)
{
	try
	{
		SerialPort port;
		port.write(packet);
	}
	catch (AlphaException& e)
	{
		cout << "Error: " << e.what() << endl;
		throw;
	}
}

int main(int argc, char **argv)
{
	//TODO: use boost::program options

	if(argc == 2 && string(argv[1]) == "test")
		test();

	AlphaPacket packet;

	packet.command<WriteText>()
			.setFileLabel('0')
			.setMessage("FUCK YOU SIGN");

	send(packet);
}
