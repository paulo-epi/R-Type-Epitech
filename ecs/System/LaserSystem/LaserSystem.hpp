/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** LaserSystem
*/

#pragma once

#include "../ISystem.hpp"

namespace ecs {
    namespace system {
        /**
         * @brief Laser system
         *
         */
        class LaserSystem : public ISystem {
        public:
            /**
             * @brief Construct a new Laser object
             *
             */
            LaserSystem();
            /**
             * @brief Destroy the Laser object
             *
             */
            ~LaserSystem() override = default;
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
             * @brief Get the Laser String object
             *
             * @return std::string
             */
            std::string getLaserString(void);

            ecs::component::Position _pos;
            ecs::component::Position _curpos;
            Direction _dir;
            int _clientIdOwner;
            float _speed;
        };
    }
}
