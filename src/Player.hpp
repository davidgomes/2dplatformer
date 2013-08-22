#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include "Tilemap.hpp"
#include "Entity.hpp"

using namespace std;

class Player : public Entity
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
