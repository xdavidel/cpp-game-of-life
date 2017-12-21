#include <iostream>
#include "GameOfLife.h"

using std::cout;
using std::endl;

GameOfLife::GameOfLife()
    : m_width(60), m_height(20), m_rounds(40), m_grid(m_width, m_height)
{
}

GameOfLife::GameOfLife(uint width, uint height, uint rounds = 10)
    : m_width(width), m_height(height), m_rounds(rounds), m_grid(m_width, m_height)
{
}

void GameOfLife::Run()
{
    for (uint i = 0; i < m_rounds; i++)
    {
        Grid<uchar> savedState(m_grid);
        for (uint row = 0; row < m_height; row++)
        {
            for (uint col = 0; col < m_width; col++)
            {
                uint neighbors = CountNeighbors(col, row, savedState);
                if (neighbors < 2 || neighbors > 3)
                {
                    m_grid.Get(col, row) = 0;
                }
                else if (neighbors == 3)
                {
                    m_grid.Get(col, row) = 1;
                }
            }
        }

        Print();
    }
}

void GameOfLife::Print()
{
    system("cls");
    const uchar printSymbol = 254;
    const uchar gridSymbol = '#';

    for (uint i = 0; i < m_width + 2; i++)
    {
        cout << gridSymbol;
    }

    cout << '\n';

    for (uint row = 0; row < m_height; row++)
    {
        cout << "#";

        for (uint col = 0; col < m_width; col++)
        {
            if (m_grid.Get(col, row) >= 1)
            {
                cout << printSymbol;
            }
            else
            {
                cout << " ";
            }
        }
        cout << "#\n";
    }

    for (uint i = 0; i < m_width + 2; i++)
    {
        cout << gridSymbol;
    }

    cout << endl;
}

void GameOfLife::RandomPlacing()
{
    for (uint i = 0; i < m_width; i++)
    {
        for (uint j = 0; j < m_height; j++)
        {
            int r = std::rand() % 10;
            if (0 == r)
            {
                m_grid.Get(i, j) = 1;
            }
        }
    }
}

uchar GameOfLife::CountNeighbors(uint x, uint y, Grid<uchar> grid)
{
    uchar sum = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            uint col = (x + i + m_width) % m_width;
            uint row = (y + j + m_height) % m_height;

            sum += m_grid.Get(col, row);
        }
    }

    sum -= m_grid.Get(x, y);
    return sum;
}