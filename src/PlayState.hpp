#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include <stdio.h>
#include <sstream>
#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "State.hpp"
#include "Player.hpp"
#include "Tilemap.hpp"

using namespace std;

class PlayState : public State
{
  private:
    Game *game;

    Player *player;
    Tilemap *currentMap;

    sf::Text fps;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundImage;

    int camX;
    int camY;

  public:
    PlayState(Game *_game);

    void setup();
    void update();
    void draw();
};

#endif
