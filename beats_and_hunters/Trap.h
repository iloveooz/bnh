#pragma once
#include "FieldObject.h"

class Trap : public FieldObject {
public:
	Trap(const std::string &name, GameField &gameField, size_t x, size_t y);

	bool isDangerous() const override;

	void move(GameField &gameField, size_t x, size_t y);
};