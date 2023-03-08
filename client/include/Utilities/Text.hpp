/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Graphics.hpp>

/**
 * @brief Text class
 *
 */
class Text {
    public:
        /**
         * @brief Construct a new Text object
         *
         * @param string
         * @param posX
         * @param posY
         * @param size
         */
        Text(std::string string, float posX = 0, float posY = 0, float size = 30);

        /**
         * @brief Destroy the Text object
         *
         */
        ~Text(){};

        /**
         * @brief Get the Text object
         *
         * @return sf::Text&
         */
        sf::Text &getText();

    private:
        sf::String _string;
        sf::Text _text;
        sf::Font _font;
};

#endif /* !TEXT_HPP_ */
