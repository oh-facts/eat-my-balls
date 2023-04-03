#ifndef BALLSPAWNER_HPP
#define BALLSPAWNER_HPP

#include <SFML/Graphics.hpp>
#include <Ball.hpp>
#include <vector>
#include <Player.hpp>

class BallSpawner
{
private:
    float time_passed;
    float maxTime;
    std::vector<Ball *> balls;

public:
    BallSpawner();
    bool checkCollision(Player);
    void update(sf::Time delta);
    void render(sf::RenderWindow &);
};
// Header file code goes here

#endif