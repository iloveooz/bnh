#include "Entity.h"

Entity::Entity(const std::string &name, GameField &gameField , size_t x, size_t y) : GameObject(name, gameField.spriteSize()), x_(x), y_(y) {
	Entity *ptrEnity = this;
	gameField.playingField_[x_][y_].entity_ = ptrEnity;
	isSelected_ = false;
	isBrainy_ = false;
}

bool Entity::isDangerous() const {
	return false;
}

bool Entity::isBrainy() {
	return isBrainy_;
}

void Entity::setBrainy(bool a) {
	isBrainy_ = a;
}


void Entity::setSelected(bool a) {
	isSelected_ = a;
}

bool Entity::isSelected() {
	return isSelected_;
}


size_t Entity::getX() {
	return x_;
}

size_t Entity::getY() {
	return y_;
}

void Entity::move(GameField &gameField, size_t x, size_t y) {
	Entity *ptrEnity = this;
	gameField.playingField_[x_][y_].entity_ = nullptr;
	x_ = x;
	y_ = y;
	gameField.playingField_[x_][y_].entity_ = ptrEnity;
}