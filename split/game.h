#pragma once

#include <string>
#include <vector>
#include "item.h"
#include "enums.h"
#include "entity.h"
#include "database.h"
#include "player.h"

using namespace std;


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