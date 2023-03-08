/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Instance
*/

#include "../../include/instance/Instance.hpp"

Instance::Instance(Player *_player) : State(LOBBY)
{
    Players.emplace_back(_player);
    Name = _player->getPlayerName() + "'s party";
}

Instance::~Instance()
{
}

void Instance::AddPlayer(Player *_player)
{
    Players.emplace_back(_player);
}

void Instance::RemovePlayer(std::string _PlayerName)
{
    for (int i = 0; i < Players.size(); i++)
    {
        if (_PlayerName.find(Players.at(i)->getPlayerName()) != std::string::npos)
        {
            Players.erase(Players.begin() + i);
            if (State == Instance::IN_GAME)
            {
                this->getEntityPool().RemoveEntity(i);
            }
        }
    }
}

void Instance::Init()
{
    EntityPool.GetEntities().clear();

    for (uint playerId = 0; playerId < GetPlayersCount(); playerId++)
    {
        if (playerId == 0)
            EntityPool.AddEntity(ecs::entity::PLAYER1);
        if (playerId == 1)
            EntityPool.AddEntity(ecs::entity::PLAYER2);
        if (playerId == 2)
            EntityPool.AddEntity(ecs::entity::PLAYER3);
        if (playerId == 3)
            EntityPool.AddEntity(ecs::entity::PLAYER4);
    }
}

void Instance::Update()
{
    if (State == IN_GAME)
    {
        if (EntityPool.anyPlayerAlive() == false)
            State = PAUSED;
        EntityPool.Update();
        removeUselessEntities();
        spawnEnemy();
    }
}

bool Instance::playerInLobby(std::string name)
{
    for (auto player : Players)
    {
        if (player->getPlayerName().find(name) != std::string::npos)
            return true;
    }
    return false;
}

std::string Instance::getInstanceInfos() const
{
    std::string str;

    if (State == Instance::LOBBY)
    {
        str.append(Name + "|");
        for (auto player : Players)
            str.append(player->getPlayerName() + ",");
        return str + "\n";
    }
}

std::string Instance::getGameDatas()
{
    return EntityPool.dumpDrawableEntities();
}

std::shared_ptr<ecs::entity::Entity> Instance::getPlayerEntity(std::string playerName)
{
    for (int i = 0; i < Players.size(); i++)
    {

        if (Players.at(i)->getPlayerName().find(playerName) != std::string::npos)
            return EntityPool.getPlayerEntityById(i);
    }
    return nullptr;
}

bool Instance::isGameReady()
{
    int count = 0;

    for (auto player : Players)
    {
        if (player->isReady())
        {
            count++;
        }
    }
    return (count == Players.size()) ? true : false;
}

void Instance::removeUselessEntities()
{
    EntityPool.removeUselessEntity();
}

void Instance::spawnEnemy()
{
    int chance = rand() % 100;
    int enemyType = rand() % 3;
    int y = rand() % 1080;
    int x = 2000;
    int a = rand() % 1080;
    int b = 2000;
    int c = rand() % 1080;
    int d = 2000;
    if (chance == 0 && enemyType == 0)
    {
        ecs::component::Position *position = new ecs::component::Position(x, y);
        EntityPool.AddEntity(ecs::entity::ENEMY, position);
    }
    if (chance == 0 && enemyType == 1)
    {
        ecs::component::Position *position = new ecs::component::Position(b, a);
        EntityPool.AddEntity(ecs::entity::ENEMY2, position);
    }
    if (chance == 0 && enemyType == 2)
    {
        ecs::component::Position *position = new ecs::component::Position(d, c);
        EntityPool.AddEntity(ecs::entity::ENEMY3, position);
    }
}
