#include "Grass.h"

Grass::Grass(const std::string &name, GameField &gameField, size_t x, size_t y) : FieldObject(name, gameField, x, y) {}

bool Grass::isDangerous() const {
	return false;
}

void Grass::move(GameField &gameField, size_t x, size_t y) {
	FieldObject::move(gameField, x, y);
}