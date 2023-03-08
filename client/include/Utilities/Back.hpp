/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Back
*/

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Background class
 *
 */
class Back {
public:
    /**
     * @brief Construct a new Back object
     *
     */
    Back(const std::string &path);

    /**
     * @brief Destroy the Back object
     *
     */
    ~Back(){};

    /**
     * @brief draw the background
     *
     * @param window
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief move the background
     *
     * @param offset
     */
    void move(float offset);

protected:
private:
    sf::RectangleShape _shape;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Sprite _sprite2;
    sf::Vector2f _size;
    float _speed;
    float _speed2;
};
