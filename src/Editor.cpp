#include "Editor.hpp"

void Editor::setup()
{
  title = "Map Editor";
  window.create(sf::VideoMode(800, 640, 1), title.c_str(), sf::Style::Titlebar | sf::Style::Close);
  window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - 400,
                                  sf::VideoMode::getDesktopMode().height / 2 - 320));
  window.setFramerateLimit(60);
  windowFocused = true;

  backgroundTexture.loadFromFile("res/background.png");
  backgroundImage.setTexture(backgroundTexture);
  
  arialFont.loadFromFile("res/arial.ttf");

  map = new Tilemap("res/map1.txt", &window);
}

void Editor::run()
{
  while (window.isOpen()) {
    update();
    draw();
  }
}

void Editor::update()
{
  sf::Event event;

  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    } else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        window.close();
      } else if (event.key.code == sf::Keyboard::S) {
        map->writeToFile();
      }
    } else if (event.type == sf::Event::GainedFocus) {
      windowFocused = true;
    } else if (event.type == sf::Event::LostFocus) {
      windowFocused = false;
    }
  }

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && windowFocused && sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 640 && sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 800) {
    map->raw[sf::Mouse::getPosition(window).y / 8][sf::Mouse::getPosition(window).x / 8] = 1;
  }

  if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && windowFocused && sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 640 && sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 800) {
    map->raw[sf::Mouse::getPosition(window).y / 8][sf::Mouse::getPosition(window).x / 8] = 0;
  }
}

void Editor::draw()
{
  window.clear();

  window.draw(backgroundImage);
  
  map->draw(400, 320);

  window.display();
}

int main(int argc, char *argv[])
{
  Editor editor;
  editor.setup();
  editor.run();

  return 0;
}
