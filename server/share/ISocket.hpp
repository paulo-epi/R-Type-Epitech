/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-kelian.this
** File description:
** ISocket
*/

#ifndef ISocket_HPP_
#define ISocket_HPP_

#include "../include/basics.hpp"

namespace rti {
    class ISocket {
        public:
            virtual void send_message(std::string message) = 0; //Send (std::string|message) to connected socket.
            virtual std::string read_message() = 0; //Return std::string if (stack|Every data will be store into "stack" variable) is not empty, otherwise return empty string.

        protected:
        private:
    };
}

#endif /* !ISocket_HPP_ */