/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Position
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        /**
         * @brief Position component
         *
         */
        class Position : public IComponent {
            public:
                /**
                 * @brief Construct a new Position object
                 *
                 */
                Position(float x = 0, float y = 0);
                /**
                 * @brief Destroy the Position object
                 *
                 */
                ~Position() override = default;
                /**
                 * @brief Get the Component Type object
                 *
                 * @return ComponentType
                 */
                ComponentType getComponentType() const override;
                /**
                 * @brief Get the position of the object
                 *
                 * @return std::pair<float, float>
                 */
                std::pair<float, float> getPosition() const;
                /**
                 * @brief Set the X object
                 *
                 * @param x
                 */
                void setX(float x);
                /**
                 * @brief Set the Y object
                 *
                 * @param y
                 */
                void setY(float y);
                /**
                 * @brief Get the X object
                 *
                 */
                float getX();
                /**
                 * @brief Get the Y object
                 *
                 */
                float getY();

            protected:
            private:
                float _x;
                float _y;
        };
    }
}
