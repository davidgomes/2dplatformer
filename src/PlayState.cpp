#include "PlayState.hpp"

using namespace std;

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

  currentMap = new Tilemap("res/map1.txt", &(game->window));
  player = new Player(_game, currentMap);
}

void PlayState::setup() { }

void PlayState::update()
{
  sf::Event event;

  while (game->window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      game->window.close();
    } else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        game->window.close();
      }
    } else if (event.type == sf::Event::LostFocus) {
      game->windowFocused = false;
    }
  }

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
