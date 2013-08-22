#include "Block.hpp"

Block::Block(int _x, int _y, int _width, int _height)
{
  setPosition(_x, _y);
  
  width = _width;
  height = _height;
}
