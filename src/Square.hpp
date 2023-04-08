#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>


class  Square
{
private:

	sf::RectangleShape m_shape;

public:
    float m_velocity;
    
    Square(sf::Vector2f pos);
    void update(sf::Time delta);
    void render(sf::RenderWindow&);
    sf::Vector2f getPos();
    sf::RectangleShape getRectangle();
     ~Square();
};
// Header file code goes here

#endif 