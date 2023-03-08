/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Player
*/

#include "../../include/instance/Player.hpp"

Player::Player(std::string _PlayerName)
{
    PlayerName = _PlayerName;
    _isReady = false;
}

Player::~Player()
{
}

