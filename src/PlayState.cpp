#include "PlayState.hpp"

PlayState::PlayState(Game *_game)
{
  game = _game;

  /* Set up FPS string */
  fps.setFont(game->arialFont);
  fps.setCharacterSize(12);
  fps.setPosition(2, 2);
  fps.setColor(sf::Color::Black);

  backgroundTexture.loadFromFile("res/background.png");
  backgroundImage.setTexture(backgroundTexture);

  currentMap = new Tilemap(game, "res/map1.txt");
  player = new Player(_game, currentMap);

  /* Populate collidables */
  vector<Entity*> mapCollidables = currentMap->collidableBlocks;
  collidables.insert(collidables.end(),
                     mapCollidables.begin(), mapCollidables.end());
}

void PlayState::setup()
{

}

void PlayState::update()
{
  player->update();
}

void PlayState::draw()
{
  /* Clear the screen */
  game->window.clear();

  /* Draw the background */
  game->window.draw(backgroundImage);

  /* Draw the map */
  currentMap->draw(player->x, player->y);

  /* Draw the player */
  player->draw();

  /* Draw FPS */
  stringstream fpsStream;
  fpsStream << ceil(game->fps);
  fps.setString(fpsStream.str());
  game->window.draw(fps);

  /* Display */
  game->window.display();
}
