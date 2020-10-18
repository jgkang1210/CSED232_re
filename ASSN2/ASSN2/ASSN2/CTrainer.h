#pragma once
#include "CPokemon.h"

class CTrainer
{
private:
	CPokemon pokemon_1;
	CPokemon pokemon_2;
	CPokemon pokemon_3;
	CPokemon in_battle;

public:
	CTrainer(const CPokemon pokemon_1_, const CPokemon pokemon_2_, const CPokemon pokemon_3_, const CPokemon in_battle_);
	CTrainer(const CTrainer& ref);
	~CTrainer();
	CPokemon& get_pokemon_1();
	void set_pokemon_1(CPokemon pokemon_1_);
	CPokemon& get_pokemon_2();
	void set_pokemon_2(CPokemon pokemon_2_);
	CPokemon& get_pokemon_3();
	void set_pokemon_3(CPokemon pokemon_3_);
	CPokemon& get_in_battle();
	void set_in_battle(CPokemon in_battle_);
	void battle();
	void change();
	void give_up();
};