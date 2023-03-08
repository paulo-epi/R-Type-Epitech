/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Movement
*/

#include "Movement.hpp"

ecs::system::SystemType ecs::system::Movement::getSystemType() const
{
    return ecs::system::SystemType::MOVEMENTSYSTEM;
}

void ecs::system::Movement::update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities)
{

}
