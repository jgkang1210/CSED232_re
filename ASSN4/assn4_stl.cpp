#include <iostream>
#include <ctime>
#include <limits>
#include "Pokemon.h"
#include "Pokedex.h"

// Creative IT Eng, 20190348, JungillKang

// Pomemon list
//
//1. Bulbasaur, �̻��ؾ�
//2. Ivysaur, �̻���Ǯ
//3. Venusaur, �̻��ز�
//4. Charmander, ���̸�
//5. Charmeleon, ���ڵ�
//6. Charizard, ���ڸ�
//7. Squirtle, ���α�
//8. Wartortle, ��Ϻα�
//9. Blastoise, �źϿ�
//10. Caterpie, ĳ����
//11. Metapod, �ܵ���
//12. Butterfree, ������
//13. Weedle, ������
//14. Kakuna, ������
//15. Beedrill, ��ħ��
//16. Pidgey, ����
//17. Pidgeotto, ����
//18. Pidgeot, ������
//19. Rattata, ����
//20. Raticate, ��Ʈ��
//21. Spearow, ������
//22. Fearow, ����帱��
//23. Ekans, �ƺ�
//24. Arbok, �ƺ�ũ
//25. Pikachu, ��ī��
//150. Mewtwo, ����

void catchPokemon(const Pokedex& database, Pokedex& userdex);
void watchPokeDex(const Pokedex& database, Pokedex& userdex);

int main() {
	// want to make the random function well
	srand((unsigned int)time(0));

	// 1-1. Create initial pokedex --> database
	// 1-2. Create User pokedex
	Pokedex database;
	Pokedex userdex;

	// �������� ���� �������� ��ȣ�� �ƴ�.
	{
		//1. Bulbasaur, �̻��ؾ�
		Pokemon bulbasaur("bulbasaur", 1, 100);
		//2. Ivysaur, �̻���Ǯ
		Pokemon ivysaur("ivysaur", 2, 90);
		//3. Venusaur, �̻��ز�
		Pokemon venusaur("venusaur", 3, 80);
		//4. Charmander, ���̸�
		Pokemon charmander("charmander", 4, 100);
		//5. Charmeleon, ���ڵ�
		Pokemon charmeleon("charmeleon", 5, 90);
		//6. Charizard, ���ڸ�
		Pokemon charizard("charizard", 6, 80);
		//7. Squirtle, ���α�
		Pokemon squirtle("squirtle", 7, 100);
		//8. Wartortle, ��Ϻα�
		Pokemon wartortle("wartortle", 8, 90);
		//9. Blastoise, �źϿ�
		Pokemon blastoise("blastoise", 9, 80);
		//10. Caterpie, ĳ����
		Pokemon caterpie("caterpie", 10, 100);
		//11. Metapod, �ܵ���
		Pokemon metapod("metapod", 11, 90);
		//12. Butterfree, ������
		Pokemon butterfree("butterfree", 12, 80);
		//13. Weedle, ������
		Pokemon weedle("weedle", 13, 100);
		//14. Kakuna, ������
		Pokemon kakuna("kakuna", 14, 90);
		//15. Beedrill, ��ħ��
		Pokemon beedrill("beedrill", 15, 80);
		//16. Pidgey, ����
		Pokemon pidgey("pidgey", 16, 100);
		//17. Pidgeotto, ����
		Pokemon pidgeotto("pidgeotto", 17, 90);
		//18. Pidgeot, ������
		Pokemon pidgeot("pidgeot", 18, 80);
		//19. Rattata, ����
		Pokemon rattata("rattata", 19, 100);
		//20. Raticate, ��Ʈ��
		Pokemon raticate("raticate", 20, 90);
		//21. Spearow, ������
		Pokemon spearow("spearow", 21, 100);
		//22. Fearow, ����帱��
		Pokemon fearow("fearow", 22, 90);
		//23. Ekans, �ƺ�
		Pokemon ekans("ekans", 23, 100);
		//24. Arbok, �ƺ�ũ
		Pokemon arbok("arbok", 24, 90);
		//25. Pikachu, ��ī��
		Pokemon pikachu("pikachu", 25, 70);
		//150. Mewtwo, ����
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
	database.printByDefaullt();

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
	
	i = 0;

	// Capture rate
	int capture_rate = (*(database.watchPokemon(i))).get_capture_rate();

	while (turn) {
  		std::cout << "You encountered a wild ";
		std::cout << (*(database.watchPokemon(i))).get_name() << "!" << std::endl;
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
				std::cout << "Uh oh.. " << (*(database.watchPokemon(i))).get_name() << "avoid the pokeball" << std::endl;
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
	int user_input;
	std::cin >> user_input;
	while (1) {
		// print the catched pokemon
		std::cout << "Catched Pokemons!" << std::endl;
		std::cout << "-----------------" << std::endl;
		userdex.printByDefaullt();
		;
		std::cout << "1. Order by id." << std::endl;
		std::cout << "2. Order by name." << std::endl;
		std::cout << "3. Search." << std::endl;
		std::cout << "4. Deposit." << std::endl;
		std::cout << "5. Exit dex." << std::endl;

		if (user_input == 1) {

		}
		else if (user_input == 2) {

		}
		else if (user_input == 3) {

		}
		else if (user_input == 4) {

		}
		else if (user_input == 5) {
			std::cout << "Return to main menu!" << std::endl;
			return;
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