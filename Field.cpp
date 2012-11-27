/*
 * Field.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include "Field.h"

#include <algorithm>

class BufferBuilder : public boost::static_visitor<>
{
public:
	std::vector<char> workingPacket;

	void operator()(const char& character)
	{
		workingPacket.push_back(character);
	}

	void operator()(const Field& field)
	{
		auto resolvedField = field.resolve();
		workingPacket.insert(workingPacket.end(), resolvedField.begin(), resolvedField.end());
	}
};

std::vector<char> Field::resolve() const
{
	BufferBuilder builder;
	auto visitor = boost::apply_visitor(builder);

	for(auto& subfield : content)
		visitor(subfield);

	return builder.workingPacket;
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

Field& Field::getField(const std::string& name)
{
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
