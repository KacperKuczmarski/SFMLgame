#include "Hero.h"

void hero::myDelay(int opoznienie)
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

void hero::playerDraw(IntRect& ksztaltsword, Sprite& sword, IntRect& ksztaltplayer, Sprite& player, Clock& clock) {

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (clock.getElapsedTime().asMilliseconds() > 120.0f) {
			if (ksztaltsword.top >= 100) {
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					ksztaltsword.top = 0;
					ksztaltsword.left = 100;
					ksztaltplayer.top = 100;
					ksztaltplayer.left = 200;
				}
				else {
					ksztaltsword.top = 0;
					ksztaltsword.left = 0;
					ksztaltplayer.top = 0;
					ksztaltplayer.left = 0;
				}
			}
			else {
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					ksztaltsword.top = 100;
					ksztaltsword.left = 100;
					ksztaltplayer.top = 200;
					ksztaltplayer.left = 100;
				}
				else {
					ksztaltsword.top = 100;
					ksztaltsword.left = 0;
					ksztaltplayer.top = 200;
					ksztaltplayer.left = 0;
				}
			}
			clock.restart();
		}

		player.setTextureRect(ksztaltplayer);
	}
	else {
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			ksztaltplayer.top = 100;
			ksztaltsword.left = 100;
			ksztaltsword.top = 0;
		}
		else {
			ksztaltplayer.top = 0;
			ksztaltsword.left = 0;
			ksztaltsword.top = 0;
		}
		if (clock.getElapsedTime().asMilliseconds() > 120.0f) {
			if (ksztaltplayer.left >= 200)
				ksztaltplayer.left = 0;
			else
				ksztaltplayer.left += 100;

			player.setTextureRect(ksztaltplayer);
			clock.restart();
		}
	}
	sword.setTextureRect(ksztaltsword);

}
void hero::create(IntRect& ksztaltsword, Sprite& sword, IntRect& ksztaltplayer, Sprite& player, Clock& clock, RenderWindow& window,RectangleShape& healthbar, float heroHealth) {
	const Vector2f playerPos = player.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::Space))
		playerDraw(ksztaltsword, sword, ksztaltplayer, player, clock);
	else {
		if (Keyboard::isKeyPressed(Keyboard::W) && playerPos.y != 120)
		{
			const Vector2f playerPos = player.getPosition();
			player.setPosition(playerPos.x, playerPos.y - 10);
			playerDraw(ksztaltsword, sword, ksztaltplayer, player, clock);

		}
		if (Keyboard::isKeyPressed(Keyboard::S) && playerPos.y != 550)
		{
			const Vector2f playerPos = player.getPosition();
			player.setPosition(playerPos.x, playerPos.y + 10);
			playerDraw(ksztaltsword, sword, ksztaltplayer, player, clock);

		}
		if (Keyboard::isKeyPressed(Keyboard::A) && playerPos.x != 50)
		{
			const Vector2f playerPos = player.getPosition();
			player.setPosition(playerPos.x - 10, playerPos.y);
			playerDraw(ksztaltsword, sword, ksztaltplayer, player, clock);

		}
		if (Keyboard::isKeyPressed(Keyboard::D) && playerPos.x != 1130)
		{
			const Vector2f playerPos = player.getPosition();
			player.setPosition(playerPos.x + 10, playerPos.y);
			playerDraw(ksztaltsword, sword, ksztaltplayer, player, clock);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
			playerDraw(ksztaltsword, sword, ksztaltplayer, player, clock);
	}
	window.draw(player);
	healthBar(healthbar, window, heroHealth);
	inventory(sword, window);
}
void hero::healthBar(RectangleShape& healthBar, RenderWindow& window, float& heroHealth) {

	healthBar.setPosition(600, 35);
	Vector2f newSize = Vector2f((heroHealth / HeroHP) * 200, 20);
	healthBar.setSize(newSize);
	window.draw(healthBar);
}
void hero::inventory(Sprite& sword, RenderWindow& window) {
	Sprite newSword = sword;
	IntRect ksztaltNewSword(0, 0, 100, 100);
	newSword.setPosition(840, -10);
	newSword.setTextureRect(ksztaltNewSword);
	newSword.setScale(1.5, 1.5);
	if (Keyboard::isKeyPressed(Keyboard::I)) {
		if (swordAvalible == swordSet) {
			myDelay(130);
			swordSet = 0;
		}
		else {
			myDelay(130);
			swordSet++;
		}
	}
	switch (swordSet) {
	case 0:
		swordDamage = 0;
		break;
	case 1:
		sword.setColor(Color::White);
		newSword.setColor(Color::White);
		window.draw(newSword);
		window.draw(sword);
		swordDamage = 1;
		break;
	case 2: 
		sword.setColor(Color::Color(130,130,130,255));
		newSword.setColor(Color::Color(130, 130, 130, 255));
		window.draw(newSword);
		window.draw(sword);
		swordDamage = 2;
		break;

	}
}