#ifndef POKEDEX
#define POKEDEX

#include <iostream>
#include "Pokemon.h"
#include <string>
#include <vector>

class Pokedex
{
private:
	std::vector<Pokemon*> pokedex;

public:
	Pokedex();
	~Pokedex();
	void capturePokemon(const Pokemon* Pokemon);
	void depositPokemon(const int& index);
	const Pokemon* watchPokemon(const int& index) const;
	void printByDefaullt() const;
	void printByName() const;
	void printById() const;
	void printBySearch(std::string name);
};

#endif
