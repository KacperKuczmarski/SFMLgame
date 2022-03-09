#pragma once
#include "SFML/Graphics.hpp"
#include "Hero.h"
#include <iostream>

#define Level3MonsterHealth 8
#define Level5MonsterHealth 10
#define Level7MonsterHealth 10



using namespace sf;
using namespace std;

class enemy {
public:
	float health;
	void create(IntRect& ksztaltmonster, Sprite& enemy, Sprite& player, int x, int y, RenderWindow& window, Clock& clock, float sword, RectangleShape& healthBar, float& heroHealth);
	void movement(Sprite& enemy, int startX, int stopX, int speed);
private:
	bool isCollision;
	bool setPos = true;
	bool setMaxHP = true;
	bool L2R;
	float maxHealth;
	void collision(Sprite& enemy, Sprite& player);
	void fight(IntRect& ksztaltmonster, Sprite& enemy, Sprite& player, Clock& clock, float sword);
	void healthBar(RectangleShape& healthBar, Sprite& enemy, RenderWindow& window);
	void damage(Sprite& enemy, Sprite& player, Clock& clock, float& heroHealth);
};