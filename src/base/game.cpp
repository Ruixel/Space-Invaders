#include <stack>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "base/game_state.hpp"
#include "base/game.hpp"
#include "base/tex_manager.hpp"

void Game::pushState(GameState* state) {
  this->states.push(state);
  return;
}

void Game::popState() {
  delete this->states.top();
  this->states.pop();

  return;
}

void Game::changeState(GameState* state) {
  if (!states.empty())
    popState();

  pushState(state);

  return;
}

GameState* Game::peekState() {
  if (states.empty()) return nullptr;
  return states.top();
}

void Game::gameLoop() {
  sf::Clock clock;
  while (this->window.isOpen()) {
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    if (peekState() == nullptr) continue;

    peekState()->handleInput();
    peekState()->update(dt);
    this->window.clear(sf::Color::Black);
    peekState()->draw(dt);
    this->window.display();
  }
}

void Game::loadTextures() {
  this->texmgr.loadTexture("assets/sprites.png", "spritesheet");

  return;
}

Game::Game() {
  this->loadTextures();

  sf::ContextSettings settings;
  settings.antialiasingLevel = 0;

  this->window.create(sf::VideoMode(434, 496), "Space Invaders", sf::Style::Default, settings);
  this->window.setFramerateLimit(60);
}

Game::~Game() {
  while(!this->states.empty())
    popState();
}
