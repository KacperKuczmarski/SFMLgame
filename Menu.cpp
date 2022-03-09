#include "Menu.h"
#include "Door.h"

void myDelay(int opoznienie)
{
	Clock zegar;
	Time czas;
	while (1)
	{
		czas = zegar.getElapsedTime();
		if (czas.asMilliseconds() > opoznienie)
		{
			zegar.restart();
			break;
		}

	}
}

mainMenu::mainMenu(float width, float height) {
	if (!font.loadFromFile("font.otf"))
	{
		return;
	}
	menuText[0].setFont(font);
	menuText[0].setFillColor(Color::Red);
	menuText[0].setString("Nowa gra");
	menuText[0].setPosition(60, 200);

	menuText[1].setFont(font);
	menuText[1].setFillColor(Color::White);
	menuText[1].setString("Wczytaj");
	menuText[1].setPosition(60, 270);

	menuText[2].setFont(font);
	menuText[2].setFillColor(Color::White);
	menuText[2].setString("Wyjscie");
	menuText[2].setPosition(60, 340);

}
void mainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < NumOfMenuOption; i++) {
		window.draw(menuText[i]);
	}
}
void mainMenu::choice() {
	if (Keyboard::isKeyPressed(Keyboard::S)) {

		x++;
		if (x == NumOfMenuOption) {
			x = 0;
			menuText[NumOfMenuOption - 1].setFillColor(Color::White);
			menuText[0].setFillColor(Color::Red);
		}
		else {
			menuText[x - 1].setFillColor(Color::White);
			menuText[x].setFillColor(Color::Red);
		}
		myDelay(200);
		cout << x;
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		if (x == 0) {

			menuText[NumOfMenuOption - 1].setFillColor(Color::Red);
			menuText[0].setFillColor(Color::White);
			x = NumOfMenuOption - 1;
		}
		else {

			menuText[x - 1].setFillColor(Color::Red);
			menuText[x].setFillColor(Color::White);
			x--;
		}
		myDelay(200);
		cout << x;
	}

}


escapeMenu::escapeMenu(float width, float height) {
	if (!font.loadFromFile("font.otf"))
	{
		return;
	}
	menuText[0].setFont(font);
	menuText[0].setFillColor(Color::Red);
	menuText[0].setString("Kontynuuj");
	menuText[0].setPosition(60, 100);

	menuText[1].setFont(font);
	menuText[1].setFillColor(Color::White);
	menuText[1].setString("Zapisz gre");
	menuText[1].setPosition(60, 170);

	menuText[2].setFont(font);
	menuText[2].setFillColor(Color::White);
	menuText[2].setString("Wczytaj gre");
	menuText[2].setPosition(60, 240);

	menuText[3].setFont(font);
	menuText[3].setFillColor(Color::White);
	menuText[3].setString("Wyjscie");
	menuText[3].setPosition(60, 310);

}
void escapeMenu::draw(RenderWindow& window) {
	for (int i = 0; i < NumofEscapeMenu; i++) {
		window.draw(menuText[i]);
	}
}
void escapeMenu::choice() {
	if (Keyboard::isKeyPressed(Keyboard::S)) {

		x++;
		if (x == NumofEscapeMenu) {
			x = 0;
			menuText[NumofEscapeMenu - 1].setFillColor(Color::White);
			menuText[0].setFillColor(Color::Red);
		}
		else {
			menuText[x - 1].setFillColor(Color::White);
			menuText[x].setFillColor(Color::Red);
		}
		myDelay(200);
		cout << x;
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		if (x == 0) {

			menuText[NumofEscapeMenu - 1].setFillColor(Color::Red);
			menuText[0].setFillColor(Color::White);
			x = NumofEscapeMenu - 1;
		}
		else {

			menuText[x - 1].setFillColor(Color::Red);
			menuText[x].setFillColor(Color::White);
			x--;
		}
		myDelay(200);
		cout << x;
	}

}

