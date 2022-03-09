#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class NPC {
public:
	void create(Sprite& NPC, IntRect& ksztaltNPC, Sprite& player, int x, int y, RenderWindow& window, Text& text, const string& messages, Clock& clock);
private:
	void collision(Sprite& NPC, Sprite& player);
	void message(const string& message, int x, int y, Text& text, RenderWindow& window);
	void animate(IntRect& ksztaltNPC, Sprite& NPC, Clock& clock);
	bool isCollision;
};