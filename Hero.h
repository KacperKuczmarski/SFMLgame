#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#define HeroHP 10

using namespace sf;
using namespace std;




class hero {
public:
	void create(IntRect& ksztaltsword, Sprite& sword, IntRect& ksztaltplayer, Sprite& player, Clock& clock, RenderWindow& window,RectangleShape& healthBar, float heroHealth);
	int swordAvalible = 0;
	int swordDamage = 0;
	int swordSet = 0;
	
private:
	void healthBar(RectangleShape& healthBar, RenderWindow& window, float& heroHealth);
	void playerDraw(IntRect& ksztaltsword, Sprite& sword, IntRect& ksztaltplayer, Sprite& player, Clock& clock);
	void inventory(Sprite& sword, RenderWindow& window);
	void myDelay(int opoznienie);
};