/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Collision
*/

#pragma once

#include "../ISystem.hpp"

typedef struct rect {
    float x, y;
    int width, height;
} rect_t;


namespace ecs {
    namespace system {
        /**
         * @brief Collision class
         *
         */
        class CollisionSystem : public ISystem {
            public:
                /**
                 * @brief Construct a new Collision object
                 *
                 */
                CollisionSystem(){};
                /**
                 * @brief Destroy the Collision object
                 *
                 */
                ~CollisionSystem() override = default;
                /**
                 * @brief Update the entities with the system properties.
                 *
                 * @param entities The entities to update
                 */
                void update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities) override;
                /**
                 * @brief Get the Type object
                 *
                 * @return SystemType
                 */
                SystemType getSystemType() const override;

            protected:
            private:
        };
    }
}
