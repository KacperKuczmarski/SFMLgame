#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;



class door {
	
public:
	void doorThru(RectangleShape& door, Sprite& player, int setLevel, RenderWindow& window);
	int Level = 1;
};