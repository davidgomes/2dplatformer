#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Game.hpp"
#include "Entity.hpp"

class Block : public Entity
{
  private:

  public:
    Block(int _x, int _y, int _width, int _height);
};

#endif
