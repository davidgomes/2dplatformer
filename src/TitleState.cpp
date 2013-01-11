#include "TitleState.hpp"

using namespace std;

TitleState::TitleState(Game *_game)
{
  game = _game;

  sf::Font titleFont;
  if (!titleFont.loadFromFile("res/arial.ttf")) {
    printf("Error loading font.\n");
  }

  title.setString("2D Platformer");
  title.setPosition(20, 20);
}

void TitleState::setup()
{

}

void TitleState::update()
{
  sf::Event event;

  while (game->window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      game->window.close();
    } else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        game->window.close();
      }
    }
  }
}

void TitleState::draw()
{
  game->window.clear();

  game->window.draw(title);
  
  game->window.display();
}
