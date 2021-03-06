/*
 * Field.h
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include <map>
#include <string>
#include <ostream>
#include <boost/variant.hpp>

class Field
{
private:
	typedef boost::variant<char, Field> FieldPiece;

	std::vector<FieldPiece> content;

	//map<Field Name, Field Index>
	std::map<std::string, unsigned> fieldNames;
	/*
	 * TODO: Weigh the difference between vector, map, and unordered map.
	 * Went with map for now because of built-in lookup, but vector (or some
	 * wrapper) is probably faster and smaller.
	 */

public:
	//Accessor functions. Use these to evaluate the fields into a single vector.
	std::vector<char> resolve() const;
	std::string resolveToString() const;
	//Instead of creating a new vector like resolve, append to the argument vector
	void resolveAppendTo(std::vector<char>& vec) const;

	Field& clear();

	Field& appendCharacter(char character);

	//Append 2 or more characters in sequence
	template<typename... chars>
	Field& appendCharacter(char character, char character2, chars... rest)
	{
		//TODO: see if this can be collapsed to 1 function call
		appendCharacter(character);
		appendCharacter(character2, rest...);

		return *this;
	}

	//char* specific version. Appends up to and ignores terminating null.
	Field& appendCharacterArray(const char* chars);

	//append a set number of characters to the buffer
	Field& appendCharacterArray(const char* chars, unsigned n);

	//generic version, for vectors, strings, etc. Does NOT ignore terminating
	//null, even with std::string. Use string::data to get a char*.
	template<class Array>
	Field& appendCharacterArray(const Array& chars)
	{
		for(char character : chars)
			appendCharacter(character);
		return *this;
	}

	//Don't let the similar signatures fool you- append returns *this, and get
	//returns the retrieved field
	Field& appendField(const std::string& name);
	Field& getField(const std::string& name);

	//pretty print
	void print(std::ostream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, const Field& field);

#endif /* FIELD_H_ */
