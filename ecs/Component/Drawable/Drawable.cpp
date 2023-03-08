/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Drawable
*/

#include "Drawable.hpp"

ecs::component::Drawable::Drawable(std::string _Texture, float _Scale) : Scale(_Scale), Texture(_Texture)
{
}

ecs::component::ComponentType ecs::component::Drawable::getComponentType() const
{
    return DRAWABLECOMPONENT;
}

float ecs::component::Drawable::getScale() const
{
    return Scale;
}

void ecs::component::Drawable::setScale(float _Scale)
{
    Scale = _Scale;
}

std::string ecs::component::Drawable::getTexture() const
{
    return Texture;
}

void ecs::component::Drawable::setTexture(std::string _Texture)
{
    Texture = _Texture;
}
