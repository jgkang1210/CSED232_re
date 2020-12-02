#include "Pokedex.h"

Pokedex::Pokedex()
{
}

Pokedex::~Pokedex()
{
	for (std::vector<Pokemon*>::iterator iter = pokedex.begin(); iter != pokedex.end(); iter++) {
		delete *iter;
	}
	pokedex.clear();
}

// Caputer pokemon
// deep copy
void Pokedex::capturePokemon(const Pokemon* pokemon)
{
	Pokemon* new_pokemon = new Pokemon((*pokemon).get_name(), (*pokemon).get_index(), (*pokemon).get_capture_rate());
	pokedex.push_back(new_pokemon);
}

void Pokedex::depositPokemon(const int& index)
{
	auto iter = pokedex.begin();
	iter += (index - 1);
	pokedex.erase(iter);
}

const Pokemon* Pokedex::watchPokemon(const int& index) const
{
	return pokedex.at(index);
}

void Pokedex::printByDefaullt() const
{
	for (int i = 0; i < pokedex.size(); i++) {
		std::cout << (*(pokedex.at(i))).get_index() << ". ";
		std::cout << (*(pokedex.at(i))).get_name() << std::endl;
	}
}

void Pokedex::printByName() const
{
	

}

void Pokedex::printById() const
{
	int length = pokedex.size();
	std::vector<int> temporary_index;
	std::vector<Pokemon*> print_list;
	for (int i = 0; i < length; i++) {
		temporary_index.push_back((*(pokedex.at(i))).get_index());
	}

	while (temporary_index.size() != 0) {
		int index_length = temporary_index.size();
		int min_index = 0;
		int min = 200;
		int index = 0;
		for (index = 0; index < index_length; index++) {
			if (min > temporary_index.at(index)) {
				min = temporary_index.at(index);
				min_index = index;
			}
		}
		
		// delete the min value
		auto iter = temporary_index.begin();
		iter += (index - 1);
		temporary_index.erase(iter);

		// check & save the min value
		if
	}
}

void Pokedex::printBySearch(std::string name)
{

}
