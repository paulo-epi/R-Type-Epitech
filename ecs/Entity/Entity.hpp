/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Entity
*/

#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include "../../Error/Error.hpp"
#include "../Component/IComponent.hpp"
#include "../Component/Position/Position.hpp"
#include "../Component/Health/Health.hpp"
#include "../Component/Damage/Damage.hpp"
#include "../Component/Speed/Speed.hpp"
#include "../Component/Collision/Collision.hpp"
#include "../Component/Drawable/Drawable.hpp"
#include "../Component/Player/Player.hpp"


namespace ecs {
    namespace entity {
        /**
         * @brief Entity type for the object
         *
         */
        enum EntityType {
            PLAYER1,
            PLAYER2,
            PLAYER3,
            PLAYER4,
            ENEMY,
            ENEMY2,
            ENEMY3,
            LASER,
            WALL,
            NONE
        };
        /**
         * @brief Entity class
         *
         */
        class Entity {
            public:
            /**
             * @brief Construct a new Entity
             * @param type Entity type
             */
            Entity(EntityType type = NONE);
            /**
             * @brief Construct a new Entity object
             *
             */
            Entity();
            /**
             * @brief Create a Entity with Components from a .conf file
             * @param _Filename Filename of the .conf file
             */
            Entity(EntityType type, std::string _Filename, ecs::component::Position *position = nullptr);
            /**
             * @brief Destroy the Entity object
             *
             */
            ~Entity();
            /**
             * @brief Get the Type object
             * @return The entity type
             */
            ecs::entity::EntityType getType() const;
            /**
             * @brief set the id of the entity
             * @param id The id of the entity
             */
            void setId(size_t id);
            /**
             * @brief Get the Id object
             * @return The id of the entity
             */
            size_t getId(void) const;
            /**
             * @brief Check if the entity has a component
             * @param type The type of the component
             *
             * @return true if the entity has the component
             * @return false if the entity doesn't have the component
             */
            bool hasComponent(ecs::component::ComponentType type);
            /**
             * @brief Add a component to the entity
             * @param component The component to add
             */
            void addComponent(std::shared_ptr<ecs::component::IComponent> component);
            /**
             * @brief Get the Component object
             * @param type The type of the component
             *
             * @return The component
             */
            std::shared_ptr<ecs::component::IComponent> getComponent(ecs::component::ComponentType type);
            /**
             * @brief Remove a component from the entity
             * @param type The type of the component
             */
            void removeComponent(ecs::component::ComponentType type);

            protected:
            private:
            /**
             * @brief The id of the entity
             *
             */
            size_t _id;
            /**
             * @brief The type of the entity
             *
             */
            ecs::entity::EntityType _type;
            /**
             * @brief The components of the entity
             *
             */
            std::vector<std::shared_ptr<ecs::component::IComponent>> _components;
        };
    }
}
