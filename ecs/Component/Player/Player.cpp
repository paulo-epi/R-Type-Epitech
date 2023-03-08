/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** Player
*/

#include "Player.hpp"

ecs::component::Player::Player() : IComponent()
{
}

ecs::component::ComponentType ecs::component::Player::getComponentType() const
{
    return PLAYERCOMPONENT;
}

std::string ecs::component::Player::getCommand()
{
    std::string command;

    if (_commands.size() == 0)
        return "";
    command = _commands.back();
    _commands.pop_back();
    return command;
}

void ecs::component::Player::addCommand(std::string command)
{
    _commands.emplace_back(command);
}
