#pragma once
#include "item.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class equipment {
public:
	armour *helmet_slot = nullptr;
	armour *platebody_slot = nullptr;
	armour *platelegs_slot = nullptr;
	armour *shield_slot = nullptr;
	weapon *weapon_slot = nullptr;

	int total_atkbonus = 0;
	int total_strbonus = 0;
	int total_defbonus = 0;

	string getCurrent(item *item);

	void view();
	void viewBonus();
	int calculatedef();
	int calculateatk();
	int calculatestr();
	void calculatebonus();
};