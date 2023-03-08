/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Picture
*/

#include "../include/Utilities/Picture.hpp"

Picture::Picture(std::string path, float x, float y, float scale) : _path(path)
{
    if (!_texture.loadFromFile(path)) {
        throw std::runtime_error("Error: Picture not found");
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
    _sprite.setScale(scale, scale);
}

sf::Sprite &Picture::getSprite()
{
    return _sprite;
}

std::string Picture::getPath()
{
    return _path;
}

void Picture::setPath(std::string path)
{
    _path = path;
}

void Picture::setPos(float x, float y)
{
    _sprite.setPosition(x, y);
}

void Picture::toggleBoundingBox(bool toggle)
{
    if (toggle)
        _sprite.setColor(sf::Color::Red);
    else
        _sprite.setColor(sf::Color::White);
}

float Picture::getPosX()
{
    return _sprite.getPosition().x;
}

float Picture::getPosY()
{
    return _sprite.getPosition().y;
}
