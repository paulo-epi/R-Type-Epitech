/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** TextButton
*/

#ifndef TEXTBUTTON_HPP_
#define TEXTBUTTON_HPP_

#include "../../include/Utilities/Text.hpp"

/**
 * @brief TextButton class
 *
 */
class TextButton : public Text {
    public:
        /**
         * @brief Construct a new TextButton object
         *
         * @param string
         * @param posX
         * @param posY
         */
        TextButton(std::string string, float posX, float posY) : Text(string, posX, posY)
        {
        };

        /**
         * @brief Check if the button is clicked
         *
         * @param mousePos
         * @return true
         * @return false
         */
        bool isClicked(sf::Vector2f mousePos);

    protected:
    private:
};

#endif /* !TEXTBUTTON_HPP_ */
