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

	void clear();

	void appendCharacter(char character);

	template<class Array>
	void appendCharacters(Array chars)
	{
		for(char character : chars)
			appendCharacter(character);
	}

	Field& appendNamedField(const std::string& name);
	Field& getNamedField(const std::string& name);
};

#endif /* FIELD_H_ */
