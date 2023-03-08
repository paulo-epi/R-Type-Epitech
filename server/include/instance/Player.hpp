/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** Player
*/

#pragma once

#include "basics.hpp"
using boost::asio::ip::udp;
using boost::asio::ip::tcp;

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player {
    public:

        /**
         * @brief Create a new Player Object
         * @param _PlayerName Player name
         * @param _TCPSendpoint Player's TCP endpoint
         * @param _UDPSendpoint Player's UDP endpoint
        */
        Player(std::string _PlayerName/*, tcp::endpoint _TCPSendpoint, udp::endpoint UDPSendpoint*/);

        /**
         * @brief Destroy a Player Object
        */
        ~Player();

        std::string getPlayerName() const{ return PlayerName; };
        /**
         * @brief Get TCP sendpoint for This
        */
        // tcp::endpoint GetTCPSendpoint() const { return TCPSendpoint; };

        /**
         * @brief Get UDP sendpoint for This
        */
        // udp::endpoint GetUDPSendpoint() const { return UDPSendpoint; };

        void setIsReady() { std::cout<<_isReady << std::endl;_isReady = true; };

        bool isReady() { return _isReady; };
    protected:
    private:

        bool _isReady;
        std::string PlayerName;
};

#endif /* !PLAYER_HPP_ */
