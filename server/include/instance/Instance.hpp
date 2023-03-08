/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Instance
*/

#pragma once

#include "Player.hpp"
#include "../../ecs/Entity/EntityPool.hpp"

/**
 * @brief Instance class
 *
 */
class Instance : public EntityPool {
    public:

        /**
         * @brief Instance state
         *
         */
        enum InstanceState {
            LOBBY,
            IN_GAME,
            PAUSED
        };

        /**
        * @brief Create a new Instance object
        */
        Instance(Player *_player);

        /**
        * @brief Delete a Instance object
        */
        ~Instance();

        /**
        * @brief Add a player to the lobby
        * @param _player Player to add
        */
        void AddPlayer(Player *_player);

        /**
        * @brief Remove a player from the lobby
        * @param _player Player to remove
        */
        void RemovePlayer(std::string _playerName);

        /**
         * @brief Set the State object
         *
         * @param state
         */
        void setState(Instance::InstanceState state) { State = state; };

        /**
        * @brief Get a list of current players
        */
        std::vector<Player *> &GetPlayers() { return Players; };

        /**
         * @brief Get the if players are in the lobby
         *
         * @param name
         * @return true
         * @return false
         */
        bool playerInLobby(std::string name);

        /**
         * @brief Get the Instance Infos object
         *
         * @return std::string
         */
        std::string getInstanceInfos() const;

        /**
         * @brief Get the game data
         *
         * @return std::string
         */
        std::string getGameDatas();

        /**
         * @brief Get the Instance state
         *
         * @return enum
         */
        InstanceState getState() const { return State; };

        /**
         * @brief Get the Player Entity object
         *
         * @param playerName
         * @return std::shared_ptr<ecs::entity::Entity>
         */
        std::shared_ptr<ecs::entity::Entity> getPlayerEntity(std::string playerName);

        /**
         * @brief Is the game ready
         *
         * @return true
         * @return false
         */
        bool isGameReady();

        /**
         * @brief Get the Entity Pool object
         *
         * @return EntityPool&
         */
        EntityPool &getEntityPool(){ return EntityPool; };

        /**
         * @brief Get the Name object
         *
         * @return std::string
         */
        std::string getName() const { return Name; };

        /**
        * @brief Get current number of player(s)
        */
        int GetPlayersCount() const { return Players.size(); }; 

        /**
        * @brief Init game entities
        */
        void Init(); 

        /**
         * @brief remove useless entities
         *
         */
        void removeUselessEntities();

        /**
         * @brief Spawn enemies
         *
         */
        void spawnEnemy();

        /**
        * @brief Update game entities
        */
       void Update();

    protected:
    private:
        EntityPool EntityPool;
        std::string Name;
        std::vector<Player *> Players;
        InstanceState State;


};