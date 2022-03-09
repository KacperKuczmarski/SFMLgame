#define NumOfMenuOption 3
#define NumofEscapeMenu 4
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>

using namespace sf;

void myDelay(int opoznienie);

class mainMenu {
	public:
		bool menuFlag = true;
		void draw(RenderWindow& window);
		mainMenu(float width, float height);
		~mainMenu() {};
		void choice();
		int x = 0;
	private:
		Font font;
		Text menuText[NumOfMenuOption];	
};

class escapeMenu {
public:
	bool menuFlag = false;
	void choice();
	void draw(RenderWindow& window);
	escapeMenu(float width, float height);
	~escapeMenu() {};
	int x = 0;
	bool esc = false;
private:
	Font font;
	Text menuText[NumofEscapeMenu];

};