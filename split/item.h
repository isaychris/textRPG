#pragma once

#include <string>
#include <iostream>
using namespace std;

// the base struct for items.
class item {
public:
	string name;
	string description;
	int item_type;
	int quantity;
	bool isStack;
	bool isEquiped;
	int price;

	item() {}

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

	//
	item(item *o) {
		name = o->name;
		description = o->description;
		item_type = o->item_type;
		quantity = o->quantity;
		isStack = o->isStack;
		isEquiped = o->isEquiped;
		price = o->price;
	}

	// virtual to override examine function();
	void virtual examine() {
		cout << " - " << name << endl;
		cout << " - '" << description << "'" << endl;
	}
};

class armour : public item {
public:
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
};

class weapon : public item {
public:
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
};
