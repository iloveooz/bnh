#include "GameObject.h"

GameObject::GameObject(const std::string &name, int size) : spriteSize_(size), firstName_(name) {
	secondName_ = name;
	firstName_ += std::to_string(spriteSize_);
	firstName_ += ".png";

	firstImage_.loadFromFile(firstName_);
	firstImage_.createMaskFromColor(sf::Color(0, 0, 0));
	firstTexture_.loadFromImage(firstImage_);
	firstSprite_.setTexture(firstTexture_);
}

void GameObject::setSecondSprite() {
	secondName_ += "i";	
	secondName_ += std::to_string(spriteSize_);
	secondName_ += ".png";

	secondImage_.loadFromFile(secondName_);
	secondImage_.createMaskFromColor(sf::Color(0, 0, 0));
	secondTexture_.loadFromImage(secondImage_);
	secondSprite_.setTexture(secondTexture_);
}

sf::Sprite &GameObject::getFirstSprite() {
	return firstSprite_;
}

sf::Sprite &GameObject::getSecondSprite() {
	return secondSprite_;
}

void GameObject::setPositionFirst(int x, int y) {
	firstSprite_.setPosition(static_cast<float>(x), static_cast<float>(y));
}

void GameObject::setPositionSecond(int x, int y) {
	secondSprite_.setPosition(static_cast<float>(x), static_cast<float>(y));
}