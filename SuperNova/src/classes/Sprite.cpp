#include "headers/Sprite.h"

Sprite::Sprite() {
	animated = false;
}

Sprite::Sprite(const std::string& filePath) {
	if (!texture.loadFromFile(filePath))
		std::cout << "Could not load sprite at: " << filePath << std::endl;

	sprite.setTexture(texture);
	this->filePath = filePath;

	sprites.push_back(this);
	//image = texture.copyToImage();
}

Sprite::Sprite(const std::string& filePath, bool animated, bool random, int numFrames, int width, int height, float scale, int frequency)
	:Sprite(filePath)
{
	this->animated = animated;
	this->random = random;
	this->numFrames = numFrames;
	this->width = width;
	this->height = height;
	this->scale = scale;
	this->frequency = frequency;

	sprite.setScale(sf::Vector2f(scale, scale));
	if (animated) animating = true;

	if (!animated) sprite.setTextureRect(sf::IntRect(0,0, width, height));

	//image = texture.copyToImage();
}

void Sprite::animate() {
	if (timer.getElapsedTime().asMilliseconds() >= frequency) {

		if (random) {
			offset = std::rand() % numFrames;
			sprite.setTextureRect(sf::IntRect(offset * abs(width) + left, top, width-boundWidth, height-boundHeight));
		}
		else {
			sprite.setTextureRect(sf::IntRect(offset++ * abs(width) + left, top, width-boundWidth, height-boundHeight));

			if (offset == numFrames) offset = 0;
		}

		timer.restart();
	}
}

void Sprite::animateAll() {
	for (Sprite* s : sprites) {
		if (s->animated && s->animating) {
			s->animate();
		}

		if (!s->animated && s->animating) {
			if (s->offset != s->numFrames) s->animateOnce();
		}

		if (s->special && s->animatingSpecial) {
			s->animateSpecial();
		}

		if (s->damaged && s->animatingDamaged) {
			s->animateDamaged();
		}
	}
}

void Sprite::animateDamaged() {
	if (!animatingDamaged) {
		animating = false;
		animatingDamaged = true;
		offset = 0;

		timer.restart();
	}

	sprite.setTextureRect(sf::IntRect(offset * abs(damagedWidth) + damagedLeft, damagedTop, damagedWidth - boundWidth, damagedHeight - boundHeight));
	
	if (timer.getElapsedTime().asMilliseconds() >= frequency*3) {
		animatingDamaged = false;
		animating = true;

		timer.restart();
	}
}

void Sprite::animateOnce() {
	if (!animating) animating = true;
	if (timer.getElapsedTime().asMilliseconds() >= frequency) {

		sprite.setTextureRect(sf::IntRect(offset++ * abs(width) + left, top, width, height));
		if (offset == numFrames) {
			offset = 0;
			animating = false;
		}

		//std::cout << "offset: " << offset << std::endl;

		timer.restart();
	}
}

void Sprite::animateSpecial() {
	if (!animatingSpecial) {
		animating = false;
		animatingSpecial = true;
		offset = 0;
	}

	if (timer.getElapsedTime().asMilliseconds() >= frequency) {

		sprite.setTextureRect(sf::IntRect(offset++ * abs(specialWidth) + specialLeft, specialTop, specialWidth, specialHeight));
		if (offset == specialNumFrames) {
			offset = 0;
			animatingSpecial = false;
			animating = true;
		}

		timer.restart();
	}
}

void Sprite::flipHorizontal() {
	left += width;
	specialLeft += specialWidth;
	damagedLeft += damagedWidth;

	flippedHorizontal = !flippedHorizontal;

	width = -width;
	specialWidth = -specialWidth;
	damagedWidth = -damagedWidth;

	sprite.setTextureRect(sf::IntRect(offset * abs(width) + left, top, width - boundWidth, height - boundHeight));
}

void Sprite::flipVertical() {
	top += height;
	specialTop += specialHeight;
	damagedTop += damagedHeight;

	flippedVertical = !flippedVertical;

	height = -height;
	specialHeight = -specialHeight;
	damagedHeight = -damagedHeight;

	sprite.setTextureRect(sf::IntRect(offset * abs(width) + left, top, width - boundWidth, height - boundHeight));
}

std::string& Sprite::getFilePath() { return filePath; }

int Sprite::getFrequency() { return frequency; }

int Sprite::getHeight() { return height; }

int Sprite::getNumFrames() { return numFrames;  }

float Sprite::getScale() { return scale; }

sf::Vector2f Sprite::getScaledSize() { return sf::Vector2f(abs(width) * scale, abs(height) * scale); }

sf::Sprite* Sprite::getSprite() { return &sprite; }

sf::Texture Sprite::getTexture() { return texture; }

sf::Clock Sprite::getTimer() { return timer; }

int Sprite::getWidth() { return width; }

sf::FloatRect Sprite::getBoundingBox() { return sprite.getGlobalBounds(); }

bool Sprite::hasDamaged() { return damaged; }

bool Sprite::hasSpecial() { return special; }

bool Sprite::isAnimated() { return animated; }

bool Sprite::isFlippedHorizontal() { return flippedHorizontal; }

bool Sprite::isFlippedVertical() { return flippedVertical; }

bool Sprite::isRandom() { return random; }

// Adapted code from: https://stackoverflow.com/questions/27306086/c-remove-object-from-vector
void Sprite::remove(Sprite* spr) {
	sprites.erase(std::remove(sprites.begin(), sprites.end(), spr));
}

void Sprite::setBounds(int width, int height) {
	boundWidth = floor(floor(scale*this->width - width) / scale);
	boundHeight = ceil((ceil(scale * this->height) - height) / scale);
}

void Sprite::setDamaged(int left, int top, int width, int height) {
	damagedLeft = left;
	damagedTop = top;
	damagedWidth = width;
	damagedHeight = height;

	damaged = true;
}

void Sprite::setFrame(int frame) {
	animating = false;
	animated = false;

	sprite.setTextureRect(sf::IntRect((frame-1) * abs(width) + left, top, width - boundWidth, height - boundHeight));
}

void Sprite::setScale(float scale) {
	this->scale = scale;

	sprite.setScale(sf::Vector2f(scale, scale));
}

void Sprite::setSpecial(int numFrames, int left, int top, int width, int height) {
	specialNumFrames = numFrames;
	specialLeft = left;
	specialTop = top;
	specialWidth = width;
	specialHeight = height;

	special = true;
}

sf::Image Sprite::getImage() {
	return image;
}