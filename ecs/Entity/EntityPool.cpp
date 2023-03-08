/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** EntityPool
*/

#include "EntityPool.hpp"


EntityPool::EntityPool()
{
    Systems.emplace_back(new ecs::system::PlayerSystem);
    Systems.emplace_back(new ecs::system::CollisionSystem);
    Systems.emplace_back(new ecs::system::LaserSystem);
    Systems.emplace_back(new ecs::system::EnemySystem);
    Systems.emplace_back(new ecs::system::DeathSystem);
}

EntityPool::~EntityPool()
{
}

void EntityPool::AddEntity(ecs::entity::EntityType _EntityType, ecs::component::Position *position)
{

    switch (_EntityType) {
        case ecs::entity::PLAYER1:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::PLAYER1, "ecs/Configuration/Player1.conf"));
            break;
        case ecs::entity::PLAYER2:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::PLAYER2, "ecs/Configuration/Player2.conf"));
            break;
        case ecs::entity::PLAYER3:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::PLAYER3, "ecs/Configuration/Player3.conf"));
            break;
        case ecs::entity::PLAYER4:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::PLAYER4, "ecs/Configuration/Player4.conf"));
            break;
        case ecs::entity::LASER:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::LASER, "ecs/Configuration/Laser.conf", position));
            break;
        case ecs::entity::ENEMY:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::ENEMY, "ecs/Configuration/Enemy.conf", position));
            break;
        case ecs::entity::ENEMY2:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::ENEMY2, "ecs/Configuration/Enemy2.conf", position));
            break;
        case ecs::entity::ENEMY3:
            Entities.emplace_back(new ecs::entity::Entity(ecs::entity::ENEMY3, "ecs/Configuration/Enemy3.conf", position));
            break;
        default:
            break;
    }
}

void EntityPool::RemoveEntity(uint id)
{
    Entities.erase(Entities.begin() + id);
}

std::vector<std::shared_ptr<ecs::entity::Entity>> &EntityPool::GetEntities()
{
    return Entities;
}

void EntityPool::Update()
{
    for (auto system : Systems) {
        system.get()->update(Entities);
    }
}