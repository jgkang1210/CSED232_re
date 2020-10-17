#pragma once
#include "CPokemon.h"


CPokemon::CPokemon()
{

}


CPokemon::~CPokemon()
{

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
	return 0;
}

void CPokemon::set_defens(int defense_)
{
}

int CPokemon::get_speed()
{
	return 0;
}

void CPokemon::set_speed(int speed_)
{
}

int CPokemon::get_skills()
{
	return 0;
}

void CPokemon::set_skills(int skills_)
{
}

int CPokemon::get_knock_down()
{
	return 0;
}

void CPokemon::set_knock_dow(int knock_down_)
{
}