#include "Enemy.h"

void enemy::create(IntRect& ksztaltmonster, Sprite& enemy, Sprite& player, int x, int y, RenderWindow& window, Clock& clock, float sword, RectangleShape& healthBarR, float& heroHealth) {

	if (setPos) {
		enemy.setPosition(x, y);
		setPos = false;
	}
	if (health > 0) {
		collision(enemy, player);
		fight(ksztaltmonster, enemy, player, clock, sword);
		healthBar(healthBarR, enemy,window);
		damage(enemy, player,clock, heroHealth);
		window.draw(enemy);
	}
	else
		if (clock.getElapsedTime().asMilliseconds() > 300.0f) 
			player.setColor(Color::White);
}
void enemy::collision(Sprite& enemy, Sprite& player) {
	Vector2f enemyPos = enemy.getPosition();
	Vector2f playerPos = player.getPosition();

	if (playerPos.x >= enemyPos.x - 60 && playerPos.x <= enemyPos.x + 60 && playerPos.y >= enemyPos.y - 60 && playerPos.y <= enemyPos.y + 60) {
		if (playerPos.x < enemyPos.x) {
			player.setPosition(playerPos.x - 10, playerPos.y);
		}
		if (playerPos.x >= enemyPos.x) {
			player.setPosition(playerPos.x + 10, playerPos.y);
		}
		isCollision = true;
	}
	else
		isCollision = false;
}
void enemy::fight(IntRect& ksztaltmonster, Sprite& enemy, Sprite& player, Clock& clock, float sword) {

	if (isCollision) {
		if (Keyboard::isKeyPressed(Keyboard::Space))
			health = health - sword;
		
	}
	if (health <= 3)
		ksztaltmonster.left = 100;
	else
		ksztaltmonster.left = 0;
	enemy.setTextureRect(ksztaltmonster);
}
void enemy::movement(Sprite& enemy, int startX, int stopX, int speed) {
	Vector2f enemyPos = enemy.getPosition();
	
	if (enemyPos.x <= startX)
		L2R = true;
	if (enemyPos.x >= stopX)
		L2R = false;

	if (L2R)
		enemy.setPosition(enemyPos.x + speed, enemyPos.y);

	if (!L2R)
		enemy.setPosition(enemyPos.x - speed, enemyPos.y);

}
void enemy::healthBar(RectangleShape& healthBar, Sprite&enemy, RenderWindow& window) {
	if (setMaxHP) {
		maxHealth = health;
		setMaxHP = false;
	}
	
	healthBar.setPosition(enemy.getPosition().x,enemy.getPosition().y-30);
	Vector2f newSize = Vector2f((health / maxHealth)*100,20);
	healthBar.setSize(newSize);
	window.draw(healthBar);
}
void enemy::damage(Sprite& enemy, Sprite& player,Clock& clock, float& heroHealth) {
	
	Vector2f enemyPos = enemy.getPosition();
	Vector2f playerPos = player.getPosition();
	
	if ((L2R && isCollision && playerPos.x >= enemyPos.x) || (!L2R && isCollision && playerPos.x <= enemyPos.x)) {
		if (clock.getElapsedTime().asMilliseconds() > 160.0f) {
			cout << "To bolalo! Zycie:"+ to_string(heroHealth);
			heroHealth--;
			player.setColor(Color::Color(109, 24, 18, 200));
			clock.restart();
		}	
	}
	else {
		if (clock.getElapsedTime().asMilliseconds() > 300.0f) {
			player.setColor(Color::White);
			clock.restart();
		}
	}
}
