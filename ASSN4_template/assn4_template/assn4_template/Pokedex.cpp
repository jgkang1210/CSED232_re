#include "Pokedex.h"

Pokedex::Pokedex()
{
}

Pokedex::~Pokedex()
{
}

// Caputer pokemon
// deep copy
void Pokedex::capturePokemon(const Pokemon* pokemon)
{
	Pokemon* new_pokemon = new Pokemon((*pokemon).get_name(), (*pokemon).get_index(), (*pokemon).get_capture_rate());
	pokedex.push_back(new_pokemon);
}


// Deposit the pokemon
void Pokedex::depositPokemon(const int& index)
{
	// Iterate untill the pokemon list will not contain the pokemon whose ID is same with the user input index.
	bool contain_index = false;
	while (!contain_index) {
		int length = pokedex.size();
		// Search all the member
		int i = 0;
		for (i = 0; i < length; i++) {
			// delete only one member
			if ((*pokedex.at(i)).get_index() == index) {
				// delete the member
				pokedex.erase(i);
				// break the for loop
				break;
			}
		}
		// Can't find the index --> i == lenght --> break the loop
		if (i == length) contain_index = true;
	}
}

const Pokemon* Pokedex::watchPokemon(const int& index) const
{
	return pokedex.at(index);
}


// Print the pokemon by catched order
void Pokedex::printByDefaullt() const
{
	int length = pokedex.size();
	for (int i = 0; i < length; i++) {
		std::cout << (*(pokedex.at(i))).get_index() << ". ";
		std::cout << (*(pokedex.at(i))).get_name() << std::endl;
	}
}

// Print the pokemon by name order
void Pokedex::printByName() const
{
	int length = pokedex.size();
	Pokevector<std::string> temporary_name;
	Pokevector<std::string> print_list;
	for (int i = 0; i < length; i++) {
		temporary_name.push_back((*(pokedex.at(i))).get_name());
	}

	while (temporary_name.size() != 0) {
		int index_length = temporary_name.size();
		int min_index = 0;
		std::string min = "zzzzzzzzzzzzzzzzzzzzzz";
		int index = 0;

		// 1. Find the min value, and index of min value.
		for (index = 0; index < index_length; index++) {
			if (min.compare(temporary_name.at(index)) > 0) {
				min = temporary_name.at(index);
				min_index = index;
			}
		}

		// 2. Check & save the min value
		// 2-1. No elements --> get the value
		int print_list_size = print_list.size();
		if (print_list_size == 0) {
			print_list.push_back(temporary_name.at(min_index));
		}
		// 2-2. Same elements as elements right before --> skip
		else if (print_list.at(print_list_size - 1) == temporary_name.at(min_index)) {}
		// 2-3. Different -->  push back
		else {
			print_list.push_back(temporary_name.at(min_index));
		}

		// 3. Delete the min value of the list
		temporary_name.erase(min_index);

	}

	// print the print_list
	std::cout << "Order by Name" << std::endl;
	std::cout << "-----------------" << std::endl;
	int print_list_size = print_list.size();
	for (int i = 0; i < print_list_size; i++) {
		std::cout << (nameToPokemon(print_list.at(i))).get_index() << ". ";
		std::cout << (nameToPokemon(print_list.at(i))).get_name() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
}

// Print the pokemon by ID order
void Pokedex::printById() const
{
	int length = pokedex.size();
	Pokevector<int> temporary_index;
	Pokevector<int> print_list;
	for (int i = 0; i < length; i++) {
		temporary_index.push_back((*(pokedex.at(i))).get_index());
	}

	while (temporary_index.size() != 0) {
		int index_length = temporary_index.size();
		int min_index = 0;
		int min = 200;
		int index = 0;

		// 1. Find the min value, and index of min value.
		for (index = 0; index < index_length; index++) {
			if (min > temporary_index.at(index)) {
				min = temporary_index.at(index);
				min_index = index;
			}
		}

		// 2. Check & save the min value
		// 2-1. No elements --> get the value
		int print_list_size = print_list.size();
		if (print_list_size == 0) {
			print_list.push_back(temporary_index.at(min_index));
		}
		// 2-2. Same elements as elements right before --> skip
		else if (print_list.at(print_list_size - 1) == temporary_index.at(min_index)) {}
		// 2-3. Different -->  push back
		else {
			print_list.push_back(temporary_index.at(min_index));
		}

		// 3. Delete the min value of the list
		temporary_index.erase(min_index);

	}

	// print the print_list
	std::cout << "Order by ID" << std::endl;
	std::cout << "-----------------" << std::endl;
	int print_list_size = print_list.size();
	for (int i = 0; i < print_list_size; i++) {
		std::cout << (idToPokemon(print_list.at(i))).get_index() << ". ";
		std::cout << (idToPokemon(print_list.at(i))).get_name() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
}

// Search and print the list
void Pokedex::printBySearch(const std::string& name) const
{
	// Search the pokemon
	int length = pokedex.size();

	// print list
	Pokevector<std::string> name_print_list;
	Pokevector<int> number_print_list;

	for (int i = 0; i < length; i++) {
		std::string current = (*(pokedex.at(i))).get_name();
		if (current.find(name) != std::string::npos) {
			// iterate the vector and find.
			int name_list_length = name_print_list.size();
			bool same_name = false;
			for (int i = 0; i < name_list_length; i++) {
				// check if same name
				if (name_print_list.at(i).compare(current) == 0) {
					number_print_list.plus(i);
					same_name = true;
				}
			}

			// new pokemon
			if (same_name == false) {
				name_print_list.push_back(current);
				number_print_list.push_back(1);
			}
		}
	}

	// print the search result
	std::cout << "Search result : " << std::endl;
	std::cout << "Pokemon with : " << name << std::endl;
	std::cout << "-----------------" << std::endl;
	int print_list_length = name_print_list.size();

	if (print_list_length == 0) std::cout << "No Pokemon!" << std::endl;
	else {
		for (int i = 0; i < print_list_length; i++) {
			std::cout << nameToPokemon(name_print_list.at(i)).get_index() << ". ";
			std::cout << nameToPokemon(name_print_list.at(i)).get_name();
			std::cout << ", Number of pokemon : " << number_print_list.at(i) << std::endl;
		}
	}
	std::cout << "-----------------" << std::endl;
}

Pokemon idToPokemon(const int& id)
{
	if (id == 1) {
		return Pokemon("bulbasaur", 1, 100);
	}
	else if (id == 2) {
		return Pokemon("ivysaur", 2, 90);
	}
	else if (id == 3) {
		return Pokemon("venusaur", 3, 80);
	}
	else if (id == 4) {
		return Pokemon("charmander", 4, 100);
	}
	else if (id == 5) {
		return Pokemon("charmeleon", 5, 90);
	}
	else if (id == 6) {
		return Pokemon("charizard", 6, 80);
	}
	else if (id == 7) {
		return Pokemon("squirtle", 7, 100);
	}
	else if (id == 8) {
		return Pokemon("wartortle", 8, 90);
	}
	else if (id == 9) {
		return Pokemon("blastoise", 9, 80);
	}
	else if (id == 10) {
		return Pokemon("caterpie", 10, 100);
	}
	else if (id == 11) {
		return Pokemon("metapod", 11, 90);
	}
	else if (id == 12) {
		return Pokemon("butterfree", 12, 80);
	}
	else if (id == 13) {
		return Pokemon("weedle", 13, 100);
	}
	else if (id == 14) {
		return Pokemon("kakuna", 14, 90);
	}
	else if (id == 15) {
		return Pokemon("beedrill", 15, 80);
	}
	else if (id == 16) {
		return Pokemon("pidgey", 16, 100);
	}
	else if (id == 17) {
		return Pokemon("pidgeotto", 17, 90);
	}
	else if (id == 18) {
		return Pokemon("pidgeot", 18, 80);
	}
	else if (id == 19) {
		return Pokemon("rattata", 19, 100);
	}
	else if (id == 20) {
		return Pokemon("raticate", 20, 90);
	}
	else if (id == 21) {
		return Pokemon("spearow", 21, 100);
	}
	else if (id == 22) {
		return Pokemon("fearow", 22, 90);
	}
	else if (id == 23) {
		return Pokemon("ekans", 23, 100);
	}
	else if (id == 24) {
		return Pokemon("arbok", 24, 90);
	}
	else if (id == 25) {
		return Pokemon("pikachu", 25, 70);
	}
	else if (id == 150) {
		return Pokemon("mewtwo", 150, 20);
	}
	else return Pokemon("", 0, 0);
}

Pokemon nameToPokemon(const std::string& name)
{
	if (name.compare("bulbasaur") == 0) {
		return Pokemon("bulbasaur", 1, 100);
	}
	else if (name.compare("ivysaur") == 0) {
		return Pokemon("ivysaur", 2, 90);
	}
	else if (name.compare("venusaur") == 0) {
		return Pokemon("venusaur", 3, 80);
	}
	else if (name.compare("charmander") == 0) {
		return Pokemon("charmander", 4, 100);
	}
	else if (name.compare("charmeleon") == 0) {
		return Pokemon("charmeleon", 5, 90);
	}
	else if (name.compare("charizard") == 0) {
		return Pokemon("charizard", 6, 80);
	}
	else if (name.compare("squirtle") == 0) {
		return Pokemon("squirtle", 7, 100);
	}
	else if (name.compare("wartortle") == 0) {
		return Pokemon("wartortle", 8, 90);
	}
	else if (name.compare("blastoise") == 0) {
		return Pokemon("blastoise", 9, 80);
	}
	else if (name.compare("caterpie") == 0) {
		return Pokemon("caterpie", 10, 100);
	}
	else if (name.compare("metapod") == 0) {
		return Pokemon("metapod", 11, 90);
	}
	else if (name.compare("butterfree") == 0) {
		return Pokemon("butterfree", 12, 80);
	}
	else if (name.compare("weedle") == 0) {
		return Pokemon("weedle", 13, 100);
	}
	else if (name.compare("kakuna") == 0) {
		return Pokemon("kakuna", 14, 90);
	}
	else if (name.compare("beedrill") == 0) {
		return Pokemon("beedrill", 15, 80);
	}
	else if (name.compare("pidgey") == 0) {
		return Pokemon("pidgey", 16, 100);
	}
	else if (name.compare("pidgeotto") == 0) {
		return Pokemon("pidgeotto", 17, 90);
	}
	else if (name.compare("pidgeot") == 0) {
		return Pokemon("pidgeot", 18, 80);
	}
	else if (name.compare("rattata") == 0) {
		return Pokemon("rattata", 19, 100);
	}
	else if (name.compare("raticate") == 0) {
		return Pokemon("raticate", 20, 90);
	}
	else if (name.compare("spearow") == 0) {
		return Pokemon("spearow", 21, 100);
	}
	else if (name.compare("fearow") == 0) {
		return Pokemon("fearow", 22, 90);
	}
	else if (name.compare("ekans") == 0) {
		return Pokemon("ekans", 23, 100);
	}
	else if (name.compare("arbok") == 0) {
		return Pokemon("arbok", 24, 90);
	}
	else if (name.compare("pikachu") == 0) {
		return Pokemon("pikachu", 25, 70);
	}
	else if (name.compare("mewtwo") == 0) {
		return Pokemon("mewtwo", 150, 20);
	}
	else return Pokemon("", 0, 0);
}
