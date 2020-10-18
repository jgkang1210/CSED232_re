#pragma once
#include <iostream>
#include "CPokemon.h"
#include "CTrainer.h"
#include "CRival.h"

// Pokemon type table
// 0. NULL (Used for initiallizing and yet created pokemon)
// 1. Electric
// 2. Grass
// 3. Water
// 4. Fire
// 5. Fly
// 6. Bug
// 7. Dragon
// 8. Esper
// 9. Poison
// 10. Ghost
// 11. Normal
// 12. Rock
// 13. Ground

// Pokemon skill table
// 1. 

// Pokemon ability table
// 1. Levitate

// Pokemon table
//1. pikachu
//2. venusaur
//3. blastoise
//4. charizard
//5. pidgeot
//6. onix
//7. butterfree
//8. gengar
//9. alakazam
//10. dragonite


// NULL_PKM -- > Pokemon class NULL object. Every stat is 0.

// Check if the trainer have three pokemons that can battle.
// input : Trainer class object
// return : TRUE if the trainer has three valid pokemons
// rtturn : False if the trainser has at least one NULL_PKM
bool check_trainer_status(CTrainer trainer);

// input : Pokemon Class object
// Return : TRUE if the pokemon is NULL_PKM
bool if_null_pokemon(CPokemon pokemon);

// Print the pokemon list
void print_pokemon_list();

// Id to name
// input : ID
// print the name of pokemon
void id_to_name(int id);

// Id to name
// input : type ID
// print the type of pokemon
void id_to_type(int id);

int main() {
	// 1. Make 10 pokemons, 1 Trainer(Player), 1 Rival(Computer)
	// Constructor -- > main_type, sub_type, hp, attack, defense, speed, skill_1, skill_2, knock_down
	CPokemon* pokemonList[10];
	CPokemon Pikachu(25, 1, 0, 160, 80, 70, 95); // 피카츄 : 단일 전기 타입
	CPokemon Venusaur(3, 2, 9, 250, 100, 110, 70); // 이상해꽃 : 풀 독 타입
	CPokemon Blastoise(9, 3, 0, 240, 95, 90, 75); // 거북왕 : 단일 물 타입
	CPokemon Charizard(6, 4, 5, 200, 105, 70, 90); // 리자몽 : 불꽃 비행
	CPokemon Pidgeot(17, 11, 5, 170, 90, 60, 95); // 피죤투 : 노말 비행
	CPokemon Onix(95, 12, 13, 190, 75, 100, 50); // 롱스톤 : 바위 땅
	CPokemon Butterfree(12, 6, 5, 140, 70, 50, 60); // 버터플 : 벌레 비행
	CPokemon Gengar(94, 10, 9, 150, 105, 55, 110); // 팬텀 : 고스트 독
	CPokemon Alakazam(65, 8, 0, 150, 105, 55, 115); // 후딘 : 단일 에스퍼 타입
	CPokemon Dragonite(149, 7, 5, 210, 110, 85, 100); // 망나뇽 : 드래곤 비행
	pokemonList[0] = &Pikachu;
	pokemonList[1] = &Venusaur;
	pokemonList[2] = &Blastoise;
	pokemonList[3] = &Charizard;
	pokemonList[4] = &Pidgeot;
	pokemonList[5] = &Onix;
	pokemonList[6] = &Butterfree;
	pokemonList[7] = &Gengar;
	pokemonList[8] = &Alakazam;
	pokemonList[9] = &Dragonite;
	

	CPokemon NULL_PKM; // 모든 값을 0으로 가지는 NULL TYPE 을 만들어 두었다.

	NULL_PKM.print_pokemon_status();

	CTrainer User(NULL_PKM, NULL_PKM, NULL_PKM, NULL_PKM);
	CRival Computer(NULL_PKM, NULL_PKM, NULL_PKM, NULL_PKM);

	// 2. Printing the main menu
	while (1) {
		std::cout << "1. Battle" << std::endl;
		std::cout << "2. Select Pokemon" << std::endl;
		std::cout << "3. Exit game" << std::endl;

		int user_input;
		std::cin >> user_input;

		if (user_input == 3) {
			std::cout << "Thank you for playing! Bye!" << std::endl;
			return 0;
		}
		else if (user_input == 1) {
			if (check_trainer_status(User)) {
				break;
			}
		}
		else if (user_input == 2) {
			std::cout << "Choose your pokemon" << std::endl;
			print_pokemon_list();

			// Make array that save the choosed pokemon.
			// Maximum 3 pokemon can be saved
			int choosed_pokemon[3] = { 0, };
			int loop_count = 0;
			while (loop_count < 3) {
				int user_choose_pokemon;

				std::cout << "Choose your " << loop_count << " pokemon : ";
				std::cin >> user_choose_pokemon;

				if (user_choose_pokemon > 10 && user_choose_pokemon < 1) {
					std::cout << "Choose from 1 ~ 10" << std::endl;
					continue;
				}

				// If we choose the pokemon that are already selected we need to choose again.
				if (choosed_pokemon[0] == user_choose_pokemon) {
					std::cout << "You've already choosed that pokemon" << std::endl;
					continue;
				}
				else if (choosed_pokemon[1] == user_choose_pokemon) {
					std::cout << "You've already choosed that pokemon" << std::endl;
					continue;
				}
				else if (choosed_pokemon[2] == user_choose_pokemon) {
					std::cout << "You've already choosed that pokemon" << std::endl;
					continue;
				}

				choosed_pokemon[loop_count] = user_choose_pokemon;
				
				if (loop_count == 0) {
					User.set_pokemon_1(*pokemonList[user_choose_pokemon - 1]);
				}
				else if (loop_count == 1) {
					User.set_pokemon_2(*pokemonList[user_choose_pokemon - 1]);
				}
				else if (loop_count == 2) {
					User.set_pokemon_3(*pokemonList[user_choose_pokemon - 1]);
				}

				loop_count++;
			}
			std::cout << "Heading to the main menu!" << std::endl;
		}
		else if (user_input == 4) {
			User.get_pokemon_1().print_pokemon_status();
			User.get_pokemon_2().print_pokemon_status();
			User.get_pokemon_3().print_pokemon_status();
		}
		else {
			std::cout << "Please choose number between 1~3" << std::endl;
		}
	}

	// 3. Battle phase
	while (1) {
		std::cout << "Welcome to the pokemon stadim" << std::endl;
		std::cout << "=== My pokemon ===" << std::endl;
		id_to_name(User.get_pokemon_1().get_id());
		id_to_type(User.get_pokemon_1().get_main_type());
		id_to_type(User.get_pokemon_1().get_sub_type());
		std::cout << std::endl;
		id_to_name(User.get_pokemon_2().get_id());
		id_to_type(User.get_pokemon_2().get_main_type());
		id_to_type(User.get_pokemon_2().get_sub_type());
		std::cout << std::endl;
		id_to_name(User.get_pokemon_3().get_id());
		id_to_type(User.get_pokemon_3().get_main_type());
		id_to_type(User.get_pokemon_3().get_sub_type());
		std::cout << std::endl;
		std::cout << "===Opponent's pokemon ===" << std::endl;



		int user_input;
		std::cin >> user_input;
	}
}

bool check_trainer_status(CTrainer trainer) {
	if (if_null_pokemon(trainer.get_pokemon_1())) {
		std::cout << "You need to choose three pokemons" << std::endl;
		return false;
	}
	if (if_null_pokemon(trainer.get_pokemon_2())) {
		std::cout << "You need to choose three pokemons" << std::endl;
		return false;
	}
	if (if_null_pokemon(trainer.get_pokemon_3())) {
		std::cout << "You need to choose three pokemons" << std::endl;
		return false;
	}

	std::cout << "Heading to the stadium!" << std::endl;
	
	return true;
}

bool if_null_pokemon(CPokemon pokemon) {
	if (pokemon.get_id()) {
		return false;
	}
	if (pokemon.get_main_type()) {
		return false;
	}
	if (pokemon.get_sub_type()) {
		return false;
	}
	if (pokemon.get_hp()) {
		return false;
	}
	if (pokemon.get_attack()) {
		return false;
	}
	if (pokemon.get_defense()) {
		return false;
	}
	if (pokemon.get_speed()) {
		return false;
	}
	if (pokemon.get_ability()) {
		return false;
	}
	if (pokemon.get_skill_1()) {
		return false;
	}
	if (pokemon.get_skill_2()) {
		return false;
	}
	if (pokemon.get_knock_down()) {
		return false;
	}

	return true;
}

void print_pokemon_list() {
	std::cout << "========POKEMONLIST========" << std::endl;
	std::cout << "1. Pikachu, ID : 25" << std::endl;
	std::cout << "2. Venusaur, ID : 3" << std::endl;
	std::cout << "3. Blastoise, ID : 9" << std::endl;
	std::cout << "4. Charizard, ID : 6" << std::endl;
	std::cout << "5. Pidgeot, ID : 17" << std::endl;
	std::cout << "6. Onix, ID : 95" << std::endl;
	std::cout << "7. Butterfree, ID : 12" << std::endl;
	std::cout << "8. Gengar, ID : 94" << std::endl;
	std::cout << "9. Alakazam, ID : 65" << std::endl;
	std::cout << "10. Dragonite, ID : 149" << std::endl;
	std::cout << "========POKEMONLIST========" << std::endl;
}

void id_to_name(int id) {
	if (id == 3) std::cout << "Venusaur ";
	else if (id == 6) std::cout << "Charizard ";
	else if (id == 9) std::cout << "Blastoise ";
	else if (id == 12) std::cout << "Butterfree ";
	else if (id == 17) std::cout << "Pidgeot ";
	else if (id == 25) std::cout << "Pikachu ";
	else if (id == 65) std::cout << "Alakazam ";
	else if (id == 94) std::cout << "Gengar ";
	else if (id == 95) std::cout << "Onix ";
	else if (id == 149) std::cout << "Dragonite ";
}

void id_to_type(int id) {
	if (id == 0) std::cout << "";
	else if (id == 1) std::cout << "Electric ";
	else if (id == 2) std::cout << "Grass ";
	else if (id == 3) std::cout << "Water ";
	else if (id == 4) std::cout << "Fire ";
	else if (id == 5) std::cout << "Fly ";
	else if (id == 6) std::cout << "Bug ";
	else if (id == 7) std::cout << "Dragon ";
	else if (id == 8) std::cout << "Esper ";
	else if (id == 9) std::cout << "Poison ";
	else if (id == 10) std::cout << "Ghost ";
	else if (id == 11) std::cout << "Normal ";
	else if (id == 12) std::cout << "Rock ";
	else if (id == 13) std::cout << "Ground ";
}