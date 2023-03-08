/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Health
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        class Health : public IComponent {
            public:
                /**
                 * @brief Construct a new Health object
                 *
                 * @param health The health of the entity
                 */
                Health(int health = 100);
                /**
                 * @brief Destroy the Health object
                 *
                 */
                ~Health() override = default;
                /**
                 * @brief Get the Type of an object
                 *
                 * @return ComponentType
                 */
                ComponentType getComponentType() const override;
                /**
                 * @brief Get the Health of an object
                 *
                 * @return int
                 */
                int getHealth() const;
                /**
                 * @brief Set the Health to an object
                 *
                 * @param health
                 */
                void setHealth(int health);
                /**
                 * @brief Get the Is Alive object
                 *
                 * @return true
                 * @return false
                 */
                bool getIsAlive() const;
                /**
                 * @brief Set the Is Alive object
                 *
                 * @param isAlive
                 */
                void setIsAlive(bool isAlive);

            protected:
            private:
                int _health;
                bool _isAlive;
        };
    }
}