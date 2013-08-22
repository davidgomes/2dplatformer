#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <stdio.h>

#include "State.hpp"

using namespace std;

class Game
{
  private:
    string title;

  public:
    sf::RenderWindow window;
    State *currentState;
    bool windowFocused;

    sf::Clock deltaClock;
    float lastTime;
    float dt;
    float fps;

    sf::Font arialFont;

    Game();
    void run();
};

#endif
