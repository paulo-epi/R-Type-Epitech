/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** EnemySystem
*/

#include "EnemySystem.hpp"
#include <cmath>

ecs::system::EnemySystem::EnemySystem()
{
    // _pos.setX(spawn);
    // _pos.setY(static_cast<float>((300 * sin(_pos.getX())) + (1080 / 2)));
    // _dir = Direction::LEFT;
}

void ecs::system::EnemySystem::update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities)
{
     for (auto entity : entities) {
        if (entity.get()->getType() == ecs::entity::ENEMY) {
            ecs::component::Speed *speed = dynamic_cast<ecs::component::Speed *>(entity.get()->getComponent(ecs::component::SPEEDCOMPONENT).get());
            ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
            if (position->getX() > - 100) {
                position->setX(position->getX() - speed->getSpeed());
            }
        }
        if (entity.get()->getType() == ecs::entity::ENEMY2) {
            ecs::component::Speed *speed = dynamic_cast<ecs::component::Speed *>(entity.get()->getComponent(ecs::component::SPEEDCOMPONENT).get());
            ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
            if (position->getX() > - 100) {
                position->setX(position->getX() - speed->getSpeed());
            }
        }
        if (entity.get()->getType() == ecs::entity::ENEMY3) {
            ecs::component::Speed *speed = dynamic_cast<ecs::component::Speed *>(entity.get()->getComponent(ecs::component::SPEEDCOMPONENT).get());
            ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
            if (position->getX() > - 100) {
                position->setX(position->getX() - speed->getSpeed());
            }
        }
    }
}

ecs::system::SystemType ecs::system::EnemySystem::getSystemType() const
{
    return ENEMYSYSTEM;
}


// std::string ecs::system::EnemySystem::getEnemyString(void)
// {
//     // std::string enemy = std::to_string(_pos.getX());
//     // enemy += ",";
//     // enemy += std::to_string(_pos.getY());
//     // enemy += ",";
//     // enemy += std::to_string(static_cast<int>(_dir));

//     // return enemy;
// }
