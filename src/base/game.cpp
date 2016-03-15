#include <stack>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "base/game_state.hpp"
#include "base/game.hpp"
#include "base/tex_manager.hpp"

void Game::gameLoop()
{
    sf::Clock clock;
    while (this->window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        window.clear(sf::Color::Black);

        if ( !states.peekState() ) continue;

        states.peekState()->handleInput();
        states.peekState()->update(dt);
        states.peekState()->draw(dt);

        this->window.display();
    }
}

void Game::loadTextures()
{
    this->texmgr.loadTexture("assets/sprites.png", "spritesheet");

    return;
}

Game::Game()
{
    this->loadTextures();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;

    this->window.create(sf::VideoMode(434, 496), "Space Invaders", sf::Style::Default, settings);
    this->window.setFramerateLimit(60);
}
