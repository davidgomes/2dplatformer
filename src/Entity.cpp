#include "Entity.hpp"

bool Entity::intersects(Entity *otherEntity)
{
  int x = getPosition().x;
  int y = getPosition().y;

  sf::Vector2f other = sf::Vector2f(otherEntity->getPosition());

  return (x <= other.x + otherEntity->width &&
          other.x <= x + width &&
          y <= other.y + otherEntity->height &&
          other.y <= y + height);
}
