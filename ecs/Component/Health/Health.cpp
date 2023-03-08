/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Health
*/

#include "Health.hpp"

ecs::component::Health::Health(int health) : IComponent(), _health(health), _isAlive(true)
{
}

ecs::component::ComponentType ecs::component::Health::getComponentType() const
{
    return HEALTHCOMPONENT;
}

int ecs::component::Health::getHealth() const
{
    return _health;
}

void ecs::component::Health::setHealth(int health)
{
    _health = health;
}

bool ecs::component::Health::getIsAlive() const
{
    return _isAlive;
}

void ecs::component::Health::setIsAlive(bool isAlive)
{
    _isAlive = isAlive;
}
