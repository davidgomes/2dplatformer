#include "Player.hpp"

Player::Player(Game *_game, Tilemap *_map)
{
  game = _game;
  map = _map;

  /* Prepare debug label */
  debugText.setFont(game->arialFont);
  debugText.setCharacterSize(12);
  debugText.setPosition(2, 14);
  debugText.setColor(sf::Color::Red);

  /* Load images */
  imageRight.loadFromFile("res/playerRight.png");
  imageLeft.loadFromFile("res/playerLeft.png");
  setTexture(imageRight);
  
  width = imageRight.getSize().x;
  height = imageRight.getSize().y;

  x = 20;
  y = 20;

  vx = 0.f;
  vy = 0.f;

  canJump = true;
}

void Player::update()
{
  debugText.setString("");

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && vx < 3.5) {
    vx += 0.5;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && vx > -3.5) {
    vx -= 0.5;
  }

  /* Jumpity jumpy jump */
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    if (collidingBelow() && canJump) {
      vy = -6;
      canJump = false;
    }
  } else {
    canJump = true;
  }

  if (!collidingBelow()) {
    vy += 0.2;
  }

  if (vx > 0) {
    setTexture(imageRight);
    
    for (int i = 0; i < floor(vx); i++) {
      if (!collidingRight())
        x++;
      else
        break;
    }
  } else if (vx < 0) {
    setTexture(imageLeft);
    
    for (int i = 0; i < floor(-vx); i++) {
      if (!collidingLeft())
        x--;
      else
        break;
    }
  }

  if (vy > 0) {
    for (int i = 0; i < floor(vy); i++) {
      if (y + height - floor(y + height) == 0.5) {
        FILE *debugFile = fopen("the_odd_bug.txt", "w");
        fprintf(debugFile, "Bug\n.");
        fclose(debugFile);

        y += 0.001;
      }

      if (!collidingBelow())
        y++;
      else
        break;
    }
  } else if (vy < 0) {
    for (int i = 0; i < floor(-vy); i++) {
      if (!collidingAbove()) {
        y--;
      } else {
        vy = 0.3;
        break;
      }
    }
  }

  /* Apply friction */
  if (vx > 0) vx -= 0.1;
  if (vx < 0) vx += 0.1;
  if (abs(vx) < 0.15) vx = 0;

  setPosition(x, y);
}

bool Player::collidingRight()
{
  for (int i = 0; i < height; i++) {
    if (map->raw[(int) floor((y + i) / 8)][(int) floor((x + width) / 8)]) {
      return true;
    }
  }

  return false;
}

bool Player::collidingLeft()
{
  for (int i = 0; i < height; i++) {
    if (map->raw[(int) floor((y + i) / 8)][(int) floor((x - 1) / 8)]) {
      return true;
    }
  }

  return false;
}

bool Player::collidingAbove()
{
  for (int i = 0; i < width; i++) {
    if (map->raw[(int) floor(floor(y - 1) / 8)][(int) floor((x + i) / 8)]) {
      return true;
    }
  }

  return false;
}

bool Player::collidingBelow()
{
  for (int i = 0; i < width; i++) {
    if (map->raw[(int) floor(floor(y + height + 0.5) / 8)][(int) floor((x + i) / 8)]) {
      return true;
    }
  }

  return false;
}

void Player::draw()
{
  game->window.draw(*this);
  game->window.draw(debugText);
}
