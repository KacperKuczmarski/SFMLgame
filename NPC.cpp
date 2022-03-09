#include "NPC.h"

void NPC::create(Sprite& NPC, IntRect& ksztaltNPC, Sprite& player, int x, int y, RenderWindow& window, Text& text, const string& messages, Clock& clock) {
	NPC.setPosition(x, y);
	collision(NPC, player);
	animate(ksztaltNPC, NPC, clock);
	message(messages, x, y, text, window);
	window.draw(NPC);
}
void NPC::collision(Sprite& NPC, Sprite& player) {
	Vector2f NPCPos = NPC.getPosition();
	Vector2f playerPos = player.getPosition();

	if (playerPos.x >= NPCPos.x - 60 && playerPos.x <= NPCPos.x + 60 && playerPos.y >= NPCPos.y - 60 && playerPos.y <= NPCPos.y + 60) {
		if (playerPos.x < NPCPos.x) {
			player.setPosition(playerPos.x - 10, playerPos.y);
		}
		if (playerPos.x >= NPCPos.x) {
			player.setPosition(playerPos.x + 10, playerPos.y);
		}
	}
	if (playerPos.x >= NPCPos.x - 120 && playerPos.x <= NPCPos.x + 120 && playerPos.y >= NPCPos.y - 120 && playerPos.y <= NPCPos.y + 120)
		isCollision = true;
	else
		isCollision = false;
}
void NPC::message(const string& message, int x, int y, Text& text, RenderWindow& window) {
	if (isCollision) {
		text.setPosition(x - 100, y - 140);
		text.setString(message);
		window.draw(text);
	}
}
void NPC::animate(IntRect& ksztaltNPC, Sprite& NPC, Clock& clock) {
	if (clock.getElapsedTime().asMilliseconds() > 400.0f) {
		if (ksztaltNPC.left >= 100)
			ksztaltNPC.left = 0;
		else
			ksztaltNPC.left = 100;

		NPC.setTextureRect(ksztaltNPC);
		clock.restart();
	}
}