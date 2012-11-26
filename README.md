signboard
=========

SignBoard is a C++ implementation of the AlphaSign Protocol. The core of the
implementation is the Field class, which allows for the easy creation of byte
sequences with nested fields. The nested fields allow easy programatic creation
of byte protocols.

Inheriting from the Field class is the AlphaPacket class, which is the base
implementation of the AlphaSign protocol. It manages the various byte fields,
and presents access to various proxy classes that allow for the various
commands.

Example use:

    vector<char> packet = AlphaPacket()
            .Command<WriteText>()
            .setMessage("Hello World")
            .resolve();
            
This creates a packet and stores it in a vector. The Command() method
initializes the packet with a command based on the template parameter. The
setMessage method sets the text that will appear, and the resolve

license
=======
    SignBoard - An experiment in aggregating data to an AlphaDot Sign
    Copyright (C) 2012 - MiMedia.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

