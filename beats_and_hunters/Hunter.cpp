
#include "Hunter.h"

Hunter::Hunter(const std::string &name, GameField &gameField, size_t x, size_t y) : Entity(name, gameField, x, y) {}

bool Hunter::isDangerous() const {
	return true;
}

void Hunter::move(GameField &gameField, size_t x, size_t y) {
	Entity::move(gameField, x, y);
}

bool Hunter::step(GameField &gameField, int direction) {
	bool result = false;
	switch (direction) {
		case(0):
			if ((getY() != (0)) && (gameField.playingField_[getX()][getY() - 1].entity_ == nullptr)) {
				move(gameField, getX(), getY() - 1);
				result = true;
			}
			break;

		case(1):
			if ((getY() != (gameField.size() - 1)) && (gameField.playingField_[getX()][getY() + 1].entity_ == nullptr)) {
				move(gameField, getX(), getY() + 1);
				result = true;
			}
			break;

		case(2):
			if ((getX() != 0) && (gameField.playingField_[getX() - 1][getY()].entity_ == nullptr)) {
				move(gameField, getX() - 1, getY());
				result = true;
			}
			break;

		case(3):
			if ((getX() != (gameField.size() - 1)) && (gameField.playingField_[getX() + 1][getY()].entity_ == nullptr)) {
				move(gameField, getX() + 1, getY());
				result = true;
			}
		break;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	return result;
}