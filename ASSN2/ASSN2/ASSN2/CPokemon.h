#pragma once

class CPokemon
{
private:
	int id;
	int main_type;
	int sub_type;
	int hp;
	int attack;
	int defense;
	int speed;
	int ability;
	int skill_1;
	int skill_2;
	bool knock_down;

public:
	CPokemon(const int id_ = 0, const int main_type_ = 0, const int sub_type_ = 0, const int hp_ = 0, const int attack_ = 0, const int defense_ = 0, const int speed_ = 0, const int ability_ = 0, const int skill_1_ = 0, const int skill_2_ = 0, const bool knock_down_ = 0);
	CPokemon(const CPokemon& ref);
	~CPokemon();
	void print_pokemon_status();
	int get_id();
	void set_id(int id_);
	int get_main_type();
	void set_main_type(int type_);
	int get_sub_type();
	void set_sub_type(int type_);
	int get_hp();
	void set_hp(int hp_);
	int get_attack();
	void set_attack(int attack_);
	int get_defense();
	void set_defens(int defense_);
	int get_speed();
	void set_speed(int speed_);
	int get_ability();
	void set_abiltiy(int ability_);
	int get_skill_1();
	void set_skill_1(int skill_1_);
	int get_skill_2();
	void set_skill_2(int skill_2_);
	bool get_knock_down();
	void set_knock_down(bool knock_down_);
};