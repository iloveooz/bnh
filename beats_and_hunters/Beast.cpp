#include "Beast.h"
#include "iostream"


	Beast::Beast(const std::string &name, GameField &gameField, size_t x, size_t y) : Entity(name, gameField, x, y) {}

	bool Beast::isDangerous() const {
		return false;
	}
 
	void Beast::move(GameField &gameField, size_t x, size_t y) {
		Entity::move(gameField, x, y);
	}

	bool Beast::step(GameField &gameField, int randDirection) {
		bool result = false;

		if (!isBrainy()) {
			switch (randDirection) {
			case(0):
				if ((getY() != 0) && (gameField.playingField_[getX()][getY() - 1].entity_ == nullptr)) {
					move(gameField, getX(), getY() - 1);
					result = true;
				}
				break;

			case(1):
				if ((getY() != gameField.size() - 1) && (gameField.playingField_[getX()][getY() + 1].entity_ == nullptr)) {
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
				if ((getX() != gameField.size() - 1) && (gameField.playingField_[getX() + 1][getY()].entity_ == nullptr)) {
					move(gameField, getX() + 1, getY());
					result = true;
				}
				break;
			}
		} else
			//тут очень много логики основная мысль: мы выбрали направление движения и проверяем есть ли там ловушка в случае если есть, 
			//мы проверяем а доступны ли другие поля если доступны то выбираем направление заново, если недоступны идем на ловушку
		{
			switch (randDirection) {
			case(0):
				if ((getY() != 0) && (gameField.playingField_[getX()][getY() - 1].entity_ == nullptr)) {
					if (gameField.playingField_[getX()][getY() - 1].field_->isDangerous()) {

						if (
							(((getY() != gameField.size() - 1) && ((gameField.playingField_[getX()][getY() + 1].entity_ != nullptr)
							|| (gameField.playingField_[getX()][getY() + 1].field_->isDangerous()))) || (getY() == gameField.size() - 1))
					
							&&
							 
							(((getX() != 0) && ((gameField.playingField_[getX() - 1][getY()].entity_ != nullptr)
								|| (gameField.playingField_[getX() - 1][getY()].field_->isDangerous()))) || (getX() == 0))
							&&

							(((getX() != gameField.size() - 1) && ((gameField.playingField_[getX() + 1][getY()].entity_ != nullptr)
								|| (gameField.playingField_[getX() + 1][getY()].field_->isDangerous()))) || (getX() == gameField.size() - 1))
							)
								
						{
							move(gameField, getX(), getY() - 1);
							result = true;
						}
					} else {
						move(gameField, getX(), getY() - 1);
						result = true;
					}
				}
				break;

			case(1):
				if ((getY() != gameField.size() - 1) && (gameField.playingField_[getX()][getY() + 1].entity_ == nullptr)) {
					if (gameField.playingField_[getX()][getY() + 1].field_->isDangerous()) {
						if (
							(((getY() != 0) && ((gameField.playingField_[getX()][getY() - 1].entity_ != nullptr)
							|| (gameField.playingField_[getX()][getY() - 1].field_->isDangerous()))) || (getY() == 0))

							&&

							(((getX() != 0) && ((gameField.playingField_[getX() - 1][getY()].entity_ != nullptr)
								|| (gameField.playingField_[getX() - 1][getY()].field_->isDangerous()))) || (getX() == 0))

							&&

							(((getX() != gameField.size() - 1) && ((gameField.playingField_[getX() + 1][getY()].entity_ != nullptr)
								|| (gameField.playingField_[getX() + 1][getY()].field_->isDangerous()))) || (getX() == gameField.size() - 1))
							)
						{
							move(gameField, getX(), getY() + 1);
							result = true;
						}

					} else {
						move(gameField, getX(), getY() + 1);
						result = true;
					}
				}
				break;

			case(2):
				if ((getX() != 0) && (gameField.playingField_[getX() - 1][getY()].entity_ == nullptr)) {
					if (gameField.playingField_[getX()-1][getY()].field_->isDangerous()) {
						if (
							(((getY() != 0) && ((gameField.playingField_[getX()][getY() - 1].entity_ != nullptr)
								|| (gameField.playingField_[getX()][getY() - 1].field_->isDangerous()))) || (getY() == 0))

							&&

							(((getY() != gameField.size() - 1) && ((gameField.playingField_[getX()][getY() + 1].entity_ != nullptr)
								|| (gameField.playingField_[getX()][getY() + 1].field_->isDangerous()))) || (getY() == gameField.size() - 1))

							&&

							(((getX() != gameField.size() - 1) && ((gameField.playingField_[getX() + 1][getY()].entity_ != nullptr)
								|| (gameField.playingField_[getX() + 1][getY()].field_->isDangerous()))) || (getX() == gameField.size() - 1))
							)
						{
							move(gameField, getX() - 1, getY());
							result = true;
						}
					} else {
						move(gameField, getX() - 1, getY());
						result = true;
					}
				}
				break;

			case(3):
				if ((getX() != gameField.size() - 1) && (gameField.playingField_[getX() + 1][getY()].entity_ == nullptr)) {
					if (gameField.playingField_[getX() + 1][getY()].field_->isDangerous()) { 
						if (
							(((getY() != 0) && ((gameField.playingField_[getX()][getY() - 1].entity_ != nullptr)
							|| (gameField.playingField_[getX()][getY() - 1].field_->isDangerous()))) || (getY() == 0))

							&&

							(((getY() != gameField.size() - 1) && ((gameField.playingField_[getX()][getY() + 1].entity_ != nullptr)
								|| (gameField.playingField_[getX()][getY() + 1].field_->isDangerous()))) || (getY() != gameField.size() - 1))

							&&

							(((getX() != 0) && ((gameField.playingField_[getX() - 1][getY()].entity_ != nullptr)
								|| (gameField.playingField_[getX() - 1][getY()].field_->isDangerous()))) || (getX() == 0))
							)
						{
							move(gameField, getX() + 1, getY());
							result = true;
						}

					} else {
						move(gameField, getX() + 1, getY());
						result = true;
					}
				}
				break;
			}
		}
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	return result;
	}

	bool Beast::beastIsLive(GameField &gameField) {
		bool result = true;

		if (gameField.playingField_[getX()][getY()].field_->isDangerous()) {
			result = false;
		}
		return result;
	}

	bool Beast::stalemate(GameField &gameField) {
		if ((((getY() != 0) && (!(gameField.playingField_[getX()][getY() - 1].entity_ == nullptr))) || (getY()==0))
			
			&&
			
			(((getY() != gameField.size() - 1) && (!(gameField.playingField_[getX()][getY() + 1].entity_ == nullptr))) || (getY() == gameField.size() - 1)) 
			
			&&

			(((getX() != 0) && (!(gameField.playingField_[getX() - 1][getY()].entity_ == nullptr))) || (getX() == 0)) 
			
			&&

			(((getX() != gameField.size() - 1) && (!(gameField.playingField_[getX() + 1][getY()].entity_ == nullptr))) || (getX() == gameField.size() - 1)))
		{
			return true;
		}
		else {
			return false;
		}
	}
