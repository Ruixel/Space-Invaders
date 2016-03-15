#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include "base/game.hpp"
#include "base/game_state.hpp"
#include "player.h"

#include <SFML/System.hpp>

class state_gameplay : public GameState
{
private:
    Game* game;
    sf::View game_view;

    player obj_player;

public:
    state_gameplay(Game* game);

    void draw(const float dt);
    void update(const float dt);
    void handleInput();
};

#endif // STATE_GAMEPLAY_H
