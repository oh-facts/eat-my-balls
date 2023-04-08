#include <Square.hpp>
Square::Square(sf::Vector2f pos)
{
  m_velocity = 300.0f;

  m_shape.setSize(sf::Vector2f(20,20));
  m_shape.setFillColor(sf::Color::Red);
  m_shape.setPosition(pos);
}
void Square::update(sf::Time delta)
{
  float velocity = m_velocity * delta.asSeconds();
  m_shape.move(sf::Vector2(0.f, velocity));
}

void Square::render(sf::RenderWindow &window)
{
  window.draw(m_shape);
}

Square::~Square() {}

sf::Vector2f Square::getPos(){return m_shape.getPosition();}
sf::RectangleShape Square::getRectangle(){return m_shape;}