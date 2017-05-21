#pragma once
#include "equipment.h"
#include "inventory.h"
#include "entity.h"
#include "enums.h"

class player : public entity {
public:
	inventory my_inventory;
	equipment my_equipment;

	int coins = 0;
	int experience = 0;

	// function to add items to inventory.
	// pushes item to vector<item>.

	void pickup(item* p);

	// function to equip item to equipment slot.
	// checks the items' type and sets the item to its equipment slot.
	void equip(item *p);

	// function to unequip item from equipment slot.
	// checks the item's type and sets the equipment slot to NULL.
	void unequip(item* p);

	void viewInfo();

	virtual void calcMax() {
		max_hit = ((1.3 + ((my_skills.strength + 3) / 10) + (my_equipment.total_strbonus / 80) + (((my_skills.strength + 3) * my_equipment.total_strbonus) / 640)));
	}
};
