#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Input.hpp>
#include <BallSpawner.hpp>
#include <Player.hpp>
#include <cmath>
#include <Score.hpp>

class App
{
private:
    /* data */
public:
    App(/* args */);
    void run();

    ~App();
};
#endif