#include <SFML/Graphics.hpp>
#include <iostream>
#include "StateObjects.h"
#include "Obstacle.h"
#include <chrono>
#include <thread>

using namespace state_objects;
using namespace obstacles;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1300, 600), "Simple Dino");

    // set Dino
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/PlayerSpriteSheet.png");
    Player player(&playerTexture, 2, 0.3f, 0.002f, 210, 90, 95);

    // set Ground
    sf::Texture groundTexture;
    groundTexture.loadFromFile("images/GroundImage.png");
    Ground ground(&groundTexture, 3, 0.3f, 500, 120);

    // set Obstacle
    sf::Texture obstacleTexture1;
    obstacleTexture1.loadFromFile("images/Cactus3.png");
    Obstacle obstacle(&obstacleTexture1, 1300, 0.002f);

    // set Obstacle
    sf::Texture restartButton;
    restartButton.loadFromFile("images/RestartButton.png");

    // saving of time
    float deltaTime = 0.0f;

    sf::Clock clock;

    bool gameOver = false;
    bool newGame = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                // exit
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        if (!gameOver) {
            // time report
            deltaTime = clock.restart().asSeconds();

            // updating Dino and Ground texture
            player.Update(deltaTime);
            ground.Update(deltaTime);

            // checking and realizing of Dino jump
            player.Jump(deltaTime);

            // moving of obstacle
            obstacle.Action(deltaTime);

            // detection of a touch
            if (player.body.getGlobalBounds().left > obstacle.body.getGlobalBounds().left - 55 && \
                player.body.getGlobalBounds().left < obstacle.body.getGlobalBounds().left && \
                player.body.getPosition().y + 130 > obstacle.body.getPosition().y) {
                gameOver = true;
                deltaTime = 0.0f;
            }

            // clean and drawing objects
            window.clear(sf::Color::White);
            ground.Draw(window);
            player.Draw(window);
            obstacle.Draw(window);
            window.display();
        }

        if (gameOver) {
            RestartButton restart(&restartButton);
            restart.Draw(window);
            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                player.Reset();
                ground.Reset();
                obstacle.Reset();
                gameOver = false;
            }
        }
    }
    return 0;
}