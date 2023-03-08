/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** IComponent
*/

#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <string>



namespace ecs {
    namespace component {
        /**
         * @brief The type of the component
         *
         */
        enum ComponentType {
            PLAYERCOMPONENT,
            DRAWABLECOMPONENT,
            POSITIONCOMPONENT,
            HEALTHCOMPONENT,
            DAMAGECOMPONENT,
            SPEEDCOMPONENT,
            COLLISIONCOMPONENT,
            NONECOMPONENT
        };
        /**
         * @brief IComponent class
         *
         */
        class IComponent {
            public:
                /**
                 * @brief Destroy the IComponent object
                 *
                 */
                virtual ~IComponent() = default;
                /**
                 * @brief Get the Type object
                 *
                 * @return componentType
                 */
                virtual ComponentType getComponentType() const = 0;

            protected:
            private:
        };
    }
}