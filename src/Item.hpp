#ifndef Item_HPP
#define Item_HPP

#include <SFML/Graphics.hpp>

template <typename T>
class Item
{
};

template <>
class Item<sf::CircleShape>
{
private:
  sf::CircleShape m_shape;

public:
  float m_velocity;

  Item(sf::Vector2f pos)
  {
    m_velocity = 300.0f;

    m_shape.setRadius(10.f);
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(pos);
  }
  void update(sf::Time delta)
  {
    float velocity = m_velocity * delta.asSeconds();
    m_shape.move(sf::Vector2(0.f, velocity));
  }
  void render(sf::RenderWindow &window)
  {
    window.draw(m_shape);
  }
  sf::Vector2f getPos() { return m_shape.getPosition(); }
  sf::CircleShape getShape(){return m_shape;}
  ~Item(){};
};

template <>
class Item<sf::RectangleShape>
{
private:
  sf::RectangleShape m_shape;

public:
  float m_velocity;

  Item(sf::Vector2f pos)
  {
    m_velocity = 300.0f;

    m_shape.setSize(sf::Vector2f(20, 20));
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(pos);
  }
  void update(sf::Time delta)
  {
    float velocity = m_velocity * delta.asSeconds();
    m_shape.move(sf::Vector2(0.f, velocity));
  }
  void render(sf::RenderWindow &window)
  {
    window.draw(m_shape);
  }
  sf::Vector2f getPos() { return m_shape.getPosition(); }
  sf::RectangleShape getShape(){return m_shape;}
  ~Item(){};
};

#endif