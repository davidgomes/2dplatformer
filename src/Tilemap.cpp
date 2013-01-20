#include "Tilemap.hpp"

using namespace std;

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

void Tilemap::readFromFile()
{
  FILE *file = fopen(filename.c_str(), "r");
  fscanf(file, "%d", &width);
  fscanf(file, "\n");
  fscanf(file, "%d", &height);
  fscanf(file, "\n");

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

  fprintf(file, "%d\n%d\n", width, height);
  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      fprintf(file, "%2d", raw[y][x]);
    }

    fprintf(file, "\n");
  }

  fclose(file);
}

void Tilemap::draw(int camX, int camY)
{
  for (int y = 0; y < height; y++) {
    for (int x = (int) 0; x < width; x++) {
      if (raw[y][x] == 1) {
        sf::Sprite block(GRAY_BLOCK);

        block.setPosition(x * tileSize, y * tileSize);
        window->draw(block);
      }
    }
  }
}
