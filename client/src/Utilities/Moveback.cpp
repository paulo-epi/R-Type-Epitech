/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Moveback
*/

#include "../include/Utilities/Moveback.hpp"

void Moveback::addBackground(const std::string &path)
{
    std::shared_ptr<Back> background(new Back(path));
    _backgrounds.push_back(background);
}

void Moveback::moveBack(sf::RenderWindow &window)
{
    int i = 1;
    for (auto &background : _backgrounds) {
        background->move(i);
        background->draw(window);
        i += 1;
    }
}
