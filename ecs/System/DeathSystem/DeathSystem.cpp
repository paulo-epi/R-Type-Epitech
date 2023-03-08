/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** DeathSystem
*/

#include "DeathSystem.hpp"

ecs::system::SystemType ecs::system::DeathSystem::getSystemType() const
{
    return ecs::system::DEATHSYSTEM;
}

void ecs::system::DeathSystem::update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities)
{
    for (int i = 0; i < entities.size(); i++) {

        if (entities.at(i).get()->hasComponent(ecs::component::HEALTHCOMPONENT)) {
            ecs::component::Health *health = static_cast<ecs::component::Health *>(entities.at(i).get()->getComponent(ecs::component::HEALTHCOMPONENT).get());
            if (health->getIsAlive()){
                if (health->getHealth() < 0)
                    health->setIsAlive(false);
            } else {
                entities.erase(entities.cbegin() + i);
            }
        }
    }
}