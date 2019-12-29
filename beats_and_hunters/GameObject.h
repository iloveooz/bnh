#pragma once
#include <SFML/Graphics.hpp> 
#include <string>

class GameObject {
public:
	GameObject(const std::string &name, int size);

	void setSecondSprite();

	sf::Sprite &getFirstSprite();
	sf::Sprite &getSecondSprite();

	void setPositionFirst(int x, int y);
	void setPositionSecond(int x, int y);
private:
	int spriteSize_;

	std::string firstName_;
	std::string secondName_;

	sf::Image firstImage_;
	sf::Image secondImage_;

	sf::Texture firstTexture_;
	sf::Texture secondTexture_;

	sf::Sprite firstSprite_;
	sf::Sprite secondSprite_;
};


