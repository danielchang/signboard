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

#include <boost/variant.hpp>

class Field
{
private:
	typedef boost::variant<char, Field> FieldPiece;
	std::map<std::string, unsigned> fieldNames;
	std::vector<FieldPiece> content;

public:
	std::vector<char> resolve() const;
	std::string resolveToString() const;

	Field& clear();

	Field& appendCharacter(char character);

	//2 or more characters, with a variadic template
	template<typename... chars>
	Field& appendCharacter(char character, char character2, chars... rest)
	{
		return appendCharacter(character).appendCharacter(character2, rest...);
	}

	//char* specific version. ignores terminating null.
	Field& appendCharacterArray(const char* chars);

	//generic version, for vectors, strings, etc.
	template<class Array>
	Field& appendCharacterArray(const Array& chars)
	{
		for(char character : chars)
			appendCharacter(character);
		return *this;
	}

	Field& appendField(const std::string& name);
	Field& getField(const std::string& name);
};

#endif /* FIELD_H_ */
