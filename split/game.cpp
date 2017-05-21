
#include "game.h"
#include <iomanip>
#include <algorithm>
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
		if (hero.my_equipment.helmet_slot == nullptr) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 1) {
		if (hero.my_equipment.platebody_slot == nullptr) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 2) {
		if (hero.my_equipment.platelegs_slot == nullptr) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 3) {
		if (hero.my_equipment.shield_slot == nullptr) {
			cout << " - slot is empty." << endl;
		}
		menu();
	}
	else if (slot == 4) {
		if (hero.my_equipment.weapon_slot == nullptr) {
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
			if (hero.my_equipment.helmet_slot != nullptr)
				hero.unequip(hero.my_equipment.helmet_slot);
		}

		// platebody slot
		else if (slot == 1) {
			if (hero.my_equipment.platebody_slot != nullptr)
				hero.unequip(hero.my_equipment.platebody_slot);
		}

		// platelegs slot
		else if (slot == 2) {
			if (hero.my_equipment.platelegs_slot != nullptr)
				hero.unequip(hero.my_equipment.platelegs_slot);
		}

		// shield slot
		else if (slot == 3) {
			if (hero.my_equipment.shield_slot != nullptr)
				hero.unequip(hero.my_equipment.shield_slot);
		}

		// weapon slot
		else if (slot == 4) {
			if (hero.my_equipment.weapon_slot != nullptr)
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
	cout << "(0): [View] Player Info." << endl;
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
