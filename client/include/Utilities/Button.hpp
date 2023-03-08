/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Button
*/

#pragma once

#include "Picture.hpp"

/**
 * @brief Button class
 *
 */
class Button : public Picture {
public:
    /**
     * @brief Construct a new Button object
     *
     * @param path
     * @param x
     * @param y
     */
    Button(std::string path, int x = 0, int y = 0, float scale = 1) : Picture(path, x, y, scale) {};

    /**
     * @brief is the button clicked
     *
     * @param mousePosF
     * @return true
     * @return false
     */
    bool isClicked(sf::Vector2f mousePosF);

    /**
     * @brief is the button hovered
     *
     * @param mousePosF
     * @return true
     * @return false
     */
    bool isHover(sf::Vector2f mousePosF);
protected:
private:
};

