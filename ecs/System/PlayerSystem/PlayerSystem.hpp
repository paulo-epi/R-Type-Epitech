/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** PlayerSystem
*/

#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "../ISystem.hpp"
#include "../../Component/Position/Position.hpp"

namespace ecs {
    namespace system {
        /**
         * @brief PlayerSystem class
         *
         */
        class PlayerSystem : public ISystem {
            public:
                /**
                 * @brief Construct a new PlayerSystem object
                 *
                 */
                PlayerSystem(/*int clientId, ecs::component::Position pos = ((1920 / 2), (1080 / 2)), Direction dir = Direction::RIGHT*/);// : _clientId(clientId), _pos(pos), _realpos(pos), _dir(dir) {};
                /**
                 * @brief Destroy the PlayerSystem object
                 *
                 */
                ~PlayerSystem() override = default;
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
                 * @brief Get the Player String object
                 *
                 * @return std::string
                 */
                std::string getPlayerString(void);

                /**
                 * @brief move player
                 *
                 * @param dir
                 */
                void move(std::string dir);

                ecs::component::Position _pos;
                ecs::component::Position _realpos;
                Direction _dir;
                int _clientId;

            protected:
            private:
        };
    }
}
