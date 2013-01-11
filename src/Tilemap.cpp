#include "Tilemap.hpp"

using namespace std;

void Tilemap::readFromFile()
{
  FILE *file = fopen(filename.c_str(), "r");

  int tempTile;
  for (int y = 0; y < 80; y++) {
    for (int x = 0; x < 100; x++) {
      fscanf(file, "%2d", &tempTile);
      raw[y][x] = tempTile;
    }

    fscanf(file, "\n");
  }

  fclose(file);
}

void Tilemap::writeToFile()
{
  FILE *file = fopen(filename.c_str(), "w");

  for (int y = 0; y < 80; y++) {
    for (int x = 0; x < 100; x++) {
      fprintf(file, "%2d", raw[y][x]);
    }

    fprintf(file, "\n");
  }

  fclose(file);
}

void Tilemap::draw(int playerX, int playerY)
{
  playerX = 400;
  playerY = 320;
  
  for (int y = 0; y < 80; y++) {
    for (int x = 0; x < 100; x++) {
      if (raw[y][x] == 1) {
        sf::Sprite block(GRAY_BLOCK);
        block.setPosition(x * tileSize, y * tileSize);
        window->draw(block);
      }
    }
  }
}

Tilemap::Tilemap(string _filename, sf::RenderWindow *_window)
{
  filename = _filename;
  window = _window;
  readFromFile();

  tileSize = 8;
  width = 100;
  height = 80;

  GRAY_BLOCK.loadFromFile("res/GRAY_BLOCK.png");
}
