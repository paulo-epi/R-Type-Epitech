/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Collision
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        /**
         * @brief Collision component
         */
        class Collision : public IComponent {
            public:
                /**
                 * @brief Construct a new Collision object
                 */
                Collision(int width = 50, int height = 50);
                /**
                 * @brief Destroy the Collision object
                 */
                ~Collision() override = default;
                /**
                 * @brief Get the Component Type object
                 *
                 * @return ComponentType
                 */
                ComponentType getComponentType() const override;
                /**
                 * @brief Get the hitbox size
                 *
                 * @return std::pair<int, int>
                 */
                std::pair<int, int> getHitbox() const;
                /**
                 * @brief Set the hitbox size
                 *
                 * @param hitbox
                 */
                void setHitbox(std::pair<int, int> hitbox);

            protected:
            private:
                int _width;
                int _height;
        };
    }
}
