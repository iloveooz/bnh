#pragma once
#include "Entity.h"
#include "vector"
#include <thread>         
#include <chrono> 

class GameField;

class Hunter : public Entity {
public:
	Hunter(const std::string &name, GameField &gameField, size_t x, size_t y);

	bool isDangerous() const override;

	void move(GameField &gameField, size_t x, size_t y);
	bool step(GameField &gameField, int randDirection);
};
