#include "Trap.h"

Trap::Trap(const std::string &name, GameField &gameField, size_t x, size_t y) : FieldObject(name, gameField, x, y) {}

bool Trap::isDangerous() const {
	return true;
}

void Trap::move(GameField &gameField, size_t x, size_t y) {
	FieldObject::move(gameField, x, y);
}