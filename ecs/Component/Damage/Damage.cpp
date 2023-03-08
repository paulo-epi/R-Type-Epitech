/*
** EPITECH PROJECT, 2022
** 1
** File description:
** Damage
*/

#include "Damage.hpp"

ecs::component::Damage::Damage(int damage) : _damage(damage)
{
}

ecs::component::ComponentType ecs::component::Damage::getComponentType() const
{
    return ecs::component::ComponentType::DAMAGECOMPONENT;
}

int ecs::component::Damage::getDamage() const
{
    return _damage;
}

void ecs::component::Damage::setDamage(int damage)
{
    _damage = damage;
}
