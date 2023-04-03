#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <Input.hpp>


class  Player
{
private:

	sf::RectangleShape m_shape;

public:
    float m_velocity;
    void render(sf::RenderWindow&);
    
    Player();
    sf::RectangleShape getRect();
    void update(sf::Time delta);
     ~ Player();
};




#endif


