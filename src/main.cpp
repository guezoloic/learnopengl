#include <iostream>
#include "game.hpp"

int main()
{
    Game game {"hello world", 800, 600};
    game.run();
    return 0;
}