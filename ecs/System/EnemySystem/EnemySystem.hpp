/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** EnemySystem
*/

#pragma once

#include "../ISystem.hpp"

namespace ecs {
    namespace system {
        /**
         * @brief EnemySystem class
         *
         */
        class EnemySystem : public ISystem {
            public:
                /**
                 * @brief Construct a new EnemySystem object
                 *
                 */
                EnemySystem();
                /**
                 * @brief Destroy the EnemySystem object
                 *
                 */
                ~EnemySystem() override = default;
                /**
                 * @brief Update the system
                 *
                 * @param entities The entities to update
                 */
                void update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities) override;
                /**
                 * @brief Get the Type object
                 *
                 * @return systemType
                 */
                SystemType getSystemType() const override;

                /**
                 * @brief Get the Enemy String object
                 *
                 * @return std::string
                 */
                // std::string getEnemyString(void);

                // ecs::component::Position _pos;
                // Direction _dir;

            protected:
            private:
        };
    }
}
