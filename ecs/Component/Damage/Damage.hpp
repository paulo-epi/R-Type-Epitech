/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Damage
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        /**
         * @brief Damage component
         *
         */
        class Damage : public IComponent {
            public:
                /**
                 * @brief Construct a new Damage object
                 *
                 */
                Damage(int damage = 10);
                /**
                 * @brief Destroy the Damage object
                 *
                 */
                ~Damage() override = default;
                /**
                 * @brief Get the Component Type object
                 *
                 * @return ComponentType
                 */
                ComponentType getComponentType() const override;
                /**
                 * @brief Get the Damage object
                 *
                 * @return int
                 */
                int getDamage() const;
                /**
                 * @brief Set the Damage object
                 *
                 * @param damage
                 */
                void setDamage(int damage);

            protected:
            private:
                int _damage;
        };
    }
}
