/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Field
*/

#include "../include/Utilities/Field.hpp"

Field::Field(const std::string path, int x, int y) : _picture(path, x, y)
{
    _text.setPosition(x + 10, y + 35);
    _text.setFillColor(sf::Color::White);
    _text.setCharacterSize(30);
    _text.setOutlineColor(sf::Color::Black);
    _text.setOutlineThickness(1);
    _maxChar = 21;
}

sf::String &Field::getString()
{
    return _string;
}

void Field::setMaxChar(int maxChar)
{
    _maxChar = maxChar;
}

sf::Text &Field::getText()
{
    return _text;
}

void Field::clear()
{
    _string.clear();
}

void Field::setPos(float x, float y)
{
    _text.setPosition(x + 10, y + 35);
    _picture.setPos(x, y);
}

void Field::setFont(sf::Font &font)
{
    _font = font;
    _text.setFont(_font);
}

sf::FloatRect Field::getBounds()
{
    return _picture.getSprite().getGlobalBounds();
}

bool Field::isClicked(sf::Vector2f mousePosF)
{
    if (getBounds().contains(mousePosF)) {
        _picture.toggleBoundingBox(true);
        return true;
    }
    _picture.toggleBoundingBox(false);
    return false;
}

void Field::draw(sf::RenderWindow &window)
{
    window.draw(_picture.getSprite());
    window.draw(_text);
}

void Field::setString(sf::Uint32 character)
{
    if (character == '\b') {
        if (_string.getSize() > 0) {
            _string.erase(_string.getSize() - 1);
            _text.setString(_string);
        }
        return;
    }
    if (_string.getSize() < _maxChar)
        _string += character;
    _text.setString(_string);
}
