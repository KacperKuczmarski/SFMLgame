#pragma once

class debug {
public:
	void heroDebug(Sprite& player) {
		if (Keyboard::isKeyPressed(Keyboard::Z)) {
			std::cout << "Aktualna pozycja: " << std::endl << "x: " << player.getPosition().x << std::endl << "y: " << player.getPosition().y;
		}

	}
	void setLevel(int& level) {
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			level = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num2)) {
			level = 2;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num3)) {
			level = 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num4)) {
			level = 4;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num5)) {
			level = 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num6)) {
			level = 6;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num7)) {
			level = 7;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num8)) {
			level = 8;
		}
		if (Keyboard::isKeyPressed(Keyboard::Num9)) {
			level = 9;
		}
	}
private:

};