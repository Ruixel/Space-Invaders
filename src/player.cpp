#include "player.h"

player::player()
{
    pos = sf::Vector2f(100, 208);
    lives = 5;
}

void player::draw(Game* game)
{
    // Draw player spaceship
    sf::Texture spaceship = game->texmgr.getRef("spritesheet");
    sf::Sprite ship;

    ship.setTexture(spaceship);
    ship.setTextureRect(sf::IntRect(0, 0, 14, 8));
    ship.setPosition(pos);

    game->window.draw(ship);

    // Draw Lives
    for (int i = 0; i < lives; i++)
    {
        ship.setPosition(24 + 16*i, 236);
        game->window.draw(ship);
    }
}
