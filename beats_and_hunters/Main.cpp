#include "FieldObject.h"
#include "MyGen.h"
#include "Cell.h"
#include "GameField.h"
#include "Entity.h"
#include "Hunter.h"
#include "Beast.h"
#include "Trap.h"
#include "Grass.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <array>


int main() {	
	unsigned int gameSize;
	bool smartBear = false;
	unsigned int trapQty;
	unsigned int hunterQty;
	int spriteSize; //64 96 128  

	std::cout << "Hello, it's game hunters and beast \nUse [W][A][S][D] or arrows for move hunters and [TAB] for next hunter \n\n";

	while (1) {
		std::cout << "pls write playing field size(4 - 32): ";
		std::cin >> gameSize;
		std::cout << "\n";

		if ((gameSize > 3) && (gameSize < 33)) {
			break;
		}
		else {
			std::cout << "error value!\n";
		}
	}

	if ((gameSize > 2) && (gameSize < 7)) {
		spriteSize = 128;
	}

	if ((gameSize > 6) && (gameSize < 9)) {
		spriteSize = 96;
	}

	if (gameSize > 8) {
		spriteSize = 64;
	}

	if (gameSize > 16) {
		spriteSize = 32;
	}

	while (1) {
		std::cout << "pls write the number of hunters(2 - " << gameSize / 2 << "): ";
		std::cin >> hunterQty;
		std::cout << "\n";

		if ((hunterQty >= 2) && (hunterQty <= gameSize / 2)) {
			break;
		}
		else {
			std::cout << "error value!\n";
		}
	}

	while (1) {
		std::cout << "pls write the number of traps(1 - " << gameSize /3 << "): ";
		std::cin >> trapQty;
		std::cout << "\n";

		if ((trapQty >= 1) && (trapQty <= gameSize / 3)) {
			break;
		}
		else {
			std::cout << "error value!\n";
		}
	}

	while (1) {
		std::string str;
		std::string stry = "yes";
		std::string strn = "no";

		std::cout << "use smart bear?(yes/no): ";
		std::cin >> str;
		std::cout << "\n";

		if (str == stry) {
			smartBear = true;
			break;
		} else if (str == strn)	{
			break;
		}
		else {
			std::cout << "error value!\n";
		}
	}

	std::cout << "good luck and have fun!";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	sf::Font myFont;
	myFont.loadFromFile("resources/fonts/myFonts.ttf");

	sf::Text messageWin("", myFont, 120);
	messageWin.setStyle(sf::Text::Bold);
	messageWin.setString("you win!");
	messageWin.setPosition(50, 50);

	sf::Text messageStalemate("", myFont, 100);
	messageStalemate.setStyle(sf::Text::Bold);
	messageStalemate.setString("stalemate!\nyou lose!");
	messageStalemate.setPosition(50, 50);
	   
	enum { UP, DOWN, LEFT, RIGHT };

	bool beastIsLive = true;
	int randDirection;
	bool beastsMove = false;
	int hunterCount = 0;

	MyGen direction(0, 3);
	MyGen randPosition(0, gameSize - 1);
	GameField gameField(gameSize, spriteSize);

	Grass grass("resources/images/grass", gameField, 0, 0);
	FieldObject *ptrgrass = &grass;

	for (unsigned int i = 0; i < gameSize; i++) {
		for (unsigned int j = 0; j < gameSize; j++) {
			gameField.playingField_[i][j].field_ = ptrgrass;
		}
	}

	std::vector <Trap> traps;
	traps.reserve(trapQty);

	for (unsigned int i = 0; i < trapQty; i++) {
		while (1) {
			int x = randPosition.next();
			int y = randPosition.next();

			if (!(gameField.playingField_[x][y].field_->isDangerous())) {
				traps.emplace_back("resources/images/spiky", gameField, x, y);
				break;
			}
		}
	}

	std::vector <Hunter> hunt;
	hunt.reserve(hunterQty);

	for (unsigned int i = 0; i < hunterQty; i++) {
		while(1) {
			int x = randPosition.next();
			int y = randPosition.next();

			if((gameField.playingField_[x][y].entity_ == nullptr) && (!(gameField.playingField_[x][y].field_->isDangerous()))) {
				hunt.emplace_back("resources/images/hunter", gameField, x, y);
				break;
			}
		}
		hunt[i].setSecondSprite();
	}

	hunt[0].setSelected(true);

	int Xbear;
	int Ybear;

	while (1) {
		Xbear = randPosition.next();
		Ybear = randPosition.next();

		if ((gameField.playingField_[Xbear][Ybear].entity_ == nullptr) && (!gameField.playingField_[Xbear][Ybear].field_->isDangerous())) {
			break;
		}
	}

	Beast beast("resources/images/bear", gameField, Xbear, Ybear);
	
	if (smartBear) {
		beast.setBrainy(true);
	}

	sf::RenderWindow window(sf::VideoMode(spriteSize* gameSize, spriteSize* gameSize), "beast and hunter");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
				window.close();
			}
		}		
	
		if (beast.beastIsLive(gameField)) {
			if (beastsMove) {
				randDirection = direction.next();
				beastsMove=!(beast.step(gameField, randDirection));
			}
			else {
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) && (hunterQty != 1)) {

					hunt[hunterCount].setSelected(false);

					if(hunterCount != hunterQty - 1) {
						hunterCount++;
					}
					else {
						hunterCount = 0;
					}	
					hunt[hunterCount].setSelected(true);
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
					beastsMove=(hunt[hunterCount].step(gameField, UP));
				}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
					beastsMove = (hunt[hunterCount].step(gameField, DOWN));
				}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
					beastsMove = (hunt[hunterCount].step(gameField, LEFT));
				}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
					beastsMove = (hunt[hunterCount].step(gameField, RIGHT));
				}
			}
		}	
		
		window.clear();
		gameField.draw(window);

		if (beast.stalemate(gameField)) {
			window.draw(messageStalemate);
	
		}

		if (!beast.beastIsLive(gameField)) {
			window.draw(messageWin);			
		}
		
		window.display();			
	}

	return 0;
}
