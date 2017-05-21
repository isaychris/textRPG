#pragma once

#include <vector>
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class inventory {
public:
	vector<item*> list;

	void view();
	string isEquiped(int i);
};