#include "equipment.h"

string equipment::getCurrent(item * item)
{
	if (item == nullptr) {
		return "empty";
	}

	return item->name;
}

void equipment::view()
{
	cout << " - [0] helmet: " << getCurrent(helmet_slot) << endl;
	cout << " - [1] plate: " << getCurrent(platebody_slot) << endl;
	cout << " - [2] legs: " << getCurrent(platelegs_slot) << endl;
	cout << " - [3] shield: " << getCurrent(shield_slot) << endl;
	cout << " - [4] weapon: " << getCurrent(weapon_slot) << endl;
}

void equipment::viewBonus()
{
	cout << " - atk bonus: " << total_atkbonus << endl;
	cout << " - str bonus: " << total_strbonus << endl;
	cout << " - def bonus: " << total_defbonus << endl;
}

int equipment::calculatedef()
{
	int defcalc = 0;

	vector<int> def;
	if (helmet_slot != nullptr)
		def.emplace_back(helmet_slot->def_bonus);
	if (platebody_slot != nullptr)
		def.emplace_back(platebody_slot->def_bonus);
	if (platelegs_slot != nullptr)
		def.emplace_back(platelegs_slot->def_bonus);
	if (shield_slot != nullptr)
		def.emplace_back(shield_slot->def_bonus);

	for (unsigned int i = 0; i < def.size(); i++) {
		defcalc += def.at(i);
	}

	return defcalc;
}

int equipment::calculateatk()
{
	int atkcalc = 0;

	if (weapon_slot != nullptr) {
		atkcalc = weapon_slot->atk_bonus;
	}
	return atkcalc;
}

int equipment::calculatestr()
{
	int strcalc = 0;

	if (weapon_slot != nullptr) {
		strcalc = weapon_slot->str_bonus;
	}
	return strcalc;
}

void equipment::calculatebonus()
{
	total_atkbonus = calculateatk();
	total_strbonus = calculatestr();
	total_defbonus = calculatedef();
}
