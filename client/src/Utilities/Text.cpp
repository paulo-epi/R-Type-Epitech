/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Text
*/

#include "../../include/Utilities/Text.hpp"

Text::Text(std::string string, float posX, float posY, float size)
{
    _string = string;
    _font.loadFromFile("client/assets/arial.ttf");
    _text.setString(_string);
    _text.setFont(_font);
    _text.setCharacterSize(size);
    _text.setPosition(posX, posY);
}

sf::Text &Text::getText()
{
    return _text;
}
