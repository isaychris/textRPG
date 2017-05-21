// ===============================================================
// Author: https://github.com/isaychris
// Date: 12/28/2016
//
// Project: Text Base RPG
// Version: 0.9
// Description: Practice
//
// TODO: 
//  - total armour bonuses - done
//  - monsters & drops - done
//  - leveling up
//	- xp tabler
//  - store - done
//================================================================

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;

//enums
enum item_type { common_t, helmet_t, platebody_t, plateleg_t, shield_t, weapon_t };
enum equip_state { equiped = true, unequiped = false };
enum stack_type { stack_t = true, unstack_t = false };

// the base struct for items.
struct item {
	string name;
	string description;
	int item_type;
	int quantity;
	bool isStack;
	bool isEquiped;
	int price;

	item() {}

	item(item *o) {
		name = o->name;
		description = o->description;
		item_type = o->item_type;
		quantity = o->quantity;
		isStack = o->isStack;
		isEquiped = o->isEquiped;
		price = o->price;
	}

	//comstructs an item
	item(string n, string d, int i, int q, bool s, bool e, int p) {
		name = n;
		description = d;
		quantity = q;
		item_type = i;
		isStack = s;
		isEquiped = e;
		price = p;
	}

	// virtual to override examine function();
	void virtual examine() {
		cout << " - " << name << endl;
		cout << " - '" << description << "'" << endl;
	}

	// virtual to access atk,str,def in derived structs.
	virtual int getdef() { return 0; }
	virtual int getatk() { return 0; }
	virtual int getstr() { return 0; }
};

struct armour : public item {
	int def_bonus;

	//constructs an armour item.
	armour(string n, string d, int i, int q, bool s, bool e, int p, int def) {
		name = n;
		description = d;
		item_type = i;
		quantity = q;
		isStack = s;
		isEquiped = e;
		price = p;
		def_bonus = def;
	}

	armour(armour *o) {
		name = o->name;
		description = o->description;
		item_type = o->item_type;
		quantity = o->quantity;
		isStack = o->isStack;
		isEquiped = o->isEquiped;
		price = o->price;
		def_bonus = o->def_bonus;
	}

	// virtual to override examine function();
	void virtual examine() {
		cout << " - " << name << endl;
		cout << " - '" << description << "'" << endl;
		cout << " - def bonus: " << def_bonus << endl;
	}

	//virtual to get access to def variable.
	virtual int getdef() { return def_bonus; }
};

struct weapon : public item {
	int atk_bonus;
	int str_bonus;

	weapon(weapon *o) {
		name = o->name;
		description = o->description;
		item_type = o->item_type;
		quantity = o->quantity;
		isStack = o->isStack;
		isEquiped = o->isEquiped;
		price = o->price;
		atk_bonus = o->atk_bonus;
		str_bonus = o->str_bonus;
	}

	//contructs a weapon item
	weapon(string n, string d, int i, int q, bool s, bool e, int p, int atk, int str) {
		name = n;
		description = d;
		item_type = i;
		quantity = q;
		isStack = s;
		isEquiped = e;
		price = p;
		atk_bonus = atk;
		str_bonus = str;
	}

	// virtual to override examine function();
	void virtual examine() {
		cout << " - " << name << endl;
		cout << " - '" << description << "'" << endl;
		cout << " - atk bonus: " << atk_bonus << endl;
		cout << " - str bonus: " << atk_bonus << endl;
	}

	//virtual to get access to atk and str variable.
	virtual int getatk() { return atk_bonus; }
	virtual int getstr() { return str_bonus; }

};

template<typename TYPE>
TYPE clone(TYPE *p) {
	TYPE test = new TYPE(p);
	return test;
}

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

struct equipment {
	armour *helmet_slot = NULL;
	armour *platebody_slot = NULL;
	armour *platelegs_slot = NULL;
	armour *shield_slot = NULL;
	weapon *weapon_slot = NULL;

	int total_atkbonus = 0;
	int total_strbonus = 0;
	int total_defbonus = 0;

	string getCurrent(item *item) {
		if (item == NULL) {
			return "empty";
		}

		return item->name;
	}

	void view() {
		cout << " - [0] helmet: " << getCurrent(helmet_slot) << endl;
		cout << " - [1] plate: " << getCurrent(platebody_slot) << endl;
		cout << " - [2] legs: " << getCurrent(platelegs_slot) << endl;
		cout << " - [3] shield: " << getCurrent(shield_slot) << endl;
		cout << " - [4] weapon: " << getCurrent(weapon_slot) << endl;
	}

	void viewBonus() {
		cout << " - atk bonus: " << total_atkbonus << endl;
		cout << " - str bonus: " << total_strbonus << endl;
		cout << " - def bonus: " << total_defbonus << endl;
	}

	int calculatedef() {
		int defcalc = 0;

		vector<int> def;
		if (helmet_slot != NULL)
			def.emplace_back(helmet_slot->def_bonus);
		if (platebody_slot != NULL)
			def.emplace_back(platebody_slot->def_bonus);
		if (platelegs_slot != NULL)
			def.emplace_back(platelegs_slot->def_bonus);
		if (shield_slot != NULL)
			def.emplace_back(shield_slot->def_bonus);

		for (unsigned int i = 0; i < def.size(); i++) {
			defcalc += def.at(i);
		}

		return defcalc;
	}

	int calculateatk() {
		int atkcalc = 0;

		if (weapon_slot != NULL) {
			atkcalc = weapon_slot->atk_bonus;
		}
		return atkcalc;
	}

	int calculatestr() {
		int strcalc = 0;

		if (weapon_slot != NULL) {
			strcalc = weapon_slot->str_bonus;
		}
		return strcalc;
	}

	void calculatebonus() {
		total_atkbonus = calculateatk();
		total_strbonus = calculatestr();
		total_defbonus = calculatedef();
	}
};

struct inventory {
	vector<item*> list;

	void view() {
		if (!list.empty()) {
			for (unsigned int i = 0; i < list.size(); i++) {
				cout << " - [" << i << "]: " << list[i]->name << " x " << list[i]->quantity << " " << isEquiped(i) << endl;
			}
		}

		else
			cout << " - empty " << endl;
	}

	string isEquiped(int i) {
		if (list[i]->isEquiped == true) {
			return "[equiped]";
		}
		return "";
	}
};

struct skills {
	int attack = 1;
	int strength = 1;
	int defense = 1;
	int hitpoints = 1;
	int combat = 1;
};

// base class for all life forms
struct entity {
	string name;
	skills my_skills;
	int max_hit = 0;

	virtual void calcMax() {
		max_hit = ((1.3 + ((my_skills.strength + 1) / 10) + (1 / 80) + (((my_skills.strength + 1) * 1) / 640)));
	}
};

struct monster : entity {
	vector<item*> droptable;

	monster() {};
	monster(string n, int atk, int str, int def, int hit, int cb) {
		name = n;
		my_skills.attack = atk;
		my_skills.strength = str;
		my_skills.defense = def;
		my_skills.hitpoints = hit;
		my_skills.combat = cb;
	}

	void viewDropTable() {
		cout << "Drops" << endl;
		for (unsigned int i = 0; i < droptable.size(); i++) {
			cout << " - " << droptable[i]->name << endl;
		}
	}
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


struct prayer {
	string name;
	int bonus;
	bool isActive;

	void activate() {
		isActive = true;
	}
};

struct prayers {
	prayer ultimate = { "ultimate str", 2, false };
	prayer super = { "super str", 3, false };
};

struct player : entity {
	inventory my_inventory;
	equipment my_equipment;
	prayers my_prayers;

	int coins = 0;
	int experience = 0;

	// function to add items to inventory.
	// pushes item to vector<item>.

	template<typename TYPE>
	void pickup(TYPE* p) {

		if (p->isStack == unstack_t) {
			my_inventory.list.push_back(new TYPE(p));
		}
		else {
			for (unsigned int i = 0; i < my_inventory.list.size(); i++) {
				if (my_inventory.list[i]->name == p->name) {
					my_inventory.list[i]->quantity++;
				}
			}
		}
	}

	// function to equip item to equipment slot.
	// checks the items' type and sets the item to its equipment slot.
	void equip(item *p) {
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

	// function to unequip item from equipment slot.
	// checks the item's type and sets the equipment slot to NULL.
	template<class TYPE>
	void unequip(TYPE* p) {
		if (p->item_type == helmet_t) {
			my_equipment.helmet_slot = NULL;
		}
		else if (p->item_type == platebody_t) {
			my_equipment.platebody_slot = NULL;
		}
		else if (p->item_type == plateleg_t) {
			my_equipment.platelegs_slot = NULL;
		}
		else if (p->item_type == shield_t) {
			my_equipment.shield_slot = NULL;
		}
		else if (p->item_type == weapon_t) {
			my_equipment.weapon_slot = NULL;
		}

		p->isEquiped = unequiped;
		cout << " - " << p->name << " has been unequiped." << endl;
	}

	void viewInfo() {
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

	virtual void calcMax() {
		max_hit = ((1.3 + ((my_skills.strength + 3) / 10) + (my_equipment.total_strbonus / 80) + (((my_skills.strength + 3) * my_equipment.total_strbonus) / 640)));
	}
};

class game {
public:
	// player
	player hero;

	//vectors to hold monsters and store items.
	vector<monster*> monsterlist;
	vector<item*> store;

	// databases
	monster_database monsters;
	item_database items;

	// default constr
	game();
	void menu();

private:
	void menuPlayer();
	void menuInventory();
	void menuEquipment();
	void menuStore();
	void menuTrain();
	void buy(int item);

	void attack(monster *enemy);
	int xpTable(int exp);
};

void game::menuPlayer()
{
	cout << "  __________________________________________   " << endl;
	cout << "<| ======         Player Info        ====== |>" << endl;
	cout << "<|__________________________________________|> " << endl;
	cout << " " << endl;

	hero.viewInfo();

	menu();
}


void game::menuInventory() {
	unsigned int selection;
	unsigned int slot;

	cout << "  __________________________________________   " << endl;
	cout << "<| ======          Inventory         ====== |>" << endl;
	cout << "<|__________________________________________|> " << endl;
	cout << " " << endl;
	hero.my_inventory.view();

	cout << endl;
	cout << "select [?]: ";
	cin >> slot;

	while (slot > hero.my_inventory.list.size() - 1 || slot < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again [?]: ";
		cin >> slot;
	}

	cout << endl;
	cout << "action [?]:" << endl;
	cout << " - 0: nothing." << endl;
	cout << " - 1: equip." << endl;
	cout << " - 2: examine. " << endl;
	cout << " > ";
	cin >> selection;

	while (selection > 2 || selection < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again [?]: ";
		cin >> selection;
	}

	if (selection == 0) {
		menu();
	}
	else if (selection == 1) {
		hero.equip(hero.my_inventory.list[slot]);
		hero.my_equipment.calculatebonus();
		hero.calcMax();
		menu();
	}
	else if (selection == 2) {
		hero.my_inventory.list[slot]->examine();
		menu();
	}
}

void game::menuEquipment() {
	cout << "  __________________________________________   " << endl;
	cout << "<| ======          Equipment         ====== |>" << endl;
	cout << "<|__________________________________________|> " << endl;
	cout << " " << endl;

	int slot;
	int selection;
	cout << "Worn Equipment" << endl;
	hero.my_equipment.view();
	cout << endl;

	cout << "Equipment Bonus" << endl;
	hero.my_equipment.viewBonus();

	cout << endl;
	cout << "select [?]: ";
	cin >> slot;


	while (slot > 4 || slot < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again [?]: ";
		cin >> slot;
	}

	if (slot == 0) {
		if (hero.my_equipment.helmet_slot == NULL) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 1) {
		if (hero.my_equipment.platebody_slot == NULL) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 2) {
		if (hero.my_equipment.platelegs_slot == NULL) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 3) {
		if (hero.my_equipment.shield_slot == NULL) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 4) {
		if (hero.my_equipment.weapon_slot == NULL) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}

	cout << endl;
	cout << "action [?]:" << endl;
	cout << " - 0: nothing." << endl;
	cout << " - 1: unequip." << endl;
	cout << " > ";
	cin >> selection;

	while (selection > 1 || selection < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again [?]: ";
		cin >> selection;
	}

	if (selection == 0) {
		menu();
	}

	else if (selection == 1) {

		// helmet slot
		if (slot == 0) {
			if (hero.my_equipment.helmet_slot != NULL)
				hero.unequip(hero.my_equipment.helmet_slot);
		}

		// platebody slot
		else if (slot == 1) {
			if (hero.my_equipment.platebody_slot != NULL)
				hero.unequip(hero.my_equipment.platebody_slot);
		}

		// platelegs slot
		else if (slot == 2) {
			if (hero.my_equipment.platelegs_slot != NULL)
				hero.unequip(hero.my_equipment.platelegs_slot);
		}

		// shield slot
		else if (slot == 3) {
			if (hero.my_equipment.shield_slot != NULL)
				hero.unequip(hero.my_equipment.shield_slot);
		}

		// weapon slot
		else if (slot == 4) {
			if (hero.my_equipment.weapon_slot != NULL)
				hero.unequip(hero.my_equipment.weapon_slot);
		}

		hero.my_equipment.calculatebonus();
		hero.calcMax();
		menu();
	}

}

void game::buy(int item) {
	char input = 'y';

	cout << " - item: " << store[item]->name << endl;
	cout << " - description: '" << store[item]->description << "'" << endl;
	cout << " - price: $" << store[item]->price << endl << endl;

	cout << "Purchase item? [y/n]: ";
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again (?): ";
		cin >> input;
	}

	if (input == 'y') {
		if (hero.coins > store[item]->price) {
			hero.coins = hero.coins - store[item]->price;
			hero.my_inventory.list.emplace_back(store[item]);

			cout << " - " << store[item]->name << " added to inventory." << endl;
			cout << " - coins = " << hero.coins << endl << endl;
		}
		else {
			cout << " - not enough coins for this purchase." << endl;
		}
	}
}
void game::menuStore() {
	cout << "  __________________________________________   " << endl;
	cout << "<| ========          Store         ======== |>" << endl;
	cout << "<|__________________________________________|> " << endl;
	cout << "" << endl;

	unsigned int selection;

	cout << "Coins = $" << hero.coins << endl;
	cout << endl;
	cout << left;
	cout << setw(9) << "code" << setw(20) << "item" << "price" << endl;
	cout << "----------------------------------------------" << endl;

	if (!store.empty()) {
		for (unsigned int i = 0; i < store.size(); i++) {
			cout << left;
			cout << " " << setw(8) << i << setw(20) << store[i]->name << "$" << store[i]->price << endl;
		}

		cout << endl;
		cout << "Enter [code]: ";
		cin >> selection;

		while (selection > store.size() - 1 || selection < 0 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid selection, enter again (?): ";
			cin >> selection;
		}

		buy(selection);
	}

	else {
		cout << "empty" << endl;
	}

	cout << " " << endl;
	cout << "---------------------------------------------" << endl;

	menu();
}


void game::menuTrain()
{
	int selection;
	cout << "  __________________________________________   " << endl;
	cout << "<| ======          Training          ====== |>" << endl;
	cout << "<|__________________________________________|> " << endl;
	cout << " " << endl;

	random_shuffle(monsterlist.begin(), monsterlist.end());

	cout << "A wild " << monsterlist[0]->name << "[lvl " << monsterlist[0]->my_skills.combat << "] " << " has appeared!" << endl;
	cout << "- 1: Attack." << endl;
	cout << "- 2: Flee." << endl;
	cout << "> ";
	cin >> selection;

	while (selection > 2 || selection < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again (?): ";
		cin >> selection;
	}

	if (selection == 1) {
		attack(monsterlist[0]);
	}
	if (selection == 2) {
		menu();
	}

}

void game::attack(monster *enemy)
{
	cout << " " << endl;
	cout << "           /\\                            " << endl;
	cout << " _         )( ___________________________      " << endl;
	cout << "(_)///////(**)_______Fight!!!____________>     " << endl;
	cout << "           )(                          " << endl;
	cout << "           \\/                            " << endl;
	cout << " " << endl;



	char selection;
	int player1_hit = 0;
	int monster_hit = 0;

	hero.calcMax();
	enemy->calcMax();

	int pid = rand() % 2;
	int player1_current_hp = hero.my_skills.hitpoints;
	int monster_current_hp = enemy->my_skills.hitpoints;

	if (pid == 0) {
		while (player1_current_hp > 0 && monster_current_hp  > 0) {

			if (player1_current_hp > 0 && monster_current_hp > 0) {
				player1_hit = rand() % hero.max_hit;
				cout << left;
				cout << setw(20) << "Player:" << "Hits = " << setw(10) << player1_hit << "HP = " << player1_current_hp << endl;
				monster_current_hp = monster_current_hp - player1_hit;
			}

			if (player1_current_hp > 0 && monster_current_hp > 0) {
				monster_hit = rand() % enemy->max_hit;
				cout << left;
				cout << setw(20) << enemy->name + ":" << "Hits = " << setw(10) << monster_hit << "HP = " << monster_current_hp << endl;
				player1_current_hp = player1_current_hp - monster_hit;
			}
		}
	}

	else if (pid == 1) {
		while (player1_current_hp > 0 && monster_current_hp > 0) {

			if (player1_current_hp > 0 && monster_current_hp > 0) {
				monster_hit = rand() % enemy->max_hit;
				cout << left;
				cout << setw(20) << enemy->name + ":" << "Hits = " << setw(10) << monster_hit << "HP = " << monster_current_hp << endl;
				player1_current_hp = player1_current_hp - monster_hit;
			}

			if (player1_current_hp > 0 && monster_current_hp > 0) {
				player1_hit = rand() % hero.max_hit;
				cout << left;
				cout << setw(20) << "Player:" << "Hits = " << setw(10) << player1_hit << "HP = " << player1_current_hp << endl;
				monster_current_hp = monster_current_hp - player1_hit;
			}
		}
	}

	if (player1_current_hp <= 0) {
		cout << " " << endl;
		cout << "Player DEFEATED with HP = " << player1_current_hp << endl;
		cout << " - Oh dear, you are dead!" << endl;

		cout << " " << endl;
		cout << "---------------------------------------------" << endl;
		cout << " " << endl;
	}

	else if (monster_current_hp <= 0) {

		int exp = enemy->my_skills.combat * 3;
		hero.experience += exp;

		cout << " " << endl;
		cout << enemy->name << " DEFEATED with HP = " << monster_current_hp << endl << endl;

		enemy->viewDropTable();

		cout << endl;
		cout << "Experience gained: " << endl;
		cout << " + " << exp << " xp" << endl;
		cout << " " << endl;

		cout << "Pick up drops? [y/n]: ";
		cin >> selection;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid selection, enter again (?): ";
			cin >> selection;
		}

		if (selection == 'y') {
			for (unsigned int i = 0; i < enemy->droptable.size(); i++) {
				cout << " - " << enemy->droptable[i]->name << " added to inventory." << endl;
				hero.pickup(enemy->droptable[i]);
			}
		}


		cout << "---------------------------------------------" << endl;
		cout << " " << endl;
	}

	menu();
}

int game::xpTable(int exp)
{
	return 0;
}

void game::menu()
{
	int selection = 0;
	cout << "  __________________________________________   " << endl;
	cout << "<| ========        Main Menu       ======== |>" << endl;
	cout << "<|__________________________________________|> " << endl;
	cout << " " << endl;
	cout << 0 << "(0): [View] Player Info." << endl;
	cout << "(1): [View] Equipment." << endl;
	cout << "(2): [View] Inventory." << endl;
	cout << "(3): [View] Store." << endl;
	cout << "(4): [Kill] Monsters." << endl;
	cout << "(5): Exit." << endl;
	cout << " " << endl;
	cout << "---------------------------------------------" << endl;
	cout << " " << endl;

	cout << "Enter menu(?): ";
	cin >> selection;

	while (selection > 5 || selection < 0 || cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid selection, enter again (?): ";
		cin >> selection;
	}

	switch (selection) {
		case 0:
			menuPlayer();
			break;
		case 1:
			menuEquipment();
			break;
		case 2:
			menuInventory();
			break;
		case 3:
			menuStore();
			break;
		case 4:
			menuTrain();
			break;
	}
}

game::game()
{

	// player 1 initialize;
	hero.name = "iSayChris";
	hero.my_skills.attack = 75;
	hero.my_skills.strength = 99;
	hero.my_skills.defense = 1;
	hero.my_skills.hitpoints = 80;
	hero.my_skills.combat = 65;
	hero.calcMax();
	hero.coins = 21470000;
	hero.my_equipment.weapon_slot = items.whip;
	hero.my_equipment.calculatebonus();
	hero.calcMax();
	hero.my_inventory.list = { items.whip, items.dhelm, items.dplate, items.dlegs, items.dshield, items.dscim, items.ely, items.dscim, items.gun };

	// monsterlist initialization;

	monsters.goblin->droptable = { items.feather, items.bones, };
	monsters.goblin->droptable = { items.ring, items.bones, };
	monsters.dragon->droptable = { items.dhelm, items.bones, };
	monsters.naruto->droptable = { items.book, items.bones, };
	monsters.sasuke->droptable = { items.katana, items.bones, };
	monsters.man->droptable = { items.bones };
	monsters.thug->droptable = { items.gun, items.bones };
	monsters.corp->droptable = { items.ely, items.bones };
	monsters.hillgiant->droptable = { items.ely, items.bones };
	monsters.jad->droptable = { items.saber, items.bones };
	monsters.abysal->droptable = { items.whip, items.bones };
	monsterlist = { monsters.chicken, monsters.dragon, monsters.naruto, monsters.man, monsters.thug,
		monsters.sasuke, monsters.jad, monsters.corp, monsters.hillgiant, monsters.abysal };

	//store intialize;
	store = { items.katana, items.gun, items.book, items.bphat, items.ags, items.dscim, items.saber, items.ely };

}


int main()
{

	int i = 3;
	int &r = i;
	i = 5;


	cout << i << endl;
	cout << r << endl;

	game o;
	srand(unsigned(time(NULL)));

	o.menu();

	return 0;
}