//
// Created by pat on 6/05/18.
//

#include "TextureManager.hpp"

void TextureManager::loadTexture(const std::string &name, const std::string &filename) {
    /* Load the texture */
    sf::Texture tex;
    tex.loadFromFile(filename);

    /* Add it to the list of textures */
    this->textures[name] = tex;
}

sf::Texture &TextureManager::getRef(const std::string &texture) {
    return this->textures.at(texture);
}
