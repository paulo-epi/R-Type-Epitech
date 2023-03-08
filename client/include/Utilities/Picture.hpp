/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Picture
*/

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Picture class
 *
 */
class Picture {
public:
    /**
     * @brief Construct a new Picture object
     *
     */
    Picture(std::string path, float posX = 0, float posY = 0, float scale = 1);

    /**
     * @brief Get the Sprite object
     *
     * @return sf::Sprite&
     */
    sf::Sprite &getSprite();

    /**
     * @brief Get the Path object
     *
     * @return std::string
     */
    std::string getPath();

    /**
     * @brief Set the Path object
     *
     * @param path
     */
    void setPath(std::string path);

    /**
     * @brief Set the Pos object
     *
     * @param posX
     * @param posY
     */
    void setPos(float posX = 0, float posY = 0);

    /**
     * @brief Get the Pos X object
     *
     * @return float
     */
    float getPosX();

    /**
     * @brief Get the Pos Y object
     *
     * @return float
     */
    float getPosY();


    /**
     * @brief bound the picture
     *
     * @param toggle
     */
    void toggleBoundingBox(bool toggle);

protected:
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    std::string _path;
};
