#pragma once
#include <SFML/Graphics.hpp>

// enumeration of parts of the picture
class Animation
{
public:
	Animation(sf::Texture* texture, int imageCount, float switchTime, int width_left, int height);
	~Animation();

	void Update(float deltaTime);

public:
	sf::IntRect uvRect;

private:
	int imageCount;
	int currentImage;

	int left;

	float totalTime;
	float switchTime;
};

