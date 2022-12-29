#include "Animation.h"

Animation::Animation(sf::Texture* texture, int imageCount, float switchTime, int width_left, int height) {
	this->switchTime = switchTime;
	this->imageCount = imageCount;

	totalTime = 0.0f;
	currentImage = 0;

	uvRect.top = 0;
	uvRect.width = width_left;
	uvRect.height = height;
	left = width_left;
}

Animation::~Animation() {}

void Animation::Update(float deltaTime) {
	// updating of texture
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage++;

		if (currentImage > imageCount) {
			currentImage = 1;
		}
	}

	uvRect.left = left * currentImage;
}