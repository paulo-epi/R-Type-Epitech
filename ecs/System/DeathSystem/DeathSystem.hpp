/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** DeathSystem
*/

#pragma once

#include "../ISystem.hpp"

namespace ecs {
    namespace system {
        /**
         * @brief Collision class
         *
         */
        class DeathSystem : public ISystem {
            public:
                /**
                 * @brief Construct a new Collision object
                 *
                 */
                DeathSystem(){};
                /**
                 * @brief Destroy the Collision object
                 *
                 */
                ~DeathSystem() override = default;
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
