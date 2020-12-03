#ifndef POKEMON
#define POKEMON

#include <iostream>
#include <string>

class Pokemon
{
private:
	std::string name;
	int index;
	int capture_rate;
public:
	Pokemon();
	Pokemon(std::string name_, int index_, int capture_rate_);
	~Pokemon();
	std::string get_name() const;
	void set_name(const std::string& name_);
	int get_index() const;
	void set_index(const int& index_);
	int get_capture_rate() const;
	void set_capture_rate(const int& capture_rate_);
};

#endif // !POKEMON