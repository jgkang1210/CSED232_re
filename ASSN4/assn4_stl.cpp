#include <iostream>
#include <ctime>
#include <limits>
#include "Pokemon.h"
#include "Pokedex.h"

// Creative IT Eng, 20190348, JungillKang


void catchPokemon(const Pokedex& database, Pokedex& userdex);
void watchPokeDex(const Pokedex& database, Pokedex& userdex);

int main() {
	// want to make the random function well
	srand((unsigned int)time(0));

	// 1-1. Create initial pokedex --> database
	// 1-2. Create User pokedex
	Pokedex database;
	Pokedex userdex;

	{
		Pokemon bulbasaur("bulbasaur", 1, 100);
		Pokemon ivysaur("ivysaur", 2, 90);
		Pokemon venusaur("venusaur", 3, 80);
		Pokemon charmander("charmander", 4, 100);
		Pokemon charmeleon("charmeleon", 5, 90);
		Pokemon charizard("charizard", 6, 80);
		Pokemon squirtle("squirtle", 7, 100);
		Pokemon wartortle("wartortle", 8, 90);
		Pokemon blastoise("blastoise", 9, 80);
		Pokemon caterpie("caterpie", 10, 100);
		Pokemon metapod("metapod", 11, 90);
		Pokemon butterfree("butterfree", 12, 80);
		Pokemon weedle("weedle", 13, 100);
		Pokemon kakuna("kakuna", 14, 90);
		Pokemon beedrill("beedrill", 15, 80);
		Pokemon pidgey("pidgey", 16, 100);
		Pokemon pidgeotto("pidgeotto", 17, 90);
		Pokemon pidgeot("pidgeot", 18, 80);
		Pokemon rattata("rattata", 19, 100);
		Pokemon raticate("raticate", 20, 90);
		Pokemon spearow("spearow", 21, 100);
		Pokemon fearow("fearow", 22, 90);
		Pokemon ekans("ekans", 23, 100);
		Pokemon arbok("arbok", 24, 90);
		Pokemon pikachu("pikachu", 25, 70);
		Pokemon mewtwo("mewtwo", 150, 20);

		database.capturePokemon(&bulbasaur);
		database.capturePokemon(&ivysaur);
		database.capturePokemon(&venusaur);
		database.capturePokemon(&charmander);
		database.capturePokemon(&charmeleon);
		database.capturePokemon(&charizard);
		database.capturePokemon(&squirtle);
		database.capturePokemon(&wartortle);
		database.capturePokemon(&blastoise);
		database.capturePokemon(&caterpie);
		database.capturePokemon(&metapod);
		database.capturePokemon(&butterfree);
		database.capturePokemon(&weedle);
		database.capturePokemon(&kakuna);
		database.capturePokemon(&beedrill);
		database.capturePokemon(&pidgey);
		database.capturePokemon(&pidgeotto);
		database.capturePokemon(&pidgeot);
		database.capturePokemon(&rattata);
		database.capturePokemon(&raticate);
		database.capturePokemon(&spearow);
		database.capturePokemon(&fearow);
		database.capturePokemon(&ekans);
		database.capturePokemon(&arbok);
		database.capturePokemon(&pikachu);
		database.capturePokemon(&mewtwo);
	}
	std::cout << "---------Pokemon List---------" << std::endl;
	database.printByDefaullt();
	std::cout << "---------Pokemon List---------" << std::endl;

	// 2. Game starts
	while (1) {
		std::cout << "Welcome to the pokemon world" << std::endl;
		std::cout << "This is main page" << std::endl;
		std::cout << "1. Catch" << std::endl;
		std::cout << "2. Pokedex" << std::endl;
		std::cout << "3. Exit game" << std::endl;

		int user_input;
		std::cin >> user_input;
		// Game ended
		if (user_input == 3) {
			std::cout << "Thank you for playing! Bye!" << std::endl;
			return 0;
		}
		// Catch Pokemon
		else if (user_input == 1) {
			catchPokemon(database, userdex);
		}
		// Watch Pokedex
		else if (user_input == 2) {
			watchPokeDex(database, userdex);
		}
		// Wrong input
		else {
			std::cout << "Wrong input" << std::endl;
			std::cout << "Please give number between 1 ~ 3" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void catchPokemon(const Pokedex& database, Pokedex& userdex)
{
	// can give food only one time in each catch phase
	int food = 1;

	// Turn last for 3 turns.
	int turn = 3;

	// choose the random pokemon!
	int i = rand() % 26;

	// Capture rate
	int capture_rate = (*(database.watchPokemon(i))).get_capture_rate();

	std::cout << "You encountered a wild ";
	std::cout << (*(database.watchPokemon(i))).get_name() << "!" << std::endl;

	while (turn) {
		std::cout << "Turn : " << 3 - turn + 1 << std::endl;
		std::cout << "1. Catch" << std::endl;
		std::cout << "2. Give Food" << std::endl;
		std::cout << "3. Run" << std::endl;

		int user_input;
		std::cin >> user_input;
		// 
		if (user_input == 1) {
			int random = rand() % 100 + 1;
			// Catch the pokemon
			if (random < capture_rate) {
				userdex.capturePokemon((database.watchPokemon(i)));
				std::cout << "You catch the " << (*(database.watchPokemon(i))).get_name() << "!" << std::endl;
				return;
			}
			// Fail to catch the pokemon
			else {
				std::cout << "Uh oh.. " << (*(database.watchPokemon(i))).get_name() << " avoid the pokeball" << std::endl;
			}
		}
		// 
		else if (user_input == 2) {
			capture_rate += 10;
			if (capture_rate > 100) capture_rate = 100;
			std::cout << (*(database.watchPokemon(i))).get_name() << " ate the food!" << std::endl;
			std::cout << "Caputre rate increased" << std::endl;
		}
		// run away
		else if (user_input == 3) {
			std::cout << "Successfully run away!" << std::endl;
			return;
		}
		// Wrong input
		else {
			std::cout << "Wrong input" << std::endl;
			std::cout << "Please give number between 1 ~ 3" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// After 3 turn. Game end!
		turn--;
	}

	// Fail to catch
	std::cout << "Failed to catch! Back to main menu!" << std::endl;
	return;
}
void watchPokeDex(const Pokedex& database, Pokedex& userdex) {
	// print the catched pokemon
	std::cout << "Catched Pokemons!" << std::endl;
	std::cout << "-----------------" << std::endl;
	userdex.printByDefaullt();
	std::cout << "-----------------" << std::endl;

	while (1) {
		std::cout << "1. Order by id." << std::endl;
		std::cout << "2. Order by name." << std::endl;
		std::cout << "3. Search." << std::endl;
		std::cout << "4. Deposit." << std::endl;
		std::cout << "5. Exit dex." << std::endl;

		int user_input;
		std::cin >> user_input;
		if (user_input == 1) {
			userdex.printById();
		}
		else if (user_input == 2) {
			userdex.printByName();
		}
		else if (user_input == 3) {
			std::cout << "Which pokemon you want to find?" << std::endl;
			std::string name;
			std::cin >> name;
			userdex.printBySearch(name);
		}
		else if (user_input == 4) {
			std::cout << "Which pokemon you want to Deposit?" << std::endl;
			std::cout << "Give the ID number!" << std::endl;
			int index;
			while (1) {
				std::cin >> index;
				// ID range from 1 ~ 25 and 150
				if (((index > 0) && (index < 26)) || (index == 150)) {
					break;
				}
				else {
					std::cout << "Wrong input" << std::endl;
					std::cout << "Please give number between 1 ~ 25 and 150" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			userdex.depositPokemon(index);

			userdex.printByDefaullt();
		}
		else if (user_input == 5) {
			std::cout << "Return to main menu!" << std::endl;
			return;
		}
		// Wrong input
		else {
			std::cout << "Wrong input" << std::endl;
			std::cout << "Please give number between 1 ~ 5" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}
}