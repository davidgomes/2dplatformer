#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Tilemap.hpp"

using namespace std;

class Editor
{
  private:
    sf::RenderWindow window;
    Tilemap *map;

    string title;
    sf::Font arialFont;

    bool windowFocused;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundImage;
    
  public:
    void setup();
    void run();

    void update();
    void draw();
};

#endif
