#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "tex_manager.hpp"
#include "state_stack.h"

class GameState;

class Game
{
    private:
        void loadTextures();

    public:
        State_Stack states;

        sf::RenderWindow window;
        TextureManager texmgr;

        void gameLoop();

        Game();

};

#endif
