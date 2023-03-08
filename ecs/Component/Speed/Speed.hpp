/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Speed
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        /**
         * @brief Speed component
         *
         */
        class Speed : public IComponent {
            public:
                /**
                 * @brief Construct a new Speed object
                 *
                 */
                Speed(float speed = 1);
                /**
                 * @brief Destroy the Speed object
                 *
                 */
                ~Speed() override = default;
                /**
                 * @brief Get the Component Type object
                 *
                 * @return ComponentType
                 */
                ComponentType getComponentType() const override;
                /**
                 * @brief Get the Speed object
                 *
                 * @return float
                 */
                float getSpeed() const;
                /**
                 * @brief Set the Speed object
                 *
                 * @param speed
                 */
                void setSpeed(float speed);

            protected:
            private:
                float _speed;
        };
    }
}
