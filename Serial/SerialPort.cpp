/*
 * SerialPort.cpp
 *
 *  Created on: Nov 27, 2012
 *      Author: nathan
 */

#include "SerialPort.h"

//Unix file handling
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

#include <iostream>

#include "../AlphaException.h"
#include "../Field.h"

SerialPort::SerialPort(const std::string port)
{
	std::cout << "Creating interface to serial port\n";

	std::cout << "Opening descriptor\n";
	portDescriptor = open(port.data(), O_RDWR | O_NOCTTY | O_NDELAY);
	if(portDescriptor < 0)
		throw AlphaException("Failed to open port");

	//All reads are non-blocking.
	/*
	if(fcntl(portDescriptor, F_SETFL, FNDELAY) < 0)
		throw AlphaException("Failed to apply fcntl");
	*/

	termios serialConfig;

	//TODO: Write better error handling, including perror
	std::cout << "Getting port attributes\n";
	if(tcgetattr(portDescriptor, &serialConfig) < 0)
		throw AlphaException("Failed to get serial attributes\n");

	std::cout << "Setting baud rate\n";
	cfsetspeed(&serialConfig, B9600);

	/*
	 * Serial spec reference: http://www.easysw.com/~mike/serial/serial.html#2_2
	 */

	std::cout << "Setting as local line\n";
	serialConfig.c_cflag |= CLOCAL;

	std::cout << "Enabling reciever\n";
	serialConfig.c_cflag |= CREAD;

	//7 data bits, even parity, 2 stop bits

	std::cout << "Setting mode as 7E2\n";
	serialConfig.c_cflag &= ~CSIZE; //mask all data size bits
	serialConfig.c_cflag |= CS7; //set 7 data size bits
	serialConfig.c_cflag |= CSTOPB; //set 2 character stop bits
	serialConfig.c_cflag &= ~PARODD; //mask odd parity
	serialConfig.c_cflag |= PARENB; //set even parity

	//Enable raw data. No buffering
	std::cout << "Setting non-cannonical\n";
	serialConfig.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

	/*
	 * The serial port documentation from the reference site seems to indicate
	 * that a port is either hardware or software flow controled. However, the
	 * 2 modes can be enabled or disabled separatly, and the Alpha Protocol
	 * spec just has "None" for flow control.
	 */
	std::cout << "Disabling hardware flow control\n";
	serialConfig.c_cflag &= ~CRTSCTS;

	std::cout << "Disabling software flow control\n";
	serialConfig.c_iflag &= ~(IXON | IXOFF | IXANY);

	std::cout << "Applying settings\n";
	if(tcsetattr(portDescriptor, TCSANOW, &serialConfig) < 0)
		throw AlphaException("Failed to apply config settings");
}

SerialPort::~SerialPort()
{
	std::cout << "Closing port\n";
	if(close(portDescriptor) < 0)
		perror("Failed to close serial port! - ");
}

bool SerialPort::write(const Field& field)
{
	std::cout << "Writing Packet\n" << field;
	return write(field.resolve());
}

bool SerialPort::write(const std::vector<char>& buffer)
{
	if(::write(portDescriptor, buffer.data(), buffer.size()) < 0)
		return false;
	return true;
}
