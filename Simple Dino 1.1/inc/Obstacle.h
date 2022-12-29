#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

namespace obstacles {
	class Obstacle
	{
	public:
		Obstacle(sf::Texture* texture1, int wayLength, float switchTime);
		~Obstacle();

		void Draw(sf::RenderWindow& window);

		// moving of Obstacle
		void Action(float deltaTime);

		void Reset();

	public:
		sf::RectangleShape body;
	private:

		int waylength;
		int currentWay;

		float switchTime;
		float totalTime;
	};
}
