#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Game.hpp"

class Entity : public sf::Sprite
{
  private:

  public:
    int width;
    int height;

    bool intersects(Entity *otherEntity);
};

#endif
