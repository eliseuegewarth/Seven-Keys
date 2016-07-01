/**
 * map.hpp
 * Main function where SevenKeys game class are instantiated. Here game also run.
 * Licença: LGPL. Sem copyright.
 */

#include "7keys.hpp"

#include <iostream>

using namespace std;

int main(int, char *[])
{
    try
    {
        srand(time(NULL));
        SevenKeys game;
        game.init("7 Keys", 1280, 720, 1, true);
        game.run();
    } catch (Exception ex)
    {
        cerr << ex.message() << endl;
        return -1;
    }

    return 0;
}
