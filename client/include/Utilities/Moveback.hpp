/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Moveback
*/

#pragma once

#include <list>
#include <memory>
#include "Back.hpp"

/**
 * @brief Moveback class
 *
 */

class Moveback {
public:
    /**
     * @brief Construct a new Moveback object
     *
     */
    Moveback(){};

    /**
     * @brief Destroy the Moveback object
     *
     */
    ~Moveback(){};

    /**
     * @brief Add a Background object
     *
     * @param path
     */
    void addBackground(const std::string &path);

    /**
     * @brief Move the Background
     *
     * @param window
     */
    void moveBack(sf::RenderWindow &window);

protected:
private:
    std::list<std::shared_ptr<Back>> _backgrounds;
};
