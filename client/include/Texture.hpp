/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Texture
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

class Texture {
public:
    Texture(){};
    sf::Texture &getTexture(const std::string &_name);
    void loadTexture(const std::string &_name, const std::string &_path);

protected:
private:
    std::map<std::string, sf::Texture> _textures;
};
