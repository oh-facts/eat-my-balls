#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>


class  Ball
{
private:

	sf::CircleShape m_shape;

public:
    float m_velocity;
    
    Ball(sf::Vector2f pos);
    void update(sf::Time delta);
    void render(sf::RenderWindow&);
    sf::Vector2f getPos();
    sf::CircleShape getCircle();
     ~Ball();
};
// Header file code goes here

#endif 