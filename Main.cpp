#include <iostream>
#include "GameOfLife.h"

using std::cin;

int main()
{
    GameOfLife game;
    game.RandomPlacing();
    game.Run();

    cin.ignore();
    return 0;
}