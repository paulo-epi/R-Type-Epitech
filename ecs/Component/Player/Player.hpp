/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Player
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        class Player : public IComponent {
            public:
                /**
                 * @brief Construct a new Player object
                 *
                 * @param Player The Player of the entity
                 */
                Player();
                /**
                 * @brief Destroy the Player object
                 *
                 */
                ~Player() override = default;
                /**
                 * @brief Get the Type of an object
                 *
                 * @return ComponentType
                 */
                ComponentType getComponentType() const override;
                /**
                 * @brief Get the Player of an object
                 *
                 * @return string
                 */
                std::string getCommand();
                /**
                 * @brief Set the Player to an object
                 *
                 * @param Player
                 */
                void addCommand(std::string command);

            protected:
            private:
                std::vector<std::string> _commands;
        };
    }
}