/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Drawable
*/

#pragma once

#include "../IComponent.hpp"

namespace ecs {
    namespace component {
        class Drawable : public IComponent {
            public:
                /**
                 * @brief Construct a new Drawable object
                 *
                 * @param _Texture The texture of the entity
                 * @param _Scale The scaling of the entity
                 */
                Drawable(std::string _Texture, float _Scale);
                /**
                 * @brief Destroy the Drawable object
                 *
                 */
                ~Drawable() override = default;
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
                float getScale() const; 
                /**
                 * @brief Set the Scale to an object
                 *
                 * @param health
                 */
                void setScale(float _Scale);
                /**
                 * @brief Get the Scale of an object
                 *
                 */
                std::string getTexture() const;
                /**
                 * @brief Set the Texture of an object
                 *
                 * @param _Texture
                 */
                void setTexture(std::string _Texture);

            protected:
            private:
                float Scale;
                std::string Texture;
        };
    }
}