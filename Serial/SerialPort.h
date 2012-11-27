/*
 * SerialPort.h
 *
 *  Created on: Nov 27, 2012
 *      Author: nathan
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <string>
#include <vector>

class Field;

class SerialPort
{
private:
	int portDescriptor;
public:
	SerialPort(const std::string port = "/dev/ttyS0");
	~SerialPort();

	//success = true, failure = false
	bool write(const Field& field);
	bool write(const std::vector<char>& buffer);

	//TODO: read
};

#endif /* SERIALPORT_H_ */
