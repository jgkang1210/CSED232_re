#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
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

// Pokemon skill table (Skill power, Accuracy)
// 1. Thunderbolt ( 95, 95% )
// 2. Solar Beam ( 110, 85% )
// 3. Hydro Pump ( 120, 80% )
// 4. Flamethrower ( 95, 95% )
// 5. Wing Attack ( 80, 99% )
// 6. X-Scissor ( 75, 99% )
// 7. Outrage ( 120, 80% )
// 8. Psychic ( 90, 90% )
// 9. Cross Poison ( 75, 99% )
// 10. Shadow Ball ( 85, 95% )
// 11. Tackle ( 50, 100% )
// 12. Rock Slide ( 80, 95% )
// 13. Earthquake ( 100, 90% )

// Pokemon ability table
// 1. Lightning Rod -- > absorb electric type skill : No damage, Rank up the attack
// 2. Overgrowth -- > * 1.5 damage of grass type skill, when the pokemon's hp is less than 30%
// 3. Torrent -- > * 1.5 damage of water type skill, when the pokemon's hp is less than 30%
// 4. Blaze -- > * 1.5 damage of fire type skill, when the pokemon's hp is less than 30%
// 5. Gale wings -- > Gives priority to Flying-type moves.
// 6. Sturdy -- > prevent from 1 hit KO.
// 7. Tinted Lens -- > Double the damage that is "Not very effective"
// 8. Levitate -- > Not hit by GROUND attacks.
// 9. Neuroforce -- > The Pokemon deals 25% more damage with super effective moves.
// 10. Multiscale -- > Halves the damage the Pokemon takes while at full HP.

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
void id_to_name(const int id);

// Id to name
// input : type ID
// print the type of pokemon
void id_to_type(const int id);

// Id to skill
// input : type ID
// print the name of skill
void id_to_skill(const int id);

// Id to default hp
// input : ability ID
// return the default hp of ability
int id_to_hp(const int id);

// Id to skill damage
// input : type ID
// return the damage of skill
int id_to_skill_dmg(const int id);

// Id to ability
// input : ability ID
// print the name of ability
void id_to_ability(const int id);

// Id to accuracy
// input : ability ID
// return the (accuracy of ability * 100)
int id_to_accuracy(const int id);

// Choosing the number from 1 ~ 10. Because we have 10 pokemons.
int random_ID_chooser();

// Choosing the number from 1 ~ 13. Beacuse we have 13 types.
// We can also choose this number as skill beacuse we have 13 skills.
int random_type_chooser();

// print all the user's pokemon entry
// print all the computer's pokemon entry
void print_user_entry(CTrainer User);
void print_computer_entry(CRival Rival);

// print user's in_battle_pokemon status
void print_user_in_battle_status(CPokemon in_battle);
// print computer's in_battle_pokemon status
void print_computer_in_battle_status(CPokemon in_battle);

// Check if the game is finished
// return 1 : Not finished
// return 0 : Game finished
int fin_checker(CTrainer User, CRival Computer);

// check if the selected pokemon is valid for changing
bool valid_change_checker(CTrainer user, int user_change);

// Change the pokemon and update the damage information
void change_pokemon(CTrainer& User, int user_select);

// Battle phase
// 1. Compare speed
// 2. Choose the skill
// 3. Calculate the damage with ability
// 4. Apply it
void battle_phase(CTrainer& User, CRival& Computer);

// Update phase
// 1. Update the in_battle_pokemon to the entry's pokemon
void update_phase(CTrainer& User, CRival& Computer);

// Computer attacks the user
// input : 1. Computer, 2. User objects
// output : return 1 : if the user pokemon fainted
// output : return 0 : if no pokemon fainted
bool attack_user(CRival& Computer, CTrainer& User);

// Computer attacks the user
// input : 1. User, 2. Computer objects
// output : return 1 : if the computer pokemon fainted
// output : return 0 : if no pokemon fainted
bool attack_computer(CTrainer& User, CRival& Computer, const int skill_number);

// Input 1 : attacking type, Input 2 : defensing type
// Return : 0 - no effect, 0.5 - not very effective, 1 - just attack, 2 - super effective
float type_checker(const int attack_type, const int defense_type);

// Initiallizing the user's data
void init_User(CTrainer& User, CTrainer& Save);
// Initiallizing the computer's data
void init_Computer(CRival& Computer, CRival& Save);

int main() {
	// want to make the random function well
	srand((unsigned int)time(0));

	// 1. Make 10 pokemons, 1 Trainer(Player), 1 Rival(Computer)
	// Constructor -- > main_type, sub_type, hp, attack, defense, speed, skill_1, skill_2, knock_down
	CPokemon pokemonList[11];
	CPokemon NULL_PKM; // 모든 값을 0으로 가지는 NULL TYPE 을 만들어 두었다.
	CPokemon Pikachu(25, 1, 0, 160, 80, 70, 95, 1, 1); // 피카츄 : 단일 전기 타입
	CPokemon Venusaur(3, 2, 9, 250, 100, 110, 70, 2, 2); // 이상해꽃 : 풀 독 타입
	CPokemon Blastoise(9, 3, 0, 240, 95, 90, 75, 3, 3); // 거북왕 : 단일 물 타입
	CPokemon Charizard(6, 4, 5, 200, 105, 70, 90, 4, 4); // 리자몽 : 불꽃 비행
	CPokemon Pidgeot(17, 11, 5, 170, 90, 60, 95, 5, 11); // 피죤투 : 노말 비행
	CPokemon Onix(95, 12, 13, 190, 75, 100, 50, 6, 12); // 롱스톤 : 바위 땅
	CPokemon Butterfree(12, 6, 5, 140, 70, 50, 60, 7, 6); // 버터플 : 벌레 비행
	CPokemon Gengar(94, 10, 9, 150, 105, 55, 110, 8, 10); // 팬텀 : 고스트 독
	CPokemon Alakazam(65, 8, 0, 150, 105, 55, 115, 9, 8); // 후딘 : 단일 에스퍼 타입
	CPokemon Dragonite(149, 7, 5, 210, 110, 85, 100, 10, 7); // 망나뇽 : 드래곤 비행
	pokemonList[0] = NULL_PKM;
	pokemonList[1] = Pikachu;
	pokemonList[2] = Venusaur;
	pokemonList[3] = Blastoise;
	pokemonList[4] = Charizard;
	pokemonList[5] = Pidgeot;
	pokemonList[6] = Onix;
	pokemonList[7] = Butterfree;
	pokemonList[8] = Gengar;
	pokemonList[9] = Alakazam;
	pokemonList[10] = Dragonite;

	CTrainer User(NULL_PKM, NULL_PKM, NULL_PKM, NULL_PKM);
	CRival Computer(NULL_PKM, NULL_PKM, NULL_PKM, NULL_PKM);

	// 2. Creating Rival's pokemon and the skill and ability
	int rival_pokemon_1;
	int rival_pokemon_2;
	int rival_pokemon_3;
	int count = 0;

	// Choosing three different pokemon
	while (1) {
		rival_pokemon_1 = random_ID_chooser();
		rival_pokemon_2 = random_ID_chooser();
		if (rival_pokemon_2 == rival_pokemon_1){
			continue;
		}
		rival_pokemon_3 = random_ID_chooser();
		if (rival_pokemon_3 == rival_pokemon_1) {
			continue;
		}
		if (rival_pokemon_3 == rival_pokemon_2) {
			continue;
		}
		break;
	}

	Computer.set_pokemon_1(pokemonList[rival_pokemon_1]);
	Computer.set_pokemon_2(pokemonList[rival_pokemon_2]);
	Computer.set_pokemon_3(pokemonList[rival_pokemon_3]);
	
	// Choosing different random skill
	int rival_pokemon_1_random_skill;
	int rival_pokemon_2_random_skill;
	int rival_pokemon_3_random_skill;

	// It has to bo diffenrent with skill_1
	while (1) {
		rival_pokemon_1_random_skill = random_type_chooser();
		rival_pokemon_2_random_skill = random_type_chooser();
		rival_pokemon_3_random_skill = random_type_chooser();
		if (rival_pokemon_1_random_skill != Computer.get_pokemon_1().get_skill_1()) {
			if (rival_pokemon_2_random_skill != Computer.get_pokemon_2().get_skill_1()) {
				if (rival_pokemon_3_random_skill != Computer.get_pokemon_3().get_skill_1()) break;
			}
		}
	}

	Computer.get_pokemon_1().set_skill_2(rival_pokemon_1_random_skill);
	Computer.get_pokemon_2().set_skill_2(rival_pokemon_2_random_skill);
	Computer.get_pokemon_3().set_skill_2(rival_pokemon_3_random_skill);

	// set the computer's first battle pokemon as pokemon 1
	Computer.set_in_battle(Computer.get_pokemon_1());

	// 3. Printing the main menu
	while (1) {
		std::cout << "Welcome to the pokemon world" << std::endl;
		std::cout << "This is main page" << std::endl;
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
				// 4. Battle phase
				CTrainer save_user(User);
				CRival save_computer(Computer);

				std::cout << "Welcome to the pokemon stadim" << std::endl;
				std::cout << "=== My pokemon ===" << std::endl;
				print_user_entry(User);

				std::cout << std::endl;
				std::cout << "===Opponent's pokemon ===" << std::endl;
				print_computer_entry(Computer);

				std::cout << "Battle begin in 5 sec" << std::endl;
				Sleep(5000);
				system("cls");
				
				while (fin_checker(User, Computer)) {
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << "Me : ";
					print_user_in_battle_status(User.get_in_battle());
					std::cout << "Rival : ";
					print_computer_in_battle_status(Computer.get_in_battle());

					std::cout << "1. Fight		2. Pokemon		3. Forfeit" << std::endl;

					int user_input;
					std::cin >> user_input;
					// Giving up
					if (user_input == 3) {
						User.give_up();
						std::cout << "Give up." << std::endl;
						std::cout << "Going back to main menu." << std::endl;
						std::cout << "Wait 5 sec" << std::endl;
						Sleep(5000);
						system("cls");
					}
					// Changing pokemon
					else if (user_input == 2) {
						// print the entry
						print_user_entry(User);
						std::cout << "Select the pokemon you want to change. (press 0 to go back)" << std::endl;
						
						int user_select;
						while (1) {
							std::cin >> user_select;
							if (user_select == 0) break; // 0 is previous key.
							// check that the pokemon can be changed
							if (valid_change_checker(User, user_select)) break;
						}
						
						if (user_select == 0) continue;
						// change the pokemon
						change_pokemon(User, user_select);
						std::cout << "Go!";
						id_to_name(User.get_in_battle().get_id());
						std::cout << std::endl;

						// Computer attacks user.
						attack_user(Computer, User);

						
					}
					// Battle phase
					else if (user_input == 1) {
						battle_phase(User, Computer);

						update_phase(User, Computer);

						
					}
					else {
						std::cout << "Wrong input. Please give between 1 ~ 3." << std::endl;
					}
				}

				init_User(User, save_user);
				init_Computer(Computer, save_computer);
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}
		}
		// Choosing pokemon
		else if (user_input == 2) {
			std::cout << "Choose your pokemon" << std::endl;
			print_pokemon_list();

			// Make array that save the choosed pokemon.
			// Maximum 3 pokemon can be saved
			int choosed_pokemon[3] = { 0, };
			int loop_count = 0;



			while (loop_count < 3) {
				int user_choose_pokemon;

				std::cout << "Choose your " << loop_count + 1 << " pokemon : ";
				std::cin >> user_choose_pokemon;

				if (user_choose_pokemon > 10 || user_choose_pokemon < 1) {
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
					int user_pokemon_1_random_skill;
					// It has to bo diffenrent with skill_1
					while (1) {
						user_pokemon_1_random_skill = random_type_chooser();
						if (user_pokemon_1_random_skill != User.get_pokemon_1().get_skill_1()) break;
					}
					User.set_pokemon_1(pokemonList[user_choose_pokemon]);
					User.get_pokemon_1().set_skill_2(user_pokemon_1_random_skill);
				}
				else if (loop_count == 1) {
					int user_pokemon_2_random_skill = random_type_chooser();
					// It has to bo diffenrent with skill_1
					while (1) {
						user_pokemon_2_random_skill = random_type_chooser();
						if (user_pokemon_2_random_skill != User.get_pokemon_2().get_skill_1()) break;
					}
					User.set_pokemon_2(pokemonList[user_choose_pokemon]);
					User.get_pokemon_2().set_skill_2(user_pokemon_2_random_skill);
				}
				else if (loop_count == 2) {
					int user_pokemon_3_random_skill = random_type_chooser();
					// It has to bo diffenrent with skill_1
					while (1) {
						user_pokemon_3_random_skill = random_type_chooser();
						if (user_pokemon_3_random_skill != User.get_pokemon_3().get_skill_1()) break;
					}
					User.set_pokemon_3(pokemonList[user_choose_pokemon]);
					User.get_pokemon_3().set_skill_2(user_pokemon_3_random_skill);
				}

				loop_count++;
			}
			User.set_in_battle(User.get_pokemon_1());
			std::cout << "Heading to the main menu!" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		//Used for debugging
		 
		/*else if (user_input == 4) {
			User.get_pokemon_1().print_pokemon_status();
			User.get_pokemon_2().print_pokemon_status();
			User.get_pokemon_3().print_pokemon_status();
			Computer.get_pokemon_1().print_pokemon_status();
			Computer.get_pokemon_2().print_pokemon_status();
			Computer.get_pokemon_3().print_pokemon_status();
		}*/
		
		else {
			std::cout << "Please choose number between 1~3" << std::endl;
		}
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
	std::cout << std::endl;
	std::cout << "1. Pikachu,	 ID : 25" << std::endl;
	std::cout << "2. Venusaur,	 ID : 3" << std::endl;
	std::cout << "3. Blastoise,	 ID : 9" << std::endl;
	std::cout << "4. Charizard,	 ID : 6" << std::endl;
	std::cout << "5. Pidgeot,	 ID : 17" << std::endl;
	std::cout << "6. Onix,	 ID : 95" << std::endl;
	std::cout << "7. Butterfree,	 ID : 12" << std::endl;
	std::cout << "8. Gengar,	 ID : 94" << std::endl;
	std::cout << "9. Alakazam,	 ID : 65" << std::endl;
	std::cout << "10. Dragonite,	 ID : 149" << std::endl;
	std::cout << std::endl;
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

void id_to_type(const int id) {
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

void id_to_skill(const int id) {
	if (id == 0) std::cout << "";
	else if (id == 1) std::cout << "Thunderbolt (95, 95%) ";
	else if (id == 2) std::cout << "Solar Beam (110, 85%) ";
	else if (id == 3) std::cout << "Hydro Pump (120, 80%) ";
	else if (id == 4) std::cout << "Flamethrower (95, 95%) ";
	else if (id == 5) std::cout << "Wing Attack (80, 99%) ";
	else if (id == 6) std::cout << "X-Scissor (75, 99%) ";
	else if (id == 7) std::cout << "Outrage (120, 80%) ";
	else if (id == 8) std::cout << "Psychic (90, 90%) ";
	else if (id == 9) std::cout << "Cross Poison (75, 99%) ";
	else if (id == 10) std::cout << "Shadow Ball (85, 95%) ";
	else if (id == 11) std::cout << "Tackle (50, 100%) ";
	else if (id == 12) std::cout << "Rock Slide (80, 95%) ";
	else if (id == 13) std::cout << "Earthquake (100, 90%) ";
}

int id_to_hp(const int id)
{
	if (id == 3) return 250;
	else if (id == 6) return 200;
	else if (id == 9) return 240;
	else if (id == 12) return 140;
	else if (id == 17) return 150;
	else if (id == 25) return 160;
	else if (id == 65) return 150;
	else if (id == 94) return 150;
	else if (id == 95) return 190;
	else if (id == 149) return 210;
}

int id_to_skill_dmg(const int id)
{
	if (id == 0) return 0;
	else if (id == 1) return 95;
	else if (id == 2) return 110;
	else if (id == 3) return 120;
	else if (id == 4) return 95;
	else if (id == 5) return 80;
	else if (id == 6) return 75;
	else if (id == 7) return 120;
	else if (id == 8) return 90;
	else if (id == 9) return 75;
	else if (id == 10) return 85;
	else if (id == 11) return 50;
	else if (id == 12) return 80;
	else if (id == 13) return 100;
	else return 0;
}

void id_to_ability(const int id)
{
	if (id == 3) std::cout << "Overgrowth ";
	else if (id == 6) std::cout << "Blaze ";
	else if (id == 9) std::cout << "Torrent ";
	else if (id == 12) std::cout << "Tinted Lens ";
	else if (id == 17) std::cout << "Keen Eye ";
	else if (id == 25) std::cout << "Lightning Rod ";
	else if (id == 65) std::cout << "Neuroforce ";
	else if (id == 94) std::cout << "Levitate ";
	else if (id == 95) std::cout << "Sturdy ";
	else if (id == 149) std::cout << "Multiscale ";
}

int id_to_accuracy(const int id)
{
	if (id == 0) return 0;
	else if (id == 1) return 95;
	else if (id == 2) return 85;
	else if (id == 3) return 80;
	else if (id == 4) return 95;
	else if (id == 5) return 99;
	else if (id == 6) return 99;
	else if (id == 7) return 80;
	else if (id == 8) return 90;
	else if (id == 9) return 99;
	else if (id == 10) return 95;
	else if (id == 11) return 100;
	else if (id == 12) return 95;
	else if (id == 13) return 90;
}

int random_ID_chooser() {
	return rand() % 10 + 1;
}

int random_type_chooser() {
	return rand() % 13 + 1;
}

void print_user_entry(CTrainer User) {
	std::cout << std::endl;
	std::cout << "1. ";
	id_to_name(User.get_pokemon_1().get_id());
	id_to_type(User.get_pokemon_1().get_main_type());
	id_to_type(User.get_pokemon_1().get_sub_type());
	std::cout << std::endl;
	std::cout << "2. ";
	id_to_name(User.get_pokemon_2().get_id());
	id_to_type(User.get_pokemon_2().get_main_type());
	id_to_type(User.get_pokemon_2().get_sub_type());
	std::cout << std::endl;
	std::cout << "3. ";
	id_to_name(User.get_pokemon_3().get_id());
	id_to_type(User.get_pokemon_3().get_main_type());
	id_to_type(User.get_pokemon_3().get_sub_type());
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_computer_entry(CRival Computer) {
	std::cout << std::endl;
	std::cout << "1. ";
	id_to_name(Computer.get_pokemon_1().get_id());
	id_to_type(Computer.get_pokemon_1().get_main_type());
	id_to_type(Computer.get_pokemon_1().get_sub_type());
	std::cout << std::endl;
	std::cout << "2. ";
	id_to_name(Computer.get_pokemon_2().get_id());
	id_to_type(Computer.get_pokemon_2().get_main_type());
	id_to_type(Computer.get_pokemon_2().get_sub_type());
	std::cout << std::endl;
	std::cout << "3. ";
	id_to_name(Computer.get_pokemon_3().get_id());
	id_to_type(Computer.get_pokemon_3().get_main_type());
	id_to_type(Computer.get_pokemon_3().get_sub_type());
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_user_in_battle_status(CPokemon in_battle)
{
	id_to_name(in_battle.get_id());
	std::cout << in_battle.get_hp() << std::endl;
}

void print_computer_in_battle_status(CPokemon in_battle)
{
	id_to_name(in_battle.get_id());
	std::cout << in_battle.get_hp() << std::endl;
}

int fin_checker(CTrainer User, CRival Computer)
{
	int user_knock_down_sum = 0;
	int computer_knock_down_sum = 0;

	user_knock_down_sum += User.get_pokemon_1().get_knock_down();
	user_knock_down_sum += User.get_pokemon_2().get_knock_down();
	user_knock_down_sum += User.get_pokemon_3().get_knock_down();

	computer_knock_down_sum += Computer.get_pokemon_1().get_knock_down();
	computer_knock_down_sum += Computer.get_pokemon_2().get_knock_down();
	computer_knock_down_sum += Computer.get_pokemon_3().get_knock_down();

	if (user_knock_down_sum == 3) {
		std::cout << "Computer Win" << std::endl;
		return 0;
	}
	else if (computer_knock_down_sum == 3) {
		std::cout << "You Win" << std::endl;
		return 0;
	}

	return 1;
}

bool valid_change_checker(CTrainer user, int user_change)
{
	if (user_change == 1) {
		if (user.get_pokemon_1().get_hp() == 0) {
			std::cout << "This pokemon is fainted." << std::endl;
			return false;
		}
		if (user.get_pokemon_1().get_id() == user.get_in_battle().get_id()) {
			std::cout << "This pokemon is already in the field." << std::endl;
			return false;
		}
	}
	else if (user_change == 2) {
		if (user.get_pokemon_2().get_hp() == 0) {
			std::cout << "This pokemon is fainted." << std::endl;
			return false;
		}
		if (user.get_pokemon_2().get_id() == user.get_in_battle().get_id()) {
			std::cout << "This pokemon is already in the field." << std::endl;
			return false;
		}
	}
	else if (user_change == 3) {
		if (user.get_pokemon_3().get_hp() == 0) {
			std::cout << "This pokemon is fainted." << std::endl;
			return false;
		}
		if (user.get_pokemon_3().get_id() == user.get_in_battle().get_id()) {
			std::cout << "This pokemon is already in the field." << std::endl;
			return false;
		}
	}
	else if (user_change == 0) {
		std::cout << "Going back." << std::endl;
		return true;
	}
	else {
		std::cout << "Choose from 1~3" << std::endl;
		return false;
	}
	return true;
}

void change_pokemon(CTrainer& User, int user_select)
{
	// ID of current in_battle pokemon
	int in_battle_id = User.get_in_battle().get_id();
	
	// Updating the pokemon's information
	if (User.get_pokemon_1().get_id() == in_battle_id) {
		User.set_pokemon_1(User.get_in_battle());
	}
	else if (User.get_pokemon_2().get_id() == in_battle_id) {
		User.set_pokemon_2(User.get_in_battle());
	}
	else if (User.get_pokemon_3().get_id() == in_battle_id) {
		User.set_pokemon_3(User.get_in_battle());
	}

	if (user_select == 1) {
		User.set_in_battle(User.get_pokemon_1());
	}
	else if (user_select == 2) {
		User.set_in_battle(User.get_pokemon_2());
	}
	else if (user_select == 3) {
		User.set_in_battle(User.get_pokemon_3());
	}
}

void battle_phase(CTrainer& User, CRival& Computer)
{
	int user_choose_skill;

	int user_IBT_ID = Computer.get_in_battle().get_id();
	int computer_IBT_ID = User.get_in_battle().get_id();
	
	std::cout << "Skills" << std::endl;
	std::cout << "1.";
	id_to_skill(User.get_in_battle().get_skill_1());
	std::cout << "2.";
	id_to_skill(User.get_in_battle().get_skill_2());
	std::cout << std::endl;

	while (1) {
		std::cin >> user_choose_skill;
		if (user_choose_skill == 1 || user_choose_skill == 2) break;
		else {
			std::cout << "Give correct number : 1 ~ 2" << std::endl;
		}
	}

	// User attack first
	if (User.get_in_battle().get_speed() > Computer.get_in_battle().get_speed()) {
		bool fainted = false;
		fainted = attack_computer(User, Computer, user_choose_skill);
		update_phase(User, Computer);
		// check if user wins
		if (!fin_checker(User, Computer)) {
			std::cout << "Your rival doesn't have any pokemon to fight with!" << std::endl;
			std::cout << "You win!" << std::endl;
			return;
		}

		if (!fainted) {
			attack_user(Computer, User);
			// check if computer wins
			update_phase(User, Computer);
			if (!fin_checker(User, Computer)) {
				std::cout << "You doesn't have any pokemon to fight with!" << std::endl;
				std::cout << "Computer win!" << std::endl;
				return;
			}
		}
	}
	// Computer attack first
	else if (User.get_in_battle().get_speed() < Computer.get_in_battle().get_speed()) {
		bool fainted = false;
		fainted = attack_user(Computer, User);
		update_phase(User, Computer);
		// check if computer wins
		if (!fin_checker(User, Computer)) {
			std::cout << "You doesn't have any pokemon to fight with!" << std::endl;
			std::cout << "Computer win!" << std::endl;
			return;
		}

		
		if (!fainted) {
			attack_computer(User, Computer, user_choose_skill);
			// check if user wins
			update_phase(User, Computer);
			if (!fin_checker(User, Computer)) {
				std::cout << "Your rival doesn't have any pokemon to fight with!" << std::endl;
				std::cout << "You win!" << std::endl;
				return;
			}
		}
	}

	// if speed is same use random function to make 1/2.
	else {
		int random = rand() % 100 + 1;
		// User attack first
		if (random > 50) {
			bool fainted = false;
			fainted = attack_computer(User, Computer, user_choose_skill);
			// check if user wins
			update_phase(User, Computer);
			if (!fin_checker(User, Computer)) {
				std::cout << "Your rival doesn't have any pokemon to fight with!" << std::endl;
				std::cout << "You win!" << std::endl;
				return;
			}

			if (!fainted) {
				attack_user(Computer, User);
				// check if computer wins
				update_phase(User, Computer);
				if (!fin_checker(User, Computer)) {
					std::cout << "You doesn't have any pokemon to fight with!" << std::endl;
					std::cout << "Computer win!" << std::endl;
					return;
				}
			}
		}
		// Computer attack first
		else {
			bool fainted = false;
			fainted = attack_user(Computer, User);
			// check if computer wins
			update_phase(User, Computer);
			if (!fin_checker(User, Computer)) {
				std::cout << "You doesn't have any pokemon to fight with!" << std::endl;
				std::cout << "Computer win!" << std::endl;
				return;
			}

			if (!fainted) {
				attack_computer(User, Computer, user_choose_skill);
				// check if user wins
				update_phase(User, Computer);
				if (!fin_checker(User, Computer)) {
					std::cout << "Your rival doesn't have any pokemon to fight with!" << std::endl;
					std::cout << "You win!" << std::endl;
					return;
				}
			}
		}
	}
}

void update_phase(CTrainer& User, CRival& Computer)
{
	int user_id = User.get_in_battle().get_id();
	int computer_id = Computer.get_in_battle().get_id();

	if (User.get_pokemon_1().get_id() == user_id) {
		User.set_pokemon_1(User.get_in_battle());
	}
	else if (User.get_pokemon_2().get_id() == user_id) {
		User.set_pokemon_2(User.get_in_battle());
	}
	else if (User.get_pokemon_3().get_id() == user_id) {
		User.set_pokemon_3(User.get_in_battle());
	}

	if (Computer.get_pokemon_1().get_id() == computer_id) {
		Computer.set_pokemon_1(Computer.get_in_battle());
	}
	else if (Computer.get_pokemon_2().get_id() == computer_id) {
		Computer.set_pokemon_2(Computer.get_in_battle());
	}
	else if (Computer.get_pokemon_3().get_id() == computer_id) {
		Computer.set_pokemon_3(Computer.get_in_battle());
	}
}

bool attack_user(CRival& Computer, CTrainer& User)
{
	int computer_skill_damage_1 = 0;
	int computer_skill_damage_2 = 0;

	int skill_type_1 = 0;
	int skill_type_2 = 0;

	int defense_type_1 = User.get_in_battle().get_main_type();
	int defense_type_2 = User.get_in_battle().get_sub_type();

	int ability_attacker = Computer.get_in_battle().get_ability();
	int ability_defender = User.get_in_battle().get_ability();

	int attacker_attack = Computer.get_in_battle().get_attack();
	int defender_defense = User.get_in_battle().get_defense();

	int attacker_ID = Computer.get_in_battle().get_id();
	int defender_ID = User.get_in_battle().get_id();

	int attacker_hp = Computer.get_in_battle().get_hp();
	int defender_hp = User.get_in_battle().get_hp();

	// If it is true pokemon hit the skill with 100% ratio.
	bool no_miss_skill = false;

	// prevent 1 hit K.O.
	bool sturdy = false;

	// absorb electric type move
	bool lightning_rod = false;

	// Calculate both skills for computer : AI
	computer_skill_damage_1 = id_to_skill_dmg(Computer.get_in_battle().get_skill_1());
	skill_type_1 = Computer.get_in_battle().get_skill_1();

	computer_skill_damage_2 = id_to_skill_dmg(Computer.get_in_battle().get_skill_2());
	skill_type_2 = Computer.get_in_battle().get_skill_2();

	int skill_1_accuracy = id_to_accuracy(skill_type_1);
	int skill_2_accuracy = id_to_accuracy(skill_type_2);


	// Check if the skill type is same with the pokemon's sub_type : 자속보정
	if (skill_type_1 == Computer.get_in_battle().get_main_type()) {
		computer_skill_damage_1 = int(float(computer_skill_damage_1) * 1.5);
	}
	if (skill_type_2 == Computer.get_in_battle().get_main_type()) {
		computer_skill_damage_2 = int(float(computer_skill_damage_2) * 1.5);
	}


	// Check the skill type effects to opponent pokemon's main_type
	computer_skill_damage_1 = int(float(computer_skill_damage_1) * type_checker(skill_type_1, defense_type_1));
	computer_skill_damage_2 = int(float(computer_skill_damage_2) * type_checker(skill_type_2, defense_type_1));

	// Check the skill type effects to opponent pokemon's sub_type
	computer_skill_damage_1 = int(float(computer_skill_damage_1) * type_checker(skill_type_1, defense_type_2));
	computer_skill_damage_2 = int(float(computer_skill_damage_2) * type_checker(skill_type_2, defense_type_2));

	// Check the ability of attacker
	// 2. Overgrowth -- > * 1.5 damage of grass type skill, when the pokemon's hp is less than 30%
	if (ability_attacker == 2) {
		if (attacker_hp < 0.3 * id_to_hp(attacker_ID)) {
			std::cout << "Overgrowth activated" << std::endl;
			if(skill_type_1 == 2) computer_skill_damage_1 = int(float(computer_skill_damage_1) * 1.5);
			if(skill_type_2 == 2) computer_skill_damage_2 = int(float(computer_skill_damage_2) * 1.5);
		}
	}
	// 3. Torrent -- > * 1.5 damage of water type skill, when the pokemon's hp is less than 30%
	else if (ability_attacker == 3) {
		if (attacker_hp < 0.3 * id_to_hp(attacker_ID)) {
			std::cout << "Torrent activated" << std::endl;
			if (skill_type_1 == 3) computer_skill_damage_1 = int(float(computer_skill_damage_1) * 1.5);
			if (skill_type_2 == 3) computer_skill_damage_2 = int(float(computer_skill_damage_2) * 1.5);
		}
	}
	// 4. Blaze -- > * 1.5 damage of fire type skill, when the pokemon's hp is less than 30%
	else if (ability_attacker == 4) {
		if (attacker_hp < 0.3 * id_to_hp(attacker_ID)) {
			std::cout << "Blaze activated" << std::endl;
			if (skill_type_1 == 4) computer_skill_damage_1 = int(float(computer_skill_damage_1) * 1.5);
			if (skill_type_2 == 4) computer_skill_damage_2 = int(float(computer_skill_damage_2) * 1.5);
		}
	}
	// 5. Keen Eye -- > No missing skill
	else if (ability_attacker == 5) {
		std::cout << "Keen Eye activated" << std::endl;
		no_miss_skill = true;
	}
	// 7. Tinted Lens -- > Double the damage that is "Not very effective"
	else if (ability_attacker == 7) {
		int count_1 = 1;
		int count_2 = 1;
		if (type_checker(skill_type_1, defense_type_1) == 0.5) {
			id_to_ability(attacker_ID);
			std::cout << "Activated" << std::endl;
			computer_skill_damage_1 = int(float(computer_skill_damage_1) * 2);
			std::cout << "Double the damage : " << count_1 << std::endl;
			count_1++;
		}
		if (type_checker(skill_type_1, defense_type_2) == 0.5) {
			id_to_ability(attacker_ID);
			std::cout << "Activated" << std::endl;
			computer_skill_damage_1 = int(float(computer_skill_damage_1) * 2);
			std::cout << "Double the damage : " << count_1 << std::endl;
			count_1++;
		}
		if (type_checker(skill_type_2, defense_type_1) == 0.5) {
			id_to_ability(attacker_ID);
			std::cout << "Activated" << std::endl;
			computer_skill_damage_2 = int(float(computer_skill_damage_2) * 2);
			std::cout << "Double the damage : " << count_2 << std::endl;
			count_2++;
		}
		if (type_checker(skill_type_2, defense_type_2) == 0.5) {
			id_to_ability(attacker_ID);
			std::cout << "Activated" << std::endl;
			computer_skill_damage_2 = int(float(computer_skill_damage_2) * 2);
			std::cout << "Double the damage : " << count_2 << std::endl;
			count_2++;
		}
	}
	// 9. Neuroforce -- > The Pokemon deals 25% more damage with super effective moves.
	else if (ability_attacker == 9) {
		int count_1 = 1;
		int count_2 = 1;
		if (type_checker(skill_type_1, defense_type_1) == 2) {
			std::cout << "Because of Neuroforce." << std::endl;
			std::cout << "It increase the damage : " << count_1 << std::endl;
			computer_skill_damage_1 = int(float(computer_skill_damage_1) * 1.25);
			count_1++;
		}
		if (type_checker(skill_type_1, defense_type_2) == 2) {
			std::cout << "Because of Neuroforce." << std::endl;
			std::cout << "It increase the damage : " << count_1 << std::endl;
			computer_skill_damage_1 = int(float(computer_skill_damage_1) * 1.25);
			count_1++;
		}
		if (type_checker(skill_type_2, defense_type_1) == 2) {
			std::cout << "Because of Neuroforce." << std::endl;
			std::cout << "It increase the damage : " << count_2 << std::endl;
			computer_skill_damage_2 = int(float(computer_skill_damage_2) * 1.25);
			count_2++;
		}
		if (type_checker(skill_type_2, defense_type_2) == 2) {
			std::cout << "Because of Neuroforce." << std::endl;
			std::cout << "It increase the damage : " << count_2 << std::endl;
			computer_skill_damage_2 = int(float(computer_skill_damage_2) * 1.25);
			count_2++;
		}
	}
	

	// Check the ability of opponents
	
	// 6. sturdy --> prevent from 1 hit K.O.
	if (ability_defender == 6) {
		// only activate when the defender has fool Hp.
		if(defender_hp == id_to_hp(defender_ID)) sturdy = true;
	}
	// 8. Levitate -- > Not hit by GROUND attacks.
	else if (ability_defender == 8) {
		if (skill_type_1 == 13) {
			std::cout << "Because of levitate, it doesn't have and effect!" << std::endl;
			computer_skill_damage_1 = 0;
		}
		if (skill_type_2 == 13) {
			std::cout << "Because of levitate, it doesn't have and effect!" << std::endl;
			computer_skill_damage_2 = 0;
		}
	}
	// 10. Multiscale -- > Halves the damage the Pokemon takes while at full HP.
	else if (ability_defender == 10) {
		// only activate when the defender has fool Hp.
		if (defender_hp == id_to_hp(defender_ID)) {
			std::cout << "Because of multisclae, It halves the damage" << std::endl;
			computer_skill_damage_1 /= 2;
			computer_skill_damage_2 /= 2;
		}
	}

	// select which skill to use!
	// 1. Base on the total damage
	// 2. 60% to choose the higher damage, 40% to choose the lower damage
	// check the damage
	int random_select = rand() % 100 + 1;
	int final_skill_damage;
	int final_skill_type;
	int final_accuracy;
	

	if (computer_skill_damage_1 > computer_skill_damage_2) {
		// 40 % to choose lower damage
		if (random_select > 60) {
			final_skill_damage = computer_skill_damage_2;
			final_skill_type = skill_type_2;
			final_accuracy = skill_2_accuracy;
		}
		else {
			final_skill_damage = computer_skill_damage_1;
			final_skill_type = skill_type_1;
			final_accuracy = skill_1_accuracy;
		}
	}
	else {
		// 40 % to choose lower damage
		if (random_select > 60) {
			final_skill_damage = computer_skill_damage_1;
			final_skill_type = skill_type_1;
			final_accuracy = skill_1_accuracy;
		}
		else {
			final_skill_damage = computer_skill_damage_2;
			final_skill_type = skill_type_2;
			final_accuracy = skill_2_accuracy;
		}
	}

	// 1. Lightning Rod, absorb electric type skill : No damage, Double the attack
	if (ability_defender == 1) {
		if (final_skill_type == 1) {
			final_skill_damage = 0;
			id_to_name(attacker_ID);
			std::cout << "used ";
			id_to_skill(final_skill_type);
			std::cout << "to ";
			id_to_name(defender_ID);
			std::cout << std::endl;
			std::cout << "It doesn't have any effect" << std::endl;
			std::cout << "Because of Lightning Rod, it doesn't have any effect!" << std::endl;
			std::cout << "It doubles the";
			id_to_name(defender_ID);
			std::cout << " attack!" << std::endl;
			User.get_in_battle().set_attack(User.get_in_battle().get_attack() * 2);
			update_phase(User, Computer);
			return 0;
		}
	}

	// check the damage
	if (final_skill_damage == 0) {
		id_to_name(attacker_ID);
		std::cout << "used ";
		id_to_skill(final_skill_type);
		std::cout << "to ";
		id_to_name(defender_ID);
		std::cout << std::endl;
		std::cout << "It doesn't have any effect" << std::endl;
		return 0;
	}
	else {
		final_skill_damage = defender_defense - (attacker_attack + final_skill_damage);
		// dafault damage = -1;
		if (final_skill_damage > 0) {
			final_skill_damage = -1;
		}
	}

	// Check if the skill will hit or not, depend on accuracy.
	// Keen eye turn the no_miss_skill = true for 100% accuracy of any skills
	if (no_miss_skill == false) {
		random_select = rand() % 100 + 1;
		if (random_select > final_accuracy) {
			id_to_name(attacker_ID);
			std::cout << "used ";
			id_to_skill(final_skill_type);
			std::cout << "to ";
			id_to_name(defender_ID);
			std::cout << std::endl;
			std::cout << "Skill does not hit!" << std::endl;
			return 0;
		}
	}

	// Check sturdy
	if (sturdy == true) {
		// If the skill was one hit K.O. damage
		if (defender_hp += final_skill_damage < 0) {
			id_to_name(attacker_ID);
			std::cout << "used ";
			id_to_skill(final_skill_type);
			std::cout << "to ";
			id_to_name(defender_ID);
			std::cout << std::endl;
			std::cout << "Sturdy prevents one hit K.O." << std::endl;
			User.get_in_battle().set_hp(1);
			update_phase(User, Computer);
			return 0;
		}
	}

	id_to_name(attacker_ID);
	std::cout << "used ";
	id_to_skill(final_skill_type);
	std::cout << "to ";
	id_to_name(defender_ID);
	std::cout << std::endl;

	if ((type_checker(final_skill_type, defense_type_1) * type_checker(final_skill_type, defense_type_2)) >= 2) {
		std::cout << "Super effective!" << std::endl;
	}
	else if ((type_checker(final_skill_type, defense_type_1) * type_checker(final_skill_type, defense_type_2)) <= float(0.5)) {
		std::cout << "Not very effective!" << std::endl;
	}

	if (defender_hp + final_skill_damage <= 0) {
		id_to_name(defender_ID);
		std::cout << "Fainted" << std::endl;
		User.get_in_battle().set_hp(0);
		User.get_in_battle().set_knock_down(1);

		update_phase(User, Computer);

		if (!fin_checker(User, Computer)) {
			return 1;
		}

		// print the entry
		print_user_entry(User);
		std::cout << "Select the pokemon you want to change." << std::endl;

		int user_select;
		while (1) {
			std::cin >> user_select;
			// check that the pokemon can be changed
			if (valid_change_checker(User, user_select)) break;
		}

		// change the pokemon
		change_pokemon(User, user_select);
		std::cout << "Go!";
		id_to_name(User.get_in_battle().get_id());
		std::cout << std::endl;

		return 1;
	}

	User.get_in_battle().set_hp(defender_hp + final_skill_damage);
	return 0;
}

bool attack_computer(CTrainer& User, CRival& Computer, const int skill_number)
{
	int user_skill_damage = 0;

	int skill_type = 0;
	int defense_type_1 = Computer.get_in_battle().get_main_type();
	int defense_type_2 = Computer.get_in_battle().get_sub_type();

	int ability_attacker = User.get_in_battle().get_ability();
	int ability_defender = Computer.get_in_battle().get_ability();

	int attacker_attack = User.get_in_battle().get_attack();
	int defender_defense = Computer.get_in_battle().get_defense();

	int attacker_hp = User.get_in_battle().get_hp();
	int defender_hp = Computer.get_in_battle().get_hp();

	int attacker_ID = User.get_in_battle().get_id();
	int defender_ID = Computer.get_in_battle().get_id();


	// If it is true pokemon hit the skill with 100% ratio.
	bool no_miss_skill = false;

	// prevent 1 hit K.O.
	bool sturdy = false;

	// Check if the skill type is same with the pokemon's main_type
	if (skill_number == 1) {
		user_skill_damage = id_to_skill_dmg(User.get_in_battle().get_skill_1());
		skill_type = User.get_in_battle().get_skill_1();
	}
	else if (skill_number == 2) {
		user_skill_damage = id_to_skill_dmg(User.get_in_battle().get_skill_2());
		skill_type = User.get_in_battle().get_skill_2();
	}

	int skill_accuracy = id_to_accuracy(skill_type);

	// Check if the skill type is same with the pokemon's sub_type
	if (skill_type == User.get_in_battle().get_main_type()) {
		user_skill_damage = int(float(user_skill_damage) * 1.5);
	}

	// Check the skill type effects to opponent pokemon's main_type
	user_skill_damage = int(float(user_skill_damage) * type_checker(skill_type, defense_type_1));

	// Check the skill type effects to opponent pokemon's sub_type
	user_skill_damage = int(float(user_skill_damage) * type_checker(skill_type, defense_type_2));

	// Check the ability of attacker
	// 2. Overgrowth -- > * 1.5 damage of grass type skill, when the pokemon's hp is less than 30%
	if (ability_attacker == 2) {
		if (attacker_hp < 0.3 * id_to_hp(attacker_ID)) {
			std::cout << "Overgrowth activated" << std::endl;
			if (skill_type == 2) user_skill_damage = int(float(user_skill_damage) * 1.5);
		}
	}
	// 3. Torrent -- > * 1.5 damage of water type skill, when the pokemon's hp is less than 30%
	else if (ability_attacker == 3) {
		if (attacker_hp < 0.3 * id_to_hp(attacker_ID)) {
			std::cout << "Torrent activated" << std::endl;
			if (skill_type == 3) user_skill_damage = int(float(user_skill_damage) * 1.5);
		}
	}
	// 4. Blaze -- > * 1.5 damage of fire type skill, when the pokemon's hp is less than 30%
	else if (ability_attacker == 4) {
		if (attacker_hp < 0.3 * id_to_hp(attacker_ID)) {
			std::cout << "Blaze activated" << std::endl;
			if (skill_type == 4) user_skill_damage = int(float(user_skill_damage) * 1.5);
		}
	}
	// 5. Keen Eye -- > No missing skill
	else if (ability_attacker == 5) {
		std::cout << "Keen Eye activated" << std::endl;
		no_miss_skill = true;
	}
	// 7. Tinted Lens -- > Double the damage that is "Not very effective"
	else if (ability_attacker == 7) {
		int count_1 = 1;
		int count_2 = 1;
		if (type_checker(skill_type, defense_type_1) == 0.5) {
			id_to_ability(attacker_ID);
			std::cout << "Activated" << std::endl;
			user_skill_damage = int(float(user_skill_damage) * 2);
			std::cout << "Double the damage : " << count_1 << std::endl;
			count_1++;
		}
		if (type_checker(skill_type, defense_type_2) == 0.5) {
			id_to_ability(attacker_ID);
			std::cout << "Activated" << std::endl;
			user_skill_damage = int(float(user_skill_damage) * 2);
			std::cout << "Double the damage : " << count_1 << std::endl;
			count_1++;
		}
	}
	// 9. Neuroforce -- > The Pokemon deals 25% more damage with super effective moves.
	else if (ability_attacker == 9) {
		int count_1 = 1;
		int count_2 = 1;
		if (type_checker(skill_type, defense_type_1) == 2) {
			std::cout << "Because of Neuroforce." << std::endl;
			user_skill_damage = int(float(user_skill_damage) * 1.25);
			std::cout << "It increase the damage : " << count_1 << std::endl;
			count_1++;
		}
		if (type_checker(skill_type, defense_type_2) == 2) {
			std::cout << "Because of Neuroforce." << std::endl;
			user_skill_damage = int(float(user_skill_damage) * 1.25);
			std::cout << "It increase the damage : " << count_1 << std::endl;
			count_1++;
		}
	}


	// Check the ability of opponents
	// 1. Lightning Rod, absorb electric type skill : No damage, Double the attack
	if (ability_defender == 1) {
		if (skill_type == 1) {
			user_skill_damage = 0;
			std::cout << "Because of Lightning Rod, it doesn't have any effect!" << std::endl;
			std::cout << "It doubles the ";
			id_to_name(defender_ID);
			std::cout << " attack!" << std::endl;
			Computer.get_in_battle().set_attack(Computer.get_in_battle().get_attack() * 2);
		}
	}
	// 6. sturdy --> prevent from 1 hit K.O.
	else if (ability_defender == 6) {
		// only activate when the defender has fool Hp.
		if (defender_hp == id_to_hp(defender_ID)) sturdy = true;
	}
	// 8. Levitate -- > Not hit by GROUND attacks.
	else if (ability_defender == 8) {
		if (skill_type == 13) {
			std::cout << "Because of levitate, it doesn't have and effect!" << std::endl;
			user_skill_damage = 0;
		}
	}
	// 10. Multiscale -- > Halves the damage the Pokemon takes while at full HP.
	else if (ability_defender == 10) {
		// only activate when the defender has fool Hp.
		if (defender_hp == id_to_hp(defender_ID)) {
			std::cout << "Because of multisclae, It halves the damage" << std::endl;
			user_skill_damage /= 2;
		}
	}

	// check the damage
	if (user_skill_damage == 0) {
		id_to_name(attacker_ID);
		std::cout << "used ";
		id_to_skill(skill_type);
		std::cout << "to ";
		id_to_name(defender_ID);
		std::cout << std::endl;
		std::cout << "It doesn't have any effect" << std::endl;
		update_phase(User, Computer);
		return 0;
	}
	else {
		user_skill_damage = defender_defense - (attacker_attack + user_skill_damage);
		// dafault damage = -1;
		if (user_skill_damage > 0) {
			user_skill_damage = -1;
		}
	}

	// Check if the skill will hit or not, depend on accuracy.
	// Keen eye turn the no_miss_skill = true for 100% accuracy of any skills
	if (no_miss_skill == false) {
		int random_select = rand() % 100 + 1;
		random_select = rand() % 100 + 1;
		if (random_select > skill_accuracy) {
			id_to_name(attacker_ID);
			std::cout << "used ";
			id_to_skill(skill_type);
			std::cout << "to ";
			id_to_name(defender_ID);
			std::cout << std::endl;
			std::cout << "Skill does not hit!" << std::endl;
			return 0;
		}
	}

	// Check sturdy
	if (sturdy == true) {
		// If the skill was one hit K.O. damage
		if (defender_hp += user_skill_damage < 0) {
			id_to_name(attacker_ID);
			std::cout << "used ";
			id_to_skill(skill_type);
			std::cout << "to ";
			id_to_name(defender_ID);
			std::cout << std::endl;
			std::cout << "Sturdy prevents one hit K.O." << std::endl;
			Computer.get_in_battle().set_hp(1);
			update_phase(User, Computer);
			return 0;
		}
	}

	id_to_name(attacker_ID);
	std::cout << "used ";
	id_to_skill(skill_type);
	std::cout << "to ";
	id_to_name(defender_ID);
	std::cout << std::endl;

	if ((type_checker(skill_type, defense_type_1) * type_checker(skill_type, defense_type_2)) >= float(2)) {
		std::cout << "Super effective!" << std::endl;
	}
	else if ((type_checker(skill_type, defense_type_1) * type_checker(skill_type, defense_type_2)) <= float(0.5)) {
		std::cout << "Not very effective!" << std::endl;
	}
	else if (type_checker(skill_type, defense_type_1) * type_checker(skill_type, defense_type_2) == 0) {
		std::cout << "No effect" << std::endl;
	}

	if (defender_hp + user_skill_damage <= 0) {
		id_to_name(defender_ID);
		std::cout << "Fainted" << std::endl;
		Computer.get_in_battle().set_hp(0);
		Computer.get_in_battle().set_knock_down(1);

		update_phase(User, Computer);

		if (Computer.get_pokemon_1().get_knock_down() == true) {
			if (Computer.get_pokemon_2().get_knock_down() == true) {
				Computer.set_in_battle(Computer.get_pokemon_3());
			}
			else {
				Computer.set_in_battle(Computer.get_pokemon_2());
			}
		}
		
		return 1;
	}
		
	Computer.get_in_battle().set_hp(defender_hp + user_skill_damage);
	update_phase(User, Computer);
	return 0;
}

float type_checker(const int attack_type, const int defense_type) {
	// *1 if defense_type = 0 --> only when the pokemon doesn't have sub_type
	if (defense_type == 0) {
		return 1;
	}

	// Attacking type is electric
	if (attack_type == 1) {
		if (defense_type == 1) return 0.5;
		else if (defense_type == 2) return 0.5;
		else if (defense_type == 3) return 2;
		else if (defense_type == 5) return 2;
		else if (defense_type == 7) return 0.5;
		else if (defense_type == 13) return 0;
		else return 1;
	}

	// Attacking type is Grass
	if (attack_type == 2) {
		if (defense_type == 2) return 0.5;
		else if (defense_type == 3) return 2;
		else if (defense_type == 4) return 0.5;
		else if (defense_type == 5) return 0.5;
		else if (defense_type == 6) return 0.5;
		else if (defense_type == 7) return 0.5;
		else if (defense_type == 9) return 0.5;
		else if (defense_type == 12) return 2;
		else if (defense_type == 13) return 2;
		else return 1;
	}

	// Attacking type is Water
	if (attack_type == 3) {
		if (defense_type == 2) return 0.5;
		else if (defense_type == 3) return 0.5;
		else if (defense_type == 4) return 2;
		else if (defense_type == 7) return 0.5;
		else if (defense_type == 12) return 2;
		else if (defense_type == 13) return 2;
		else return 1;
	}

	// Attacking type is Fire
	if (attack_type == 4) {
		if (defense_type == 2) return 2;
		else if (defense_type == 3) return 0.5;
		else if (defense_type == 4) return 0.5;
		else if (defense_type == 6) return 2;
		else if (defense_type == 7) return 0.5;
		else if (defense_type == 12) return 0.5;
		else return 1;
	}

	// Attacking type is Fly
	if (attack_type == 5) {
		if (defense_type == 1) return 0.5;
		else if (defense_type == 2) return 2;
		else if (defense_type == 6) return 2;
		else if (defense_type == 12) return 0.5;
		else return 1;
	}

	// Attacking type is Bug
	if (attack_type == 6) {
		if (defense_type == 2) return 2;
		else if (defense_type == 4) return 0.5;
		else if (defense_type == 5) return 0.5;
		else if (defense_type == 8) return 2;
		else if (defense_type == 9) return 0.5;
		else if (defense_type == 10) return 0.5;
		else return 1;
	}

	// Attacking type is Dragon
	if (attack_type == 7) {
		if (defense_type == 7) return 2;
		else return 1;
	}

	// Attacking type is Esper
	if (attack_type == 8) {
		if (defense_type == 8) return 0.5;
		else if (defense_type == 9) return 2;
		else return 1;
	}

	// Attacking type is Poison
	if (attack_type == 9) {
		if (defense_type == 2) return 2;
		else if (defense_type == 9) return 0.5;
		else if (defense_type == 10) return 0.5;
		else if (defense_type == 12) return 0.5;
		else if (defense_type == 13) return 0.5;
		else return 1;
	}

	// Attacking type is Ghost
	if (attack_type == 10) {
		if (defense_type == 8) return 2;
		else if (defense_type == 10) return 2;
		else if (defense_type == 11) return 0;
		else return 1;
	}

	// Attacking type is Normal
	if (attack_type == 11) {
		if (defense_type == 10) return 0;
		else if (defense_type == 12) return 0.5;
		else return 1;
	}

	// Attacking type is Rock
	if (attack_type == 12) {
		if (defense_type == 4) return 2;
		else if (defense_type == 5) return 2;
		else if (defense_type == 6) return 2;
		else if (defense_type == 13) return 0.5;
		else return 1;
	}

	// Attacking type is Ground
	if (attack_type == 13) {
		if (defense_type == 1) return 2;
		else if (defense_type == 2) return 0.5;
		else if (defense_type == 4) return 2;
		else if (defense_type == 5) return 0;
		else if (defense_type == 6) return 0.5;
		else if (defense_type == 9) return 2;
		else if (defense_type == 12) return 2;
		else return 1;
	}
}

void init_User(CTrainer& User, CTrainer& Save)
{
	User.set_pokemon_1(Save.get_pokemon_1());
	User.set_pokemon_2(Save.get_pokemon_2());
	User.set_pokemon_3(Save.get_pokemon_3());
	User.set_in_battle(Save.get_in_battle());
}

void init_Computer(CRival& Computer, CRival& Save)
{
	Computer.set_pokemon_1(Save.get_pokemon_1());
	Computer.set_pokemon_2(Save.get_pokemon_2());
	Computer.set_pokemon_3(Save.get_pokemon_3());
	Computer.set_in_battle(Save.get_in_battle());
}