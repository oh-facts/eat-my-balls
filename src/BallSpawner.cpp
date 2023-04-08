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

        Square *square = new Square(sf::Vector2f((rand() % 600), 0.f));
        squares.push_back(square);

    }

    for (Ball *ball : balls)
    {
        ball->update(delta);
    }
    for (Square *square : squares)
    {
        square->update(delta);
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

    for (std::vector<Square *>::iterator it = squares.begin(); it != squares.end();)
    {
        Square *square = *it;
        square->render(window);
        if (square->getPos().y > 600.f)
        {
            it = squares.erase(it);
            delete square;
        }
        else
        {
            ++it;
        }
    }
}


bool BallSpawner::checkBallCollision(Player py)
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


bool BallSpawner::checkSquareCollision(Player py)
{
    for (std::vector<Square *>::iterator it = squares.begin(); it != squares.end();)
    {
        Square *square = *it;

        if (square->getRectangle().getGlobalBounds().intersects(py.getRect().getGlobalBounds()))
        {
            it = squares.erase(it);
            delete square;
            return true;
        }
        else
        {
            ++it;
        }
    }
    return false;
}