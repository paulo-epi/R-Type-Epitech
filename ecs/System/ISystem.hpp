/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** ISystem
*/

#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "../Entity/Entity.hpp"

namespace ecs {
    namespace system {
        /**
         * @brief Enum of the system type
         *
         */
        enum SystemType {
            MOVEMENTSYSTEM,
            DEATHSYSTEM,
            COLLISIONSYSTEM,
            PLAYERSYSTEM,
            ENEMYSYSTEM,
            LASERSYSTEM,
            NONESYSTEM
        };

        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        /**
         * @brief ISystem class
         *
         */
        class ISystem {
            public:
                /**
                 * @brief Destroy the ISystem object
                 *
                 */
                virtual ~ISystem() = default;
                /**
                 * @brief Update the entities with the system properties.
                 *
                 * @param entities The entities to update
                 */
                virtual void update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities) = 0;
                /**
                 * @brief Get the Type object
                 *
                 * @return SystemType
                 */
                virtual SystemType getSystemType() const = 0;

            protected:
            private:
        };
    }
}
