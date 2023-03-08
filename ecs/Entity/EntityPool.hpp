/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** EntityPool
*/

#pragma once

#include "basics.hpp"
#include "Entity.hpp"
#include "../System/CollisionSystem/CollisionSystem.hpp"
#include "../System/EnemySystem/EnemySystem.hpp"
#include "../System/MovementSystem/Movement.hpp"
#include "../System/PlayerSystem/PlayerSystem.hpp"
#include "../System/LaserSystem/LaserSystem.hpp"
#include "../System/DeathSystem/DeathSystem.hpp"


#ifndef ENTITYPOOL_HPP_
#define ENTITYPOOL_HPP_

class EntityPool {
    public:

        /**
         * @brief Create a EntityPool Object
        */
        EntityPool();

        /**
         * @brief Destroy a EntityPool Object
        */
        ~EntityPool();

        /**
         * @brief Add a Entity Object in Entities
         * @param _EntityType Entity type from EntityType enum
        */
        void AddEntity(ecs::entity::EntityType _EntityType, ecs::component::Position *position = nullptr);

        /**
         * @brief Remove a Entity Object in Entities
         * @param _Id Entity id
        */
        void RemoveEntity(uint _Id);

        void setEntities(std::vector<std::shared_ptr<ecs::entity::Entity>> entities){ Entities = entities; };

        /**
         * @brief Get entities
         * @return Entities
        */
        std::vector<std::shared_ptr<ecs::entity::Entity>> &GetEntities();

        std::shared_ptr<ecs::entity::Entity> getPlayerEntityById(uint id)
        {
            for (auto entity : Entities) {
                if (entity.get()->getType() == ecs::entity::PLAYER1 && id == 0)
                    return entity;
                if (entity.get()->getType() == ecs::entity::PLAYER2 && id == 1)
                    return entity;
                if (entity.get()->getType() == ecs::entity::PLAYER3 && id == 2)
                    return entity;
                if (entity.get()->getType() == ecs::entity::PLAYER4 && id == 3)
                    return entity;
            }
        }

        void removeUselessEntity()
        {
            for (int i = 0; i < Entities.size(); i++) {
                if (Entities.at(i).get()->hasComponent(ecs::component::POSITIONCOMPONENT)) {
                    ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(Entities.at(i).get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
                    if (position->getX() > 2300 || position->getX() < -99)
                        RemoveEntity(i);
                }
            }
        }

        std::string dumpDrawableEntities()
        {
            std::string str;

            for (auto entity : Entities) {
                if (entity.get()->hasComponent(ecs::component::DRAWABLECOMPONENT) && entity.get()->hasComponent(ecs::component::POSITIONCOMPONENT)){
                    ecs::component::Drawable *drawable = dynamic_cast<ecs::component::Drawable *>(entity.get()->getComponent(ecs::component::DRAWABLECOMPONENT).get());
                    str.append(drawable->getTexture() + ",");
                    str.append(std::to_string(drawable->getScale()) + ",");
                    ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
                    str.append(std::to_string(position->getX()) + "," + std::to_string(position->getY()) + "|");
                }
            }

            return str;
        }

        bool anyPlayerAlive()
        {
            int playerCount = 0;
            for (auto entity : Entities) {
                 if (entity.get()->getType() == ecs::entity::PLAYER1 || entity.get()->getType() == ecs::entity::PLAYER2 
                || entity.get()->getType() == ecs::entity::PLAYER3 || entity.get()->getType() == ecs::entity::PLAYER4) {
                    playerCount++;
                }
            }
            return (playerCount > 0) ? true : false;
        }

        void Update();

    protected:
    private:
        std::vector<std::shared_ptr<ecs::entity::Entity>> Entities;
        std::vector<std::shared_ptr<ecs::system::ISystem>> Systems;
};

#endif /* !ENTITYPOOL_HPP_ */
