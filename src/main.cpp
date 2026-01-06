#include "core/core.hpp"
#include "core/logger.hpp"

int main()
{
  Game game{800, 600, "window"};
  game.run();
  return 0;
}