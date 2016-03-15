#ifndef TEX_MANAGER_HPP
#define TEX_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
private:
  std::map<std::string, sf::Texture> textures;
public:
  void loadTexture(const std::string& filename, const std::string& tex_name);
  sf::Texture& getRef(const std::string& tex_name);

};

#endif
