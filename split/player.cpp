#include "player.h"

void player::pickup(item * p)
{
	if (p->isStack == unstack_t) {
		my_inventory.list.emplace_back(new item(p));
	}
	else {
		for (unsigned int i = 0; i < my_inventory.list.size(); i++) {
			if (my_inventory.list[i]->name == p->name) {
				my_inventory.list[i]->quantity++;
			}
		}
	}
}

void player::equip(item * p)
{
	if (p->item_type == helmet_t) {
		if (my_equipment.helmet_slot != NULL) {
			my_equipment.helmet_slot->isEquiped = false;
		}

		my_equipment.helmet_slot = (armour*)p;
		p->isEquiped = equiped;
		cout << " - " << p->name << " has been equiped." << endl;
	}
	else if (p->item_type == platebody_t) {
		if (my_equipment.platebody_slot != NULL) {
			my_equipment.platebody_slot->isEquiped = false;
		}

		my_equipment.platebody_slot = (armour*)p;
		p->isEquiped = equiped;
		cout << " - " << p->name << " has been equiped." << endl;
	}
	else if (p->item_type == plateleg_t) {
		if (my_equipment.platelegs_slot != NULL) {
			my_equipment.platelegs_slot->isEquiped = false;
		}

		my_equipment.platelegs_slot = (armour*)p;
		p->isEquiped = equiped;
		cout << " - " << p->name << " has been equiped." << endl;
	}
	else if (p->item_type == shield_t) {
		if (my_equipment.shield_slot != NULL) {
			my_equipment.shield_slot->isEquiped = false;
		}

		my_equipment.shield_slot = (armour*)p;
		p->isEquiped = equiped;
		cout << " - " << p->name << " has been equiped." << endl;
	}
	else if (p->item_type == weapon_t) {
		if (my_equipment.weapon_slot != NULL) {
			my_equipment.weapon_slot->isEquiped = false;
		}
		my_equipment.weapon_slot = (weapon*)p;

		p->isEquiped = equiped;
		cout << " - " << p->name << " has been equiped." << endl;
	}
	else if (p->item_type == common_t) {
		cout << " - " << p->name << " cannot be equiped." << endl;
	}
}

void player::unequip(item * p)
{
	if (p->item_type == helmet_t) {
		my_equipment.helmet_slot = nullptr;
	}
	else if (p->item_type == platebody_t) {
		my_equipment.platebody_slot = nullptr;
	}
	else if (p->item_type == plateleg_t) {
		my_equipment.platelegs_slot = nullptr;
	}
	else if (p->item_type == shield_t) {
		my_equipment.shield_slot = nullptr;
	}
	else if (p->item_type == weapon_t) {
		my_equipment.weapon_slot = nullptr;
	}

	p->isEquiped = unequiped;
	cout << " - " << p->name << " has been unequiped." << endl;
}

void player::viewInfo()
{
	cout << "> Player: " << name << endl << endl;
	cout << "> Skills " << endl;
	cout << " - atk lvl: " << my_skills.attack << endl;
	cout << " - str lvl: " << my_skills.strength << endl;
	cout << " - def lvl: " << my_skills.defense << endl;
	cout << " - hp lvl: " << my_skills.hitpoints << endl << endl;

	cout << "> Combat" << endl;
	cout << " - combat lvl: " << my_skills.combat << endl;
	cout << " - total exp: " << experience << endl;
	cout << " - max hit: " << max_hit << endl << endl;

	cout << "> Other" << endl;
	cout << " - coins: " << coins << endl;
}
