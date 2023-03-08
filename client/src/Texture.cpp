/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Texture
*/

#include "Texture.hpp"

sf::Texture &Texture::getTexture(const std::string &_name)
{
    return _textures.at(_name);
}

void Texture::loadTexture(const std::string &_name, const std::string &_path)
{
    sf::Texture texture;
    if (texture.loadFromFile(_path))
        _textures.insert(std::pair<std::string, sf::Texture>(_name, texture));
    else
        std::cout << "Error: Texture not found" << std::endl;
    _textures[_name] = texture;
}
