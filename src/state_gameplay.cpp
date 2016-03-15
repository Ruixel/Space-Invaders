#include "state_gameplay.h"
#include <iostream>

state_gameplay::state_gameplay(Game* game)
{
    this->game = game;

    game_view = sf::View(sf::FloatRect(0, 0, 217, 248));

    std::cout << "Hello World" << std::endl;
}

void state_gameplay::draw(const float dt)
{
    game->window.setView(game_view);

    // Layer 1 : Background
    sf::RectangleShape ground(sf::Vector2f(217, 2));
    ground.setPosition(sf::Vector2f(0, 230));
    ground.setFillColor(sf::Color::Green);
    game->window.draw(ground);                          // Green Line

    // Layer 2 : Entities
    obj_player.draw(game); // Player

    // Layer 3 : HUD
    sf::Font chava;
    if (!chava.loadFromFile("assets/Chava-Regular.ttf"))
        std::cout << "FFFFFFFFFFF\n";

    sf::Text space_text;
    space_text.setFont(chava);
    space_text.setString("space text");
    space_text.setColor(sf::Color::White);
    space_text.setCharacterSize(12);
    space_text.setPosition( { 68, 4 } );

    game->window.draw(space_text);
}

void state_gameplay::update(const float dt)
{

}

void state_gameplay::handleInput()
{
    sf::Event event;
    while (this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            game->window.close();
            break;
        }

    }

}
