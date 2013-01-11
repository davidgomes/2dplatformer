#ifndef TILE_TYPE_HPP
#define TILE_TYPE_HPP

#include <stdio.h>
#include <string>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Tilemap
{
  private:
    string filename;
    void readFromFile();
    sf::RenderWindow *window;
    sf::Texture GRAY_BLOCK;

  public:
    Tilemap(string _filename, sf::RenderWindow *_window);

    void draw(int playerX, int playerY);
    void writeToFile();

    int tileSize;
    int width;
    int height;
    int raw[80][100];
};

#endif
