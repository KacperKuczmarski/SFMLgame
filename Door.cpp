#include "Door.h"

void door::doorThru(RectangleShape& door, Sprite& player, int setLevel, RenderWindow& window) {
	const Vector2f playerPos = player.getPosition();
	const Vector2f doorPos = door.getPosition();

	if (playerPos.y < 150 || playerPos.y > 500) {
		if (playerPos.x >= doorPos.x - 20 && playerPos.x <= doorPos.x + 100 && (playerPos.y == doorPos.y || playerPos.y == doorPos.y - 95)) {
			cout << "drzwi hor";

			if (playerPos.y < 300) {
				player.setPosition(playerPos.x, playerPos.y + 400);
			}
			else {
				player.setPosition(playerPos.x, playerPos.y - 400);
				if (playerPos.x < 0)
					player.setPosition(590, 540);

			}
			Level = setLevel;
		}
	}
	else {
		if (playerPos.y >= doorPos.y - 50 && playerPos.y <= doorPos.y + 50 && (playerPos.x == doorPos.x + 45 || playerPos.x == doorPos.x - 70)) {
			cout << "drzwi";

			if (playerPos.x < 300) {
				player.setPosition(playerPos.x + 1030, playerPos.y);
			}
			else {
				player.setPosition(playerPos.x - 1030, playerPos.y);
			}
			Level = setLevel;
		}
	}
	window.draw(door);
}
