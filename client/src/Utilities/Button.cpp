/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Button
*/

#include "../include/Utilities/Button.hpp"

bool Button::isClicked(sf::Vector2f mousePosF)
{
    if (getSprite().getGlobalBounds().contains(mousePosF)) {
        getSprite().setColor(sf::Color::Red);
        return true;
    }
    getSprite().setColor(sf::Color::White);
    return false;
}

bool Button::isHover(sf::Vector2f mousePosF)
{
    if (getSprite().getGlobalBounds().contains(mousePosF)) {
        getSprite().setColor(sf::Color::Blue);
        return true;
    }
    getSprite().setColor(sf::Color::White);
    return false;
}
