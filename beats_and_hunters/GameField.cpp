#include "GameField.h"
#include "FieldObject.h"
#include "Entity.h"



GameField::GameField(size_t size, int spriteSize) : size_(size), spriteSize_(spriteSize) {
	playingField_.resize(size);
	for (size_t i = 0; i < size_; i++) {
		playingField_[i].resize(size);
	}
}

size_t GameField::size() const {
	return size_;
}

size_t GameField::spriteSize() const {
	return spriteSize_;
}

void GameField::draw(sf::RenderWindow &window) {
	for (size_t i = 0; i < size_; i++) {
		for (size_t j = 0; j < size_; j++) {
			if ((playingField_[i][j].field_ != nullptr)) {	
				playingField_[i][j].field_->setPositionFirst(i * spriteSize_, j * spriteSize_);
				window.draw(playingField_[i][j].field_->getFirstSprite());
			}
			
			if ((playingField_[i][j].entity_ != nullptr)) {
				if (playingField_[i][j].entity_->isSelected()) {
					playingField_[i][j].entity_->setPositionSecond(i * spriteSize_, j * spriteSize_);
					window.draw(playingField_[i][j].entity_->getSecondSprite());					
				}
				else {
					playingField_[i][j].entity_->setPositionFirst(i * spriteSize_, j * spriteSize_);
					window.draw(playingField_[i][j].entity_->getFirstSprite());
				}
			}
		}	
	}
}