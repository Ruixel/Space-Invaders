#include <SFML/Graphics.hpp>

#include "tex_manager.hpp"

void TextureManager::loadTexture(const std::string& filename, const std::string& tex_name) {
  sf::Texture tex;
  tex.loadFromFile(filename);

  textures[tex_name] = tex;

  return;
}

sf::Texture& TextureManager::getRef(const std::string& tex_name) {
  return textures.at(tex_name);
}
