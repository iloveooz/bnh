#pragma once
#include "FieldObject.h"

class Grass : public FieldObject {
public:
	Grass(const std::string &name, GameField &gameField, size_t x, size_t y);

	bool isDangerous() const override;

	void move(GameField &gameField, size_t x, size_t y);
};