#pragma once
#include "Cell.h"
#include "GameObject.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class Entity;
class FieldObject;

class GameField {
public:
	std::vector<std::vector<Cell>> playingField_;

	size_t size_;
	int spriteSize_;

	GameField(size_t size,int spriteSize);

	size_t spriteSize() const;
	size_t size() const;

	void draw(sf::RenderWindow &window);
};
