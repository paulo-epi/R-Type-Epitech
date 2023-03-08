/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Collision
*/

#include "Collision.hpp"

ecs::component::Collision::Collision(int width, int height) : _width(width), _height(height)
{
}

ecs::component::ComponentType ecs::component::Collision::getComponentType() const
{
    return ecs::component::ComponentType::COLLISIONCOMPONENT;
}

std::pair<int, int> ecs::component::Collision::getHitbox() const
{
    return std::pair<int, int>(_width, _height);
}

void ecs::component::Collision::setHitbox(std::pair<int, int> hitbox)
{
    _width = hitbox.first;
    _height = hitbox.second;
}
