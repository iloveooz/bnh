#pragma once
#include "GameField.h"
#include "GameObject.h"

class Entity : public GameObject {
public:
	Entity(const std::string &name, GameField &gameField, size_t x, size_t y);

	virtual bool isDangerous() const;

	size_t getX();
	size_t getY();

	void move(GameField &gameField, size_t x, size_t y);
	void setSelected(bool a);
	void setBrainy(bool a);

	bool isSelected();
	bool isBrainy();
private:
	size_t x_;
	size_t y_;

	bool isSelected_;
	bool isBrainy_;
};