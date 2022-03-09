//====================================
//		Kacper Kuczmarski
//		
//		Gra komputerowa SFML
//
//		2020
//====================================
#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include "Menu.h"
#include "Debug.h"
#include "Hero.h"
#include "Enemy.h"
#include "NPC.h"
#include "Door.h"

using namespace sf; 
using namespace std;


int main2()
{

	Clock zegar;
	Clock NPCclock;
	Font font;
	font.loadFromFile("font.otf");

	debug debug;

	RenderWindow window(VideoMode(1280, 720), "Gra 01" /*, Style::Fullscreen*/);
	window.setFramerateLimit(60);

	fstream save;

	//RectangleShapes
	 
		//Doors shapes

		RectangleShape doorShapeUp(Vector2f(120, 60));
		doorShapeUp.setFillColor(Color::Black);
		doorShapeUp.setPosition(580, 120);

		RectangleShape doorShapeDown(Vector2f(120, 70));
		doorShapeDown.setFillColor(Color::Black);
		doorShapeDown.setPosition(580, 645);

		RectangleShape doorShapeLeft(Vector2f(75, 120));
		doorShapeLeft.setFillColor(Color::Black);
		doorShapeLeft.setPosition(5, 360);

		RectangleShape doorShapeRight(Vector2f(75, 120));
		doorShapeRight.setFillColor(Color::Black);
		doorShapeRight.setPosition(1200, 360);

		RectangleShape healthBar(Vector2f(100, 20));
		healthBar.setFillColor(Color::Color(109, 24, 18, 255));

		RectangleShape inventorySword(Vector2f(80, 80));
		inventorySword.setFillColor(Color::Color(123, 123, 123, 255));
		inventorySword.setPosition(900, 10);
		inventorySword.setOutlineColor(Color::Color(109, 24, 18, 255));
		inventorySword.setOutlineThickness(5);

	
	//Text
	 
		Text text;
		text.setFont(font);
		text.setPosition(250, 30);
		text.setCharacterSize(35);

		Text NPCmessages;
		NPCmessages.setFont(font);
		NPCmessages.setCharacterSize(20);
		NPCmessages.setFillColor(Color::Color(0, 0, 0, 255));
		
		Text swordDmg;
		swordDmg.setFont(font);
		swordDmg.setCharacterSize(20);
		swordDmg.setPosition(1000, 10);

		Text helpText;
		helpText.setFont(font);
		helpText.setCharacterSize(20);
		helpText.setFillColor(Color::Red);

		Text gameover;
		gameover.setFont(font);
		gameover.setCharacterSize(30);
		gameover.setFillColor(Color::Red);
		gameover.setString("KONIEC GRY!");
		gameover.setPosition(60, 60);
	
	//Textures&Sprites
	 
		Texture mapaT;
		mapaT.loadFromFile("map2.png");
		IntRect ksztaltMapa(0, 0, 1280, 720);
		Sprite map(mapaT, ksztaltMapa);

		Texture playerT;
		playerT.loadFromFile("player.png");
		IntRect ksztaltPlayer(0, 0, 100, 100);
		Sprite player(playerT, ksztaltPlayer);

		player.setPosition(100, 120);

		Texture swordT;
		swordT.loadFromFile("sword.png");
		IntRect ksztaltSword(0, 0, 100, 100);
		Sprite sword(swordT, ksztaltSword);


		Texture monsterT;
		monsterT.loadFromFile("monster1v2.png");
		IntRect ksztaltMonster(0, 0, 100, 100);
		Sprite monster1(monsterT, ksztaltMonster);
		Sprite monster2(monsterT, ksztaltMonster);
		Sprite monster3(monsterT, ksztaltMonster);

		Texture npcT;
		npcT.loadFromFile("npc1.png");
		IntRect ksztaltNpc(0, 0, 100, 100);
		Sprite npc(npcT, ksztaltNpc);
	
	//sound
		SoundBuffer buffer;
		buffer.loadFromFile("SOUND/steps.wav");

		Sound steps;
		steps.setBuffer(buffer);

	mainMenu mainMenu(window.getSize().x, window.getSize().y);
	escapeMenu escapeMenu(window.getSize().x, window.getSize().y);


	hero hero;
	float heroHealth = 10;
	door door;
	//Level 3 monsters
	enemy monsterL3V1;
	monsterL3V1.health = Level3MonsterHealth;
	enemy monsterL3V2;
	monsterL3V2.health = Level3MonsterHealth;
	//Level 5 monsters
	enemy monsterL5V1;
	monsterL5V1.health = Level5MonsterHealth;
	//Level 7 monsters
	enemy monsterL7V1;
	monsterL7V1.health = Level7MonsterHealth;
	enemy monsterL7V2;
	monsterL7V2.health = Level7MonsterHealth;

	NPC NPC1;

	while (window.isOpen())
	{
		const Vector2f playerPos = player.getPosition();
		sword.setPosition(playerPos);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		//MAIN MENU
		if (mainMenu.menuFlag) {
			mainMenu.choice();


			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Z)) {

				if (mainMenu.x == 0) {
					cout << "New game";
					
					door.Level = 1;
					heroHealth = HeroHP;
					player.setColor(Color::White);
					mainMenu.menuFlag = false;
				}
				if (mainMenu.x == 1) {

					save.open("SAVE/save.dat", ios::in);
					if (!save.good()) {
						cout << "save error";
						mainMenu.menuFlag = false;
					}
					else {
						string line;
						int lineN = 1;
						while (getline(save, line))
						{
							switch (lineN) {
							case 1: door.Level = atoi(line.c_str()); break;
							case 2: heroHealth = atoi(line.c_str()); break;
							case 3: hero.swordAvalible; break;
							case 4: monsterL3V1.health = atoi(line.c_str()); break;
							case 5: monsterL3V2.health = atoi(line.c_str()); break;
							case 6: monsterL5V1.health = atoi(line.c_str()); break;
							case 7: monsterL7V2.health = atoi(line.c_str()); break;
							case 8: monsterL7V1.health = atoi(line.c_str()); break;
							}
							lineN++;
						}
						hero.swordSet = 0;
						std::cout << "Save loaded";
					}
					save.close();
					mainMenu.menuFlag = false;
				}
				if (mainMenu.x == 2) {
					cout << "Exit";
					window.close();
				}
			}
		}
		//MAIN MENU END

		//ESCAPE MENU EVENT
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			escapeMenu.esc = true;
		if (escapeMenu.esc)
		{
			escapeMenu.menuFlag = true;
			escapeMenu.choice();

			if (Keyboard::isKeyPressed(Keyboard::Z))
			{
				if (escapeMenu.x == 0)
					escapeMenu.menuFlag = false;
					escapeMenu.esc = false;

				if (escapeMenu.x == 1) {
					save.open("SAVE/save.dat", ios::out);
					save << door.Level << endl;
					save << heroHealth << endl;
					save << hero.swordAvalible << endl;
					save << monsterL3V1.health << endl;
					save << monsterL3V2.health << endl;
					save << monsterL5V1.health << endl;
					save << monsterL7V2.health << endl;
					save << monsterL7V1.health << endl;
					save.close();

					cout << "Game saved" << endl;

					escapeMenu.menuFlag = false;
					escapeMenu.esc = false;
				}
				if (escapeMenu.x == 2) {

					save.open("SAVE/save.dat", ios::in);
					if (!save.good()) {
						std::cout << "save error";
						escapeMenu.menuFlag = false;
						escapeMenu.esc = false;
					}
					else {
						string line;
						int lineN = 1;
						while (getline(save, line))
						{
							switch (lineN) {
							case 1: door.Level = atoi(line.c_str()); break;
							case 2: heroHealth = atoi(line.c_str()); break;
							case 3: hero.swordAvalible; break;
							case 4: monsterL3V1.health = atoi(line.c_str()); break;
							case 5: monsterL3V2.health = atoi(line.c_str()); break;
							case 6: monsterL5V1.health = atoi(line.c_str()); break;
							case 7: monsterL7V2.health = atoi(line.c_str()); break;
							case 8: monsterL7V1.health = atoi(line.c_str()); break;
							
							}
							lineN++;
						}
						hero.swordSet = 0;
						std::cout << "Save loaded";
					}
					save.close();
					escapeMenu.menuFlag = false;
					escapeMenu.esc = false;
				}
					if (escapeMenu.x == 3)
						window.close();
				}
			}
			else
				escapeMenu.menuFlag = false;
			// ESCAPE MENU END

			window.clear();

			if (!mainMenu.menuFlag && !escapeMenu.menuFlag) {
				//Main LEVELS

				swordDmg.setString("Obrazenia: " + to_string(hero.swordDamage));
				text.setString("Poziom: " + to_string(door.Level));

				if (door.Level == 1) {
					window.draw(map);
					window.draw(inventorySword);
					
					door.doorThru(doorShapeUp, player, 2, window);
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						/*steps.play();*/
					}
					hero.swordAvalible = 0;
				}
				if (door.Level == 2) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeDown, player, 1, window);
					door.doorThru(doorShapeRight, player, 3, window);

					NPC1.create(npc, ksztaltNpc, player, 590, 300, window, NPCmessages, "Witaj! Przed wyruszeniem w podroz \n zabierz ze soba ten oto miecz. (nacisnij 'I' aby wybrac.) \n Chociaz jest tylko drewniany, uchroni Cie przed niebezpieczenstwami \n kryjacymi sie w nastepnej komnacie.", NPCclock);
					hero.swordAvalible = 1;
				}
				if (door.Level == 3) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeLeft, player, 2, window);
					if (monsterL3V1.health <= 0 && monsterL3V2.health <= 0)
						door.doorThru(doorShapeRight, player, 4, window);

					monsterL3V1.create(ksztaltMonster, monster1, player, 200, 200, window, zegar, hero.swordDamage, healthBar, heroHealth);
					monsterL3V2.create(ksztaltMonster, monster2, player, 500, 300, window, zegar, hero.swordDamage, healthBar, heroHealth);
				}
				if (door.Level == 4) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeLeft, player, 3, window);
					door.doorThru(doorShapeDown, player, 5, window);

					NPC1.create(npc, ksztaltNpc, player, 590, 300, window, NPCmessages, "Widze, ze pokonales swoich pierwszych przeciwnikow z latwoscia. \n Byly one nieruchome, wiec latwo je pokonales. \n Potwor w nastepnej komnacie bedzie wiekszym wyzwaniem. \n Atakuj go tylko w momencie kiedy od Ciebie odchodzi!", NPCclock);
				}
				if (door.Level == 5) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeUp, player, 4, window);
					if (monsterL5V1.health <= 0)
						door.doorThru(doorShapeRight, player, 6, window);

					monsterL5V1.create(ksztaltMonster, monster1, player, 500, 300, window, zegar, hero.swordDamage, healthBar,heroHealth);
					monsterL5V1.movement(monster1, 100, 600, 1);
				}
				if (door.Level == 6) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeLeft, player, 5, window);
					door.doorThru(doorShapeRight, player, 7, window);

					NPC1.create(npc, ksztaltNpc, player, 590, 300, window, NPCmessages, "Tego tez udalo Ci sie pokonac? \n Brawo! \n A co powiesz na wieksza ilosc potworow?", NPCclock);
				}
				if (door.Level == 7) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeLeft, player, 6, window);
					if (monsterL7V1.health <= 0 && monsterL7V2.health <= 0)
						door.doorThru(doorShapeUp, player, 8, window);

					monsterL7V1.create(ksztaltMonster, monster1, player, 600, 300, window, zegar, hero.swordDamage, healthBar, heroHealth);
					monsterL7V1.movement(monster1, 200, 600, 2);
					monsterL7V2.create(ksztaltMonster, monster2, player, 800, 500, window, zegar, hero.swordDamage, healthBar, heroHealth);
					monsterL7V2.movement(monster2, 700, 800, 4);
				}
				if (door.Level == 8) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeDown, player, 7, window);
					door.doorThru(doorShapeRight, player, 9, window);

					NPC1.create(npc, ksztaltNpc, player, 590, 300, window, NPCmessages, "Stales sie na prawde doswiadczonym wojownikiem!\n Niestety w daleszej czesci przygody nie moge\n Ci uczestniczyc. Prosze wez ten miecz. Jest on lepszy niz drewniany. \n Powodzenia na szlaku i mam nadzieje ze sie zobaczymy!", NPCclock);
					hero.swordAvalible = 2;
				}
				if (door.Level == 9) {
					window.draw(map);
					window.draw(inventorySword);

					door.doorThru(doorShapeLeft, player, 8, window);


				}
				
				hero.create(ksztaltSword, sword, ksztaltPlayer, player, zegar, window, healthBar, heroHealth);
				window.draw(text);
				window.draw(swordDmg);
			}

			if (heroHealth <= 0) {
				mainMenu.menuFlag = true;
				window.draw(gameover);
			}
				
			if (mainMenu.menuFlag)
				mainMenu.draw(window);

			if (escapeMenu.menuFlag)
				escapeMenu.draw(window);

			//HELP MENU
			if (Keyboard::isKeyPressed(Keyboard::F1)) 
			{
				helpText.setPosition(playerPos.x, playerPos.y + 100);
				helpText.setString("Quick help:\n\n 1.Sterowanie: WASD\n2.Atak: naciskanie SPACE + A lub D\n3.Wybieranie broni: I (daje krotkie spowolnienie czasu na wybor)");
				window.draw(helpText);
			}

			window.display();

			debug.heroDebug(player);
			debug.setLevel(door.Level);
		}
		return 0;
	
}

