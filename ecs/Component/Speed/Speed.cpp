/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Speed
*/

#include "Speed.hpp"

ecs::component::Speed::Speed(float speed) : _speed(speed)
{
}

ecs::component::ComponentType ecs::component::Speed::getComponentType() const
{
    return ecs::component::ComponentType::SPEEDCOMPONENT;
}

float ecs::component::Speed::getSpeed() const
{
    return _speed;
}

void ecs::component::Speed::setSpeed(float speed)
{
    _speed = speed;
}
