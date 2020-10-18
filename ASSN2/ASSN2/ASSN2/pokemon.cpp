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

// Pokemon skill table
// 1. Thunderbolt ( 95 )
// 2. Solar Beam ( 110 )
// 3. Hydro Pump ( 120 )
// 4. Flamethrower ( 95 )
// 5. Wing Attack ( 80 )
// 6. X-Scissor ( 75 )
// 7. Outrage ( 120 )
// 8. Psychic ( 90 )
// 9. Cross Poison ( 75 )
// 10. Shadow Ball ( 85 )
// 11. Tackle ( 50 )
// 12. Rock Slide ( 80 )
// 13. Earthquake ( 100 )

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
void id_to_name(int id);


// Id to name
// input : type ID
// print the type of pokemon
void id_to_type(int id);

// Id to skill
// input : type ID
// print the name of skill
void id_to_skill(int id);

// Id to skill damage
// input : type ID
// return the damage of skill
int id_to_skill_dmg(int id);

// Id to ability
// input : ability ID
// print the name of ability
void id_to_ability(int id);


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

// Initiallizing the user's data
void init_User(CTrainer& User, CTrainer& Save);
// Initiallizing the computer's data
void init_Computer(CRival& Computer, CRival& Save);

int main() {
	// want to make the random function well
	srand((unsigned int)time(0));

	// 1. Make 10 pokemons, 1 Trainer(Player), 1 Rival(Computer)
	// Constructor -- > main_type, sub_type, hp, attack, defense, speed, skill_1, skill_2, knock_down
	CPokemon* pokemonList[10];
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
		if (rival_pokemon_3 == rival_pokemon_1) {
			continue;
		}
		break;
	}

	Computer.set_pokemon_1(*pokemonList[rival_pokemon_1]);
	Computer.set_pokemon_2(*pokemonList[rival_pokemon_2]);
	Computer.set_pokemon_3(*pokemonList[rival_pokemon_3]);
	Computer.set_in_battle(*pokemonList[rival_pokemon_1]);
	
	// Choosing different random skill
	int rival_pokemon_1_random_skill = random_type_chooser();
	int rival_pokemon_2_random_skill = random_type_chooser();
	int rival_pokemon_3_random_skill = random_type_chooser();

	Computer.get_pokemon_1().set_skill_2(rival_pokemon_1_random_skill);
	Computer.get_pokemon_2().set_skill_2(rival_pokemon_2_random_skill);
	Computer.get_pokemon_3().set_skill_2(rival_pokemon_3_random_skill);

	
	//Computer.get_pokemon_1().print_pokemon_status();
	//Computer.get_pokemon_2().print_pokemon_status();
	//Computer.get_pokemon_3().print_pokemon_status();
	

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
						print_user_entry(User);
						std::cout << "Select the pokemon you want to change." << std::endl;
						int user_select;
						while (1) {
							std::cin >> user_select;
							if (valid_change_checker(User, user_select)) break;
						}
						change_pokemon(User, user_select);
					}
					// Battle phase
					else if (user_input == 1) {


						battle_phase(User, Computer);
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
					int user_pokemon_1_random_skill = random_type_chooser();
					User.set_pokemon_1(*pokemonList[user_choose_pokemon - 1]);
					User.get_pokemon_1().set_skill_2(user_pokemon_1_random_skill);
				}
				else if (loop_count == 1) {
					int user_pokemon_2_random_skill = random_type_chooser();
					User.set_pokemon_2(*pokemonList[user_choose_pokemon - 1]);
					User.get_pokemon_2().set_skill_2(user_pokemon_2_random_skill);
				}
				else if (loop_count == 2) {
					int user_pokemon_3_random_skill = random_type_chooser();
					User.set_pokemon_3(*pokemonList[user_choose_pokemon - 1]);
					User.get_pokemon_3().set_skill_2(user_pokemon_3_random_skill);
				}

				loop_count++;
			}
			User.set_in_battle(User.get_pokemon_1());
			std::cout << "Heading to the main menu!" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
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

void id_to_skill(int id) {
	if (id == 0) std::cout << "";
	else if (id == 1) std::cout << "Thunderbolt (95) ";
	else if (id == 2) std::cout << "Solar Beam (110) ";
	else if (id == 3) std::cout << "Hydro Pump (120) ";
	else if (id == 4) std::cout << "Flamethrower (95) ";
	else if (id == 5) std::cout << "Wing Attack (80) ";
	else if (id == 6) std::cout << "X-Scissor (75) ";
	else if (id == 7) std::cout << "Outrage (120) ";
	else if (id == 8) std::cout << "Psychic (90) ";
	else if (id == 9) std::cout << "Cross Poison (75) ";
	else if (id == 10) std::cout << "Shadow Ball (85) ";
	else if (id == 11) std::cout << "Tackle (50) ";
	else if (id == 12) std::cout << "Rock Slide (80) ";
	else if (id == 13) std::cout << "Earthquake (100) ";
}

int id_to_skill_dmg(int id)
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
}

void id_to_ability(int id)
{

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
	int computer_choose_skill = rand() % 2 + 1;

	int user_skill_damage;
	int computer_skill_damage;
	
	std::cout << "Skills" << std::endl;
	std::cout << "1.";
	id_to_skill(User.get_in_battle().get_skill_1());
	std::cout << "2.";
	id_to_skill(User.get_in_battle().get_skill_2());
	std::cout << std::endl;

	while (1) {
		std::cin >> user_choose_skill;
		if (user_choose_skill == 1) { 
			user_skill_damage = id_to_skill_dmg(User.get_in_battle().get_skill_1());
			break;
		}
		else if (user_choose_skill == 2) {
			user_skill_damage = id_to_skill_dmg(User.get_in_battle().get_skill_2());
			break;
		}
		else {
			std::cout << "Give correct number : 1 ~ 2" << std::endl;
		}
	}

	if (computer_choose_skill == 1) {
		computer_skill_damage = id_to_skill_dmg(Computer.get_in_battle().get_skill_1());
	}
	else if (computer_choose_skill == 2) {
		computer_skill_damage = id_to_skill_dmg(Computer.get_in_battle().get_skill_2());
	}

	// Check if the skill type is same with the pokemon's main_type

	// Check if the skill type is same with the pokemon's sub_type

	// Check the skill type effects to opponent pokemon's main_type

	// Check the skill type effects to opponent pokemon's sub_type

	// Check the ability of attacker

	// Check the ability of opponents


	// User attack first
	if (User.get_in_battle().get_speed() > Computer.get_in_battle().get_speed()) {

	}
	// Computer attack first
	else if (User.get_in_battle().get_speed() < Computer.get_in_battle().get_speed()) {

	}
	else {
		int random = rand() % 100 + 1;
		// User attack first
		if (random > 50) {

		}
		// Computer attack first
		else {

		}
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
