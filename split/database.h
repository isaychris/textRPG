#pragma once
#include "item.h"
#include "enums.h"
#include "entity.h"

struct item_database {
	item *book = new item("shonen jump", "believe it!", common_t, 1, unstack_t, unequiped, 5000);
	item *ring = new item("gold ring", "my precious!", common_t, 1, unstack_t, unequiped, 1);
	item *coins = new item("coins", "lovely money!", common_t, 1, stack_t, unequiped, 1);
	item *bones = new item("bones", "spoOoOky", common_t, 1, unstack_t, unequiped, 1);
	item *feather = new item("feather", "chicken dinner", common_t, 1, stack_t, unequiped, 1);

	armour *dhelm = new armour("dragon helmet", "helmet made from a dragon", helmet_t, 1, unstack_t, unequiped, 10000, 36);
	armour *dplate = new armour("dragon platebody", "platebody made from dragon", platebody_t, 1, unstack_t, unequiped, 75000, 85);
	armour *dlegs = new armour("dragon platelegs", "platelegs made from a dragon", plateleg_t, 1, unstack_t, unequiped, 50000, 66);
	armour *dshield = new armour("dragon shield", "shield made from a dragon", shield_t, 1, unstack_t, unequiped, 40000, 72);
	armour *ely = new armour("elysian shield", "godlike", shield_t, 1, unstack_t, unequiped, 40000, 300);
	armour *bphat = new armour("blue partyhat", "its blue!", helmet_t, 1, unstack_t, unequiped, 5000, 2);

	weapon *whip = new weapon("whip", "a weapon from the abyss", weapon_t, 1, unstack_t, unequiped, 25000, 70, 82);
	weapon *katana = new weapon("katana", "a weapon from the hidden leaf village", weapon_t, 1, unstack_t, unequiped, 25000, 66, 70);
	weapon *gun = new weapon("gun", "a weapon from a gang member", weapon_t, 1, unstack_t, unequiped, 300000, 400, 500);
	weapon *ags = new weapon("armadyl godsword", "gg kid, sit down", weapon_t, 1, unstack_t, unequiped, 80000, 76, 132);
	weapon *dscim = new weapon("dragon scimitar", "sword made from a dragon", weapon_t, 1, unstack_t, unequiped, 25000, 55, 82);
	weapon *saber = new weapon("lightsaber", "may the force be with you", weapon_t, 1, unstack_t, unequiped, 200000, 200, 200);

};

struct monster_database {
	monster *chicken = new monster("Chicken", 5, 5, 5, 20, 12);
	monster *goblin = new monster("Goblin", 25, 42, 20, 40, 42);
	monster *hillgiant = new monster("Hill Giant", 50, 70, 50, 60, 65);
	monster *abysal = new monster("Abyssal Demon", 60, 80, 43, 70, 82);
	monster *dragon = new monster("Dragon", 45, 70, 40, 80, 132);
	monster *naruto = new monster("Naruto", 80, 99, 80, 90, 102);
	monster *sasuke = new monster("Sasuke", 80, 99, 80, 90, 102);
	monster *man = new monster("Man", 10, 23, 20, 32, 26);
	monster *thug = new monster("Thug", 30, 54, 30, 62, 72);
	monster *corp = new monster("Corporeal Demon", 320, 300, 80, 150, 785);
	monster *jad = new monster("Jad", 200, 200, 200, 150, 702);
};
