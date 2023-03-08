/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Movement
*/

#pragma once

#include "../ISystem.hpp"

namespace ecs {
    namespace system {
        /**
         * @brief Movement system
         *
         */
        class Movement : public ISystem {
        public:
            /**
             * @brief Construct a new Movement object
             *
             */
            Movement(){};
            /**
             * @brief Destroy the Movement object
             *
             */
            ~Movement() override = default;
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
        };
    }
}
