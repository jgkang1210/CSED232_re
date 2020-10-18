#pragma once
#include "CRival.h"

CRival::CRival(const CPokemon pokemon_1_, const CPokemon pokemon_2_, const CPokemon pokemon_3_, const CPokemon in_battle_)
{
	pokemon_1 = pokemon_1_;
	
}


CRival::~CRival()
{
}

CPokemon CRival::get_pokemon_1()
{
	return pokemon_1;
}

void CRival::set_pokemon_1(CPokemon pokemon_1_)
{
	pokemon_1 = pokemon_1_;
}

CPokemon CRival::get_pokemon_2()
{
	return pokemon_2;
}

void CRival::set_pokemon_2(CPokemon pokemon_2_)
{
	pokemon_2 = pokemon_2_;
}

CPokemon CRival::get_pokemon_3()
{
	return pokemon_3;
}

void CRival::set_pokemon_3(CPokemon pokemon_3_)
{
	pokemon_3 = pokemon_3_;
}
