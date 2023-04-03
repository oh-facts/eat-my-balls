#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>

class Score
{
private:
    int score;
    sf::Text text;
    sf::Font font;

public:
    Score();
    void increaseScore();
    void render(sf::RenderWindow &);
};

#endif