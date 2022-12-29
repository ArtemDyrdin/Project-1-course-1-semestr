#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"

namespace state_objects {
	// Dino
	class Player
	{
	public:
		Player(sf::Texture* texture, int imageCount, float switchTime, float switchTimeUp, int jump_height, int width_left, int height);
		~Player();

		void Update(float deltaTime);
		void Jump(float deltaTime);
		sf::Vector2f GetPosition();
		void Draw(sf::RenderWindow& window);
		void Reset();

	public:
		sf::RectangleShape body;
		Animation animation;
		bool jump_up = false;
		bool jump_down = false;
		int coeficent = 1;

	private:
		int jump_height;
		int currentHeight;

		float switchTimeUp;
		float totalTime;
	};

	// Ground
	class Ground
	{
	public:
		Ground(sf::Texture* texture, int imageCount, float switchTime, int width_left, int height);
		~Ground();

		void Update(float deltaTime);
		void Reset();
		void Draw(sf::RenderWindow& window);

	public:
		sf::RectangleShape body;
		Animation animation;
	};

	class RestartButton 
	{
	public:
		RestartButton(sf::Texture* texture);
		~RestartButton();
		void Draw(sf::RenderWindow& window);
	public:
		sf::RectangleShape body;
	};
}
