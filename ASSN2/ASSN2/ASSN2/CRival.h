#pragma once
#include "CPokemon.h"

class CRival
{
private:
	CPokemon pokemon_1;
	CPokemon pokemon_2;
	CPokemon pokemon_3;
	CPokemon in_battle;

public:
	CRival(const CPokemon pokemon_1_, const CPokemon pokemon_2_, const CPokemon pokemon_3_, const CPokemon in_battle_);
	CRival(const CRival& ref);
	~CRival();
	// get and set pokemon 1, 2, 3 and in_battle pokemon
	CPokemon& get_pokemon_1();
	void set_pokemon_1(CPokemon pokemon_1_);
	CPokemon& get_pokemon_2();
	void set_pokemon_2(CPokemon pokemon_2_);
	CPokemon& get_pokemon_3();
	void set_pokemon_3(CPokemon pokemon_3_);
	CPokemon& get_in_battle();
	void set_in_battle(CPokemon in_battle_);

	// check the if the inbattle pokemon can fight
	int battle();
};