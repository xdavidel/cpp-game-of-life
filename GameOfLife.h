#pragma once
#include "GameOfLife.h"
#include "Grid.h"

using uchar = unsigned char;

class GameOfLife
{
  public:
    GameOfLife();

    GameOfLife(uint width, uint height, uint rounds);

    void Run();
    void Print();
    void RandomPlacing();

  private:
    uint m_width;
    uint m_height;
    uint m_rounds;
    Grid<uchar> m_grid;

    uchar CountNeighbors(uint x, uint y, Grid<uchar> grid);
};