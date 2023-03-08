/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Position
*/

#include "Position.hpp"

ecs::component::Position::Position(float x, float y) : _x(x), _y(y)
{
}

ecs::component::ComponentType ecs::component::Position::getComponentType() const
{
    return ecs::component::ComponentType::POSITIONCOMPONENT;
}

std::pair<float, float> ecs::component::Position::getPosition() const
{
    return std::make_pair(_x, _y);
}

void ecs::component::Position::setX(float x)
{
    _x = x;
}

void ecs::component::Position::setY(float y)
{
    _y = y;
}

float ecs::component::Position::getX()
{
    return _x;
}

float ecs::component::Position::getY()
{
    return _y;
}
