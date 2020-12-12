#ifndef POKEDEX
#define POKEDEX

#include <iostream>
#include "Pokemon.h"
#include "Pokevector.h"
#include <string>

Pokemon idToPokemon(const int& id);
Pokemon nameToPokemon(const std::string& name);

class Pokedex
{
private:
	Pokevector<Pokemon*> pokedex;

public:
	Pokedex();
	~Pokedex();
	void capturePokemon(const Pokemon* Pokemon);
	void depositPokemon(const int& index);
	const Pokemon* watchPokemon(const int& index) const;
	void printByDefaullt() const;
	void printByName() const;
	void printById() const;
	void printBySearch(const std::string& name) const;
};

#endif // !POKEDEXS