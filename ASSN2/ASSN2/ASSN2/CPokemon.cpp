#pragma once
#include <iostream>
#include "CPokemon.h"


CPokemon::CPokemon(int id_, int main_type_, int sub_type_, int hp_, int attack_, int defense_, int speed_, int ability_, int skill_1_, int skill_2_, bool knock_down_)
{
	id = id_;
	main_type = main_type_;
	sub_type = sub_type_;
	hp = hp_;
	attack = attack_;
	defense = defense_;
	speed = speed_;
	ability = ability_;
	skill_1 = skill_1_;
	skill_2 = skill_2_;
	knock_down = knock_down_;
}

CPokemon::CPokemon(const CPokemon& ref) {
	id = ref.id;
	main_type = ref.main_type;
	sub_type = ref.sub_type;
	hp = ref.hp;
	attack = ref.attack;
	defense = ref.defense;
	speed = ref.speed;
	ability = ref.ability;
	skill_1 = ref.skill_1;
	skill_2 = ref.skill_2;
	knock_down = ref.knock_down;
}

CPokemon::~CPokemon()
{
	
}

void CPokemon::print_pokemon_status() {
	std::cout << "id : " << id << std::endl;
	std::cout << "main_type : " << main_type << std::endl;
	std::cout << "sub_type : " << sub_type << std::endl;
	std::cout << "hp : " << hp << std::endl;
	std::cout << "attack : " << attack << std::endl;
	std::cout << "defense : " << defense << std::endl;
	std::cout << "speed : " << speed << std::endl;
	std::cout << "ability : " << ability << std::endl;
	std::cout << "skill_1 : " << skill_1 << std::endl;
	std::cout << "skill_2 : " << skill_2 << std::endl;
	std::cout << "knock_down : " << knock_down << std::endl;
}

int CPokemon::get_id()
{
	return id;
}

void CPokemon::set_id(int id_)
{
	id = id_;
}

int CPokemon::get_main_type()
{
	return main_type;
}

void CPokemon::set_main_type(int type_)
{
	main_type = type_;
}

int CPokemon::get_sub_type()
{
	return sub_type;
}

void CPokemon::set_sub_type(int type_)
{
	sub_type = type_;
}

int CPokemon::get_hp()
{
	return hp;
}

void CPokemon::set_hp(int hp_)
{
	hp = hp_;
}

int CPokemon::get_attack()
{
	return attack;
}

void CPokemon::set_attack(int attack_)
{
	attack = attack_;
}

int CPokemon::get_defense()
{
	return defense;
}

void CPokemon::set_defens(int defense_)
{
	defense = defense_;
}

int CPokemon::get_speed()
{
	return speed;
}

void CPokemon::set_speed(int speed_)
{
	speed = speed_;
}

int CPokemon::get_ability()
{
	return ability;
}

void CPokemon::set_abiltiy(int ability_)
{
	ability = ability_;
}


int CPokemon::get_skill_1()
{
	return skill_1;
}

void CPokemon::set_skill_1(int skill_1_)
{
	skill_1 = skill_1_;
}

int CPokemon::get_skill_2()
{
	return skill_2;
}

void CPokemon::set_skill_2(int skill_2_)
{
	skill_2 = skill_2_;
}

bool CPokemon::get_knock_down()
{
	return knock_down;
}

void CPokemon::set_knock_down(bool knock_down_)
{
	knock_down = knock_down_;
}