/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Field
*/

#pragma once

#include <iostream>
#include <string>
#include "Picture.hpp"

/**
 * @brief Field class
 *
 */
class Field {
public:
    /**
     * @brief Construct a new Field object
     *
     * @param posX
     * @param posY
     * @param name
     */
    Field(const std::string path, int posX = 0, int posY = 0);

    /**
     * @brief Destroy the Field object
     *
     */
    ~Field(){};

    /**
     * @brief Get the String object
     *
     * @return sf::String&
     */
    sf::String &getString();

    /**
     * @brief Get the Text object
     *
     * @return sf::Text&
     */
    void setMaxChar(int maxChar);

    /**
     * @brief Get the Text object
     *
     * @return sf::Text&
     */
    sf::Text &getText();

    /**
     * @brief clear the field
     *
     */
    void clear();

    /**
     * @brief Set the Pos object
     *
     * @param x
     * @param y
     */
    void setPos(float x, float y);

    /**
     * @brief Set the Font object
     *
     * @param font
     */
    void setFont(sf::Font &font);

    /**
     * @brief Get the Bounds object
     *
     * @return sf::FloatRect
     */
    sf::FloatRect getBounds();

    /**
     * @brief draw the field
     *
     * @param window
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Set the String object
     *
     * @param character
     */
    void setString(sf::Uint32 character);

    /**
     * @brief is the field clicked
     *
     * @param mousePosF
     * @return true
     * @return false
     */
    bool isClicked(sf::Vector2f mousePosF);

protected:
private:
    Picture _picture;

    int _maxChar;

    sf::String _string;
    sf::Text _text;
    sf::Font _font;
    std::string _name;
};
