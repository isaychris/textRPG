#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "skills.h"
using namespace std;

// base class for all life forms
class entity {
public:
	string name;
	skills my_skills;
	int max_hit = 0;

	virtual void calcMax() {
		max_hit = ((1.3 + ((my_skills.strength + 1) / 10) + (1 / 80) + (((my_skills.strength + 1) * 1) / 640)));
	}
};

class monster : public entity {
public:
	vector<item*> droptable;

	monster() {}
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
