/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** TextButton
*/

#include "../../include/Utilities/TextButton.hpp"

bool TextButton::isClicked(sf::Vector2f mousePos)
{
    if (getText().getGlobalBounds().contains(mousePos))
    {
        getText().setColor(sf::Color::Red);
        return true;
    }
    getText().setColor(sf::Color::White);
    return false;
}