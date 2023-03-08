/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this [WSL: Ubuntu]
** File description:
** PlayerSystem
*/

#include "PlayerSystem.hpp"
// std::string ecs::system::PlayerSystem::getPlayerString(void)
// {
//     std::string player = std::to_string(_pos.getX());
//     player += ",";
//     player += std::to_string(_pos.getY());
//     player += ",";
//     player += std::to_string(static_cast<int>(_dir));

//     return player;
// }

// void ecs::system::PlayerSystem::move(std::string dir)
// {
//     if (dir.find("LEFT")) {
//         _dir = Direction::LEFT;
//         _pos.setX(_pos.getX() - 10);
//     } else if (dir.find("RIGHT")) {
//         _dir = Direction::RIGHT;
//         _pos.setX(_pos.getX() + 10);
//     } else if (dir.find("UP")) {
//         _dir = Direction::UP;
//         _pos.setY(_pos.getY() - 10);
//     } else if (dir.find("DOWN")) {
//         _dir = Direction::DOWN;
//         _pos.setY(_pos.getY() + 10);
//     }
// }


ecs::system::PlayerSystem::PlayerSystem(){};

void ecs::system::PlayerSystem::update(std::vector<std::shared_ptr<ecs::entity::Entity>> &entities)
{
    for (auto entity : entities) {
        if (entity.get()->hasComponent(ecs::component::PLAYERCOMPONENT)) {
            ecs::component::Position *position = dynamic_cast<ecs::component::Position *>(entity.get()->getComponent(ecs::component::POSITIONCOMPONENT).get());
            ecs::component::Speed *speed = dynamic_cast<ecs::component::Speed *>(entity.get()->getComponent(ecs::component::SPEEDCOMPONENT).get());
            ecs::component::Player *player = dynamic_cast<ecs::component::Player *>(entity.get()->getComponent(ecs::component::PLAYERCOMPONENT).get());

            std::string command = player->getCommand();

            while (command != "") {

                if (command.find("UP") != std::string::npos) {
                    position->setY(position->getY() - speed->getSpeed());
                }
                if (command.find("RIGHT") != std::string::npos) {
                    position->setX(position->getX() + speed->getSpeed());
                }
                if (command.find("DOWN") != std::string::npos) {
                    position->setY(position->getY() + speed->getSpeed());
                }
                if (command.find("LEFT") != std::string::npos) {
                    position->setX(position->getX() - speed->getSpeed());
                }
                command = player->getCommand();
            }
        }
    }
}

ecs::system::SystemType ecs::system::PlayerSystem::getSystemType() const 
{
    return PLAYERSYSTEM;
}
