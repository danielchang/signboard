/*
 * Field.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include "Field.h"

//TODO: rewrite across the board with boost::range. Lazy evaluation!
class BufferBuilder : public boost::static_visitor<>
{
public:
	std::vector<char>* const workingPacket;

	BufferBuilder(std::vector<char>& packet):
		workingPacket(&packet)
	{}

	void operator()(const char& character)
	{
		workingPacket->push_back(character);
	}

	void operator()(const Field& field)
	{
		field.resolveAppendTo(*workingPacket);
	}
};

void Field::resolveAppendTo(std::vector<char>& vec) const
{
	BufferBuilder builder(vec);

	for(auto& subfield : content)
		boost::apply_visitor(builder, subfield);
}


std::vector<char> Field::resolve() const
{
	std::vector<char> result;
	resolveAppendTo(result);
	return result;
}

std::string Field::resolveToString() const
{
	auto resolved = resolve();

	return std::string(resolved.data(), resolved.size());
}

Field& Field::clear()
{
	fieldNames.clear();
	content.clear();

	return *this;
}

Field& Field::appendCharacter(char character)
{
	content.push_back(character);
	return *this;
}

Field& Field::appendField(const std::string& name)
{
	unsigned index = content.size();
	fieldNames[name] = index;

	content.push_back(Field());
	return *this;
}

Field& Field::appendCharacterArray(const char* chars)
{
	while(*chars != 0)
		appendCharacter(*(chars++));
	return *this;
}

Field& Field::appendCharacterArray(const char* chars, unsigned n)
{
	for(; chars != (chars + n); ++chars)
		appendCharacter(*chars);
	return *this;
}

Field& Field::getField(const std::string& name)
{
	//TODO: catch the potential map out-of-range exception, throw one that is more appropriate
	return boost::get<Field>(content[fieldNames.at(name)]);
}

void Field::print(std::ostream& stream) const
{
	for(char character : resolve())
		stream << '(' << (int)character << ")\t" << character << '\n';
}

std::ostream& operator<<(std::ostream& stream, const Field& field)
{
	field.print(stream);
	return stream;
}
