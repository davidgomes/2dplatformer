#ifndef TILE_TYPE_HPP
#define TILE_TYPE_HPP

#include <stdio.h>
#include <string>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game.hpp"

using namespace std;

class Tilemap
{
  private:
    Game *game;
    string filename;
    void readFromFile();
    sf::Texture GRAY_BLOCK;

    sf::View view;
    
  public:
    Tilemap(Game *_game, string _filename);

    void draw(int playerX, int playerY);
    void writeToFile();

    int tileSize;
    int width;
    int height;
    int raw[80][100];
};

#endif
