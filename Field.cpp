/*
 * Field.cpp
 *
 *  Created on: Nov 21, 2012
 *      Author: nathan
 */

#include "Field.h"

#include <algorithm>

struct PacketBuilder : public boost::static_visitor<>
{
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
	PacketBuilder builder;

	std::for_each(content.cbegin(), content.cend(), boost::apply_visitor(builder));

	return builder.workingPacket;
}

std::string Field::resolveToString() const
{
	auto resolved = resolve();

	return std::string(resolved.data(), resolved.size());
}

void Field::clear()
{
	fieldNames.clear();
	content.clear();
}

void Field::appendCharacter(char character)
{
	content.push_back(character);
}

Field& Field::appendNamedField(const std::string& name)
{
	unsigned index = content.size();

	content.push_back(Field());
	fieldNames[name] = index;
	return boost::get<Field>(content[index]);
}

Field& Field::getNamedField(const std::string& name)
{
	return boost::get<Field>(content[fieldNames.at(name)]);
}
