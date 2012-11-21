/*
 * main.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include <vector>
#include <string>

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> arguments(argv, argv + argc);

	cout << "Hello World!\n\n";

	cout << "Received Arguments:\n";
	for(string& argument : arguments)
	{
		cout << '\t' << argument << '\n';
	}
}
