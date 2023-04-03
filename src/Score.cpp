#include <Score.hpp>

Score::Score()
{
   score = 0;

    if (!font.loadFromFile("res/font.ttf"))
    {
        printf("couldn't load");
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
}

void Score::increaseScore()
{
    score++;
    text.setString(std::to_string(score));
}

void Score::render(sf::RenderWindow &window)
{
    window.draw(text);
}