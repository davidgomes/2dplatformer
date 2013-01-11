#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include <stdio.h>

#include "Game.hpp"
#include "Tilemap.hpp"

using namespace std;

class Player : public sf::Sprite
{
  private:
    sf::Texture imageRight;
    sf::Texture imageLeft;

    Game *game;
    Tilemap *map;

    sf::Text debugText;

    bool canJump;

    bool collidingRight();
    bool collidingLeft();
    bool collidingAbove();
    bool collidingBelow();
    
  public:
    Player(Game *_game, Tilemap *_map);

    void update();
    void draw();
    
    float x;
    float y;

    float vx;
    float vy;

    float width;
    float height;
};

#endif
