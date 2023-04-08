#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <SFML/Graphics.hpp>
#include <Item.hpp>
#include <vector>
#include <Player.hpp>

template<typename T>

class Spawner
{
private:
    float m_time_passed;
    float m_spawn_time;

    std::vector<T *> m_items;

public:
    Spawner(float spawn_time);

    void update(sf::Time delta);
    bool checkCollision(Player);
    void render(sf::RenderWindow &);
};
// Header file code goes here

template <typename T>
Spawner<T>::Spawner(float spawn_time)
{
    m_spawn_time = spawn_time;
}

template <typename T>
void Spawner<T>::update(sf::Time delta)
{
    m_time_passed += delta.asSeconds();

    if (m_time_passed > m_spawn_time)
    {
        m_time_passed = 0;
        // maxTime = 0 + (rand() % 3);

        T *item = new T(sf::Vector2f(static_cast<float>(rand() % 600), 0.f));
        m_items.push_back(item);
    }

    for (T *item : m_items)
    {
        item->update(delta);
    }
}

template <typename T>
void Spawner<T>::render(sf::RenderWindow &window)
{
    for (typename std::vector<T *>::iterator it = m_items.begin(); it != m_items.end();)
    {
        T *item = *it;
        item->render(window);
        if (item->getPos().y > 600.f)
        {
            it = m_items.erase(it);
            delete item;
        }
        else
        {
            ++it;
        }
    }
}

template <typename T>
bool Spawner<T>::checkCollision(Player py)
{
    for (typename std::vector<T *>::iterator it = m_items.begin(); it != m_items.end();)
    {
        T *item = *it;
        if (item->getShape().getGlobalBounds().intersects(py.getRect().getGlobalBounds()))
        {
            it = m_items.erase(it);
            delete item;
            return true;
        }
        else
        {
            ++it;
        }
    }
    return false;
}
#endif