#ifndef TITLE_STATE_HPP
#define TITLE_STATE_HPP

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "State.hpp"
#include "Game.hpp"

using namespace std;

class TitleState : public State {
  private:
    sf::Text title;
    Game *game;

  public:
    TitleState(Game *_game);

    void setup();
    void update();
    void draw();
};

#endif
