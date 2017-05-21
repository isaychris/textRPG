#include "inventory.h"

void inventory::view()
{
	if (!list.empty()) {
		for (unsigned int i = 0; i < list.size(); i++) {
			cout << " - [" << i << "]: " << list[i]->name << " x " << list[i]->quantity << " : " << list[i] << " " << isEquiped(i) << endl;
		}
	}
	else
		cout << " - empty " << endl;

}

string inventory::isEquiped(int i)
{
	if (list[i]->isEquiped == true) {
		return "[equiped]";
	}
	return "";
}
