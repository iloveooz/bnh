#include "Honey.h"

Honey::Honey(const std::string &name, GameField &gameField, size_t x, size_t y) : FieldObject(name, gameField, x, y) {}

bool Honey::isDangerous() const {
	return false;
}


void Honey::move(GameField &gameField, size_t x, size_t y) {
	FieldObject::move(gameField, x, y);
}
