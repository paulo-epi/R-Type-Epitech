/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** LaserSystem
*/

#include "LaserSystem.hpp"

ecs::system::LaserSystem::LaserSystem()
{
}

void ecs::system::LaserSystem::update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities)
{
    for (auto entity : entities) {
        if (entity.get()->getType() == ecs::entity::LASER) {
            ecs::component::Speed *speed = dynamic_cast<ecs::component::Speed *>(entity.get()->getComponent(ecs::component::SPEEDCOMPONENT).get());
            ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
            if (position->getX() < 2000) {
                position->setX(position->getX() + speed->getSpeed());
            }
        }
    }
}

ecs::system::SystemType ecs::system::LaserSystem::getSystemType() const
{
    return LASERSYSTEM;
}
