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