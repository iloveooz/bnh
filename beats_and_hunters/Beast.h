#pragma once
#include "Entity.h"
#include "FieldObject.h"
#include "vector"
#include <thread>         
#include <chrono> 

class GameField;

class Beast : public Entity {
public:
	Beast(const std::string &name, GameField &gameField, size_t x, size_t y);

	bool isDangerous() const override;

	void move(GameField &gameField, size_t x, size_t y);
	bool step(GameField &gameField, int randDirection);
	bool stalemate(GameField &gameField);

	bool beastIsLive(GameField &gameField);	
};