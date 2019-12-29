#include "FieldObject.h"

FieldObject::FieldObject(const std::string &name, GameField &gameField, size_t x, size_t y) : GameObject(name, gameField.spriteSize()), x_(x), y_(y) {
	FieldObject *ptrField = this;
	gameField.playingField_[y_][x_].field_ = ptrField;
}

bool FieldObject::isDangerous() const {
	return false;
}

size_t FieldObject::getX() {
	return x_;
}

size_t FieldObject::getY() {	
	return x_;
}

void FieldObject::move(GameField &gameField, size_t x, size_t y) {
	FieldObject *ptrField = this;
	gameField.playingField_[y_][x_].field_ = nullptr;
	x_ = x;
	y_ = y;
	gameField.playingField_[y_][x_].field_ = ptrField;
}