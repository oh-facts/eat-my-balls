#include <Ball.hpp>
Ball::Ball(sf::Vector2f pos)
{
  m_velocity = 300.0f;

  m_shape.setRadius(10.f);
  m_shape.setFillColor(sf::Color::Red);
  m_shape.setPosition(pos);
}
void Ball::update(sf::Time delta)
{
  float velocity = m_velocity * delta.asSeconds();
  m_shape.move(sf::Vector2(0.f, velocity));
}

void Ball::render(sf::RenderWindow &window)
{
  window.draw(m_shape);
}

Ball::~Ball() {}

sf::Vector2f Ball::getPos(){return m_shape.getPosition();}
sf::CircleShape Ball::getCircle(){return m_shape;}