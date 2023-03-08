/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Back
*/

#include "../include/Utilities/Back.hpp"

Back::Back(const std::string &path)
{
    if (!_texture.loadFromFile(path)) {
        throw std::runtime_error("Error: Picture not found");
    }
    _size = (sf::Vector2f)_texture.getSize();
    _shape.setTexture(&_texture);
    _shape.setSize(_size);
    _sprite.setTexture(_texture);
    _sprite2.setTexture(_texture);
    _speed = 0;
    _speed2 = _size.x;
}

void Back::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
    window.draw(_sprite2);
}

void Back::move(float offset)
{
    float x = (_size.x * - 1);
    float res = (_speed > x) ? _speed - offset : _size.x;
    float res2 = (_speed2 > x) ? _speed2 - offset : _size.x;
    _speed = res;
    _speed2 = res2;
    _sprite.setScale(1, 1);
    _sprite2.setScale(1, 1);
    _sprite.setPosition(_speed, 0);
    _sprite2.setPosition(_speed2, 0);
}
