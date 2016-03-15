#include "base/game.hpp"
#include "base/game_state.hpp"
#include "state_gameplay.h"

int main(int argc, char const *argv[])
{
    Game game;

    game.pushState(new state_gameplay(&game));
    game.gameLoop();

    return 0;
}
