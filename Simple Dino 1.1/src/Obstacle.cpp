#include <iostream>
#include "SFML/Graphics.hpp"
#include "Obstacle.h"
#include <chrono>
#include <thread>

namespace obstacles {
	Obstacle::Obstacle(sf::Texture* texture1, int wayLength, float switchTime)
	{
		body.setSize(sf::Vector2f(50.0f, 100.0f));
		body.setPosition(1300.0f, 405.0f);
		body.setTexture(texture1);

		this->switchTime = switchTime;
		this->waylength = wayLength;

		totalTime = 0.0f;
		currentWay = 0;
	}

	Obstacle::~Obstacle() {}

	void Obstacle::Draw(sf::RenderWindow& window)
	{
		window.draw(body);
	}
	void Obstacle::Action(float deltaTime)
	{
		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			totalTime -= switchTime;
			currentWay++;

			if (currentWay > waylength) {
				currentWay = 0;
			}
			body.setPosition(1300.0f - currentWay, 405.0f);
		}
	}
	void Obstacle::Reset()
	{
		totalTime = 0;
		body.setPosition(1300.0f, 405.0f);
	}
}
