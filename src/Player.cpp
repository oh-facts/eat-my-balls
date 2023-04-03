#include <Player.hpp>
Player::Player()
{
	m_velocity = 300.0f;

  m_shape.setSize(sf::Vector2f(80.f,10.f));
  m_shape.setFillColor(sf::Color::Red);
  m_shape.setPosition(10.f, 500.f);
}
void Player::update(sf::Time delta)
{
	float velocity = m_velocity * delta.asSeconds();
	if (isKeyHeld(sf::Keyboard::A) || isKeyHeld(sf::Keyboard::Left))
	{
		m_shape.move(-velocity, 0);
	}
	if (isKeyHeld(sf::Keyboard::D) || isKeyHeld(sf::Keyboard::Right))
	{
		m_shape.move(velocity, 0);
	}

}

void Player::render(sf::RenderWindow &window)
{
	window.draw(m_shape);
}

sf::RectangleShape Player::getRect(){return m_shape;}

Player::~ Player()
{
}
