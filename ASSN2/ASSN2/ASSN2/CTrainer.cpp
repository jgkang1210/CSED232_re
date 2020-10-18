#pragma once
#include "CTrainer.h"


CTrainer::CTrainer(const CPokemon pokemon_1_, const CPokemon pokemon_2_, const CPokemon pokemon_3_, const CPokemon in_battle_)
{
	pokemon_1 = pokemon_1_;
	pokemon_2 = pokemon_2_;
	pokemon_3 = pokemon_3_;
	in_battle = in_battle_;
}

CTrainer::CTrainer(const CTrainer& ref) {
	pokemon_1 = ref.pokemon_1;
	pokemon_2 = ref.pokemon_2;
	pokemon_3 = ref.pokemon_3;
	in_battle = ref.in_battle;
}


CTrainer::~CTrainer()
{
	
}

CPokemon& CTrainer::get_pokemon_1()
{
	return pokemon_1;
}

void CTrainer::set_pokemon_1(CPokemon pokemon_1_)
{
	pokemon_1 = pokemon_1_;
}

CPokemon& CTrainer::get_pokemon_2()
{
	return pokemon_2;
}

void CTrainer::set_pokemon_2(CPokemon pokemon_2_)
{
	pokemon_2 = pokemon_2_;
}

CPokemon& CTrainer::get_pokemon_3()
{
	return pokemon_3;
}

void CTrainer::set_pokemon_3(CPokemon pokemon_3_)
{
	pokemon_3 = pokemon_3_;
}

CPokemon& CTrainer::get_in_battle()
{
	return in_battle;
}

void CTrainer::set_in_battle(CPokemon in_battle_)
{
	in_battle = in_battle_;
}

void CTrainer::battle()
{

}

void CTrainer::change()
{

}

void CTrainer::give_up()
{
	pokemon_1.set_knock_down(true);
	pokemon_2.set_knock_down(true);
	pokemon_3.set_knock_down(true);
}

