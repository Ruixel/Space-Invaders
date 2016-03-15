#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "base/game.hpp"

class player
{
private:
    sf::Vector2f pos;

    int lives;

public:
    player();

    void draw(Game* game);
};

#endif // PLAYER_H
