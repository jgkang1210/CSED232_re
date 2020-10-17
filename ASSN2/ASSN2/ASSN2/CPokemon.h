#pragma once
class CPokemon
{
private:
	int main_type;
	int sub_type;
	int hp;
	int attack;
	int defense;
	int speed;
	int skills;
	int knock_down;

public:
	CPokemon();
	~CPokemon();
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
	int get_skills();
	void set_skills(int skills_);
	int get_knock_down();
	void set_knock_dow(int knock_down_);
};

