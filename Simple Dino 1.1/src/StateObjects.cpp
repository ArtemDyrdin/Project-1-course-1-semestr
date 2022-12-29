#include <iostream>
#include "StateObjects.h"

namespace state_objects {

    Player::Player(sf::Texture* texture, int imageCount, float switchTime, float switchTimeUp, int jump_height, int width_left, int heigth) :
        animation(texture, imageCount, switchTime, width_left, heigth)
    {
        body.setSize(sf::Vector2f(100.0f, 150.0f));
        body.setPosition(150.0f, 360.0f);
        body.setTexture(texture);

        this->switchTimeUp = switchTimeUp;
        this->jump_height = jump_height;

        totalTime = 0.0f;
        currentHeight = 0;
    }

    Player::~Player() {}

    void Player::Update(float deltaTime)
    {
        animation.Update(deltaTime);
        body.setTextureRect(animation.uvRect);
    }

    void Player::Jump(float deltaTime)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            if (currentHeight == 0) {
                jump_up = true;
            }
        }

        // jumping up
        if (jump_up) {
            totalTime += deltaTime;
            if (totalTime >= switchTimeUp) {
                totalTime -= switchTimeUp;
                currentHeight++;

                if (currentHeight > jump_height) {
                    jump_up = false;
                    jump_down = true;
                }
                body.setPosition(150.0f, 360.0f - currentHeight);
            }
        }

        // jumping down
        if (jump_down) {
            totalTime += deltaTime;
            if (totalTime >= switchTimeUp) {
                totalTime -= switchTimeUp;
                currentHeight--;

                if (currentHeight == 0) {
                    jump_down = false;
                }
                body.setPosition(150.0f, 360.0f - currentHeight);
            }
        }
    }

    sf::Vector2f Player::GetPosition()
    {
        return body.getPosition();
    }

    void Player::Draw(sf::RenderWindow& window)
    {
        window.draw(body);
    }

    void Player::Reset()
    {
        totalTime = 0;
        body.setPosition(150.0f, 360.0f);
    }


    //Ground

    Ground::Ground(sf::Texture* texture, int imageCount, float switchTime, int width_left, int height) :
        animation(texture, imageCount, switchTime, width_left, height)
    {
        body.setSize(sf::Vector2f(1300.0f, 70.0f));
        body.setPosition(0.0f, 500.0f);
        body.setTexture(texture);
    }

    Ground::~Ground() {}

    void Ground::Update(float deltaTime)
    {
        animation.Update(deltaTime);
        body.setTextureRect(animation.uvRect);
    }

    void Ground::Reset()
    {
        body.setTextureRect(sf::IntRect(500, 0, 500, 120));
    }

    void Ground::Draw(sf::RenderWindow& window)
    {
        window.draw(body);
    }

    // RestartButton

    RestartButton::RestartButton(sf::Texture* texture)
    {
        body.setSize(sf::Vector2f(300.0f, 300.0f));
        body.setPosition(500.0f, 200.0f);
        body.setTexture(texture);
    }

    RestartButton::~RestartButton() {}

    void RestartButton::Draw(sf::RenderWindow& window)
    {
        window.draw(body);
    }

}