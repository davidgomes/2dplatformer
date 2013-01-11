#include "Game.hpp"

/* Include all states */
#include "TitleState.hpp"
#include "PlayState.hpp"

void Game::setup()
{
  title = "2D Platformer";
  window.create(sf::VideoMode(800, 640, 1), title.c_str(), sf::Style::Titlebar | sf::Style::Close);
  window.setFramerateLimit(60);
  lastTime = 0;
  windowFocused = true;

  /* Load arial font */
  arialFont.loadFromFile("res/arial.ttf");

  currentState = new PlayState(this);
}

void Game::run()
{
  currentState->setup();

  while (window.isOpen()) {
    if (windowFocused) {
      currentState->update();
      currentState->draw();

      float currentTime = deltaClock.restart().asSeconds();
      dt = currentTime - lastTime;
      fps = 1.f / currentTime;
      lastTime = currentTime;
    } else {
      sf::Event event;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::GainedFocus) {
          windowFocused = true;
        }
      }
    }
  }
}

int main(int argc, char *argv[])
{
  Game game;
  game.setup();
  game.run();

  return 0;
}
