
#include "Pokemon.h"

Pokemon::Pokemon()
{
	name = "";
	index = 0;
	capture_rate = 0;
}

Pokemon::Pokemon(std::string name_, int index_, int capture_rate_):name(name_), index(index_), capture_rate(capture_rate_)
{
}

Pokemon::~Pokemon()
{
}

std::string Pokemon::get_name() const
{
	return name;
}

void Pokemon::set_name(const std::string& name_)
{
	name = name_;
}

int Pokemon::get_index() const
{
	return index;
}

void Pokemon::set_index(const int& index_)
{
	index = index_;
}

int Pokemon::get_capture_rate() const
{
	return capture_rate;
}

void Pokemon::set_capture_rate(const int& capture_rate_)
{
	capture_rate = capture_rate_;
}
