//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_TEXTUREMANAGER_H
#define BUBBLETROUBLE_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
private:
    /* Array of textures used */
    std::map<std::string, sf::Texture> textures;

public:
    /* Add a texture from a file */
    void loadTexture(const std::string& name, const std::string &filename);

    /* Translate an id into a reference */
    sf::Texture& getRef(const std::string& texture);

    /* Constructor */
    TextureManager() {}
};


#endif //BUBBLETROUBLE_TEXTUREMANAGER_H
