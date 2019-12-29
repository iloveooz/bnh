#pragma once
#include "GameField.h"
#include "GameObject.h"

class FieldObject : public GameObject {
public:
	FieldObject(const std::string &name, GameField &gameField, size_t x, size_t y);

	virtual bool isDangerous() const;

	size_t getX();
	size_t getY();

	void move(GameField &gameField, size_t x, size_t y);
private:
	size_t x_;
	size_t y_;
};