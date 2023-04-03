#include <BallSpawner.hpp>

BallSpawner::BallSpawner()
{
    maxTime = 1.f;
}

void BallSpawner::update(sf::Time delta)
{

    time_passed += delta.asSeconds();

    if (time_passed > maxTime)
    {
        time_passed = 0;
        // maxTime = 0 + (rand() % 3);

        Ball *ball = new Ball(sf::Vector2f((rand() % 600), 0.f));
        balls.push_back(ball);
    }

    for (Ball *ball : balls)
    {
        ball->update(delta);
    }
}

void BallSpawner::render(sf::RenderWindow &window)
{
    for (std::vector<Ball *>::iterator it = balls.begin(); it != balls.end();)
    {
        Ball *ball = *it;
        ball->render(window);
        if (ball->getPos().y > 600.f)
        {
            it = balls.erase(it);
            delete ball;
        }
        else
        {
            ++it;
        }
    }
}
bool BallSpawner::checkCollision(Player py)
{
    for (std::vector<Ball *>::iterator it = balls.begin(); it != balls.end();)
    {
        Ball *ball = *it;

        if (ball->getCircle().getGlobalBounds().intersects(py.getRect().getGlobalBounds()))
        {
            it = balls.erase(it);
            delete ball;
            return true;
        }
        else
        {
            ++it;
        }
    }
    return false;
}